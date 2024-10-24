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

// #include "XRCameraClient.h"
// #include <client/XRCameraClient.h>
#include <XRCameraClient.h>

const unsigned long long NS_PER_SEC = 1000000000ULL;

const char pCameraName0[] = "fish-eye-mid";
const char pCameraName1[] = "fish-eye-leftdown";
const char pCameraName2[] = "fish-eye-rightdown";
[[maybe_unused]]const char pCameraName3[] = "tof";
const char pCameraName4[] = "rgb-left";
[[maybe_unused]]const char pCameraName5[] = "rgb-right";


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

int selfgetframe(xrcamera_device_helper_t** CamDeviceHelper, int mdumpSign, const char *pCameraName)
{
    int fnum = 0;
    int ret = 0;
    int i = 0;
    const int COUNT = 300;
    std::string cameraNameId(pCameraName);
    xrcamera_frame_t pic;
    memset(&pic, 0, sizeof(pic));

    if (waitCameraStarted(*CamDeviceHelper) < 0) {
        printf("camera not ready or RingBuffer is empty\n");
        return -1;
    }
    for (i = 0; i < COUNT; ++i) {
        ret = XRCameraDevice_GetCurrentFrameNumber(*CamDeviceHelper, &fnum);
        if (ret != 0) {
            printf("%d: call XRCameraDevice_GetCurrentFrameNumber failed.%d\n", __LINE__, ret);
            continue;
        }
        printf("%d: call XRCameraDevice_GetCurrentFrameNumber success.\n", __LINE__);
        std::cout << "current frame num:  " << fnum << std::endl;

        ret = XRCameraDevice_GetFrame(*CamDeviceHelper, &fnum,
                                    XRCAMERA_MODE_BLOCKING,
                                    XRCAMERA_MODE_NEWER_IF_AVAILABLE, &pic);
        if (ret != 0) {
            std::cout << __LINE__ << ": call XRCameraDevice_GetFrame failed." << std::endl;
            continue;
        }
        std::cout << __LINE__ << ": call XRCameraDevice_GetFrame success." << std::endl;
        printf("get %s frame OK!\n", pCameraName);

        if(mdumpSign == 1) {
            std::string filename =
                "/sdcard/Pictures/" + cameraNameId
                + std::to_string(fnum) + "pic.raw";
            ret = savePicture(pic.buffer, filename.c_str(), 1, pic.len);
            if (ret < 0) {
                std::cout << "save " << filename << "failed" << std::endl;
            } else {
                std::cout << "frame path is: " << filename << ", frame size is: " << pic.len << std::endl;
            }
            if (pic.second_len) {
                std::cout << "valid crop region " << pic.second_width << ", x " << pic.second_height << std::endl;
                std::string regionfile =
                    "/sdcard/Pictures/" + cameraNameId
                    + std::to_string(fnum) + "region.raw";
                ret = savePicture(pic.buffer + pic.len, regionfile.c_str(), 1, pic.second_len);
                if (ret < 0) {
                    std::cout << "save " << regionfile << "failed" << std::endl;
                } else {
                    std::cout << "frame path is: " << regionfile << std::endl;
                    std::cout << "frame size is: " << pic.second_len << std::endl;
                }
            }
        }

        ret = XRCameraDevice_ReleaseFrame(*CamDeviceHelper, fnum);
        usleep(50000);
        if (ret != 0) {
            std::cout << __LINE__ << ": call XRCameraDevice_ReleaseFrame failed." << std::endl;
            printf("%d: %s release frame %d fail! please retry\n", __LINE__, pCameraName, fnum);
            continue;
        }
        std::cout << __LINE__ << ": call XRCameraDevice_ReleaseFrame success." << std::endl;
    }
    printf("%s release frame OK!\n", pCameraName);
    return ret;
}

