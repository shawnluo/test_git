#ifndef XRCOMMON_H
#define XRCOMMON_H

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

#if !defined(XR_MAY_ALIAS)
#if defined(__clang__) || (defined(__GNUC__) && (__GNUC__ > 4))
#define XR_MAY_ALIAS __attribute__((__may_alias__))
#else
#define XR_MAY_ALIAS
#endif
#endif

#define XR_DEVICE_NAME_MAX_LENGTH      64
#define XR_COMPONENT_NAME_MAX_LENGTH   64

/**************************************************************************
 * XR eye-tracking data section.
 ******************************************************************************/
#define XR_MAX_VIEWPORTS 6

/**
 * \enum XRSERVICE_EYE_ID
 *   \var XR_EYE_LEFT
 *      Left eye index.
 *   \var XR_EYE_RIGHT
 *      Right eye index.
 */
typedef enum XRSERVICE_EYE_ID {
    XR_EYE_LEFT,
    XR_EYE_RIGHT,
    XR_EYE_MAX,
} XRSERVICE_EYE_ID;

/**
 *   Type representing a bitmask to convey which signals the system is capable
 *   of delivering. Unlike struct-specific flags (e.g. xr_gaze_flags_t), which
 *   may be set or cleared depending on run-time conditions, these bits reflect
 *   whether a particular signal may ever be delivered by the system.
 */
typedef uint64_t xr_capabilities_flags_t;

/// Flag bits for xr_capabilities_flags_t for eye tracking
/// Note: an eye tracking plugin must support the XR_CAPABILITY_GAZE_COMBINED_GAZE
///       capability for the system to consider that stereo eye tracking is supported
///       (XRSERVICE_EYE_TRACKING_MODE_DUAL)
static const xr_capabilities_flags_t XR_CAPABILITY_GAZE_COMBINED_GAZE = 0x00000001;
static const xr_capabilities_flags_t XR_CAPABILITY_GAZE_CONVERGENCE_DISTANCE = 0x00000002;
static const xr_capabilities_flags_t XR_CAPABILITY_GAZE_FOVEATED_GAZE = 0x00000004;
static const xr_capabilities_flags_t XR_CAPABILITY_GAZE_PER_EYE_GAZE_ORIGIN = 0x00000008;
static const xr_capabilities_flags_t XR_CAPABILITY_GAZE_PER_EYE_GAZE_DIRECTION = 0x00000010;
static const xr_capabilities_flags_t XR_CAPABILITY_GAZE_PER_EYE_2D_GAZE_POINT = 0x00000020;
static const xr_capabilities_flags_t XR_CAPABILITY_GAZE_PER_EYE_EYE_OPENNESS = 0x00000040;
static const xr_capabilities_flags_t XR_CAPABILITY_GAZE_PER_EYE_PUPIL_DILATION = 0x00000080;
static const xr_capabilities_flags_t XR_CAPABILITY_GAZE_PER_EYE_POSITION_GUIDE = 0x00000100;
static const xr_capabilities_flags_t XR_CAPABILITY_GAZE_PER_EYE_BLINK = 0x00000200;
static const xr_capabilities_flags_t XR_CAPABILITY_GAZE_SUGGESTED_EYE_CAMERA_OFFSET_X = 0x00000400;

/**
 *   Type representing a bitmask used by the eye tracking plugin to convey
 *   the availability of the combined eye gaze data.
 *   A valid value for a variable of type xr_gaze_flags_t is
 *   either zero or a bitwise OR of the individual valid flags shown below:
 *   - XR_GAZE_ORIGIN_COMBINED_VALID
 *   - XR_GAZE_DIRECTION_COMBINED_VALID
 *   - XR_GAZE_CONVERGENCE_DISTANCE_VALID
 */
typedef uint64_t xr_gaze_flags_t;

/// Flag bits for xr_gaze_flags_t
static const xr_gaze_flags_t XR_GAZE_ORIGIN_COMBINED_VALID = 0x00000001;
static const xr_gaze_flags_t XR_GAZE_DIRECTION_COMBINED_VALID = 0x00000002;
static const xr_gaze_flags_t XR_GAZE_CONVERGENCE_DISTANCE_VALID = 0x00000004;

