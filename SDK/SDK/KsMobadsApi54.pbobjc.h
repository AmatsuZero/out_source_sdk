// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ks_mobads_api_5.4.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers.h>
#else
 #import "GPBProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30002
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30002 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class SXLCAd;
@class SXLCAdSlot;
@class SXLCAdStrategy;
@class SXLCApp;
@class SXLCDevice;
@class SXLCGps;
@class SXLCMaterialMeta;
@class SXLCMetaIndex;
@class SXLCNetwork;
@class SXLCSize;
@class SXLCTracking;
@class SXLCUdId;
@class SXLCVersion;
@class SXLCVideo;
@class SXLCWiFiAp;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum SXLCMobadsRequest_RequestProtocolType

/** 请求协议类型 */
typedef GPB_ENUM(SXLCMobadsRequest_RequestProtocolType) {
  /** 未知协议 */
  SXLCMobadsRequest_RequestProtocolType_UnknownProtocolType = 0,

  /** http协议 */
  SXLCMobadsRequest_RequestProtocolType_HTTPProtocolType = 1,

  /** https协议 */
  SXLCMobadsRequest_RequestProtocolType_HTTPSProtocolType = 2,
};

GPBEnumDescriptor *SXLCMobadsRequest_RequestProtocolType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL SXLCMobadsRequest_RequestProtocolType_IsValidValue(int32_t value);

#pragma mark - Enum SXLCDevice_DeviceType

/** 设备类型 */
typedef GPB_ENUM(SXLCDevice_DeviceType) {
  /** 手机，含iTouch */
  SXLCDevice_DeviceType_Phone = 1,

  /** 平板 */
  SXLCDevice_DeviceType_Tablet = 2,
};

GPBEnumDescriptor *SXLCDevice_DeviceType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL SXLCDevice_DeviceType_IsValidValue(int32_t value);

#pragma mark - Enum SXLCDevice_OsType

/** 操作系统类型 */
typedef GPB_ENUM(SXLCDevice_OsType) {
  /** Android */
  SXLCDevice_OsType_Android = 1,

  /** iOS */
  SXLCDevice_OsType_Ios = 2,
};

GPBEnumDescriptor *SXLCDevice_OsType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL SXLCDevice_OsType_IsValidValue(int32_t value);

#pragma mark - Enum SXLCNetwork_ConnectionType

/** 网络连接类型 */
typedef GPB_ENUM(SXLCNetwork_ConnectionType) {
  /** 无法探测当前网络状态 */
  SXLCNetwork_ConnectionType_ConnectionUnknown = 0,

  /** 蜂窝数据接入，未知网络类型 */
  SXLCNetwork_ConnectionType_CellUnknown = 1,

  /** 蜂窝数据2G网络 */
  SXLCNetwork_ConnectionType_Cell2G = 2,

  /** 蜂窝数据3G网络 */
  SXLCNetwork_ConnectionType_Cell3G = 3,

  /** 蜂窝数据4G网络 */
  SXLCNetwork_ConnectionType_Cell4G = 4,

  /** 蜂窝数据5G网络 */
  SXLCNetwork_ConnectionType_Cell5G = 5,

  /** Wi-Fi网络接入 */
  SXLCNetwork_ConnectionType_Wifi = 100,

  /** 以太网接入 */
  SXLCNetwork_ConnectionType_Ethernet = 101,

  /** 未知新类型 */
  SXLCNetwork_ConnectionType_NewType = 999,
};

GPBEnumDescriptor *SXLCNetwork_ConnectionType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL SXLCNetwork_ConnectionType_IsValidValue(int32_t value);

#pragma mark - Enum SXLCNetwork_OperatorType

/** 移动运营商类型 */
typedef GPB_ENUM(SXLCNetwork_OperatorType) {
  /** 未知的运营商 */
  SXLCNetwork_OperatorType_UnknownOperator = 0,

  /** 中国移动 */
  SXLCNetwork_OperatorType_ChinaMobile = 1,

  /** 中国电信 */
  SXLCNetwork_OperatorType_ChinaTelecom = 2,

  /** 中国联通 */
  SXLCNetwork_OperatorType_ChinaUnicom = 3,

  /** 其他运营商 */
  SXLCNetwork_OperatorType_OtherOperator = 99,
};

GPBEnumDescriptor *SXLCNetwork_OperatorType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL SXLCNetwork_OperatorType_IsValidValue(int32_t value);

#pragma mark - Enum SXLCGps_CoordinateType

/** GPS坐标类型 */
typedef GPB_ENUM(SXLCGps_CoordinateType) {
  /** 全球卫星定位系统坐标系 */
  SXLCGps_CoordinateType_Wgs84 = 1,

  /** 国家测绘局坐标系 */
  SXLCGps_CoordinateType_Gcj02 = 2,

  /** 百度坐标系 */
  SXLCGps_CoordinateType_Bd09 = 3,
};

GPBEnumDescriptor *SXLCGps_CoordinateType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL SXLCGps_CoordinateType_IsValidValue(int32_t value);

#pragma mark - Enum SXLCVideo_CopyRight