int getframe(const char *pCameraName) {
    int ret = -1;
    int a = 1;
    xrcamera_client_helper_t *clientHelper = nullptr;
    xrcamera_device_helper_t *CamDeviceHelper = nullptr;
    XRCAMERA_CAMERA_STATUS camstate = XRCAMERA_CAMERA_CLIENT_DISCONNECTED;

    clientHelper = XRCameraClient_Create();
    if (!clientHelper) {
        std::cout << __LINE__ << ": create client failed\n";
        return -1;
    }
    std::cout << "Client handle create success." << std::endl;

    ret = XRCameraClient_GetVersion(clientHelper);
    if (ret <= 0) {
        std::cout << __LINE__ << ": get version fail" << std::endl;
        goto getframeDestoryClient;
    }
    std::cout << "get version success" << std::endl;

    CamDeviceHelper = XRCameraClient_AttachCamera(clientHelper, pCameraName);
    if (!CamDeviceHelper) {
        printf("attach %s fail!\n", pCameraName);
        goto getframeDestoryClient;
    }
    printf("attach %s ok!\n", pCameraName);
    ret = XRCameraDevice_GetCameraState(CamDeviceHelper, &camstate);
    printf("get %s state: %s\n", pCameraName, XRCameraHelper_ShowState(camstate));
    if (ret != 0) {
        printf("%d: get %s state fail\n", __LINE__, pCameraName);
        goto getframeDetachCamera;
    }
    std::cout << "get camera state successed" << std::endl;

    ret = XRCameraDevice_GetVersion(CamDeviceHelper);
    if ( ret <= 0 ) {
        std::cout << __LINE__ << ": get device version fail" << std::endl;
        goto getframeDetachCamera;
    }
    std::cout << "get device version success" << std::endl;

    ret = XRCameraDevice_Start(CamDeviceHelper);
    if (ret != 0) {
        printf("%d: open %s fail! please retry\n", __LINE__, pCameraName);
        goto getframeDetachCamera;
    }
    printf("open %s okay!\n", pCameraName);

    ret = XRCameraDevice_GetCameraState(CamDeviceHelper, &camstate);
    printf("get %s state: %s\n", pCameraName, XRCameraHelper_ShowState(camstate));
    if (ret != 0) {
        printf("%d: get %s state fail\n", __LINE__, pCameraName);
        goto getframeStopCamera;
    }
    printf("%s get state successed\n", pCameraName);

    ret = selfgetframe(&CamDeviceHelper, a, pCameraName);
    if (ret == 0) {
        printf("%s get frame okay!\n", pCameraName);
    } else {
        printf("%d: %s: get frame fail please retry\n", __LINE__, pCameraName);
    }
getframeStopCamera:
    printf("close %s\n", pCameraName);
    ret = XRCameraDevice_Stop(CamDeviceHelper);
    if (ret == 0) {
        printf("stop %s okay!\n", pCameraName);
    } else {
        printf("%d: stop %s fail! please retry\n", __LINE__, pCameraName);
    }
getframeDetachCamera:
    XRCameraDevice_DetachCamera(CamDeviceHelper);
    std::cout << "detach camera ok!" << std::endl;
getframeDestoryClient:
    if (!!clientHelper) {
        XRCameraClient_Destroy(clientHelper);
    }
    std::cout << "Client handle destory success." << std::endl;

    return 0;
}