/**
 *   Type representing a bitmask used by the plugin to convey
 *   the availability of the per-eye gaze data.
 *   A valid value for a variable of type xr_gaze_per_eye_flags_t is
 *   either zero or a bitwise OR of the individual valid flags shown below:
 *   - XR_GAZE_PER_EYE_GAZE_ORIGIN_VALID
 *   - XR_GAZE_PER_EYE_GAZE_DIRECTION_VALID
 *   - XR_GAZE_PER_EYE_GAZE_POINT_VALID
 *   - XR_GAZE_PER_EYE_EYE_OPENNESS_VALID
 *   - XR_GAZE_PER_EYE_PUPIL_DILATION_VALID
 *   - XR_GAZE_PER_EYE_POSITION_GUIDE_VALID
 *   - XR_GAZE_PER_EYE_BLINK_VALID
 *   - XR_GAZE_PER_EYE_SUGGESTED_EYE_CAMERA_OFFSET_X_VALID
 */
typedef uint64_t xr_gaze_per_eye_flags_t;

/** Flag bits for xr_gaze_per_eye_flags_t. */
static const xr_gaze_per_eye_flags_t XR_GAZE_PER_EYE_GAZE_ORIGIN_VALID = 0x00000001;
static const xr_gaze_per_eye_flags_t XR_GAZE_PER_EYE_GAZE_DIRECTION_VALID = 0x00000002;
static const xr_gaze_per_eye_flags_t XR_GAZE_PER_EYE_GAZE_POINT_VALID = 0x00000004;
static const xr_gaze_per_eye_flags_t XR_GAZE_PER_EYE_EYE_OPENNESS_VALID = 0x00000008;
static const xr_gaze_per_eye_flags_t XR_GAZE_PER_EYE_PUPIL_DILATION_VALID = 0x00000010;
static const xr_gaze_per_eye_flags_t XR_GAZE_PER_EYE_POSITION_GUIDE_VALID = 0x00000020;
static const xr_gaze_per_eye_flags_t XR_GAZE_PER_EYE_BLINK_VALID = 0x00000040;
static const xr_gaze_per_eye_flags_t XR_GAZE_PER_EYE_SUGGESTED_EYE_CAMERA_OFFSET_X_VALID = 0x00000080;

#define XR_EYE_MAX_BUFFER_CNT 8
#define XR_EYE_MAX_FRAME_SIZE 2 * 1024 * 1024

///< 眼睛类型
typedef enum XrEyeType {
    XR_EYE_TYPE_LEFT = 0x1 << 0,   ///< 左眼
    XR_EYE_TYPE_RIGHT = 0x1 << 1,  ///< 右眼
    XR_EYE_TYPE_BOTH = 0x1 << 2,   ///< 双眼合并结果
} XrEyeType;

///< 佩戴检测的状态
typedef enum XrEyeHmdPosition {
    XR_EYE_WEARING_POSITION_NO_EYE = 0x0,     ///< 未检测到眼睛
    XR_EYE_WEARING_POSITION_UPPER,            ///< 头显位置偏上
    XR_EYE_WEARING_POSITION_LOWER,            ///< 头显位置偏下
    XR_EYE_WEARING_POSITION_OK,               ///< 头显位置适中
} XrEyeHmdPosition;

///< IPD调节的状态
typedef enum XrEyeIpdState {
    XR_EYE_IPD_STATE_DEFAULT = 0x0,   ///< 初始状态
    XR_EYE_IPD_STATE_KEEP,            ///< 正在进行校准
    XR_EYE_IPD_STATE_INCORRECT_WEAR, ///< 未正确佩戴设备
    XR_EYE_IPD_STATE_FINISH,          ///< 校准完成
} XrEyeIpdState;

///< 录入/比对虹膜时状态
typedef enum XrEyeIrisState {
    XR_EYE_IRIS_STATE_NOT_LOOK_TARGET = 0x0,
    XR_EYE_IRIS_STATE_INCORRECT_WEAR,
    XR_EYE_IRIS_STATE_KEEP,
    XR_EYE_IRIS_STATE_DELETE_OLD_USER,
    XR_EYE_IRIS_STATE_ENROLL_SUCCESS,
    XR_EYE_IRIS_STATE_COMPARE_SUCCESS,
    XR_EYE_IRIS_STATE_COMPARE_NOT_MATCHED,
} XrEyeIrisState;