typedef GPB_ENUM(SXLCVideo_CopyRight) {
  SXLCVideo_CopyRight_CrNone = 0,
  SXLCVideo_CopyRight_CrExist = 1,
  SXLCVideo_CopyRight_CrUgc = 2,
  SXLCVideo_CopyRight_CrOther = 3,
};

GPBEnumDescriptor *SXLCVideo_CopyRight_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL SXLCVideo_CopyRight_IsValidValue(int32_t value);

#pragma mark - Enum SXLCMaterialMeta_CreativeType

/** 创意类型 */
typedef GPB_ENUM(SXLCMaterialMeta_CreativeType) {
  /** 无创意类型，主要针对原生自定义素材广告，不再制定返回广告的创意类型，根据广告位设置对返回字段进行读取即可 */
  SXLCMaterialMeta_CreativeType_NoType = 0,

  /** 纯文字广告，一般由title、description构成 */
  SXLCMaterialMeta_CreativeType_Text = 1,

  /** 纯图片广告，一般由单张image_src构成 */
  SXLCMaterialMeta_CreativeType_Image = 2,

  /** 图文混合广告，一般由单张icon_src和title、description构成 */
  SXLCMaterialMeta_CreativeType_TextIcon = 3,

  /** 视频广告，一般由视频URL和视频时长构成 */
  SXLCMaterialMeta_CreativeType_Video = 4,

  /** 激励视频广告, 一般由视频URL/视频时长和一个落地页面构成. */
  SXLCMaterialMeta_CreativeType_VideoHtml = 9,
};

GPBEnumDescriptor *SXLCMaterialMeta_CreativeType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL SXLCMaterialMeta_CreativeType_IsValidValue(int32_t value);

#pragma mark - Enum SXLCMaterialMeta_InteractionType

/** 交互类型 */
typedef GPB_ENUM(SXLCMaterialMeta_InteractionType) {
  /** 无动作，即广告广告点击后无需进行任何响应 */
  SXLCMaterialMeta_InteractionType_NoInteraction = 0,

  /** 使用浏览器打开网页 */
  SXLCMaterialMeta_InteractionType_Surfing = 1,

  /** 下载应用 */
  SXLCMaterialMeta_InteractionType_Download = 2,

  /** 可选交互类型,针对app. 开发者可选择是打开详情页还是直接下载推广应用.需要开发者替换click_url中的宏$ACCT_TYPE}. 0表示打开详情页,35表示直接下载. */
  SXLCMaterialMeta_InteractionType_Optional = 9,
};

GPBEnumDescriptor *SXLCMaterialMeta_InteractionType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL SXLCMaterialMeta_InteractionType_IsValidValue(int32_t value);

#pragma mark - Enum SXLCTracking_TrackingEvent

/** 广告展示过程事件类型 */
typedef GPB_ENUM(SXLCTracking_TrackingEvent) {
  /** 广告展示过程共性事件 */
  SXLCTracking_TrackingEvent_AdClick = 0,

  /** 广告被展现 */
  SXLCTracking_TrackingEvent_AdExposure = 1,

  /** 广告被关闭 */
  SXLCTracking_TrackingEvent_AdClose = 2,

  /** 视频类广告展示过程事件 */
  SXLCTracking_TrackingEvent_VideoAdStart = 101000,

  /** 视频全屏 */
  SXLCTracking_TrackingEvent_VideoAdFullScreen = 101001,

  /** 视频播放结束(正常) */
  SXLCTracking_TrackingEvent_VideoAdEnd = 101002,

  /** 点击预览图播放视频 */
  SXLCTracking_TrackingEvent_VideoAdStartCardClick = 101003,

  /** 视频播放被中途关闭 */
  SXLCTracking_TrackingEvent_VideoAdClose = 101009,

  /** 下载类广告推广APP相关事件 */
  SXLCTracking_TrackingEvent_AppAdDownload = 102000,

  /** 安装推广APP */
  SXLCTracking_TrackingEvent_AppAdInstall = 102001,

  /** 激活推广APP */
  SXLCTracking_TrackingEvent_AppAdActive = 102002,

  /** 开始下载app */
  SXLCTracking_TrackingEvent_AppAdStartDownload = 102009,
};

GPBEnumDescriptor *SXLCTracking_TrackingEvent_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL SXLCTracking_TrackingEvent_IsValidValue(int32_t value);

#pragma mark - Enum SXLCAdStrategy_ChannelType

/** 渠道分类 */
typedef GPB_ENUM(SXLCAdStrategy_ChannelType) {
  SXLCAdStrategy_ChannelType_ChannelVung = 201,
  SXLCAdStrategy_ChannelType_ChannelUnit = 202,
  SXLCAdStrategy_ChannelType_ChannelKs = 203,
};

GPBEnumDescriptor *SXLCAdStrategy_ChannelType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL SXLCAdStrategy_ChannelType_IsValidValue(int32_t value);

#pragma mark - SXLCKsMobadsApi54Root

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
@interface SXLCKsMobadsApi54Root : GPBRootObject
@end

#pragma mark - SXLCMobadsRequest