int selfgetframes(xrcamera_device_helper_t** CamDeviceHelper1, xrcamera_device_helper_t** CamDeviceHelper2,int mdumpSign, const char *pCameraName1,const char *pCameraName2)
{
    int fnum = 0;
    int fnum2 = 0;
    int ret = 0;
    int i = 0;
    const int COUNT = 300;
    std::string cameraNameId(pCameraName1);
    std::string cameraNameId2(pCameraName2);
    xrcamera_frame_t pic;
    xrcamera_frame_t pic2;
    memset(&pic, 0, sizeof(pic));
    memset(&pic2, 0, sizeof(pic2));

    if (waitCameraStarted(*CamDeviceHelper1) < 0) {
        printf("camera1 not ready or RingBuffer is empty\n");
        return -1;
    }
    if (waitCameraStarted(*CamDeviceHelper2) < 0) {
        printf("camera2 not ready or RingBuffer is empty\n");
        return -1;
    }

    for (i = 0; i < COUNT; ++i) {

        //get cam1 frame
        ret = XRCameraDevice_GetCurrentFrameNumber(*CamDeviceHelper1, &fnum);
        if (ret != 0) {
            printf("%d: call XRCameraDevice_GetCurrentFrameNumber failed.%d\n", __LINE__, ret);
            continue;
        }
        printf("%d: call XRCameraDevice_GetCurrentFrameNumber success.\n", __LINE__);
        std::cout << "current frame num:  " << fnum << std::endl;

        ret = XRCameraDevice_GetFrame(*CamDeviceHelper1, &fnum,
                                    XRCAMERA_MODE_BLOCKING,
                                    XRCAMERA_MODE_NEWER_IF_AVAILABLE, &pic);
        if (ret != 0) {
            std::cout << __LINE__ << ": call XRCameraDevice_GetFrame failed." << std::endl;
            continue;
        }
        std::cout << __LINE__ << ": call XRCameraDevice_GetFrame success." << std::endl;
        printf("get %s frame OK!\n", pCameraName1);

        if(mdumpSign == 1) {
            //store cam1
            std::string filename =
                "/sdcard/Pictures/" + cameraNameId
                + std::to_string(fnum) + "pic.raw";
            ret = savePicture(pic.buffer, filename.c_str(), 1, pic.len);
            if (ret < 0) {
                std::cout << "save " << filename << "failed" << std::endl;
            } else {
                std::cout << "frame path is: " << filename << ", frame size is: " << pic.len << std::endl;
            }
          
        }
        
         //get cam2 frame
        ret = XRCameraDevice_GetCurrentFrameNumber(*CamDeviceHelper2, &fnum2);
        if (ret != 0) {
            printf("%d: call XRCameraDevice_GetCurrentFrameNumber failed.%d\n", __LINE__, ret);
            continue;
        }
        printf("%d: call XRCameraDevice_GetCurrentFrameNumber success.\n", __LINE__);
        std::cout << "current frame num:  " << fnum2 << std::endl;

        ret = XRCameraDevice_GetFrame(*CamDeviceHelper2, &fnum2,
                                    XRCAMERA_MODE_BLOCKING,
                                    XRCAMERA_MODE_NEWER_IF_AVAILABLE, &pic2);
        if (ret != 0) {
            std::cout << __LINE__ << ": call XRCameraDevice_GetFrame failed." << std::endl;
            continue;
        }
        std::cout << __LINE__ << ": call XRCameraDevice_GetFrame success." << std::endl;
        printf("get %s frame OK!\n", pCameraName2);

        if(mdumpSign == 1) {
            //store cam2
            std::string filename =
                "/sdcard/Pictures/" + cameraNameId2
                + std::to_string(fnum2) + "pic2.raw";
            ret = savePicture(pic2.buffer, filename.c_str(), 1, pic2.len);
            if (ret < 0) {
                std::cout << "save " << filename << "failed" << std::endl;
            } else {
                std::cout << "frame path is: " << filename << ", frame size is: " << pic2.len << std::endl;
            }
        }

        ret = XRCameraDevice_ReleaseFrame(*CamDeviceHelper1, fnum);
        usleep(50000);
        if ((ret != 0)) {
            std::cout << __LINE__ << ": call XRCameraDevice_ReleaseFrame failed." << std::endl;
            printf("%d: %s release frame %d fail! please retry\n", __LINE__, pCameraName1, fnum);
            continue;
        }
        std::cout << __LINE__ << ": call XRCameraDevice_ReleaseFrame success." << std::endl;

        ret = XRCameraDevice_ReleaseFrame(*CamDeviceHelper2, fnum2);
        usleep(50000);
        if ((ret != 0)) {
            std::cout << __LINE__ << ": call XRCameraDevice_ReleaseFrame failed." << std::endl;
            printf("%d: %s release frame %d fail! please retry\n", __LINE__, pCameraName2, fnum2);
            continue;
        }
        std::cout << __LINE__ << ": call XRCameraDevice_ReleaseFrame success." << std::endl;
    }
    
    return ret;
}

