//
//  SXUMobAdCommonConfig.h
//  SXUMobAdSdk
//
//  Created by Henray Luo on 2016/12/19.
//  Copyright © 2016年 Henray Luo. All rights reserved.
//
#import <UIKit/UIKit.h>
#ifndef SXUMobAdSdk_SXUMobAdCommonConfig_h
#define SXUMobAdSdk_SXUMobAdCommonConfig_h

#ifdef DEBUG
#define NSLog(format, ...) printf("\n[%s] %s [第%d行]:\n%s\n", __TIME__, __FUNCTION__, __LINE__, [[NSString stringWithFormat:format, ## __VA_ARGS__] UTF8String]);
#else
#define NSLog(format, ...)
#endif

/**
 *  广告展示失败类型枚举
 */
typedef enum _NetServiceFailError {
    
    SXUMobAdFialError_ParaseError           = 0, // 解析返回数据错误
    SXUMobAdFialError_ParamError            = 1, // 请求参数数据错误,参照下面错误枚举值
    SXUMobAdFialError_NetworkError          = 2, // 网络错误
    
} SXUMobAdFialError;

//========================API 错误码对照表========================

/*
 * 1 前言
 *错误码对照表文件作为对 API 接口的补充说明，在 API 接口升级后，会不定期更新维护。
 *每个错误码对应 的处理方法均为引导性建议，对于具体的错误需要相关技术人员根据具体情况来处理。
 *对文档中未说明的内容，请咨询椰子传媒商务同学。
 */