typedef GPB_ENUM(SXLCMobadsRequest_FieldNumber) {
  SXLCMobadsRequest_FieldNumber_RequestId = 1,
  SXLCMobadsRequest_FieldNumber_ApiVersion = 2,
  SXLCMobadsRequest_FieldNumber_App = 3,
  SXLCMobadsRequest_FieldNumber_Device = 4,
  SXLCMobadsRequest_FieldNumber_Network = 5,
  SXLCMobadsRequest_FieldNumber_Gps = 6,
  SXLCMobadsRequest_FieldNumber_Adslot = 7,
  SXLCMobadsRequest_FieldNumber_IsDebug = 8,
  SXLCMobadsRequest_FieldNumber_RequestProtocolType = 9,
};

/**
 * API请求结构
 **/
@interface SXLCMobadsRequest : GPBMessage

/** 必填！接入方自定义请求ID，[a-zA-Z0-9]{32} */
@property(nonatomic, readwrite, copy, null_resettable) NSString *requestId;
/** Test to see if @c requestId has been set. */
@property(nonatomic, readwrite) BOOL hasRequestId;

/** 必填！API版本，按照当前接入所参照的API文档版本赋值，影响所有后续逻辑。填写错误会导致拒绝请求。 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCVersion *apiVersion;
/** Test to see if @c apiVersion has been set. */
@property(nonatomic, readwrite) BOOL hasApiVersion;

/** 必填！广告位信息 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCAdSlot *adslot;
/** Test to see if @c adslot has been set. */
@property(nonatomic, readwrite) BOOL hasAdslot;

/** 必填！应用信息 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCApp *app;
/** Test to see if @c app has been set. */
@property(nonatomic, readwrite) BOOL hasApp;

/** 必填！设备信息 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCDevice *device;
/** Test to see if @c device has been set. */
@property(nonatomic, readwrite) BOOL hasDevice;

/** 必填！网络环境信息 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCNetwork *network;
/** Test to see if @c network has been set. */
@property(nonatomic, readwrite) BOOL hasNetwork;

/** 选填！强烈建议填写，用于辅助触发LBS广告 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCGps *gps;
/** Test to see if @c gps has been set. */
@property(nonatomic, readwrite) BOOL hasGps;

/** 选填！测试流量标记，可获取广告，但不被计费，勿用于线上请求 */
@property(nonatomic, readwrite) BOOL isDebug;

@property(nonatomic, readwrite) BOOL hasIsDebug;
/** 选填, https媒体必填！ */
@property(nonatomic, readwrite) SXLCMobadsRequest_RequestProtocolType requestProtocolType;

@property(nonatomic, readwrite) BOOL hasRequestProtocolType;
@end

#pragma mark - SXLCVersion

typedef GPB_ENUM(SXLCVersion_FieldNumber) {
  SXLCVersion_FieldNumber_Major = 1,
  SXLCVersion_FieldNumber_Minor = 2,
  SXLCVersion_FieldNumber_Micro = 3,
};

/**
 * 版本号信息
 **/
@interface SXLCVersion : GPBMessage

/** 必填！ */
@property(nonatomic, readwrite) uint32_t major;

@property(nonatomic, readwrite) BOOL hasMajor;
/** 选填！ */
@property(nonatomic, readwrite) uint32_t minor;

@property(nonatomic, readwrite) BOOL hasMinor;
/** 选填！ */
@property(nonatomic, readwrite) uint32_t micro;

@property(nonatomic, readwrite) BOOL hasMicro;
@end

#pragma mark - SXLCApp

typedef GPB_ENUM(SXLCApp_FieldNumber) {
  SXLCApp_FieldNumber_AppId = 1,
  SXLCApp_FieldNumber_ChannelId = 2,
  SXLCApp_FieldNumber_AppVersion = 3,
  SXLCApp_FieldNumber_AppPackage = 4,
};

/**
 * 应用信息
 **/
@interface SXLCApp : GPBMessage

/** 必填！应用ID，在Mobile SSP（以下简称MSSP）完成注册，并上传应用通过审核后，平台会提供应用ID */
@property(nonatomic, readwrite, copy, null_resettable) NSString *appId;
/** Test to see if @c appId has been set. */
@property(nonatomic, readwrite) BOOL hasAppId;

/** 选填！发布渠道ID，渠道接入方必需填写。 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *channelId;
/** Test to see if @c channelId has been set. */
@property(nonatomic, readwrite) BOOL hasChannelId;

/** 必填！应用版本，将影响优选策略 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCVersion *appVersion;
/** Test to see if @c appVersion has been set. */
@property(nonatomic, readwrite) BOOL hasAppVersion;

/** 必填！应用包名，需要跟应用提交时一一对应，中文需要UTF-8编码 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *appPackage;
/** Test to see if @c appPackage has been set. */
@property(nonatomic, readwrite) BOOL hasAppPackage;

@end

#pragma mark - SXLCAdSlot