typedef enum XrEyeNotification {
    XR_EYE_PUPILS,
    XR_EYE_ADJUST_IPD_RESULT,
    XR_EYE_IRIS_RESULT,
} XrEyeNotification;

///< 4x4 浮点矩阵，用于表示 View Matrix 和 Projection Matrix
typedef struct XrMatrix {
    float m[4][4];
} XrMatrix;

///< 三维向量
typedef struct XrVector3f {
    float x;
    float y;
    float z;
} XrVector3f;

///< 四元数
typedef struct XrQuaternionf {
    float x;
    float y;
    float z;
    float w;
} XrQuaternionf;

///< 颜色
typedef struct XrColor {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    float alpha;
} XrColor;

typedef struct XrPupilParam {
    float distance_l, distance_r; ///< 左右瞳孔离原点距离
} XrPupilParam;

///< 启动校准所需的数据
// 校准点坐标为camera坐标系下坐标
// 每次切换背景需要再校准一轮，预计需要进行三种不同背景亮度下的校准
typedef struct XrEye_CalibrateStartInfo {
	XrVector3f center_point;                        ///< 校准点坐标（单点）
    XrVector3f cali_point[XR_EYE_MAX_BUFFER_CNT];   ///< 校准点坐标（6点）
    size_t cali_point_count;                        ///< 校准点数量
    XrColor cali_bg[XR_EYE_MAX_BUFFER_CNT];         ///< 校准背景颜色
    size_t cali_bg_count;                           ///< 校准背景数量
} XrEye_CalibrateStartInfo;

///< 单眼算法结果
typedef struct XrSingleEyeResult {
    XrEyeType type;               ///< 左右眼类型
    bool is_valid;                ///< 是否有效
    XrVector3f position;          ///< 眼睛位置
    XrQuaternionf orientation;    ///< 注视方向
    XrVector3f target_position;   ///< camera坐标系下的注视点
} XrSingleEyeResult;

///< 眼动算法结果
typedef struct XrEyeResult {
    XrSingleEyeResult result[XR_EYE_MAX_BUFFER_CNT];    ///< 单眼算法结果
    size_t result_count;                                ///< 结果数量
} XrEyeResult;

///< 图像结构体
typedef struct XrEyeImage {
    size_t height;          ///< 宽度
    size_t width;           ///< 高度
    uint64_t timestamp;     ///< 时间戳
    uint8_t data[XR_EYE_MAX_FRAME_SIZE];
} XrEyeImage;

/// @brief 佩戴检测功能回调
typedef void (*XrEyeWearingPositionCb)(const XrEyeHmdPosition wearingPosition);

/// @brief 眼动追踪功能回调
typedef void (*XrEyeTrackingPoseCb)(const XrEyeResult *pose);

/// @brief 原始图像回调
typedef void (*XrEyeTrackingRawFrameCb)(const XrEyeImage *image);

/// @brief 通知回调
/// 当 type 为 XR_EYE_PUPILS, data 为 XrPupilParam;
/// 当 type 为 XR_EYE_ADJUST_IPD_RESULT, data 为 XrEyeIpdState;
/// 当 type 为 XR_EYE_IRIS_RESULT, data 为 XrEyeIrisState;
typedef void (*XrEyeNotificationCb)(XrEyeNotification type, const void *data);

typedef struct XrEyeCallbacks {
    XrEyeWearingPositionCb wearingPositionCb; /// 佩戴位置检测
    XrEyeTrackingPoseCb poseCb; /// 眼动追踪
    XrEyeTrackingRawFrameCb frameCb; /// 图像回调
    XrEyeNotificationCb notifCb; /// 通知回调
} XrEyeCallbacks;

//----------------------------------------------------------
// 下面所有 eyetracking 相关数据结构都已经弃用，在移植结束后记得移除！
//----------------------------------------------------------