int selfgetframes_shawn(xrcamera_device_helper_t** CamDeviceHelper1, xrcamera_device_helper_t** CamDeviceHelper2, xrcamera_device_helper_t** CamDeviceHelper3, \
    int mdumpSign, const char *pCameraName1,const char *pCameraName2, \
    const char *pCameraName3)
{
    int fnum = 0;
    int fnum2 = 0;
    int fnum3 = 0;
    int ret = 0;
    int i = 0;
    const int COUNT = 10;
    std::string cameraNameId(pCameraName1);
    std::string cameraNameId2(pCameraName2);
    std::string cameraNameId3(pCameraName3);
    xrcamera_frame_t pic;
    xrcamera_frame_t pic2;
    xrcamera_frame_t pic3;
    memset(&pic, 0, sizeof(pic));
    memset(&pic2, 0, sizeof(pic2));
    memset(&pic3, 0, sizeof(pic3));

    if (waitCameraStarted(*CamDeviceHelper1) < 0) {
        printf("camera1 not ready or RingBuffer is empty\n");
        return -1;
    }
    if (waitCameraStarted(*CamDeviceHelper2) < 0) {
        printf("camera2 not ready or RingBuffer is empty\n");
        return -1;
    }
    if (waitCameraStarted(*CamDeviceHelper3) < 0) {
        printf("camera3 not ready or RingBuffer is empty\n");
        return -1;
    }
    for (i = 0; i < COUNT; ++i) {

        //get cam1 frame
        ret = XRCameraDevice_GetCurrentFrameNumber(*CamDeviceHelper1, &fnum);
        if (ret != 0) {
            printf("%d: call XRCameraDevice_GetCurrentFrameNumber failed.%d\n", __LINE__, ret);
            continue;
        }
        printf("%d: call XRCameraDevice_GetCurrentFrameNumber success.\n", __LINE__);
        std::cout << "current frame num:  " << fnum << std::endl;

        ret = XRCameraDevice_GetFrame(*CamDeviceHelper1, &fnum,
                                    XRCAMERA_MODE_BLOCKING,
                                    XRCAMERA_MODE_NEWER_IF_AVAILABLE, &pic);
        if (ret != 0) {
            std::cout << __LINE__ << ": call XRCameraDevice_GetFrame failed." << std::endl;
            continue;
        }
        std::cout << __LINE__ << ": call XRCameraDevice_GetFrame success." << std::endl;
        printf("get %s frame OK!\n", pCameraName1);

        if(mdumpSign == 1) {
            //store cam1
            std::string filename =
                "/sdcard/Pictures/" + cameraNameId
                + std::to_string(fnum) + "pic.raw";
            ret = savePicture(pic.buffer, filename.c_str(), 1, pic.len);
            if (ret < 0) {
                std::cout << "save " << filename << "failed" << std::endl;
            } else {
                std::cout << "frame path is: " << filename << ", frame size is: " << pic.len << std::endl;
            }
          
        }
        
         //get cam2 frame
        ret = XRCameraDevice_GetCurrentFrameNumber(*CamDeviceHelper2, &fnum2);
        if (ret != 0) {
            printf("%d: call XRCameraDevice_GetCurrentFrameNumber failed.%d\n", __LINE__, ret);
            continue;
        }
        printf("%d: call XRCameraDevice_GetCurrentFrameNumber success.\n", __LINE__);
        std::cout << "current frame num:  " << fnum2 << std::endl;

        ret = XRCameraDevice_GetFrame(*CamDeviceHelper2, &fnum2,
                                    XRCAMERA_MODE_BLOCKING,
                                    XRCAMERA_MODE_NEWER_IF_AVAILABLE, &pic2);
        if (ret != 0) {
            std::cout << __LINE__ << ": call XRCameraDevice_GetFrame failed." << std::endl;
            continue;
        }
        std::cout << __LINE__ << ": call XRCameraDevice_GetFrame success." << std::endl;
        printf("get %s frame OK!\n", pCameraName2);

        if(mdumpSign == 1) {
            //store cam2
            std::string filename =
                "/sdcard/Pictures/" + cameraNameId2
                + std::to_string(fnum2) + "pic2.raw";
            ret = savePicture(pic2.buffer, filename.c_str(), 1, pic2.len);
            if (ret < 0) {
                std::cout << "save " << filename << "failed" << std::endl;
            } else {
                std::cout << "frame path is: " << filename << ", frame size is: " << pic2.len << std::endl;
            }
        }

        // ========================================

         //get cam3 frame
        ret = XRCameraDevice_GetCurrentFrameNumber(*CamDeviceHelper3, &fnum3);
        if (ret != 0) {
            printf("%d: call XRCameraDevice_GetCurrentFrameNumber failed.%d\n", __LINE__, ret);
            continue;
        }
        printf("%d: call XRCameraDevice_GetCurrentFrameNumber success.\n", __LINE__);
        std::cout << "current frame num:  " << fnum3 << std::endl;

        ret = XRCameraDevice_GetFrame(*CamDeviceHelper3, &fnum3,
                                    XRCAMERA_MODE_BLOCKING,
                                    XRCAMERA_MODE_NEWER_IF_AVAILABLE, &pic3);
        if (ret != 0) {
            std::cout << __LINE__ << ": call XRCameraDevice_GetFrame failed." << std::endl;
            continue;
        }
        std::cout << __LINE__ << ": call XRCameraDevice_GetFrame success." << std::endl;
        printf("get %s frame OK!\n", pCameraName3);

        if(mdumpSign == 1) {
            //store cam2
            std::string filename =
                "/sdcard/Pictures/" + cameraNameId3
                + std::to_string(fnum3) + "pic3.raw";
            ret = savePicture(pic3.buffer, filename.c_str(), 1, pic3.len);
            if (ret < 0) {
                std::cout << "save " << filename << "failed" << std::endl;
            } else {
                std::cout << "frame path is: " << filename << ", frame size is: " << pic3.len << std::endl;
            }
        }

        // ========================================

        ret = XRCameraDevice_ReleaseFrame(*CamDeviceHelper1, fnum);
        usleep(50000);
        if ((ret != 0)) {
            std::cout << __LINE__ << ": call XRCameraDevice_ReleaseFrame failed." << std::endl;
            printf("%d: %s release frame %d fail! please retry\n", __LINE__, pCameraName1, fnum);
            continue;
        }
        std::cout << __LINE__ << ": call XRCameraDevice_ReleaseFrame success." << std::endl;

        ret = XRCameraDevice_ReleaseFrame(*CamDeviceHelper2, fnum2);
        usleep(50000);
        if ((ret != 0)) {
            std::cout << __LINE__ << ": call XRCameraDevice_ReleaseFrame failed." << std::endl;
            printf("%d: %s release frame %d fail! please retry\n", __LINE__, pCameraName2, fnum2);
            continue;
        }
        std::cout << __LINE__ << ": call XRCameraDevice_ReleaseFrame success." << std::endl;

        ret = XRCameraDevice_ReleaseFrame(*CamDeviceHelper3, fnum3);
        usleep(50000);
        if ((ret != 0)) {
            std::cout << __LINE__ << ": call XRCameraDevice_ReleaseFrame failed." << std::endl;
            printf("%d: %s release frame %d fail! please retry\n", __LINE__, pCameraName3, fnum3);
            continue;
        }
        std::cout << __LINE__ << ": call XRCameraDevice_ReleaseFrame success." << std::endl;
    }
    
    return ret;
}