typedef GPB_ENUM(SXLCAdSlot_FieldNumber) {
  SXLCAdSlot_FieldNumber_AdslotId = 1,
  SXLCAdSlot_FieldNumber_AdslotSize = 2,
  SXLCAdSlot_FieldNumber_Video = 4,
  SXLCAdSlot_FieldNumber_AdslotType = 5,
  SXLCAdSlot_FieldNumber_Ads = 15,
};

/**
 * 广告位信息
 **/
@interface SXLCAdSlot : GPBMessage

/** 必填！广告位ID，需要媒体在MSSP平台进行设置！非常重要！ */
@property(nonatomic, readwrite, copy, null_resettable) NSString *adslotId;
/** Test to see if @c adslotId has been set. */
@property(nonatomic, readwrite) BOOL hasAdslotId;

/** 必填！广告位尺寸 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCSize *adslotSize;
/** Test to see if @c adslotSize has been set. */
@property(nonatomic, readwrite) BOOL hasAdslotSize;

/** 选填，但视频广告位必填！传递视频标题、时长、频道、版权等信息 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCVideo *video;
/** Test to see if @c video has been set. */
@property(nonatomic, readwrite) BOOL hasVideo;

/** 广告类型 */
@property(nonatomic, readwrite) uint32_t adslotType;

@property(nonatomic, readwrite) BOOL hasAdslotType;
/** 返回广告条数,目前仅支持信息流. */
@property(nonatomic, readwrite) uint32_t ads;

@property(nonatomic, readwrite) BOOL hasAds;
@end

#pragma mark - SXLCUdId

typedef GPB_ENUM(SXLCUdId_FieldNumber) {
  SXLCUdId_FieldNumber_Idfa = 1,
  SXLCUdId_FieldNumber_Imei = 2,
  SXLCUdId_FieldNumber_Mac = 3,
  SXLCUdId_FieldNumber_ImeiMd5 = 4,
  SXLCUdId_FieldNumber_AndroidId = 5,
  SXLCUdId_FieldNumber_IdfaMd5 = 8,
  SXLCUdId_FieldNumber_AndroididMd5 = 9,
};

/**
 * 唯一用户标识，优先使用明文，必需按要求填写，具体填写指导详见接口说明文档
 **/
@interface SXLCUdId : GPBMessage

/** 必填！iOS设备的IDFA，格式要求[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12} */
@property(nonatomic, readwrite, copy, null_resettable) NSString *idfa;
/** Test to see if @c idfa has been set. */
@property(nonatomic, readwrite) BOOL hasIdfa;

/** 必填！Android手机设备的IMEI，格式要求[0-9a-fA-F]{14,15} */
@property(nonatomic, readwrite, copy, null_resettable) NSString *imei;
/** Test to see if @c imei has been set. */
@property(nonatomic, readwrite) BOOL hasImei;

/** Android非手机设备的WiFi网卡MAC地址，格式要求[0-9a-fA-F]{2}:[0-9a-fA-F]{2}:[0-9a-fA-F]{2}:[0-9a-fA-F]{2}:[0-9a-fA-F]{2}:[0-9a-fA-F]{2} */
@property(nonatomic, readwrite, copy, null_resettable) NSString *mac;
/** Test to see if @c mac has been set. */
@property(nonatomic, readwrite) BOOL hasMac;

/** 必填！Android手机设备系统ID，格式要求[0-9A-Za-z]{16} */
@property(nonatomic, readwrite, copy, null_resettable) NSString *androidId;
/** Test to see if @c androidId has been set. */
@property(nonatomic, readwrite) BOOL hasAndroidId;

/** iOS设备的IDFA，经过MD5加密，格式要求[0-9A-Za-z]{32} */
@property(nonatomic, readwrite, copy, null_resettable) NSString *idfaMd5;
/** Test to see if @c idfaMd5 has been set. */
@property(nonatomic, readwrite) BOOL hasIdfaMd5;

/** Android手机设备的IMEI，经过MD5加密，格式要求[0-9A-Za-z]{32} */
@property(nonatomic, readwrite, copy, null_resettable) NSString *imeiMd5;
/** Test to see if @c imeiMd5 has been set. */
@property(nonatomic, readwrite) BOOL hasImeiMd5;

/** Android手机设备系统ID，经过MD5加密，格式要求[0-9A-Za-z]{32} */
@property(nonatomic, readwrite, copy, null_resettable) NSString *androididMd5;
/** Test to see if @c androididMd5 has been set. */
@property(nonatomic, readwrite) BOOL hasAndroididMd5;

@end

#pragma mark - SXLCSize

typedef GPB_ENUM(SXLCSize_FieldNumber) {
  SXLCSize_FieldNumber_Width = 1,
  SXLCSize_FieldNumber_Height = 2,
};

/**
 * 二维尺寸信息
 **/
@interface SXLCSize : GPBMessage

/** 必填！宽度 */
@property(nonatomic, readwrite) uint32_t width;

@property(nonatomic, readwrite) BOOL hasWidth;
/** 必填！高度 */
@property(nonatomic, readwrite) uint32_t height;

@property(nonatomic, readwrite) BOOL hasHeight;
@end

#pragma mark - SXLCDevice