/** Used to report the per-eye eye-tracking information. */
typedef struct xrservice_gaze_per_eye_t {
    xr_gaze_per_eye_flags_t flags;           /*!< Validity bitmask for the per-eye eye gaze
                                                   attributes. */
    uint32_t                 reserved1[2];
    float                    gazeOrigin[3];   /*!< Contains the origin (x, y, z) of the eye
                                                   gaze vector in meters from the HMD center-eye
                                                   coordinate system's origin. */
    uint32_t                 reserved2;
    float                    gazeDirection[3];/*!< Contains the unit vector of the eye gaze direction
                                                   in the HMD center-eye coordinate system. */
    uint32_t                 reserved3;
    float                    viewport2DGazePoint[XR_MAX_VIEWPORTS][2];
                                              /*!< For each supported viewport, an unsigned
                                                   normalized 2D gaze point where origin is top left
                                                   of the view port. */
    float                    eyeOpenness;     /*!< Value between 0.0 and 1.0 where 1.0 means fully
                                                   open and 0.0 closed. */
    float                    pupilDilation;   /*!< Value in millimeter indicating the pupil
                                                   dilation. */
    uint32_t                 reserved4[2];
    float                    positionGuide[3];/*!< Normalized (0.0-1.0) position of pupil in relation
                                                   to optical axis where 0.5, 0.5 is on the optical axis.
                                                   This information is useful to convey if the user is
                                                   wearing the headset correctly and if the user's
                                                   interpupillary distance matches the lens separation. */
    uint32_t                 blink;           /*!< Indicates whether the eye of the user is closed (1) or
                                                   not closed (0). */
    float                    suggestedEyeCameraOffsetX;
                                              /*!< Contains the suggested eye camera x-axis offset
                                                   from the center-eye when calculating the view matrix.
                                                   Measured in meters from the HMD center-eye coordinate
                                                   system's origin. */
    uint8_t                  reserved[ 256
                                      -sizeof(xr_gaze_per_eye_flags_t)
                                      -sizeof(float) * 24
                                      -sizeof(uint32_t) * 7];
} xrservice_gaze_per_eye_t;

/**
 *   Type representing a bitmask used by the plugin to convey
 *   infomation about the frame data used.
 *   A valid value for a variable of type xr_timing_flags_t is
 *   either zero or a bitwise OR of the individual valid flags shown below:
 *   - XR_TIMING_CAMERA_DATA_VALID
 */
typedef uint64_t xr_timing_flags_t;

/** Flag bits for xr_gaze_per_eye_flags_t. */
static const xr_timing_flags_t XR_TIMING_CAMERA_DATA_VALID = 0x00000001;

/** Used to report eye-tracking data source. */
typedef union xrservice_timing_t {
    struct {
        uint32_t frameNumber;
        uint32_t exposureNs;
        uint64_t startOfExposureNs; /*!< In ns using Android BOOTTIME clock. */
    } camera;
} xrservice_timing_t;

/**
 * \enum XRSERVICE_FOVEATED_GAZE_TRACKING_STATE
 *   \var XRSERVICE_FOVEATED_GAZE_TRACKING_STATE_TRACKING
 *      The user is being tracked and the value has been updated.
 *   \var XRSERVICE_FOVEATED_GAZE_TRACKING_STATE_EXTRAPOLATED
 *      The user is not being tracked and the value has been extrapolated from
 *      historical data.
 *   \var XRSERVICE_FOVEATED_GAZE_TRACKING_STATE_LAST_KNOWN
 *      The user is not being tracked and the value is a repeat of the last
 *      last tracked value.
 */
typedef enum XRSERVICE_FOVEATED_GAZE_TRACKING_STATE {
    XRSERVICE_FOVEATED_GAZE_TRACKING_STATE_TRACKING,
    XRSERVICE_FOVEATED_GAZE_TRACKING_STATE_EXTRAPOLATED,
    XRSERVICE_FOVEATED_GAZE_TRACKING_STATE_LAST_KNOWN,
    XRSERVICE_FOVEATED_GAZE_TRACKING_STATE_MAX = 0x7fffffff
} XRSERVICE_FOVEATED_GAZE_TRACKING_STATE;