int get2camframes(const char *pCameraName1, const char *pCameraName2) {
   int ret = -1;
    int a = 1;
    xrcamera_client_helper_t *clientHelper = nullptr;
    xrcamera_device_helper_t *CamDeviceHelper1 = nullptr;
    xrcamera_device_helper_t *CamDeviceHelper2 = nullptr;
    XRCAMERA_CAMERA_STATUS camstate = XRCAMERA_CAMERA_CLIENT_DISCONNECTED;

    clientHelper = XRCameraClient_Create();
    if (!clientHelper) {
        std::cout << __LINE__ << ": create client failed\n";
        return -1;
    }
    std::cout << "Client handle create success." << std::endl;

    ret = XRCameraClient_GetVersion(clientHelper);
    if (ret <= 0) {
        std::cout << __LINE__ << ": get version fail" << std::endl;
        goto getframeDestoryClient;
    }
    std::cout << "get version success" << std::endl;
    
      //  start cam1
    CamDeviceHelper1 = XRCameraClient_AttachCamera(clientHelper, pCameraName1);
    if (!CamDeviceHelper1) {
        printf("attach %s fail!\n", pCameraName1);
        goto getframeDestoryClient;
    }
    printf("attach %s ok!\n", pCameraName1);
    ret = XRCameraDevice_GetCameraState(CamDeviceHelper1, &camstate);
    printf("get %s state: %s\n", pCameraName1, XRCameraHelper_ShowState(camstate));
    if (ret != 0) {
        printf("%d: get %s state fail\n", __LINE__, pCameraName1);
        goto getframeDetachCamera;
    }
    std::cout << "get camera state successed" << std::endl;

    ret = XRCameraDevice_GetVersion(CamDeviceHelper1);
    if ( ret <= 0 ) {
        std::cout << __LINE__ << ": get device version fail" << std::endl;
        goto getframeDetachCamera;
    }
    std::cout << "get device version success" << std::endl;

    ret = XRCameraDevice_Start(CamDeviceHelper1);
    if (ret != 0) {
        printf("%d: open %s fail! please retry\n", __LINE__, pCameraName1);
        goto getframeDetachCamera;
    }
    printf("open %s okay!\n", pCameraName1);

    //  start cam2
    CamDeviceHelper2 = XRCameraClient_AttachCamera(clientHelper, pCameraName2);
    if (!CamDeviceHelper2) {
        printf("attach %s fail!\n", pCameraName2);
        goto getframeDestoryClient;
    }
    printf("attach %s ok!\n", pCameraName2);
    ret = XRCameraDevice_GetCameraState(CamDeviceHelper2, &camstate);
    printf("get %s state: %s\n", pCameraName2, XRCameraHelper_ShowState(camstate));
    if (ret != 0) {
        printf("%d: get %s state fail\n", __LINE__, pCameraName2);
        goto getframeDetachCamera;
    }
    std::cout << "get camera state successed" << std::endl;

    ret = XRCameraDevice_GetVersion(CamDeviceHelper2);
    if ( ret <= 0 ) {
        std::cout << __LINE__ << ": get device version fail" << std::endl;
        goto getframeDetachCamera;
    }
    std::cout << "get device version success" << std::endl;

    ret = XRCameraDevice_Start(CamDeviceHelper2);
    if (ret != 0) {
        printf("%d: open %s fail! please retry\n", __LINE__, pCameraName2);
        goto getframeDetachCamera;
    }
    printf("open %s okay!\n", pCameraName2);


    //get cam1 state
    ret = XRCameraDevice_GetCameraState(CamDeviceHelper1, &camstate);
    printf("get %s state: %s\n", pCameraName1, XRCameraHelper_ShowState(camstate));
    if (ret != 0) {
        printf("%d: get %s state fail\n", __LINE__, pCameraName1);
        goto getframeStopCamera;
    }
    printf("%s get state successed\n", pCameraName1);

    //get cam2 state
    ret = XRCameraDevice_GetCameraState(CamDeviceHelper2, &camstate);
    printf("get %s state: %s\n", pCameraName2, XRCameraHelper_ShowState(camstate));
    if (ret != 0) {
        printf("%d: get %s state fail\n", __LINE__, pCameraName2);
        goto getframeStopCamera;
    }
    printf("%s get state successed\n", pCameraName2);

    ret = selfgetframes(&CamDeviceHelper1,&CamDeviceHelper2, a, pCameraName1,pCameraName2);
    
getframeStopCamera:
    
    if(CamDeviceHelper1 !=nullptr){
        printf("close %s\n", pCameraName1);
        ret = XRCameraDevice_Stop(CamDeviceHelper1);
        if (ret == 0) {
            printf("stop %s okay!\n", pCameraName1);
        } else {
            printf("%d: stop %s fail! please retry\n", __LINE__, pCameraName1);
        }
    }

     if(CamDeviceHelper2 !=nullptr){
        printf("close %s\n", pCameraName2);
        ret = XRCameraDevice_Stop(CamDeviceHelper2);
        if (ret == 0) {
            printf("stop %s okay!\n", pCameraName2);
        } else {
            printf("%d: stop %s fail! please retry\n", __LINE__, pCameraName2);
        }
    }
    
getframeDetachCamera:
    if(CamDeviceHelper1 != nullptr)
        XRCameraDevice_DetachCamera(CamDeviceHelper1);
    if(CamDeviceHelper2 != nullptr)
        XRCameraDevice_DetachCamera(CamDeviceHelper2);
    std::cout << "detach camera ok!" << std::endl;
getframeDestoryClient:
    if (!!clientHelper) {
        XRCameraClient_Destroy(clientHelper);
    }
    std::cout << "Client handle destory success." << std::endl;

    return 0;
}

