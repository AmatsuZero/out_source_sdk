//
//  Constants.h
//  SDK
//
//  Created by 姜振华 on 2016/12/26.
//  Copyright © 2016年 姜振华. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

typedef NS_ENUM(NSInteger, SXAdvertiseErrorCode) {
    SXAdvertiseConfigurationRequestFailed   = -90001,//请求配比配置参数失败
    SXAdvertiseAutoOptimazationRequestFail  = -90002,//请求自动优化配比失败
    SXAdvertiseSDKInitFailed                =       -900004, //SDK初始化失败
    SXAdvertiseSDKPlayFailed                =       -900005,//播放失败
    SXAdvertiseNoConfiguration              =       -900006,//没有配比文件
    SXAdvertiseNoCaheData                   =       -900007,//广告缓存失败
    SXAdvertiseSystemError
};

typedef NS_ENUM(NSUInteger, SXAdClosedStatus) {
    SXAdForceClose, // 用户强制关闭
    SXAdNaturalClose // 广告播放结束或点击下载推广应用后关闭
};

typedef NS_ENUM(NSUInteger, SXRewardVideoAdCacheStatus) {
    SXRewardVideoAdCacheStatusNoAdData,     // 无广告
    SXRewardVideoAdCacheStatusNoVideo,      // 有广告数据无视频缓存(调用displayAd:将使用流媒体播放)
    SXRewardVideoAdCacheStatusCacheFinished // 有视频广告
};

#endif /* Constants_h */