/** Used to report the combined eye-tracking information. */
typedef struct xrservice_eye_tracking_data_t {
    int64_t                   timestamp;               /**< In ns using Android BOOTTIME clock. */
    xr_gaze_flags_t          flags;                   /**< xr_gaze_flags_t validity bitmask for the
                                                            combined eye gaze attributes. */
    xrservice_gaze_per_eye_t eye[XR_EYE_MAX];        /**< Array of 2 xrservice_gaze_per_eye_t
                                                            structures. representing the left eye
                                                            then right eye, per-eye gaze information. */
    float                     gazeOriginCombined[3];   /**< Contains the origin (x, y, z) of the
                                                            combined gaze vector in meters from the
                                                            HMD center-eye coordinate system origin. */
    float                     reserved1;               /**< Reserved field. */
    float                     gazeDirectionCombined[3];/**< Contains the origin (x, y, z) of the
                                                            combined gaze vector in meters from the
                                                            HMD center-eye coordinate system's origin. */
    float                     gazeConvergenceDistance; /**< Distance in meters from gazeOriginCombined
                                                            where the vectors converge. */
    xr_timing_flags_t        timingFlags;             /**< Indicates if timing info is valid and the
                                                            source of the information. */
    xrservice_timing_t       timing;                  /**< Data source timing information (ex: camera
                                                            exposure and timestamp). */
    float                     foveatedGazeDirection[3]; /**< Contains the unit vector of the gaze
                                                            direction in the HMD center-eye coordinate
                                                            system. Origin of this vector is the same
                                                            as the origin for the HMD center-eye
                                                            coordinate system. This signal is
                                                            optimized for foveated rendering or other
                                                            use cases gazeDirectionCombined is
                                                            preferred. */
    XRSERVICE_FOVEATED_GAZE_TRACKING_STATE foveatedGazeTrackingState;
                                                        /**< Contains the current state of the
                                                            foveatedGazeDirection signal. */
    // NOTE: struct is 64-bit aligned, add fields accordingly.
    uint8_t                   reserved[ 640
                                       -sizeof(uint64_t)
                                       -sizeof(xr_gaze_flags_t)
                                       -sizeof(xrservice_gaze_per_eye_t) * XR_EYE_MAX
                                       -sizeof(float) * 11
                                       -sizeof(xr_timing_flags_t)
                                       -sizeof(xrservice_timing_t)
                                       -sizeof(XRSERVICE_FOVEATED_GAZE_TRACKING_STATE)];
                                                        /**< Reserved field. */
} xrservice_eye_tracking_data_t;

/**
 * @par XR_EYE_TRACKING_DATA_ENABLE_SYNC
 *     When set, the sync framework will measure GetEyeTrackingDataWithFlags()
 *     call frequency and adjust the timing of eye pose generation to minimize
 *     latency. Calls must be made at regular intervals (i.e. ~30/45/60 Hz).
 *     This flag will only be available for use if the caller obtained a
 *     xrsync_ctrl_t object using XRServiceClient_GetSyncCtrl() with the source
 *     specified as XR_SYNC_SOURCE_EYE_POSE_CLIENT_READ.
 */
typedef uint64_t xr_eye_tracking_data_flags_t;

static const xr_eye_tracking_data_flags_t XR_EYE_TRACKING_DATA_ENABLE_SYNC  = 0x00000001;

typedef enum {
    RING_BUFFER_POSE = 0,
    RING_BUFFER_EYE_POSE,
    RING_BUFFER_PREDICTED_HEAD_POSE,
    RING_BUFFER_FRAME_POSE,
    RING_BUFFER_MAX
} XRSERVICE_RING_BUFFER_ID;

typedef struct {
    int32_t fd;
    uint32_t size;
    uint32_t index_offset;
    uint32_t ring_offset;
    uint32_t element_size;
    uint32_t num_elements;
    uint32_t reserved;
} xrservice_ring_buffer_desc_t;

typedef struct XrOffset2DiXR {
    int32_t x;
    int32_t y;
} XrOffset2DiXR;

typedef struct XrExtent2DiXR {
    int32_t width;
    int32_t height;
} XrExtent2DiXR;

typedef struct XrVector2dXR {
    double x;
    double y;
} XrVector2dXR;

typedef struct XrQuaternionfXR {
    float x;
    float y;
    float z;
    float w;
} XrQuaternionfXR;

typedef struct XrVector3fXR {
    float x;
    float y;
    float z;
} XrVector3fXR;

typedef struct XrPosefXR {
   XrQuaternionfXR orientation;                            /**< Pose orientation. */
   XrVector3fXR    position;                               /**< Pose position. */
} XrPosefXR;