// ------------------------------- 3 cams start ----------------------------------------


int get3camframes(const char *pCameraName1, const char *pCameraName2, const char *pCameraName3) {
   int ret = -1;
    int a = 1;
    xrcamera_client_helper_t *clientHelper = nullptr;
    xrcamera_device_helper_t *CamDeviceHelper1 = nullptr;
    xrcamera_device_helper_t *CamDeviceHelper2 = nullptr;
    xrcamera_device_helper_t *CamDeviceHelper3 = nullptr;
    XRCAMERA_CAMERA_STATUS camstate = XRCAMERA_CAMERA_CLIENT_DISCONNECTED;

    clientHelper = XRCameraClient_Create();
    if (!clientHelper) {
        std::cout << __LINE__ << ": create client failed\n";
        return -1;
    }
    std::cout << "Client handle create success." << std::endl;

    ret = XRCameraClient_GetVersion(clientHelper);
    if (ret <= 0) {
        std::cout << __LINE__ << ": get version fail" << std::endl;
        goto getframeDestoryClient;
    }
    std::cout << "get version success" << std::endl;
    
    
      //  start cam1
    std::cout << " ----- start cam 1 ----- " << std::endl;
    CamDeviceHelper1 = XRCameraClient_AttachCamera(clientHelper, pCameraName1);
    if (!CamDeviceHelper1) {
        printf("attach %s fail!\n", pCameraName1);
        goto getframeDestoryClient;
    }
    printf("attach %s ok!\n", pCameraName1);
    ret = XRCameraDevice_GetCameraState(CamDeviceHelper1, &camstate);
    printf("get %s state: %s\n", pCameraName1, XRCameraHelper_ShowState(camstate));
    if (ret != 0) {
        printf("%d: get %s state fail\n", __LINE__, pCameraName1);
        goto getframeDetachCamera;
    }
    std::cout << "get camera state successed" << std::endl;

    ret = XRCameraDevice_GetVersion(CamDeviceHelper1);
    if ( ret <= 0 ) {
        std::cout << __LINE__ << ": get device version fail" << std::endl;
        goto getframeDetachCamera;
    }
    std::cout << "get device version success" << std::endl;

    ret = XRCameraDevice_Start(CamDeviceHelper1);
    if (ret != 0) {
        printf("%d: open %s fail! please retry\n", __LINE__, pCameraName1);
        goto getframeDetachCamera;
    }
    printf("open %s okay!\n", pCameraName1);


    //  start cam2
    std::cout << " ----- start cam 2 ----- " << std::endl;
    CamDeviceHelper2 = XRCameraClient_AttachCamera(clientHelper, pCameraName2);
    if (!CamDeviceHelper2) {
        printf("attach %s fail!\n", pCameraName2);
        goto getframeDestoryClient;
    }
    printf("attach %s ok!\n", pCameraName2);
    ret = XRCameraDevice_GetCameraState(CamDeviceHelper2, &camstate);
    printf("get %s state: %s\n", pCameraName2, XRCameraHelper_ShowState(camstate));
    if (ret != 0) {
        printf("%d: get %s state fail\n", __LINE__, pCameraName2);
        goto getframeDetachCamera;
    }
    std::cout << "get camera state successed" << std::endl;

    ret = XRCameraDevice_GetVersion(CamDeviceHelper2);
    if ( ret <= 0 ) {
        std::cout << __LINE__ << ": get device version fail" << std::endl;
        goto getframeDetachCamera;
    }
    std::cout << "get device version success" << std::endl;

    ret = XRCameraDevice_Start(CamDeviceHelper2);
    if (ret != 0) {
        printf("%d: open %s fail! please retry\n", __LINE__, pCameraName2);
        goto getframeDetachCamera;
    }
    printf("open %s okay!\n", pCameraName2);


      //  start cam3
    std::cout << " ----- start cam 3 ----- " << std::endl;
    CamDeviceHelper3 = XRCameraClient_AttachCamera(clientHelper, pCameraName3);
    if (!CamDeviceHelper3) {
        printf("attach %s fail!\n", pCameraName3);
        goto getframeDestoryClient;
    }
    printf("attach %s ok!\n", pCameraName3);
    ret = XRCameraDevice_GetCameraState(CamDeviceHelper3, &camstate);
    printf("get %s state: %s\n", pCameraName3, XRCameraHelper_ShowState(camstate));
    if (ret != 0) {
        printf("%d: get %s state fail\n", __LINE__, pCameraName3);
        goto getframeDetachCamera;
    }
    std::cout << "get camera state successed" << std::endl;

    ret = XRCameraDevice_GetVersion(CamDeviceHelper3);
    if ( ret <= 0 ) {
        std::cout << __LINE__ << ": get device version fail" << std::endl;
        goto getframeDetachCamera;
    }
    std::cout << "get device version success" << std::endl;

    ret = XRCameraDevice_Start(CamDeviceHelper3);
    if (ret != 0) {
        printf("%d: open %s fail! please retry\n", __LINE__, pCameraName3);
        goto getframeDetachCamera;
    }
    printf("open %s okay!\n", pCameraName3);

    //get cam1 state
    ret = XRCameraDevice_GetCameraState(CamDeviceHelper3, &camstate);
    printf("get %s state: %s\n", pCameraName3, XRCameraHelper_ShowState(camstate));
    if (ret != 0) {
        printf("%d: get %s state fail\n", __LINE__, pCameraName3);
        goto getframeStopCamera;
    }
    printf("%s get state successed\n", pCameraName3);

    //get cam2 state
    ret = XRCameraDevice_GetCameraState(CamDeviceHelper2, &camstate);
    printf("get %s state: %s\n", pCameraName2, XRCameraHelper_ShowState(camstate));
    if (ret != 0) {
        printf("%d: get %s state fail\n", __LINE__, pCameraName2);
        goto getframeStopCamera;
    }
    printf("%s get state successed\n", pCameraName2);

    //get cam3 state
    ret = XRCameraDevice_GetCameraState(CamDeviceHelper3, &camstate);
    printf("get %s state: %s\n", pCameraName3, XRCameraHelper_ShowState(camstate));
    if (ret != 0) {
        printf("%d: get %s state fail\n", __LINE__, pCameraName3);
        goto getframeStopCamera;
    }
    printf("%s get state successed\n", pCameraName3);

    // ===============================================================

    ret = selfgetframes_shawn(&CamDeviceHelper1,&CamDeviceHelper2,&CamDeviceHelper3, a, pCameraName1,pCameraName2,pCameraName3);

getframeStopCamera:
    std::cout << " ----- getframeStopCamera 1 ----- " << std::endl;
    if(CamDeviceHelper1 !=nullptr){
        printf("close %s\n", pCameraName1);
        ret = XRCameraDevice_Stop(CamDeviceHelper1);
        if (ret == 0) {
            printf("stop %s okay!\n", pCameraName1);
        } else {
            printf("%d: stop %s fail! please retry\n", __LINE__, pCameraName1);
        }
    }

    std::cout << " ----- getframeStopCamera 2 ----- " << std::endl;
     if(CamDeviceHelper2 !=nullptr){
        printf("close %s\n", pCameraName2);
        ret = XRCameraDevice_Stop(CamDeviceHelper2);
        if (ret == 0) {
            printf("stop %s okay!\n", pCameraName2);
        } else {
            printf("%d: stop %s fail! please retry\n", __LINE__, pCameraName2);
        }
    }

    std::cout << " ----- getframeStopCamera 3 ----- " << std::endl;
     if(CamDeviceHelper3 !=nullptr){
        printf("close %s\n", pCameraName3);
        ret = XRCameraDevice_Stop(CamDeviceHelper3);
        if (ret == 0) {
            printf("stop %s okay!\n", pCameraName3);
        } else {
            printf("%d: stop %s fail! please retry\n", __LINE__, pCameraName3);
        }
    }


getframeDetachCamera:
    if(CamDeviceHelper1 != nullptr)
        XRCameraDevice_DetachCamera(CamDeviceHelper1);
    if(CamDeviceHelper2 != nullptr)
        XRCameraDevice_DetachCamera(CamDeviceHelper2);
    if(CamDeviceHelper3 != nullptr)
        XRCameraDevice_DetachCamera(CamDeviceHelper3);
    std::cout << "detach camera ok!" << std::endl;
getframeDestoryClient:
    if (!!clientHelper) {
        XRCameraClient_Destroy(clientHelper);
    }
    std::cout << "Client handle destory success." << std::endl;

    return 0;
}


