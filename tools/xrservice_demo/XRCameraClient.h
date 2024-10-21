/*****************************************************************************/
/**
* @file VXCAMERACLIENT_H.h
* @copyright Copyright (c) 2023 ThunderSoft Technologies, Inc.
* All Rights Reserved Confidential and Proprietary - ThunderSoft Technologies, Inc.
* @author Chuanlong Wu
*
******************************************************************************/
#ifndef VXCAMERACLIENT_H
#define VXCAMERACLIENT_H
#define XR_CASE_RETURN_STR(a)  case a: return #a
#define XRCAMERA_API_VERSION int
/**
 * @mainpage
 * VR/AR/MR in this file we will use XR instead. \n
 * Client APIs communicate with XRCamera. Typical call flow is as follows:
 * - Call VXCAMERACLIENT_Create()
 * - Call VXCAMERACLIENT_Destroy()
*/

#ifdef __cplusplus
extern "C" {
#endif

#include <dlfcn.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <jni.h>
#include <android/log.h>

#ifdef USE_VNDK
#include <vndk/hardware_buffer.h>
#else
#include <android/hardware_buffer.h>
#endif

#include "XRCommon.h"

#define XRLOG(LEVEL, TAG, ...) __android_log_print(LEVEL, TAG, __VA_ARGS__)
#define XRLOGD(TAG, ...)       XRLOG(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define XRLOGI(TAG, ...)       XRLOG(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define XRLOGW(TAG, ...)       XRLOG(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define XRLOGE(TAG, ...)       XRLOG(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

/**************************************************************************
* Can be used with GetParam() to get the XR service version.
* XR service version name looks like "1.0.0-ssbuild-20230227"
******************************************************************************/
//#define XRCAMERA_SERVICE_VERSION    "xr-service-version-name"

/**************************************************************************
* Can be used with GetParam() to get the XR client version.
* XR client version name looks like "1.0.0-ssbuild-20230227"
******************************************************************************/
//#define VXCAMERA_CLIENT_VERSION    "xr-client-version-name"

typedef enum XRCAMERA_CAMERA_STATUS {
    XRCAMERA_CAMERA_CLIENT_DISCONNECTED, /* Client has been disconnect from the server. It is expected that the user would then call DetachCamera to release the camera handle. */
    XRCAMERA_CAMERA_INITIALISING, /* Camera Device is being initialized as soon as its first client attaches. The state will automatically transition to XRCAMERA_CAMERA_READY once initialization is complete. */
    XRCAMERA_CAMERA_READY, /* Camera device is ready and can be started by its master client. */
    XRCAMERA_CAMERA_STARTING, /* Camera device is starting after having receive a start command from its master client. The state will automatically transition to XRCAMERA_CAMERA_STARTED once startup is complete. */
    XRCAMERA_CAMERA_STARTED, /* Camera device is started/active. While in this state, only the client that started the camera deviceXR camera can modify its state. */
    XRCAMERA_CAMERA_STOPPING, /* Camera device is stopping. The state will automatically transition to XRCAMERA_CAMERA_READY once complete. */
    XRCAMERA_CAMERA_ERROR,    /* Camera device has encountered an error. */
    XRCAMERA_CAMERA_STATUS_MAX = 0xff
} XRCAMERA_CAMERA_STATUS;

typedef enum XRCAMERA_BLOCK_MODE {
    XRCAMERA_MODE_BLOCKING, /* XRCameraDevice_GetFrame() will block until the requested frame number is available. If the requested frame number is available, XRCameraDevice_GetFrame() return immediately. */
    XRCAMERA_MODE_NON_BLOCKING, /* XRCameraDevice_GetFrame() will not block. If the requested frame number is not available, XRCameraDevice_GetFrame() returns immediately. */
} XRCAMERA_BLOCK_MODE;

typedef enum XRCAMERA_DROP_MODE {
    XRCAMERA_MODE_NEWER_IF_AVAILABLE, /* XRCameraDevice_GetFrame() will attempt to return at least the requested frame number or newer if available. If the requested frame number is in the future, XRCameraDevice_GetFrame() either blocks or returns with error code depending on the XRCAMERA_BLOCK_MODE specified. */
    XRCAMERA_MODE_EXPLICIT_FRAME_NUMBER /* XRCameraDevice_GetFrame() will attempt to return the requested frame number. If frame number is too old, XRCameraDevice_GetFrame() returns with error code. If the requested frame number is in the future, XRCameraDevice_GetFrame() either blocks or returns with error code depending on the XRCAMERA_BLOCK_MODE specified. */
} XRCAMERA_DROP_MODE;

typedef struct XrOffset2D {
    int32_t x;
    int32_t y;
} XrOffset2D;

// Associates an AHardwareBuffer with an offset that describes where, in the context of a large, this AHardwareBuffer sits.
typedef struct xrcamera_hwbuffer_t {
    AHardwareBuffer *buf; /* AHardwareBuffer pointer. */
    volatile uint8_t *bufVAddr; /* hardware frame data pointer */
    XrOffset2D offset; /* offset into the larger image. */
} xrcamera_hwbuffer_t;

typedef struct xrWatermark {
    uint64_t inMagicNum;
    uint64_t frameNum;
    uint64_t bufferId;
    uint64_t outMagicNum;
} xrWatermark;

typedef enum XrStructType {
    XR_TYPE_BASE_STRUCT,
    XR_TYPE_CAM_REQUEST_FULL_FRAME_INPUT_INFO,
    XR_TYPE_CAM_REQUEST_FULL_FRAME_OUTPUT_INFO,
    XR_TYPE_CAM_REQUEST_PARTIAL_FRAME_INPUT_INFO,
    XR_TYPE_CAM_REQUEST_PARTIAL_FRAME_OUTPUT_INFO,
} XrStructType;

typedef struct XrCameraFrameInfo {
    uint64_t startOfExposureNs;             /* frame timeStamp in ns (kernel boottime clk) */
    uint32_t exposureNs;                    /* frame exposure time in ns. */
    uint32_t gain;                          /* frame gain value */
    uint64_t exposure_center_of_frame_ts;   /* Frame exposure center timestamp in ns(qtimer). */
    uint8_t autoExposureMode;
} XrCameraFrameInfo;

typedef struct XrBaseStruct {
    XrStructType type;
    //const struct XrBaseStructQTI * XR_MAY_ALIAS     next; /* for future expansion, set to NULL */
} XrBaseStruct;

typedef struct XrCameraBufferInfo {
    uint32_t format;
    uint32_t len;
    uint32_t width;
    uint32_t height;
    uint32_t stride;
    XrOffset2D offset;
    volatile uint8_t* bufVAddr;
} XrCameraBufferInfo;

typedef struct XrCameraRequestFrameInputInfo {
    XrStructType type;
    XrBaseStruct *next;
    XRCAMERA_BLOCK_MODE blockMode;
    XRCAMERA_DROP_MODE dropMode;
    uint32_t frameNumber;
} XrCameraRequestFrameInputInfo;

typedef struct XrCameraRequestFrameOutputInfo {
    XrStructType type;
    XrBaseStruct *next;
    uint32_t frameNumber;
    XrCameraFrameInfo frameInfo;
    XrCameraBufferInfo bufferInfo;
    xrcamera_hwbuffer_t hwBufferInfo;  /* In the partial frame */
} XrCameraRequestFrameOutputInfo;

typedef struct xrcamera_frame_t {
    uint32_t fn;                          /* Frame number */
    uint64_t start_of_frame_ts;           /* Frame timestamp in ns(qtimer). */
    uint64_t start_of_exposure_ts;        /* Frame timestamp in ns(kernel boottime clk). */
    uint32_t exposure;                    /* Frame exposure time in ns. */
    uint8_t *buffer;                      /* Frame data. */
    uint32_t len;                         /* Frame length = width * height*/
    uint32_t width;                       /* Width of frame or crop-image1. */
    uint32_t height;                      /* Height of frame or crop-image1. */
    uint32_t second_width;                /* Width of crop-image2 or 0 (no crop-image2). */
    uint32_t second_height;               /* Heighe of crop-image2 or 0 (no crop-image2). */
    uint32_t gain;                        /* Frame gain */
    uint32_t stride;                      /* Stride of frame */
    uint32_t format;                      /* Frame format of type XRCAMERA_FRAME_FORMAT */
    uint32_t buffer_count;                /* Frame Graphic Buffer count. */
    uint32_t buffer_index;                /* Frame Graphic Buffer index, should <= buffer_count - 1. */
    uint32_t next_buffer_index;           /* Next processing Frame Graphic Buffer index, should <= buffer_count - 1. */
    uint64_t exposure_center_of_frame_ts; /* Frame exposure center timestamp in ns(qtimer). */
    uint32_t real_fn;                     /* Real Frame number */
    uint32_t second_len;                  /* Frame length = second_width * second_height */
} xrcamera_frame_t;

typedef struct XrCameraRequestPartialFrameInputInfo {
    XrStructType type;
    uint32_t fillPercentage;
} XrCameraRequestPartialFrameInputInfo;

typedef struct XrCameraRequestPartialFrameOutputInfo {
    XrStructType type;
    uint32_t fillPercentage;
} XrCameraRequestPartialFrameOutputInfo;

typedef enum XRCAMERA_PARAM_NUM_TYPE {
    XRCAMERA_PARAM_NUM_TYPE_UINT8  = 0,    /**< parameter is of type uint8_t */
    XRCAMERA_PARAM_NUM_TYPE_UINT16,        /**< parameter is of type uint16_t */
    XRCAMERA_PARAM_NUM_TYPE_UINT32,        /**< parameter is of type uint32_t */
    XRCAMERA_PARAM_NUM_TYPE_UINT64,        /**< parameter is of type uint64_t */
    XRCAMERA_PARAM_NUM_TYPE_INT8,          /**< parameter is of type int8_t */
    XRCAMERA_PARAM_NUM_TYPE_INT16,         /**< parameter is of type int16_t */
    XRCAMERA_PARAM_NUM_TYPE_INT32,         /**< parameter is of type int32_t */
    XRCAMERA_PARAM_NUM_TYPE_INT64,         /**< parameter is of type int64_t */
    XRCAMERA_PARAM_NUM_TYPE_FLOAT,         /**< parameter is of type float */
    XRCAMERA_PARAM_NUM_TYPE_FLOAT_VECT,    /**< float vectors are not supported, do not use */
    XRCAMERA_PARAM_NUM_TYPE_MAX = 0xFF
} XRCAMERA_PARAM_NUM_TYPE;

/**************************************************************************//**
* \enum XRCAMERA_CLIENT_STATUS
*
*   \var XRCAMERA_CLIENT_DISCONNECTED
*      The client was unexpectedly disconnected from server. If this occurs,
*      the XRCameraClient object must be deleted.
*   \var XRCAMERA_CLIENT_CONNECTED
*      The client is connected.
******************************************************************************/
typedef enum XRCAMERA_CLIENT_STATUS {
    XRCAMERA_CLIENT_DISCONNECTED = 0,
    XRCAMERA_CLIENT_CONNECTED,
    XRCAMERA_CLIENT_STATUS_MAX = 0xff
} XRCAMERA_CLIENT_STATUS;

// Return the data type of calibration data
typedef struct {
    uint32_t width;
    uint32_t height;
    float fx;
    float fy;
    float cx;
    float cy;
    float k1, k2, p1, p2, k3;
} calibration_t;

#define MAXNUMBERXYZ 10368  /*576 x 6 x 3 = 10368, The maximum possible length of xyz data*/
/**************************************************************************//**
* This structure is used to return data for DTof
******************************************************************************/
typedef struct {
    uint64_t time;  /*Time per frame*/
    uint32_t xyzLen; /*The actual length of xyz data*/
    float xyz[MAXNUMBERXYZ]; /*Array for storing xyz data*/
    bool hasGlass;              /*Whether this frame contains glass*/
} XrDTofFrameData_t;

/**************************************************************************//**
* \enum XRCAMERA_FRAME_PARAM
*
*   Enum to capture all the per frame params that can be retrieved using GetFrameParamNum
*   API. These params supplement the fixed frame data that can be retrieved via GetFrame API.
*   Any future frame param types should be appended to this enum.
*
*   \var XRCAMERA_FRAME_PARAM_U64_ROLLING_SHUTTER_SKEW_NS
*      Rolling shutter skew in ns for full sensor output dimension.
*   \var XRCAMERA_FRAME_PARAM_U64_TARGET_ROLLING_SHUTTER_SKEW_NS
*      Scaled rolling shutter skew in ns to match target dimension reported in xrcamera_frame_t,
*      target dimension is less than or equal to sensor output dimensions.
*   \var XRCAMERA_FRAME_PARAM_U32_PEER_FRAME_NUMBER
*      Indicates matching peer frame number when pair sync is active
*   \var XRCAMERA_FRAME_PARAM_U64_ILLUMINATION_DURATION_NS
*      The duration in ns for which the illumination was turned on for the current frame
*      If illumination was not used for this frame then this will be 0
*   \var XRCAMERA_FRAME_PARAM_I32_YUV420_COLOR_ARRANGEMENT
*      Param to indicate if YUV420 arrangement is NV12 or NV21.
*   \var XRCAMERA_FRAME_PARAM_I8_AUTO_EXPOSURE_ACTIVE
*      Indicates if auto exposure is active for the current frame
******************************************************************************/
typedef enum {
    XRCAMERA_FRAME_PARAM_U64_ROLLING_SHUTTER_SKEW_NS,
    XRCAMERA_FRAME_PARAM_U64_TARGET_ROLLING_SHUTTER_SKEW_NS,
    XRCAMERA_FRAME_PARAM_I32_PEER_FRAME_NUMBER,
    XRCAMERA_FRAME_PARAM_U64_ILLUMINATION_DURATION_NS,
    XRCAMERA_FRAME_PARAM_I32_YUV420_COLOR_ARRANGEMENT,
    XRCAMERA_FRAME_PARAM_I8_AUTO_EXPOSURE_ACTIVE
} XRCAMERA_FRAME_PARAM;

/**************************************************************************//**
* \enum XRCAMERA_FRAME_FORMAT_YUV420_ARRANGEMENT
*
*   \var XRCAMERA_FRAME_FORMAT_NOT_YUV420
*      The frame format is in not YUV420.
*   \var XRCAMERA_FRAME_FORMAT_YUV420_NV12
*      The frame format is YUV420 NV12/CBCR.
*   \var XRCAMERA_FRAME_FORMAT_YUV420_NV21
*      The frame format is YUV420 NV21/CRCB.
******************************************************************************/
typedef enum XRCAMERA_FRAME_FORMAT_YUV420_ARRANGEMENT {
    XRCAMERA_FRAME_FORMAT_NOT_YUV420,
    XRCAMERA_FRAME_FORMAT_YUV420_NV12,
    XRCAMERA_FRAME_FORMAT_YUV420_NV21
} XRCAMERA_FRAME_FORMAT_YUV420_ARRANGEMENT;

/**************************************************************************//**
* \enum XRCAMERA_CLIENT_NOTIFICATION
*
*   \var CAMERA_CLIENT_NOTIFICATION_STATE_CHANGED
*      The client state has changed. camera_client_notification_callback_fn
*      payload will contain
*      xrservice_camera_client_state_change_notify_payload_t.
******************************************************************************/
typedef enum XRCAMERA_CLIENT_NOTIFICATION {
    CAMERA_CLIENT_NOTIFICATION_STATE_CHANGED=0,
    CAMERA_CLIENT_NOTIFICATION_MAX
} XRCAMERA_CLIENT_NOTIFICATION;

/**************************************************************************//**
* This structure is used to pass the payload to
* camera_client_notification_callback_fn.
*
******************************************************************************/
typedef struct xrservice_camera_client_state_change_notify_payload_t {
    XRCAMERA_CLIENT_STATUS new_state; /**< New XRCAMERA_CLIENT_STATUS. */
    XRCAMERA_CLIENT_STATUS previous_state; /**< previous XRCAMERA_CLIENT_STATUS. */
} xrservice_camera_client_state_change_notify_payload_t;

/**************************************************************************//**
* Callback for handling camera client notifications.
* Callback is registered using RegisterForClientNotification().
* @param[in] pCtx            The context passed to RegisterForClientNotification().
* @param[in] notification    Notification value specifying the reason for the
*                            callback.
* @param[in] payload        Pointer to payload. Payload type depends on
*                            notification. Memory for the payload is allocated
*                            by xr service client and will be released when
*                            callback returns.
* @param[in] payload_length  Length of valid data in payload.
******************************************************************************/
typedef void (*camera_client_notification_callback_fn)(void *pCtx,
        XRCAMERA_CLIENT_NOTIFICATION notification, void *payload,
        uint32_t payload_length);

/**************************************************************************//**
* \enum XRCAMERA_DEVICE_NOTIFICATION
*
*   \var CAMERA_DEVICE_NOTIFICATION_STATE_CHANGED
*      The camera state has changed. camera_device_notification_callback_fn
*      payload will contain
*      xrservice_camera_device_state_change_notify_payload_t.
******************************************************************************/
typedef enum XRCAMERA_DEVICE_NOTIFICATION {
    CAMERA_DEVICE_NOTIFICATION_STATE_CHANGED=0,
    CAMERA_DEVICE_NOTIFICATION_MAX
} XRCAMERA_DEVICE_NOTIFICATION;

/**************************************************************************//**
* This structure is used to pass the payload to
* camera_device_notification_callback_fn.
*
******************************************************************************/
typedef struct xrservice_camera_device_state_change_notify_payload_t {
    XRCAMERA_CAMERA_STATUS new_state; /**< New XRCAMERA_CAMERA_STATUS. */
    XRCAMERA_CAMERA_STATUS previous_state; /**< Previous XRCAMERA_CAMERA_STATUS. */
} xrservice_camera_device_state_change_notify_payload_t;

/**************************************************************************//**
* Callback for handling a camera status event.
* @param[in] pCtx   The context passed in to SetClientStatusCallback().
* @param[in] state  Camera new state.
******************************************************************************/
typedef void (*camera_device_notification_callback_fn)(void *pCtx,
        XRCAMERA_DEVICE_NOTIFICATION notification, void *payload,
        uint32_t payload_length);

typedef struct _xr_plugin_param {
    const char* name;
    const char* val;
} xr_plugin_param_t;

// Error code
#define XR_CAM_SUCCESS                     0
#define XR_CAM_ERROR                      -1
#define XR_CAM_CALLBACK_NOT_SUPPORTED     -2
#define XR_CAM_API_NOT_SUPPORTED          -3
#define XR_CAM_INVALID_PARAM              -4
#define XR_CAM_EXPIRED_FRAMENUMBER        -5
#define XR_CAM_FUTURE_FRAMENUMBER         -6
#define XR_CAM_DROPPED_FRAMENUMBER        -7
#define XR_CAM_DEVICE_NOT_STARTED         -8
#define XR_CAM_DEVICE_STOPPING            -9
#define XR_CAM_DEVICE_DETACHING           -10
#define XR_CAM_DEVICE_ERROR               -11

// XR client libraries
#ifdef USE_XR_TEST
#define XRCAMERA_CLIENT_LIB "libopenxr_xrcamera_client_android.so"
#else
#define XRCAMERA_CLIENT_LIB "libopenxr_xrcamera_client.so"
#endif


typedef void* xrcamera_client_handle_t;
typedef void* xrcamera_device_handle_t;

typedef struct xrcamera_client_ops {
    xrcamera_client_handle_t (*Create)();
    void (*Destroy)(xrcamera_client_handle_t client);
    xrcamera_device_handle_t (*AttachCamera)(
        xrcamera_client_handle_t clientHandle, const char* pCameraName);
    int32_t (*InitRingBufferData)(xrcamera_client_handle_t clientHandle,
        XRSERVICE_RING_BUFFER_ID id);
    int32_t (*WriteRingBufferData)(xrcamera_client_handle_t clientHandle,
       XRSERVICE_RING_BUFFER_ID id, void* pData, uint32_t len);

    xrcamera_device_handle_t (*AttachCameraWithParams)(
        xrcamera_client_handle_t clientHandle, const char* pCameraName,
        xr_plugin_param_t pParams[], int32_t nParams);

    int32_t (*GetParam)(xrcamera_client_handle_t clientHandle,
            const char* pName, uint32_t* pLen, char* pValue);

    int32_t (*SetParam)(xrcamera_client_handle_t clientHandle,
            const char* pName, const char* pValue);
    int32_t (*EnumerateCameras)(xrcamera_client_handle_t clientHandle,
            uint32_t *cameraCount, const char ***cameras);
    int32_t (*RegisterForClientNotification)(xrcamera_client_handle_t client,
            XRCAMERA_CLIENT_NOTIFICATION notification,
            camera_client_notification_callback_fn cb, void *pCtx);
    xrcamera_client_handle_t (*CreateWithKey)(const char *szKey);
    void* reserved[64 - 12];
} xrcamera_client_ops_t;

typedef struct xrcamera_device_ops {
    int32_t (*DetachCamera)(xrcamera_device_handle_t CamDeviceHandle);
    int32_t (*GetCameraState)(xrcamera_device_handle_t CamDeviceHandle,
                              XRCAMERA_CAMERA_STATUS* pState);
    int32_t (*CamStart)(xrcamera_device_handle_t CamDeviceHandle);
    int32_t (*CamStop)(xrcamera_device_handle_t CamDeviceHandle);
    int32_t (*GetCurrentFrameNumber)(xrcamera_device_handle_t CamDeviceHandle,
                                     int32_t* fn);
    int32_t (*GetFrame)(xrcamera_device_handle_t CamDeviceHelper, int32_t* fn,
                        XRCAMERA_BLOCK_MODE block, XRCAMERA_DROP_MODE drop,
                        xrcamera_frame_t* pframe);
    int32_t (*GetFrameEx)(xrcamera_device_handle_t CamDeviceHelper,
                        XrCameraRequestFrameInputInfo *rfi,
                        XrCameraRequestFrameOutputInfo *rfo);
    int32_t (*ReleaseFrame)(xrcamera_device_handle_t CamDeviceHandle,
                            int32_t fn);
    xrsync_ctrl_t* (*GetSyncCtrl)(xrcamera_device_handle_t CamDeviceHelper,
                                   XR_SYNC_SOURCE syncSrc);
    int32_t (*ReleaseSyncCtrl)(xrcamera_device_handle_t CamDeviceHelper,
                            xrsync_ctrl_t* pSyncCtrl);
    int32_t (*GetParam)(xrcamera_device_handle_t CamDeviceHandle,
            const char* pName, uint32_t* pLen, char* pValue);
    int32_t (*SetParam)(xrcamera_device_handle_t CamDeviceHandle,
            const char* pName, const char* pValue);
    int32_t (*GetParamNum)(xrcamera_device_handle_t CamDeviceHandle,
            const char* pName, XRCAMERA_PARAM_NUM_TYPE type, uint8_t size,
            char* pValue);
    int32_t (*SetParamNum)(xrcamera_device_handle_t CamDeviceHandle,
            const char* pName, XRCAMERA_PARAM_NUM_TYPE type, uint8_t size,
            const char* pValue);

    int32_t (*SetExposureAndGain)(xrcamera_device_handle_t CamDeviceHandle,
        uint64_t exposure_ns, int iso_gain);

    int32_t (*SetCropRegion)(xrcamera_device_handle_t CamDeviceHandle,
        uint32_t l_top, uint32_t l_left, uint32_t l_width, uint32_t l_height,
        uint32_t r_top, uint32_t r_left, uint32_t r_width, uint32_t r_height);

    // Only supported by ITOF camera
    int32_t (*GetCalibration)(xrcamera_device_handle_t CamDeviceHandle, calibration_t *calibration);

    // Only supported by DTOF camera
    int32_t (*GetDTofXyz)(xrcamera_device_handle_t CamDeviceHandle,
                            int32_t*            fn,
                            XRCAMERA_BLOCK_MODE block,
                            XRCAMERA_DROP_MODE  drop,
                            XrDTofFrameData_t *frameData);

    // Only supported by ITOF camera
    int32_t (*GetITofFrame)(xrcamera_device_handle_t   CamDeviceHandle,
                            int32_t*                    fn,
                            XRCAMERA_BLOCK_MODE         block,
                            XRCAMERA_DROP_MODE          drop,
                            xrcamera_frame_t*          depthFrame,
                            xrcamera_frame_t*          confidenceFrame);

    int32_t (*FrameToHardwareBuffer)(xrcamera_device_handle_t camDeviceHelper, xrcamera_frame_t *pFrame,
                                     uint32_t *pNumHwBufs, xrcamera_hwbuffer_t **ppHwBuf);
    int32_t (*GetFrameParamNum)(xrcamera_device_handle_t camDeviceHelper, xrcamera_frame_t *pFrame,
                                XRCAMERA_FRAME_PARAM param, uint8_t size, void *pValue);
    int32_t (*SetGammaCorrectionValue)(xrcamera_device_handle_t camDeviceHelper, float gamma);
    int32_t (*RegisterForCameraNotification)(xrcamera_device_handle_t camDeviceHelper,
                                             XRCAMERA_DEVICE_NOTIFICATION notification,
                                             camera_device_notification_callback_fn cb, void *pCtx);
    int32_t (*GetFrameMatch)(xrcamera_device_handle_t camDeviceHelper,
                             xrcamera_frame_t *pFrameBase, xrcamera_frame_t *pFrameMatch);
    int32_t (*GetProperties)(xrcamera_device_handle_t camDeviceHelper,
                             XrCameraDevicePropertiesXR* pProperties);

    // Only supported by DTOF camera
    int32_t (*GetDTofFrameData)(xrcamera_device_handle_t CamDeviceHandle,
                            int32_t*            fn,
                            XRCAMERA_BLOCK_MODE block,
                            XRCAMERA_DROP_MODE  drop,
                            XrDTofFrameData_t *frameData);
    void* reserved[64 - 12];
} xrcamera_device_ops_t;

typedef struct xrcamera_client {
    int32_t api_version;
    xrcamera_client_ops_t* ops;
} xrcamera_client_t;

typedef struct xrcamera_client_helper {
    void* libHandle;
    xrcamera_client_t *client;
    xrcamera_client_handle_t clientHandle;
} xrcamera_client_helper_t;

typedef struct xrcamera_device {
    int32_t api_version;
    xrcamera_device_ops_t* ops;
} xrcamera_device_t;

typedef struct xrcamera_device_helper {
    xrcamera_client_t *client;
    xrcamera_device_t *cam;
    xrcamera_device_handle_t cameraHandle;
} xrcamera_device_helper_t;

/*********************************camera client create start******************************************/
#define TAG_CLIENT "XRCameraClient"
static inline XRCAMERA_API_VERSION XRCameraClient_GetVersion(xrcamera_client_helper_t* clientHelper)
{
    if (!clientHelper) return XR_CAM_INVALID_PARAM;
    return clientHelper->client->api_version;
}

static inline xrcamera_client_helper_t* XRCameraClient_Create()
{
    typedef xrcamera_client_t* (*getXRCameraClientOps_t)(void);
    getXRCameraClientOps_t getXRCameraClientOps = NULL;
    xrcamera_client_helper_t *clientHelper = NULL;

    XRLOGD(TAG_CLIENT, "start create client");
    clientHelper = (xrcamera_client_helper_t *)calloc(1, sizeof(xrcamera_client_helper_t));
    if (!clientHelper) {
        return NULL;
    }
    clientHelper->libHandle = dlopen(XRCAMERA_CLIENT_LIB, RTLD_NOW);
    if (!clientHelper->libHandle) {
        XRLOGE(TAG_CLIENT, "%s", dlerror());
        goto CreateError;
    }
    XRLOGD(TAG_CLIENT, "dlopen: %s, success get libHandle", XRCAMERA_CLIENT_LIB);

    getXRCameraClientOps = (getXRCameraClientOps_t)dlsym(clientHelper->libHandle, "getXRLibClientOps");
    if (!getXRCameraClientOps) {
        XRLOGE(TAG_CLIENT, "get client instance ops failed %s", dlerror());
        goto CreateClose;
    }
    XRLOGD(TAG_CLIENT, "success get client instance ops");

    clientHelper->client = getXRCameraClientOps();
    clientHelper->clientHandle = clientHelper->client->ops->Create();
    if (!clientHelper->clientHandle) {
        XRLOGE(TAG_CLIENT, "creant client instance failed");
        goto CreateClose;
    }
    XRLOGD(TAG_CLIENT, "success create client handle");
    return clientHelper;
CreateClose:
    dlclose(clientHelper->libHandle);
CreateError:
    free(clientHelper);
    return NULL;
}

static inline void XRCameraClient_Destroy(
        xrcamera_client_helper_t* clientHelper)
{
    if (!clientHelper) return;
    if (clientHelper->client->ops->Destroy) {
        clientHelper->client->ops->Destroy(clientHelper->clientHandle);
    }
    if (clientHelper->libHandle) {
        dlclose(clientHelper->libHandle);
    }
    free(clientHelper);
}

static inline xrcamera_device_helper_t* XRCameraClient_AttachCamera(
    xrcamera_client_helper_t* clientHelper, const char* pCameraName)
{
    typedef xrcamera_device_t* (*getXRCameraDeviceOps_t)(void);
    getXRCameraDeviceOps_t getXRCameraDeviceOps = NULL;
    xrcamera_device_helper_t *CamDeviceHelper = NULL;

    if (!clientHelper || !pCameraName) {
        return NULL;
    }
    CamDeviceHelper = (xrcamera_device_helper_t*)calloc(1, sizeof(xrcamera_device_helper_t));
    if (!CamDeviceHelper) {
        XRLOGE(TAG_CLIENT, "deivce helper is NULL");
        return NULL;
    }

    CamDeviceHelper->cameraHandle = clientHelper->client->ops->AttachCamera(clientHelper->clientHandle, pCameraName);
    if (!CamDeviceHelper->cameraHandle) {
        XRLOGE(TAG_CLIENT, "attatch %s failed", pCameraName);
        goto AttachCameraError;
    }

    getXRCameraDeviceOps = (getXRCameraDeviceOps_t) dlsym(clientHelper->libHandle, "getXRLibDeviceOps");
    if (!getXRCameraDeviceOps) {
        XRLOGE(TAG_CLIENT, "deivce ops get failed");
        goto AttachCameraError;
    }
    CamDeviceHelper->client = clientHelper->client;
    CamDeviceHelper->cam = getXRCameraDeviceOps();
    return CamDeviceHelper;
AttachCameraError:
    free(CamDeviceHelper);
    return NULL;
}

/*********************************camera device create start******************************************/
#define TAG_CAMERA "XRCameraDevice"
static inline XRCAMERA_API_VERSION XRCameraDevice_GetVersion(xrcamera_device_helper_t* CamDeviceHelper)
{
    if (!CamDeviceHelper) return XR_CAM_INVALID_PARAM;
    return CamDeviceHelper->cam->api_version;
}

static inline int32_t XRCameraDevice_DetachCamera(
    xrcamera_device_helper_t* CamDeviceHelper)
{
    int32_t ret = -1;
    if (!CamDeviceHelper) return XR_CAM_INVALID_PARAM;
    if (CamDeviceHelper->cam->ops->DetachCamera) {
        ret = CamDeviceHelper->cam->ops->DetachCamera(CamDeviceHelper->cameraHandle);
        if (ret == 0) free(CamDeviceHelper);
    }
    return ret;
}

static inline int32_t XRCameraDevice_GetCameraState(
    xrcamera_device_helper_t* CamDeviceHelper,
    XRCAMERA_CAMERA_STATUS* pState)
{
    if (!CamDeviceHelper) return XR_CAM_INVALID_PARAM;
    if (!CamDeviceHelper->cam->ops->GetCameraState) return XR_CAM_API_NOT_SUPPORTED;
    return CamDeviceHelper->cam->ops->GetCameraState(CamDeviceHelper->cameraHandle, pState);
}

static inline int32_t XRCameraDevice_Start(
    xrcamera_device_helper_t* CamDeviceHelper)
{
    if (!CamDeviceHelper) return XR_CAM_INVALID_PARAM;
    if (!CamDeviceHelper->cam->ops->CamStart) return XR_CAM_API_NOT_SUPPORTED;
    return CamDeviceHelper->cam->ops->CamStart(CamDeviceHelper->cameraHandle);
}

static inline int32_t XRCameraDevice_Stop(
    xrcamera_device_helper_t* CamDeviceHelper)
{
    if (!CamDeviceHelper) return XR_CAM_INVALID_PARAM;
    if (!CamDeviceHelper->cam->ops->CamStop) return XR_CAM_API_NOT_SUPPORTED;
    return CamDeviceHelper->cam->ops->CamStop(CamDeviceHelper->cameraHandle);
}

static inline int32_t XRCameraDevice_GetCurrentFrameNumber(
    xrcamera_device_helper_t* CamDeviceHelper, int32_t* fn)
{
    if (!CamDeviceHelper) return XR_CAM_INVALID_PARAM;
    if (!CamDeviceHelper->cam->ops->GetCurrentFrameNumber)
        return XR_CAM_API_NOT_SUPPORTED;
    return CamDeviceHelper->cam->ops->GetCurrentFrameNumber(CamDeviceHelper->cameraHandle, fn);
}

static inline int32_t XRCameraDevice_GetFrame(
    xrcamera_device_helper_t* CamDeviceHelper, int32_t* fn,
    XRCAMERA_BLOCK_MODE block, XRCAMERA_DROP_MODE drop,
    xrcamera_frame_t* pframe)
{
    if (!CamDeviceHelper || !pframe || !fn) return XR_CAM_INVALID_PARAM;
    if (!CamDeviceHelper->cam->ops->GetFrame) return XR_CAM_API_NOT_SUPPORTED;
    return CamDeviceHelper->cam->ops->GetFrame(
        CamDeviceHelper->cameraHandle, fn, block, drop, pframe);
}

static inline int32_t XRCameraDevice_GetFrameEx(
    xrcamera_device_helper_t* CamDeviceHelper,
    XrCameraRequestFrameInputInfo *rfi,
    XrCameraRequestFrameOutputInfo *rfo)
{
    if (!CamDeviceHelper) return XR_CAM_INVALID_PARAM;
    if (!CamDeviceHelper->cam->ops->GetFrameEx) return XR_CAM_API_NOT_SUPPORTED;
    return CamDeviceHelper->cam->ops->GetFrameEx(CamDeviceHelper->cameraHandle, rfi, rfo);
}

static inline int32_t XRCameraDevice_ReleaseFrame(
    xrcamera_device_helper_t* CamDeviceHelper, int32_t fn)
{
    if (!CamDeviceHelper) return XR_CAM_INVALID_PARAM;
    if (!CamDeviceHelper->cam->ops->ReleaseFrame) return XR_CAM_API_NOT_SUPPORTED;
    return CamDeviceHelper->cam->ops->ReleaseFrame(CamDeviceHelper->cameraHandle, fn);
}


static inline int32_t XRCameraDevice_GetDTofFrameData(
            xrcamera_device_helper_t* CamDeviceHandler,
            int32_t*            fn,
            XRCAMERA_BLOCK_MODE block,
            XRCAMERA_DROP_MODE  drop,
            XrDTofFrameData_t *frameData)
{
    if (!CamDeviceHandler) return XR_CAM_INVALID_PARAM;
    if (!CamDeviceHandler->cam->ops->GetDTofFrameData) return XR_CAM_API_NOT_SUPPORTED;
    return CamDeviceHandler->cam->ops->GetDTofFrameData(CamDeviceHandler->cameraHandle, fn, block, drop,frameData);
}

static inline int32_t XRCameraDevice_GetITofFrame(
                xrcamera_device_helper_t* CamDeviceHandler,
                int32_t*                    fn,
                XRCAMERA_BLOCK_MODE         block,
                XRCAMERA_DROP_MODE          drop,
                xrcamera_frame_t*          depthFrame,
                xrcamera_frame_t*          confidenceFrame)
{
    if (!CamDeviceHandler) return XR_CAM_INVALID_PARAM;
    if (!CamDeviceHandler->cam->ops->GetITofFrame) return XR_CAM_API_NOT_SUPPORTED;
    return CamDeviceHandler->cam->ops->GetITofFrame(CamDeviceHandler->cameraHandle, fn, block, drop, depthFrame, confidenceFrame);
}

static inline const char* XRCameraHelper_ShowState(XRCAMERA_CAMERA_STATUS camstate)
{
    switch (camstate){
        XR_CASE_RETURN_STR(XRCAMERA_CAMERA_CLIENT_DISCONNECTED);
        XR_CASE_RETURN_STR(XRCAMERA_CAMERA_INITIALISING);
        XR_CASE_RETURN_STR(XRCAMERA_CAMERA_READY);
        XR_CASE_RETURN_STR(XRCAMERA_CAMERA_STARTING);
        XR_CASE_RETURN_STR(XRCAMERA_CAMERA_STARTED);
        XR_CASE_RETURN_STR(XRCAMERA_CAMERA_STOPPING);
        XR_CASE_RETURN_STR(XRCAMERA_CAMERA_ERROR);
        default : return "unknown";
    }
}

static inline const char* XRCameraHelper_ShowCamError(int error)
{
    switch(error){
        XR_CASE_RETURN_STR(XR_CAM_SUCCESS);
        XR_CASE_RETURN_STR(XR_CAM_ERROR);
        XR_CASE_RETURN_STR(XR_CAM_CALLBACK_NOT_SUPPORTED);
        XR_CASE_RETURN_STR(XR_CAM_API_NOT_SUPPORTED);
        XR_CASE_RETURN_STR(XR_CAM_INVALID_PARAM);
        XR_CASE_RETURN_STR(XR_CAM_EXPIRED_FRAMENUMBER);
        XR_CASE_RETURN_STR(XR_CAM_FUTURE_FRAMENUMBER);
        XR_CASE_RETURN_STR(XR_CAM_DROPPED_FRAMENUMBER);
        XR_CASE_RETURN_STR(XR_CAM_DEVICE_STOPPING);
        XR_CASE_RETURN_STR(XR_CAM_DEVICE_NOT_STARTED);
        XR_CASE_RETURN_STR(XR_CAM_DEVICE_DETACHING);
        XR_CASE_RETURN_STR(XR_CAM_DEVICE_ERROR);
        default: return "unknown";
    }
}

#ifdef __cplusplus
}
#endif

#endif /* XRSERVICECLIENT_H */