typedef struct XrFramePose {
    XrPosefXR                   pose;                    /**< Rotation and translation pose. */
    uint16_t                     tracking_state;          /**< Bitmask contains the state of 6DOF tracking. */
                                                          /**< If no bits are high : UNINITIALIZED. */
                                                          /**< bit 0     : RELOCATION_IN_PROGRESS. */
                                                          /**< bit 1     : TRACKING_SUSPENDED. */
                                                          /**< bit 2     : TRACKING. */
                                                          /**< bit 3     : FATAL_ERROR. */
                                                          /**< bits 4-15 : reserved. */
    uint16_t                     tracking_warning_flags;  /**< Bitmask contains the 6DOF tracking warnings. */
                                                          /**< These warnings are only valid when pose_quality is 0. */
                                                          /**< Bit 0 : LOW_FEATURE_COUNT_ERROR. */
                                                          /**< Bit 1 : LOW_LIGHT_ERROR. */
                                                          /**< Bit 2 : BRIGHT_LIGHT_ERROR. */
                                                          /**< Bit 3 : STEREO_CAMERA_CALIBRATION. */
                                                          /**< Bit 4 : TIMESTAMP_ERROR. */
                                                          /**< Bit 5 : CONFIG_FILE_ERROR. */
                                                          /**< Bit 6 : CALIBRATION_FILE_ERROR. */
                                                          /**< Bit 7 : EVA_ERROR. */
                                                          /**< Bit 8 : EVA_FATAL. */
                                                          /**< Bits 9-15 : reserved. */
    uint64_t                     ts;                      /**< Timestamp corresponding to the frame. */
    float                        pose_quality;            /**< Binary, with 0.0 (bad) or 1.0 (good). */
    float                        sensor_quality;          /**< This value is deprecated and set to 0. */
    float                        camera_quality;          /**< This value is deprecated and set to 0. */
    uint8_t                      reserved[12];            /**< Reserved. */
} XrFramePose;

#define XR_STRUCT_TYPE_XR_BASE        0x545300

typedef int64_t XrDuration;
typedef uint64_t XrFlags64;
typedef uint32_t XrHandleXR;

/** A single point within a point cloud. */
typedef struct XrMapPointXR {
   XrVector3fXR position;                                  /**< Point position. */
   uint32_t      id;                                        /**< Point ID. */
} XrMapPointXR;

/** Point cloud. */
typedef struct XrPointCloudXR {
    uint64_t      timestamp;                              /**< Timestamp in Android boot time ns of when the points were updated. */
    uint32_t      maxPoints;                              /**< Maximum number of elements in the points array. */
    uint32_t      numPoints;                              /**< Number of valid points in the points array. */
    XrMapPointXR points[];                               /**< Map points. */
} XrPointCloudXR;

/** XR structure types. */
typedef enum XrStructureTypeXR {
    XR_TYPE_XR_CAM_SENSOR_PROPS = XR_STRUCT_TYPE_XR_BASE,
    XR_TYPE_XR_CAM_DEVICE_PROPS,
    XR_TYPE_XR_CAM_PROPS,
    XR_TYPE_XR_CAM_FRAME_REQ_INFO_INPUT,
    XR_TYPE_XR_CAM_FRAME_REQ_INFO_OUTPUT,
    XR_TYPE_XR_CAM_PARTIAL_FRAME_REQ_INFO_INPUT,
    XR_TYPE_XR_CAM_PARTIAL_FRAME_REQ_INFO_OUTPUT,
    XR_TYPE_XR_CAM_HW_FRAME_BUFFER_INFO_OUTPUT,
    XR_TYPE_XR_CAM_HW_BUFFER_OUTPUT,
    XR_TYPE_XR_CAM_BUFFER_OUTPUT,
    XR_TYPE_XR_CAM_FRAME_INFO_OUTPUT,
    XR_TYPE_XR_CAM_FRAME_BUFFER_INFO_OUTPUT,
    XR_TYPE_XR_CAM_FRAME_CALIBRATION_INFO,
    XR_TYPE_XR_CAM_FRAME_CROP_INFO,
    XR_TYPE_XR_MAX_ENUM = 0x7fffffff
} XrStructureTypeXR;

/** Hardware component types. */
typedef enum XrHwComponentTypeXR {
    XR_HW_COMP_TYPE_XR_CAMERA_SENSOR,                    /**< Physical camera sensor. */
    XR_HW_COMP_TYPE_XR_MAX_ENUM = 0x7fffffff
} XrHwComponentTypeXR;

/** Hardware device types. */
typedef enum XrHwDeviceTypeXR {
    XR_HW_DEVICE_TYPE_XR_CAMERA,                         /**< A camera device, comprised of one or more camera sensor components. */
    XR_HW_DEVICE_TYPE_XR_MAX_ENUM = 0x7fffffff
} XrHwDeviceTypeXR;