typedef GPB_ENUM(SXLCDevice_FieldNumber) {
  SXLCDevice_FieldNumber_DeviceType = 1,
  SXLCDevice_FieldNumber_OsType = 2,
  SXLCDevice_FieldNumber_OsVersion = 3,
  SXLCDevice_FieldNumber_Vendor = 4,
  SXLCDevice_FieldNumber_Model = 5,
  SXLCDevice_FieldNumber_Udid = 6,
  SXLCDevice_FieldNumber_ScreenSize = 7,
};

/**
 * 设备信息
 **/
@interface SXLCDevice : GPBMessage

/** 必填！设备类型 */
@property(nonatomic, readwrite) SXLCDevice_DeviceType deviceType;

@property(nonatomic, readwrite) BOOL hasDeviceType;
/** 必填！操作系统类型 */
@property(nonatomic, readwrite) SXLCDevice_OsType osType;

@property(nonatomic, readwrite) BOOL hasOsType;
/** 必填！操作系统版本 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCVersion *osVersion;
/** Test to see if @c osVersion has been set. */
@property(nonatomic, readwrite) BOOL hasOsVersion;

/** 必填！设备厂商名称，中文需要UTF-8编码 */
@property(nonatomic, readwrite, copy, null_resettable) NSData *vendor;
/** Test to see if @c vendor has been set. */
@property(nonatomic, readwrite) BOOL hasVendor;

/** 必填！设备型号，中文需要UTF-8编码 */
@property(nonatomic, readwrite, copy, null_resettable) NSData *model;
/** Test to see if @c model has been set. */
@property(nonatomic, readwrite) BOOL hasModel;

/** 必填！唯一设备标识，必需按要求填写 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCUdId *udid;
/** Test to see if @c udid has been set. */
@property(nonatomic, readwrite) BOOL hasUdid;

/** 必填！设备屏幕宽高 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCSize *screenSize;
/** Test to see if @c screenSize has been set. */
@property(nonatomic, readwrite) BOOL hasScreenSize;

@end

#pragma mark - SXLCNetwork

typedef GPB_ENUM(SXLCNetwork_FieldNumber) {
  SXLCNetwork_FieldNumber_Ipv4 = 1,
  SXLCNetwork_FieldNumber_ConnectionType = 2,
  SXLCNetwork_FieldNumber_OperatorType = 3,
  SXLCNetwork_FieldNumber_CellularId = 4,
  SXLCNetwork_FieldNumber_WifiApsArray = 5,
};

/**
 * 网络环境信息
 **/
@interface SXLCNetwork : GPBMessage

/** 必填！用户设备的公网IPv4地址，服务器对接必填，格式要求：255.255.255.255 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *ipv4;
/** Test to see if @c ipv4 has been set. */
@property(nonatomic, readwrite) BOOL hasIpv4;

/** 必填！网络连接类型，用于判断网速 */
@property(nonatomic, readwrite) SXLCNetwork_ConnectionType connectionType;

@property(nonatomic, readwrite) BOOL hasConnectionType;
/** 必填！移动运营商类型，用于运营商定向广告 */
@property(nonatomic, readwrite) SXLCNetwork_OperatorType operatorType;

@property(nonatomic, readwrite) BOOL hasOperatorType;
/** 选填！当前连接的运营商基站ID，用于快速用户定位 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *cellularId;
/** Test to see if @c cellularId has been set. */
@property(nonatomic, readwrite) BOOL hasCellularId;

/** 选填！周边WiFi热点列表，用于精细用户定位 */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SXLCWiFiAp*> *wifiApsArray;
/** The number of items in @c wifiApsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger wifiApsArray_Count;

@end

#pragma mark - SXLCWiFiAp

typedef GPB_ENUM(SXLCWiFiAp_FieldNumber) {
  SXLCWiFiAp_FieldNumber_ApMac = 1,
  SXLCWiFiAp_FieldNumber_Rssi = 2,
  SXLCWiFiAp_FieldNumber_ApName = 3,
  SXLCWiFiAp_FieldNumber_IsConnected = 4,
};

/**
 * WiFi热点信息
 **/
@interface SXLCWiFiAp : GPBMessage

/** 必填！热点MAC地址，格式要求[0-9a-fA-F]{2}:[0-9a-fA-F]{2}:[0-9a-fA-F]{2}:[0-9a-fA-F]{2}:[0-9a-fA-F]{2}:[0-9a-fA-F]{2} */
@property(nonatomic, readwrite, copy, null_resettable) NSString *apMac;
/** Test to see if @c apMac has been set. */
@property(nonatomic, readwrite) BOOL hasApMac;

/** 必填！热点信号强度，通常是负数 */
@property(nonatomic, readwrite) int32_t rssi;

@property(nonatomic, readwrite) BOOL hasRssi;
/** 必填！热点名称，可不传递，建议传递当前接入热点的名称，用于判断用户当前所处场所，中文需要UTF-8编码 */
@property(nonatomic, readwrite, copy, null_resettable) NSData *apName;
/** Test to see if @c apName has been set. */
@property(nonatomic, readwrite) BOOL hasApName;

/** 必填！是否是当前连接热点，配合热点名称可用于识别用户所处场所 */
@property(nonatomic, readwrite) BOOL isConnected;