typedef enum _SXUModAdAPIFailCode {
    // 2 无错误响应
    NO_ERROR                                = 0, //请求响应无误，返回广告
    
    // 3 请求信息错误
    
    // 3.1 请求 ID 信息错误
    ERROR_FORMAT_REQUEST                    = 100000, //请求格式错误
    MISSING_REQUEST_ID                      = 101000, //请求 ID 信息缺失
    ERROR_FORMAT_REQUEST_ID                 =  101001, //请求 ID 不符合约定格式

    // 3.2 API 版本信息错误
    MISSING_API_VERSION                     = 102000, //使用 API 版本信息缺失
    MISSING_API_VERSION_MAJOR               = 102010, //API 主版本信息缺失
    ERROR_API_VERSION                       = 102011, //API 版本信息错误
    
    // 3.3 应用信息错误
    MISSING_APP_INFO                        = 103000, //应用信息缺失
    MISSING_APP_ID                          = 103010, //应用 ID 信息缺失
    ERROR_APP_ID                            = 103011, //应用 ID 信息错误，MSSP 未收录
    DISABLED_APP_ID                         = 103012, //应用 ID 无效，MSSP 上未生效
    ERROR_CHANNEL_ID                        = 103020, //渠道 ID 信息错误
    MISSING_APP_VERSION                     = 103030, //应用版本信息缺失
    MISSING_APP_VERSION_MAJOR               = 103040, //应用主版本信息缺失
    OS_MIX                                  = 103050, //os 混用
    
    // 3.4 设备信息错误
    MISSING_DEVICE_INFO                     = 104000, //设备信息缺失
    MISSING_DEVICE_TYPE                     = 104010, //设备类型信息缺失
    ERROR_DEVICE_TYPE                       = 104011, //设备类型信息错误
    MISSING_OS_TYPE                         = 104020, //操作系统信息缺失
    ERROR_OS_TYPE                           = 104021, //操作系统信息错误
    MISSING_OS_VERSION                      = 104030, //操作系统版本信息缺失
    MISSING_OS_VERSION_MAJOR                = 104040, //操作系统主版本信息缺失
    MISSING_VENDOR                          = 104050, //厂商信息缺失
    MISSING_MODEL                           = 104060, //设备型号信息缺失
    MISSING_UDID                            = 104070, //设备唯一标识符缺失
    ERROR_UDID                              = 104071, //设备唯一标识符错误
    MISSING_ANDROID_ID                      = 104080, //android id 缺失
    ERROR_FORMAT_ANDROID_ID                 = 104081, //android id 格式错误
    MISSING_SCREEN_SIZE                     = 104090, //设备屏幕尺寸信息缺失
    MISSING_SCREEN_SIZE_WIDTH               = 104100, //设备屏幕尺寸宽度缺失
    MISSING_SCREEN_SIZE_HEIGHT              = 104110, //设备屏幕尺寸高度缺失
    
    // 3.5 网络环境信息错误
    MISSING_NETWORK_INFO                    = 105000, // 网络环境信息缺失
    MISSING_IPV4                            = 105010, // 网络地址信息缺失
    ERROR_FORMAT_IPV4                       = 105011, // 网络地址信息格式错误
    MISSING_CONNECTION_TYPE                 = 105020, // 网络连接类型缺失
    ERROR_CONNECTION_TYPE                   = 105021, // 网络连接类型错误
    MISSING_OPERATOR_TYPE                   = 105030, // 网络运营商类型缺失
    ERROR_OPERATOR_TYPE                     = 105031, // 网络运营商类型错误
    MISSING_AP_MAC                          = 105040, // Wi-Fi 热点地址信息缺失
    ERROR_FORMAT_AP_MAC                     = 105041, // Wi-Fi 热点地址信息格式错误
    MISSING_RSSI                            = 105050, // Wi-Fi 热点信号强度信息缺失
    MISSING_AP_NAME                         = 105060, // Wi-Fi 热点名称缺失
    MISSING_AP_CONNECTION                   = 105070, // Wi-Fi 连接状态信息缺失
    
    // 3.6 GPS 坐标信息错误
    MISSING_COORDINATE_TYPE                 = 106000, //坐标类型信息缺失
    ERROR_COORDINATE_TYPE                   = 106001, //坐标类型信息错误
    MISSING_LONGITUDE                       = 106010, //经度信息缺失
    MISSING_LATITUDE                        = 106020, //纬度信息缺失
    MISSING_GPS_TIMESTAMP                   = 106030, //定位时间戳信息缺失
    
    // 3.7 广告位信息错误
    MISSING_ADSLOT_ID                       = 107000, // 广告位 ID 缺失
    ERROR_ADSLOT_ID                         = 107001, // 广告位 ID 未收录
    DISABLED_ADSLOT_ID                      = 107002, // 广告位 ID 未启用
    NOT_MATCH_ADSLOT_ID                     = 107003, // 广告位 ID 与应用 ID 不匹配
    MISSING_ADSLOT_SIZE                     = 107010, // 广告位尺寸信息缺失
    MISSING_ADSLOT_SIZE_WIDTH               = 107020, // 广告位尺寸宽度缺失
    MISSING_ADSLOT_SIZE_HEIGHT              = 107030, // 广告位尺寸高度缺失
    MISSING_ADSLOT                          = 107040, // 广告位信息缺失
    ERROR_ADSLOT_MUN                        = 100311, // 请求广告位数量不合法
    ERROR_ADSLOT_SIZE                       = 100125, // 广告位尺寸无法匹配对应广告位规格
    
    // 4 响应信息错误
    
    // 4.1 广告请求
    NO_AD                                   = 200000, // 无广告返回
    AD_NO_DATA                              = 201000, // 广告无数据
    AD_NO_SIGN                              = 201010, // 广告无签名
    MISSING_CRETIVE_TYPE                    = 201020, // 广告创意类型信息丢失
    ERROR_CRETIVE_TYPE                      = 201021, // 广告创意类型信息无法识别
    MISSING_INTERATION_TYPE                 = 201030, // 广告动作类型信息丢失
    ERROR_INTERATION_TYPE                   = 201031, // 广告动作类型信息无法识别
    MISSING_WIN_NOTICE_URL                  = 201040, // 曝光汇报地址丢失
    MISSING_CLICK_URL                       = 201050, // 点击响应地址丢失
    MISSING_TITLE                           = 201060, // 推广标题丢失
    MISSING_DESCRIPTION                     = 201070, // 推广描述丢失
    MISSING_APP_PACKAGE                     = 201080, // 推广应用包名丢失
    MISSING_APP_SIZE                        = 201090, // 推广应用包大小丢失
    MISSING_ICON_SRC                        = 201100, // 推广图标丢失
    MISSING_IMAGE_SRC                       = 201110, // 推广图片丢失
    
} SXUModAdAPIFailCode;

#endif