/** Distortion models. */
typedef enum XrDistortionModelXR {                       /**< ENUM to select the specific lens distortion model used. */
    XR_DISTORTION_MODEL_XR_LINEAR,                       /**< Only the linear projection parameters (principal_point and focal_length) are used. */
    XR_DISTORTION_MODEL_XR_RADIAL_2_PARAMS,              /**< A radial distortion model using 2 parameters of radial_distortion to form a second-order polynomial. */
    XR_DISTORTION_MODEL_XR_RADIAL_3_PARAMS,              /**< A radial distortion model using 3 parameters of radial_distortion to form a third-order polynomial. */
    XR_DISTORTION_MODEL_XR_RADIAL_6_PARAMS,              /**< A radial distortion model using 6 parameters of radial_distortion to form a rational function. */
    XR_DISTORTION_MODEL_XR_FISHEYE_1_PARAM,              /**< A radial distortion model using the first parameter of radial_distortion, combining arctan with a linear model. */
    XR_DISTORTION_MODEL_XR_FISHEYE_4_PARAMS,             /**< A radial distortion model using 4 parameters of radial_distortion, combining arctan with a forth-order polynomial. */
    XR_DISTORTION_MODEL_XR_MAX_ENUM = 0x7fffffff
} XrDistortionModelXR;

typedef XrFlags64 XrHardwareComponentFlagsXR;

// Flag bits for XrHardwareComponentFlagsXR
static const XrHardwareComponentFlagsXR XR_HARDWARE_COMPONENT_EXTRINSIC_VALID_BIT = 0x00000001;
static const XrHardwareComponentFlagsXR XR_HARDWARE_COMPONENT_EXTRINSIC_DYNAMIC_BIT = 0x00000002;

typedef XrFlags64 XrHardwareDeviceFlagsXR;

// Flag bits for XrHardwareDeviceFlagsXR
static const XrHardwareDeviceFlagsXR XR_HARDWARE_DEVICE_REMOVABLE_BIT = 0x00000001;

typedef XrFlags64 XrCameraSensorCalibrationFlagsXR;

// Flag bits for XrCameraSensorCalibrationFlagsXR
static const XrCameraSensorCalibrationFlagsXR XR_CAMERA_SENSOR_CALIBRATION_DYNAMIC_BIT = 0x00000001;

/** Hardware component descriptor. */
typedef struct XR_MAY_ALIAS XrHardwareComponentBaseXR {
    XrStructureTypeXR           type;
    const void* XR_MAY_ALIAS     next;
    XrHwComponentTypeXR         componentType;           /**< Type of this component. */
    XrHandleXR                  handle;                  /**< Component handle. */
    XrHandleXR                  parentHandle;            /**< Handle of this component's parent. */
    char                         componentName[XR_COMPONENT_NAME_MAX_LENGTH];   /**< Name of the component. */
    XrHardwareComponentFlagsXR  flags;                   /**< Flags for this component. */
    XrPosefXR                   extrinsic;               /**< Extrinsic of component in world coordinates, relative to the reference hardware component (IMU). */
    char                         reserved[32];            /**< reserved for future use */
} XrHardwareComponentBaseXR;

/** Hardware device descriptor. */
typedef struct XR_MAY_ALIAS XrHardwareDeviceBaseXR {
    XrStructureTypeXR           type;
    const void* XR_MAY_ALIAS     next;
    XrHwDeviceTypeXR            deviceType;              /**< Type of this device. */
    XrHandleXR                  handle;                  /**< Device handle. */
    char                         deviceName[XR_DEVICE_NAME_MAX_LENGTH];      /**< Name of the device. */
    XrHardwareDeviceFlagsXR     flags;                   /**< Flags for this device. */
    uint32_t                     componentCount;          /**< Number of components in this device. */
    XrHardwareComponentBaseXR*  components;               /**< Component. */
    char                         reserved[32];            /**< reserved for future use */
} XrHardwareDeviceBaseXR;