@property(nonatomic, readwrite) BOOL hasIsConnected;
@end

#pragma mark - SXLCGps

typedef GPB_ENUM(SXLCGps_FieldNumber) {
  SXLCGps_FieldNumber_CoordinateType = 1,
  SXLCGps_FieldNumber_Longitude = 2,
  SXLCGps_FieldNumber_Latitude = 3,
  SXLCGps_FieldNumber_Timestamp = 4,
};

/**
 * GPS信息
 **/
@interface SXLCGps : GPBMessage

/** 必填！坐标类型 */
@property(nonatomic, readwrite) SXLCGps_CoordinateType coordinateType;

@property(nonatomic, readwrite) BOOL hasCoordinateType;
/** 必填！经度 */
@property(nonatomic, readwrite) double longitude;

@property(nonatomic, readwrite) BOOL hasLongitude;
/** 必填！纬度 */
@property(nonatomic, readwrite) double latitude;

@property(nonatomic, readwrite) BOOL hasLatitude;
/** 必填！时间戳，单位秒 */
@property(nonatomic, readwrite) uint32_t timestamp;

@property(nonatomic, readwrite) BOOL hasTimestamp;
@end

#pragma mark - SXLCVideo

typedef GPB_ENUM(SXLCVideo_FieldNumber) {
  SXLCVideo_FieldNumber_Title = 1,
  SXLCVideo_FieldNumber_ContentLength = 2,
  SXLCVideo_FieldNumber_Copyright = 3,
};

@interface SXLCVideo : GPBMessage

/** 视频标题，UTF-8编码 */
@property(nonatomic, readwrite, copy, null_resettable) NSData *title;
/** Test to see if @c title has been set. */
@property(nonatomic, readwrite) BOOL hasTitle;

/** 视频内容长度 */
@property(nonatomic, readwrite) uint32_t contentLength;

@property(nonatomic, readwrite) BOOL hasContentLength;
/** 视频版权信息 */
@property(nonatomic, readwrite) SXLCVideo_CopyRight copyright;

@property(nonatomic, readwrite) BOOL hasCopyright;
@end

#pragma mark - SXLCMobadsResponse

typedef GPB_ENUM(SXLCMobadsResponse_FieldNumber) {
  SXLCMobadsResponse_FieldNumber_RequestId = 1,
  SXLCMobadsResponse_FieldNumber_ErrorCode = 2,
  SXLCMobadsResponse_FieldNumber_AdsArray = 3,
  SXLCMobadsResponse_FieldNumber_ExpirationTime = 4,
  SXLCMobadsResponse_FieldNumber_SearchKey = 5,
  SXLCMobadsResponse_FieldNumber_AutomaticPro = 6,
  SXLCMobadsResponse_FieldNumber_AdStrategyArray = 7,
  SXLCMobadsResponse_FieldNumber_RequestTimeS = 15,
};

/**
 * 广告应答结构
 **/
@interface SXLCMobadsResponse : GPBMessage

/** 对应请求的接入方自定义请求ID */
@property(nonatomic, readwrite, copy, null_resettable) NSString *requestId;
/** Test to see if @c requestId has been set. */
@property(nonatomic, readwrite) BOOL hasRequestId;

/** 请求响应出错时的错误码，用于问题排查 */
@property(nonatomic, readwrite) uint64_t errorCode;

@property(nonatomic, readwrite) BOOL hasErrorCode;
/** 应答广告清单，一次请求可以返回多个广告，需要逐个解析 */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SXLCAd*> *adsArray;
/** The number of items in @c adsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger adsArray_Count;

/** 广告清单过期时间戳，单位秒 */
@property(nonatomic, readwrite) uint32_t expirationTime;

@property(nonatomic, readwrite) BOOL hasExpirationTime;
/** 当次请求内部生成的唯一表示ID */
@property(nonatomic, readwrite, copy, null_resettable) NSString *searchKey;
/** Test to see if @c searchKey has been set. */
@property(nonatomic, readwrite) BOOL hasSearchKey;

/** 是否已自动优化广告. */
@property(nonatomic, readwrite) BOOL automaticPro;

@property(nonatomic, readwrite) BOOL hasAutomaticPro;
/** 如果已开启自动优化, 忽略该字段. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SXLCAdStrategy*> *adStrategyArray;
/** The number of items in @c adStrategyArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger adStrategyArray_Count;

/** 请求处理耗时 */
@property(nonatomic, readwrite) double requestTimeS;

@property(nonatomic, readwrite) BOOL hasRequestTimeS;
@end

#pragma mark - SXLCMetaIndex

typedef GPB_ENUM(SXLCMetaIndex_FieldNumber) {
  SXLCMetaIndex_FieldNumber_TotalNum = 1,
  SXLCMetaIndex_FieldNumber_CurrentIndex = 2,
};

/**
 * 广告元数据组索引结构
 * 一条广告可能包含多个物料元信息,我们统称这些元信息为广告元数据组
 * 返回广告时，total_num表明当前广告包含的物料元数据个数，current_index表明当前的物料元数据在元数据组中的索引
 * 请求多个广告返回时，ad_key唯一标识一个广告元数据组(一个广告)，MetaIndex标识一个元数据组中的每个元数据信息
 **/
