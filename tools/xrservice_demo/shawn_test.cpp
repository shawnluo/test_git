#include <linux/sched.h>
#include <pthread.h>
#include <sched.h>
#include <sys/timerfd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <semaphore.h>
#include <unistd.h>
#include <cerrno>
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include <sstream>
#include <cctype>
#include <cstdint>
#include <memory>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <map>
#include <tuple>
#include <optional>

#include <iostream>
#include <thread>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>

#include <XRCameraClient.h>


// 控制调试标志位
bool shawn_dbg = false;

struct CameraData {
    xrcamera_device_helper_t* CamDeviceHelper;
    const char* pCameraName;
    int fnum;
    std::string cameraNameId;
    xrcamera_frame_t pic;
};

const unsigned long long NS_PER_SEC = 1000000000ULL;

const char pCameraName0[] = "fish-eye-mid";
const char pCameraName1[] = "fish-eye-leftdown";
const char pCameraName2[] = "fish-eye-rightdown";
[[maybe_unused]]const char pCameraName3[] = "tof";
const char pCameraName4[] = "rgb-left";
[[maybe_unused]]const char pCameraName5[] = "rgb-right";

// int shawn_dbg = 0;

int32_t savePicture(const void *data, const char *pfile, size_t elemsize, size_t count)
{
    int ret = -1;
    size_t outputsize = 0;
    FILE *fp = nullptr;
    // printf("data: %p, pfile: %s, elemsize: %zu, count: %zu\n", data, pfile, elemsize, count);
    fp = fopen(pfile, "wb");
    if (!fp) {
        printf("open %s error: %s\n", pfile, strerror(errno));
        return ret;
    }
    outputsize = fwrite(data, elemsize, count, fp);
    if (outputsize != count) {
        printf("%s write %zu error: %s\n", pfile, outputsize, strerror(errno));
    }
    ret = fclose(fp);
    return ret;
}

bool isValidInteger(const std::string& str)
{
    if (str.empty() || (!std::isdigit(str[0]) && str[0] != '-' && str[0] != '+')) {
        return false;
    }

    std::istringstream iss(str);
    int number;
    iss >> number;

    return !iss.fail() && iss.eof();
}

int32_t waitCameraStarted(xrcamera_device_helper_t *CameraDeviceHelper)
{
    int ret = 0;
    int i = 0;
    constexpr int COUNT = 1000;
    XRCAMERA_CAMERA_STATUS status = XRCAMERA_CAMERA_STATUS_MAX;
    for (i = 0; i < COUNT; ++i) {
        ret = XRCameraDevice_GetCameraState(CameraDeviceHelper, &status);
        if(status == XRCAMERA_CAMERA_ERROR) {
            printf("[ERROR] %s: Camera has encountered an error, status %d\n", __func__, status);
            return -1;
        }
        if (ret < 0 || status != XRCAMERA_CAMERA_STARTED) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            continue;
        }
        printf("[INFO] wait camera started takes %dms\n", i);
        return 0;
    }
    printf("[ERROR] wait camera started timeout %dms\n", COUNT);
    return -1;
}

void processCamera(CameraData& data, int mdumpSign, int mycount) {
    int ret = 0;

    if (waitCameraStarted(data.CamDeviceHelper) < 0) {
        printf("camera %s not ready or RingBuffer is empty\n", data.pCameraName);
        return;
    }

    for (int i = 0; i < mycount; ++i) {
        ret = XRCameraDevice_GetCurrentFrameNumber(data.CamDeviceHelper, &data.fnum);
        if (ret != 0) {
            printf("%d: call XRCameraDevice_GetCurrentFrameNumber failed.%d\n", __LINE__, ret);
            continue;
        }

        ret = XRCameraDevice_GetFrame(data.CamDeviceHelper, &data.fnum, XRCAMERA_MODE_BLOCKING, XRCAMERA_MODE_NEWER_IF_AVAILABLE, &data.pic);
        if (ret != 0) {
            printf("%d: call XRCameraDevice_GetFrame failed for camera %s.\n", __LINE__, data.pCameraName);
            continue;
        }

        if (mdumpSign == 1) {
            std::string filename = "/sdcard/Pictures/" + data.cameraNameId + std::to_string(data.fnum) + "pic.raw";
            ret = savePicture(data.pic.buffer, filename.c_str(), 1, data.pic.len);
            if (ret < 0) {
                std::cout << "save " << filename << " failed" << std::endl;
            } else {
                std::cout << "frame path: " << filename << ", size: " << data.pic.len << std::endl;
            }
        }

        ret = XRCameraDevice_ReleaseFrame(data.CamDeviceHelper, data.fnum);
        if (ret != 0) {
            printf("%d: call XRCameraDevice_ReleaseFrame failed for camera %s.\n", __LINE__, data.pCameraName);
            continue;
        }
    }

    // 停止相机
    XRCameraDevice_Stop(data.CamDeviceHelper);
    // 分离相机
    XRCameraDevice_DetachCamera(data.CamDeviceHelper);
}

int get_6_camframes(const std::vector<const char*>& cameraNames, int mycount, int dump_image) {
    xrcamera_client_helper_t* clientHelper = XRCameraClient_Create();
    if (!clientHelper) {
        std::cout << __LINE__ << ": create client failed\n";
        return -1;
    }
    std::cout << "Client handle create success." << std::endl;

    int ret = XRCameraClient_GetVersion(clientHelper);
    if (ret <= 0) {
        std::cout << __LINE__ << ": get version fail" << std::endl;
        XRCameraClient_Destroy(clientHelper);
        return -1;
    }

    std::vector<CameraData> cameraDataList;
    for (size_t i = 0; i < cameraNames.size(); ++i) {
        if(strcmp(cameraNames[i], "tof") == 0) {
            continue;
        }
        xrcamera_device_helper_t* helper = XRCameraClient_AttachCamera(clientHelper, cameraNames[i]);
        if (!helper) {
            printf("attach %s fail!\n", cameraNames[i]);
            XRCameraClient_Destroy(clientHelper);
            return -1;
        }
        std::cout << "attach " << cameraNames[i] << " ok!" << std::endl;

        CameraData data = {helper, cameraNames[i], 0, cameraNames[i], {}};
        memset(&data.pic, 0, sizeof(data.pic));
        cameraDataList.push_back(data);
    }

    // 启动相机设备并启动线程处理每个相机
    std::vector<std::thread> threads;
    for (auto& cameraData : cameraDataList) {
        XRCameraDevice_Start(cameraData.CamDeviceHelper);  // 启动相机
        threads.emplace_back(processCamera, std::ref(cameraData), dump_image, mycount);
    }

    // 等待所有线程完成
    for (auto& t : threads) {
        t.join();
    }

    // 销毁客户端
    XRCameraClient_Destroy(clientHelper);
    std::cout << "Client handle destroy success." << std::endl;

    return 0;
}

int main() {
    std::vector<const char*> cameraNames = {"fish-eye-mid", \
                                "fish-eye-leftdown", \
                                "fish-eye-rightdown", \
                                "tof", \
                                "rgb-left", \
                                "rgb-right"};
    std::vector<const char*> cameraNames2 = {"fish-eye-mid", "fish-eye-leftdown"};
    int mycount = 300;
    int dump_image = 1;

    // 启动获取相机帧
    get_6_camframes(cameraNames, mycount, dump_image);

    return 0;
}