// ------------------------------- 3 cams  END ----------------------------------------

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

int main([[maybe_unused]]int argc, [[maybe_unused]]char *argv[]) {
    std::cout << std::endl
              << "\t------------cameraclient test   v8 -----------\n"
              << "\t--------please choose cameratest:-------\n"
              << "\t 0: get fish-eye-mid frame\n"
              << "\t 1: get fish-eye-leftdown frame\n"
              << "\t 2: get fish-eye-rightdown frame\n"
              << "\t 3: get rgb-left frame\n"
              << "\t 4: get rgb-right  frame\n"
              << "\t 5: get tof frame\n"
              << "\t 6: get fish-eye-leftdown and fish-eye-rightdown frame\n"
              << "\t 7: get fish-eye-leftdown and fish-eye-rightdown and fish-eye-mid frame\n"
              << std::endl;
    int ret = 0;
    int dumpFn = 0;
    int percentage = 0;
    if (argc == 3) {
        dumpFn = std::stoi(argv[1]);
        percentage = std::stoi(argv[2]);
    }
    std::string message;

    std::cout << __func__ << ": Enter control mode: ";
    std::getline(std::cin, message);

    if (!isValidInteger(message)) {
        std::cout << __LINE__ << ": Input is not a valid integer\n";
        return -1;
    }

    int number = std::stoi(message);
    if (number < 0 || number > 1000) {
        std::cout << __LINE__ << ": Test Case " << number << " is out of range [0, 1000]\n";
        return -1;
    }

    switch (number) {
           case 0:
            ret = getframe(pCameraName0);
            break;
           case 1:
            ret = getframe(pCameraName1);
            break;
           case 2:
            ret = getframe(pCameraName2);
            break;
           case 3:
            ret = getframe(pCameraName4);
            break;
           case 4:
            ret = getframe(pCameraName5);
            break;
           case 5:
            ret = getTofFrame(pCameraName3, processGetITofFrame);
            break;
            case 6:
            ret = get2camframes("fish-eye-leftdown", "fish-eye-rightdown");
            break;
            case 7:
            ret = get3camframes("fish-eye-leftdown", "fish-eye-rightdown", "pCameraName1");
            ret = get3camframes("fish-eye-leftdown", "fish-eye-rightdown", "pCameraName2");
            ret = get3camframes("fish-eye-leftdown", "fish-eye-rightdown", "pCameraName3");
            ret = get3camframes("fish-eye-leftdown", "fish-eye-rightdown", "pCameraName4");
            ret = get3camframes("fish-eye-leftdown", "fish-eye-rightdown", "pCameraName5");
            break;
        default:
            std::cout << __LINE__ << ": Unexpected test case " << number << std::endl;
            ret = -1;
            break;
    }

    if (ret < 0) {
        printf("Test case failed\n");
    } else {
        printf("Test exit success\n");
    }

    return ret;
}