@interface SXLCMetaIndex : GPBMessage

/** 每条广告对应元素组中元数据个数 */
@property(nonatomic, readwrite) uint32_t totalNum;

@property(nonatomic, readwrite) BOOL hasTotalNum;
/** 当前元数据所在索引 */
@property(nonatomic, readwrite) uint32_t currentIndex;

@property(nonatomic, readwrite) BOOL hasCurrentIndex;
@end

#pragma mark - SXLCAd

typedef GPB_ENUM(SXLCAd_FieldNumber) {
  SXLCAd_FieldNumber_AdslotId = 1,
  SXLCAd_FieldNumber_HtmlSnippet = 2,
  SXLCAd_FieldNumber_AdKey = 4,
  SXLCAd_FieldNumber_AdTrackingArray = 5,
  SXLCAd_FieldNumber_MetaGroupArray = 6,
  SXLCAd_FieldNumber_MobAdtext = 7,
  SXLCAd_FieldNumber_MobAdlogo = 8,
  SXLCAd_FieldNumber_Vid = 15,
};

/**
 * 广告信息
 **/
@interface SXLCAd : GPBMessage

/** 对应请求时填写的广告位ID */
@property(nonatomic, readwrite, copy, null_resettable) NSString *adslotId;
/** Test to see if @c adslotId has been set. */
@property(nonatomic, readwrite) BOOL hasAdslotId;

/** 对当前返回广告的签名，可以唯一标识广告 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *adKey;
/** Test to see if @c adKey has been set. */
@property(nonatomic, readwrite) BOOL hasAdKey;

/** 物料元数据组信息 */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SXLCMaterialMeta*> *metaGroupArray;
/** The number of items in @c metaGroupArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger metaGroupArray_Count;

/** HTML片段，中文需要UTF-8编码. 激励视频广告时,存放落地页面模板H5代码. */
@property(nonatomic, readwrite, copy, null_resettable) NSData *htmlSnippet;
/** Test to see if @c htmlSnippet has been set. */
@property(nonatomic, readwrite) BOOL hasHtmlSnippet;

/** 广告监控信息 */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SXLCTracking*> *adTrackingArray;
/** The number of items in @c adTrackingArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger adTrackingArray_Count;

/** 20160901新广告法出台，要求明确使用"广告"，该字段为"广告"小图标地址，媒体需要在渲染的时候添加 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *mobAdtext;
/** Test to see if @c mobAdtext has been set. */
@property(nonatomic, readwrite) BOOL hasMobAdtext;

/** 20160901新广告法出台，该字段为与上述字段配合使用的"logo"图标地址，媒体需要在渲染的时候添加 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *mobAdlogo;
/** Test to see if @c mobAdlogo has been set. */
@property(nonatomic, readwrite) BOOL hasMobAdlogo;

/** 广告曝光唯一标识 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *vid;
/** Test to see if @c vid has been set. */
@property(nonatomic, readwrite) BOOL hasVid;

@end

#pragma mark - SXLCMaterialMeta

typedef GPB_ENUM(SXLCMaterialMeta_FieldNumber) {
  SXLCMaterialMeta_FieldNumber_CreativeType = 1,
  SXLCMaterialMeta_FieldNumber_InteractionType = 2,
  SXLCMaterialMeta_FieldNumber_WinNoticeURLArray = 3,
  SXLCMaterialMeta_FieldNumber_ClickURL = 4,
  SXLCMaterialMeta_FieldNumber_Title = 5,
  SXLCMaterialMeta_FieldNumber_DescriptionArray = 6,
  SXLCMaterialMeta_FieldNumber_IconSrcArray = 7,
  SXLCMaterialMeta_FieldNumber_ImageSrcArray = 8,
  SXLCMaterialMeta_FieldNumber_AppPackage = 9,
  SXLCMaterialMeta_FieldNumber_AppSize = 10,
  SXLCMaterialMeta_FieldNumber_VideoURL = 11,
  SXLCMaterialMeta_FieldNumber_VideoDuration = 12,
  SXLCMaterialMeta_FieldNumber_MetaIndex = 13,
  SXLCMaterialMeta_FieldNumber_MaterialWidth = 14,
  SXLCMaterialMeta_FieldNumber_MaterialHeight = 15,
  SXLCMaterialMeta_FieldNumber_BrandName = 16,
};

/**
 * 广告物料元数据信息
 **/
@interface SXLCMaterialMeta : GPBMessage

/** 创意类型 */
@property(nonatomic, readwrite) SXLCMaterialMeta_CreativeType creativeType;

@property(nonatomic, readwrite) BOOL hasCreativeType;
/** 交互类型 */
@property(nonatomic, readwrite) SXLCMaterialMeta_InteractionType interactionType;