/** Describes the intrinsic calibration parameters of a lens. */
typedef struct XrIntrinsicCalibrationXR {
    XrExtent2DiXR       size;                            /**< Size of the image viewed through the lens as [columns, rows]. */
    XrVector2dXR        principalPoint;                  /**< Location of the principal point in the image in pixels. */
    XrVector2dXR        focalLength;                     /**< Focal length in x and y direction in pixels. */
    double               skew;                            /**< Axis skew. */
    double               radialDistortion[7];             /**< Up to 7 radial distortion coefficients. */
    double               tangentialDistortion[2];         /**< Up to 2 tangential distortion coefficients. */
    double               distortion_limit;                /**< Distortion limit. */
    double               undistortion_limit;              /**< Undistortion limit. */
    XrDistortionModelXR distortionModel;                 /**< Lens distortion model used for this calibration. */
} XrIntrinsicCalibrationXR;

/** Camera sensor calibration data. */
typedef struct XrCameraSensorCalibrationXR {
    XrCameraSensorCalibrationFlagsXR flags;              /**< Flags for this camera sensor calibration. */
    XrIntrinsicCalibrationXR         intrinsics;         /**< Intrinsic lens and sensor parameters. */
    XrDuration                        lineTime;           /**< Line time for rolling shutter cameras in nanoseconds; for global shutter cameras, set to 0. */
    int32_t                           timestampRow;       /**< Row of the image that corresponds to the time stamp associated with the image; for global shutter cameras, set to 0. */
} XrCameraSensorCalibrationXR;

/** Camera sensor properties. */
typedef struct XrCameraSensorPropertiesXR {
    XrHardwareComponentBaseXR   base;
    XrOffset2DiXR               frameOffset;             /**< Offset into frame image for this sensor, together with size in XrIntrinsicCalibrationXR can be used to define the full rectangle. */
    XrCameraSensorCalibrationXR calibrationInfo;         /**< Camera sensor calibration information. */
} XrCameraSensorPropertiesXR;

/** Camera device properties. */
typedef struct XrCameraDevicePropertiesXR {
    XrHardwareDeviceBaseXR      base;
    XrExtent2DiXR               fullResExtent;           /**< Dimensions of full resolution image. */
} XrCameraDevicePropertiesXR;

/** IMU sensor device properties. */
typedef struct XrIMUDevicePropertiesXR {
    XrHardwareDeviceBaseXR      base;
    double               ombc[3];                         /**< Gyroscope Bias Vector. */
    double               tbc[3];                          /**< Accelerometer Bias Vector. */
    double               aBias[3];                        /**< Accelerometer Scale Factor Error. */
    double               wBias[3];                        /**< Gyroscope Scale Factor Error. */
    double               ka[3];                           /**< Accelerometer Noise Coefficient. */
    double               kg[3];                           /**< Gyroscope Noise Coefficient. */
    double               na[3];                           /**< Accelerometer Non-orthogonality Errors. */
    double               ng[3];                           /**< Gyroscope Non-orthogonality Errors. */
    double               ombg[3];                         /**< Gyro-Accelerometer Cross-coupling Errors. */
    double               accelDelta;                      /**< Initial Accelerometer Bias. */
    double               delta;                           /**< Initial Gyroscope Bias. */
    double               movingAccelNoise;                /**< Moving Accelerometer Noise */
    double               movingGyroNoise;                 /**< Moving Gyroscope Noise */
} XrIMUDevicePropertiesXR;

typedef struct xrservice_class_t {
    int api_version;
    XrStructureTypeXR type;
    void* ops;
    void* clientHelper;
} xrservice_class_t;

typedef enum XR_SYNC_SOURCE {
    XR_SYNC_SOURCE_EYE_POSE, /**< Synchronization is driven by the eye pose being read by a client. */
    XR_SYNC_SOURCE_CAMERA_FRAME_VST_R,
    XR_SYNC_SOURCE_CAMERA_FRAME_VST_L,
    XR_SYNC_SOURCE_CAMERA_FRAME = XR_SYNC_SOURCE_CAMERA_FRAME_VST_R, /** Synchronization is driven by the camera frame being read by a client. */
    XR_SYNC_SOURCE_DISPLAY_VSYNC, /** Synchronization is driven by the periodic VSYNC signal of the display. */
    XR_SYNC_SOURCE_MAX
} XR_SYNC_SOURCE;

typedef struct xrsync_ctrl_t {
    void* handle;
    uint32_t size;
} xrsync_ctrl_t;

#ifdef __cplusplus
}
#endif

#endif
