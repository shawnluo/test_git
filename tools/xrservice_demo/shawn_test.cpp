#include <cctype>
#include <cerrno>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <linux/sched.h>
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <sched.h>
#include <semaphore.h>
#include <sstream>
#include <string>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/timerfd.h>
#include <sys/types.h>
#include <thread>
#include <tuple>
#include <unistd.h>
#include <vector>

#include <XRCameraClient.h>

// 控制调试标志位
bool shawn_dbg = true;

struct CameraData {
  xrcamera_device_helper_t *CamDeviceHelper;
  const char *pCameraName;
  int fnum;
  std::string cameraNameId;
  xrcamera_frame_t pic;
};

const unsigned long long NS_PER_SEC = 1000000000ULL;

[[maybe_unused]] const char pCameraName3[] = "tof";
const char pCameraName4[] = "rgb-left";
[[maybe_unused]] const char pCameraName5[] = "rgb-right";

// int shawn_dbg = 0;

int32_t savePicture(const void *data, const char *pfile, size_t elemsize,
                    size_t count) {
  int ret = -1;
  size_t outputsize = 0;
  FILE *fp = nullptr;
  // printf("data: %p, pfile: %s, elemsize: %zu, count: %zu\n", data, pfile,
  // elemsize, count);
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

bool isValidInteger(const std::string &str) {
  if (str.empty() ||
      (!std::isdigit(str[0]) && str[0] != '-' && str[0] != '+')) {
    return false;
  }

  std::istringstream iss(str);
  int number;
  iss >> number;

  return !iss.fail() && iss.eof();
}

#if 0
int processGetITofFrame(xrcamera_device_helper_t *CamDeviceHelper,
    int32_t frameNumber,
    int frameCount,
    [[maybe_unused]]xrcamera_client_helper_t *clientHelper) {
    xrcamera_frame_t depth;
    xrcamera_frame_t confidence;
    char                               filePath[128] = {0};
    int                                ret           = 0;

    memset(&depth, 0, sizeof(xrcamera_frame_t));
    memset(&confidence, 0, sizeof(xrcamera_frame_t));
    for (int i = 0; i < frameCount; ++i) {
        std::cout << "current frame frameNumber:  " << frameNumber << std::endl;
        ret = XRCameraDevice_GetITofFrame(CamDeviceHelper,
                                           &frameNumber,
                                           XRCAMERA_MODE_BLOCKING,
                                           XRCAMERA_MODE_EXPLICIT_FRAME_NUMBER,
                                           &depth,
                                           &confidence);

        if (ret != 0) {
            std::cout << "get " << frameNumber << " frame fail" << std::endl;
            ret = XRCameraDevice_GetCurrentFrameNumber(CamDeviceHelper, &frameNumber);
            if (ret < 0) {
                printf("%d: get frame number failed\n", __LINE__);
            }
            continue;
        }

        sprintf(filePath,"/sdcard/Pictures/depth_%u.raw", depth.fn);
        FILE *fp = fopen(filePath, "wb");
        if (!fp) {
            std::cout << __LINE__ << ": open failed: " << strerror(errno) << std::endl;
            return -1;
        }
        fwrite(depth.buffer, 1, depth.len, fp);
        fclose(fp);

        sprintf(filePath,"/sdcard/Pictures/confidence_%u.raw", depth.fn);
        fp = fopen(filePath, "wb");
        if (!fp) {
            std::cout << __LINE__ << ": open failed: " << strerror(errno) << std::endl;
            return -1;
        }
        fwrite(confidence.buffer, 1, confidence.len, fp);
        fclose(fp);

        ret = XRCameraDevice_ReleaseFrame(CamDeviceHelper, frameNumber);
        if (ret != 0) {
            std::cout << __LINE__ << ": release frame fail! please retry" << std::endl;
            return -1;
        }
        ++frameNumber;
    }
    return 0;
}

int getTofFrame(const char *pCameraName,
                int (*processFunc)(xrcamera_device_helper_t*,
                int32_t,
                int,
                xrcamera_client_helper_t *)) {
    xrcamera_client_helper_t           *clientHelper       = nullptr;
    xrcamera_device_helper_t           *CamDeviceHelper    = nullptr;
    XRCAMERA_CAMERA_STATUS             camstate            = XRCAMERA_CAMERA_CLIENT_DISCONNECTED;
    int                                 ret                 = 0;
    int32_t                             frameNumber         = 0;
    uint32_t                            frameCount          = 1;

    std::cout << "Please enter the required number of frames: ";
    std::cin >> frameCount;
    std::cout << "The required number of frames is: " << frameCount << std::endl;

    clientHelper = XRCameraClient_Create();
    if (!clientHelper) {
        std::cout << __LINE__ << ": create client failed\n";
        return -1;
    }
    std::cout << "Client handle create success." << std::endl;

    CamDeviceHelper = XRCameraClient_AttachCamera(clientHelper, pCameraName);
    if (!CamDeviceHelper) {
        std::cout << __LINE__ << ": attachcamera fail! " << pCameraName << "please retry" << std::endl;
        return -1;
    }
    std::cout << "attachcamera ok! test name : " << pCameraName << std::endl;

    ret = XRCameraDevice_Start(CamDeviceHelper);
    if (ret != 0) {
        std::cout << __LINE__ << ": start open camera fail! please retry" << std::endl;
        return -1;
    }
    std::cout << "start open camera ok! " << std::endl;

    ret = XRCameraDevice_GetCameraState(CamDeviceHelper, &camstate);
    std::cout << "get camera state: "
        << XRCameraHelper_ShowState(camstate) << std::endl;
    if (ret != 0) {
        std::cout << __LINE__ << ": get camera state fail" << std::endl;
        return -1;
    }
    std::cout << "get camera state succed" << std::endl;
    if (waitCameraStarted(CamDeviceHelper) < 0) {
        printf("camera not ready or RingBuffer is empty\n");
        return -1;
    }

    sleep(2);
    //std::cout << __LINE__ << ": sleep 5 s" << std::endl;

    ret = XRCameraDevice_GetCurrentFrameNumber(CamDeviceHelper, &frameNumber);
    if (ret != 0) {
        std::cout << __LINE__ << ": get current frame fail! " << std::endl;
        return -1;
    }

    processFunc(CamDeviceHelper, frameNumber, frameCount, clientHelper);

    ret = XRCameraDevice_Stop(CamDeviceHelper);
    if (ret != 0) {
        std::cout << __LINE__ << ": stop camera fail! please retry" << std::endl;
        return -1;
    }
    std::cout << "stop camera ok! " << std::endl;

    XRCameraDevice_DetachCamera(CamDeviceHelper);
    std::cout << "detach camera ok!" << std::endl;

    if (!!clientHelper) XRCameraClient_Destroy(clientHelper);
    std::cout << "Client handle destory success." << std::endl;

    return 0;
}
#endif

int32_t waitCameraStarted(xrcamera_device_helper_t *CameraDeviceHelper) {
  int ret = 0;
  int i = 0;
  constexpr int COUNT = 1000;
  XRCAMERA_CAMERA_STATUS status = XRCAMERA_CAMERA_STATUS_MAX;
  for (i = 0; i < COUNT; ++i) {
    ret = XRCameraDevice_GetCameraState(CameraDeviceHelper, &status);
    if (status == XRCAMERA_CAMERA_ERROR) {
      printf("[ERROR] %s: Camera has encountered an error, status %d\n",
             __func__, status);
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

void processCamera(CameraData &data, int mdumpSign, int mycount) {
  int ret = 0;

  if (waitCameraStarted(data.CamDeviceHelper) < 0) {
    printf("camera %s not ready or RingBuffer is empty\n", data.pCameraName);
    return;
  }

  static int pre_fnum = 0;

  for (int i = 0; i < mycount; ++i) {
    int timeout = 600;
    while (timeout--) {
      int timeout2 = 600;
      while (timeout2--) {
        ret = XRCameraDevice_GetCurrentFrameNumber(data.CamDeviceHelper,
                                                   &data.fnum);
        // std::cout << "data.fnum: " << data.fnum << std::endl;
        if (ret != 0) {
          printf("%d: call XRCameraDevice_GetCurrentFrameNumber failed.%d\n",
                 __LINE__, ret);
          continue;
        }
        std::this_thread::sleep_for(std::chrono::microseconds(1));
      }

      if (data.fnum == pre_fnum) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
      } else {
        // std::cout << "  ---- break ----  " << data.pCameraName << " - fnum: "
        // << data.fnum << std::endl;
        break;
      }
    }
    if (0 == timeout) {
      std::cout << "[timeout] " << data.pCameraName << std::endl;
    }
    pre_fnum = data.fnum;
    if(shawn_dbg) {
    // std::cout << data.pCameraName << "\t fnum: " << data.fnum << std::endl;
      std::cout << "[cam_name]: " << data.pCameraName << "\tdata.fnum: " << data.fnum << "\treal_fn: " << data.pic.real_fn << std::endl;
    }
    ret = XRCameraDevice_GetFrame(data.CamDeviceHelper, &data.fnum,
                                  XRCAMERA_MODE_BLOCKING,
                                  XRCAMERA_MODE_NEWER_IF_AVAILABLE, &data.pic);
    if (ret != 0) {
      printf("%d: call XRCameraDevice_GetFrame failed for camera %s.\n",
             __LINE__, data.pCameraName);
      continue;
    }

    if (mdumpSign == 1) {
      std::string filename = "/sdcard/Pictures/" + data.cameraNameId +
                             std::to_string(data.fnum) + "pic.raw";
      ret = savePicture(data.pic.buffer, filename.c_str(), 1, data.pic.len);
      if (ret < 0) {
        std::cout << "save " << filename << " failed" << std::endl;
      } else {
        if(shawn_dbg) {
        std::cout << "frame path: " << filename << ", size: " << data.pic.len
                  << std::endl;
        }
        // std::cout << "frame format: " << data.pic.format << std::endl;
      }
    }

    ret = XRCameraDevice_ReleaseFrame(data.CamDeviceHelper, data.fnum);
    if (ret != 0) {
      printf("%d: call XRCameraDevice_ReleaseFrame failed for camera %s.\n",
             __LINE__, data.pCameraName);
      continue;
    }
  }

  // 停止相机
  XRCameraDevice_Stop(data.CamDeviceHelper);
  // 分离相机
  XRCameraDevice_DetachCamera(data.CamDeviceHelper);
}

int get_camframes(const std::vector<const char *> &cameraNames, int mycount,
                  int dump_image) {
  xrcamera_client_helper_t *clientHelper = XRCameraClient_Create();
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
    if (strcmp(cameraNames[i], "tof") == 0) {
      continue;
    }
    xrcamera_device_helper_t *helper =
        XRCameraClient_AttachCamera(clientHelper, cameraNames[i]);
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
  for (auto &cameraData : cameraDataList) {
    XRCameraDevice_Start(cameraData.CamDeviceHelper); // 启动相机
    threads.emplace_back(processCamera, std::ref(cameraData), dump_image,
                         mycount);
  }

  // 等待所有线程完成
  for (auto &t : threads) {
    t.join();
  }

  // 销毁客户端
  XRCameraClient_Destroy(clientHelper);
  std::cout << "Client handle destroy success." << std::endl;

  return 0;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
  // if (argc == 1) {
    std::cout << "usage: \n"
              << "xrservice 1 \n"
              << "test_xr_camera_client 30 1 1 \n - 30 fps \n - dumpimages?\n - show dbg info?"
              << std::endl;
    // return 0;
  // }

  auto now = std::chrono::system_clock::now();

  // Convert time_point to time_t (for formatting)
  std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

  // Format the time and print it
  std::cout << "Current time: "
            << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S")
            << std::endl;

  std::cout << "version 1" << std::endl;

  int count = 30;
  int dump_image = 1;

  // Check if argv[1] (count) is provided
  if (argc > 1) {
      count = std::stoi(argv[1]);
  }

  // Check if argv[2] (dump_image) is provided
  if (argc > 2) {
      dump_image = std::stoi(argv[2]);
  }
  // Check if argv[3] (shawn_dbg) is provided
  if (argc > 3) {
      shawn_dbg = std::stoi(argv[3]);
  }

  std::vector<const char *> cameraNames = {
      "fish-eye-mid", "fish-eye-leftdown", "fish-eye-rightdown",
      "tof",          "rgb-left",          "rgb-right"};
  std::vector<const char *> cameraNames2 = {"fish-eye-mid",
                                            "fish-eye-leftdown"};
  // int mycount = 30;
  // int dump_image = 1;

  // 启动获取相机帧
  get_camframes(cameraNames, count, dump_image);

  return 0;
}