@property(nonatomic, readwrite) BOOL hasInteractionType;
/** 曝光日志URL列表，在曝光后必须在客户端逐个汇报完 */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *winNoticeURLArray;
/** The number of items in @c winNoticeURLArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger winNoticeURLArray_Count;

/** 点击行为地址，用户点击后，在客户端进行响应，会经过多次302跳转最终到达目标地址 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *clickURL;
/** Test to see if @c clickURL has been set. */
@property(nonatomic, readwrite) BOOL hasClickURL;

/** 推广标题，中文需要UTF-8编码 */
@property(nonatomic, readwrite, copy, null_resettable) NSData *title;
/** Test to see if @c title has been set. */
@property(nonatomic, readwrite) BOOL hasTitle;

/** 广告品牌名称，下载类则为app名称（如“手机百度”），非下载类则为品牌名称（如“小米”） */
@property(nonatomic, readwrite, copy, null_resettable) NSString *brandName;
/** Test to see if @c brandName has been set. */
@property(nonatomic, readwrite) BOOL hasBrandName;

/** 广告描述，默认只有一个元素，暂时约定最多只有两个元素，具体情况已线上广告实际返回结果为准，中文需要UTF-8编码 */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSData*> *descriptionArray;
/** The number of items in @c descriptionArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger descriptionArray_Count;

/** 广告图标地址，注意：单个广告可能有多张图标返回 */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *iconSrcArray;
/** The number of items in @c iconSrcArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger iconSrcArray_Count;

/** 广告图片地址，注意：单个广告可能有多张图片返回 */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *imageSrcArray;
/** The number of items in @c imageSrcArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger imageSrcArray_Count;

/** 下载类广告应用包名 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *appPackage;
/** Test to see if @c appPackage has been set. */
@property(nonatomic, readwrite) BOOL hasAppPackage;

/** 下载类广告应用大小 */
@property(nonatomic, readwrite) uint32_t appSize;

@property(nonatomic, readwrite) BOOL hasAppSize;
/** 广告视频物料地址 */
@property(nonatomic, readwrite, copy, null_resettable) NSString *videoURL;
/** Test to see if @c videoURL has been set. */
@property(nonatomic, readwrite) BOOL hasVideoURL;

/** 广告视频物料时长 */
@property(nonatomic, readwrite) uint32_t videoDuration;

@property(nonatomic, readwrite) BOOL hasVideoDuration;
/** 当前元数据在一条广告元素组中的索引结构 */
@property(nonatomic, readwrite, strong, null_resettable) SXLCMetaIndex *metaIndex;
/** Test to see if @c metaIndex has been set. */
@property(nonatomic, readwrite) BOOL hasMetaIndex;

/** 物料的宽度:如果是图片,表示图片的宽度;如果是视频(含有视频截图),则为视频宽度;如果是图文或文本,则不会填充此字段 */
@property(nonatomic, readwrite) uint32_t materialWidth;

@property(nonatomic, readwrite) BOOL hasMaterialWidth;
/** 物料的高度:如果是图片,表示图片的高度;如果是视频(含有视频截图),则为视频高度;如果是图文或文本,则不会填充此字段 */
@property(nonatomic, readwrite) uint32_t materialHeight;

@property(nonatomic, readwrite) BOOL hasMaterialHeight;
@end

#pragma mark - SXLCTracking

typedef GPB_ENUM(SXLCTracking_FieldNumber) {
  SXLCTracking_FieldNumber_TrackingEvent = 1,
  SXLCTracking_FieldNumber_TrackingURLArray = 2,
};

/**
 * 广告效果跟踪信息
 **/
@interface SXLCTracking : GPBMessage

/** 被跟踪的广告展示过程事件 */
@property(nonatomic, readwrite) SXLCTracking_TrackingEvent trackingEvent;

@property(nonatomic, readwrite) BOOL hasTrackingEvent;
/** 事件监控URL */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *trackingURLArray;
/** The number of items in @c trackingURLArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger trackingURLArray_Count;

@end

#pragma mark - SXLCAdStrategy

typedef GPB_ENUM(SXLCAdStrategy_FieldNumber) {
  SXLCAdStrategy_FieldNumber_AppId = 1,
  SXLCAdStrategy_FieldNumber_AdslotId = 2,
  SXLCAdStrategy_FieldNumber_ChannelType = 3,
  SXLCAdStrategy_FieldNumber_Weight = 4,
};

/**
 * 广告策略配比
 **/
@interface SXLCAdStrategy : GPBMessage

@property(nonatomic, readwrite, copy, null_resettable) NSString *appId;
/** Test to see if @c appId has been set. */
@property(nonatomic, readwrite) BOOL hasAppId;

@property(nonatomic, readwrite, copy, null_resettable) NSString *adslotId;
/** Test to see if @c adslotId has been set. */
@property(nonatomic, readwrite) BOOL hasAdslotId;

/** 渠道分类 */
@property(nonatomic, readwrite) SXLCAdStrategy_ChannelType channelType;

@property(nonatomic, readwrite) BOOL hasChannelType;
/** 权重比.取值范围[1,10] */
@property(nonatomic, readwrite) uint32_t weight;

@property(nonatomic, readwrite) BOOL hasWeight;
@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
