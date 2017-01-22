//
//  KSCRewardVideoAd.h
//  KSCAdvertiseSDK
//
//  Created by zcl_kingsoft on 16/8/18.
//  Copyright © 2016年 zcl_kingsoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString * const KSCAdvertiseErrorDomain;
FOUNDATION_EXTERN NSString * const KSCAdvertiseErrorKey;

typedef NS_ENUM(NSInteger, KSCAdvertiseErrorCode) {
    KSCAdvertiseCacheFailed                 =       -300001, //缓存广告失败，将尝试使用流媒体播放
    KSCAdvertiseRequestFailed               =       -300002, //请求广告失败，将无法播放视频广告，需重新初始化以请求广告
    KSCAdvertiseParameterInvalid            =       -300003, //参数初始化失败，无法播放
    KSCAdvertisePlayerInitFailed            =       -300004, //播放器初始化失败，无法播放
    KSCAdvertiseResponseParameterFailed     =       -300005  //请求广告返回参数有问题，需重新初始化以请求广告
};

typedef NS_ENUM(NSUInteger, KSCAdClosedStatus) {
    KSCAdForceClose, // 用户强制关闭
    KSCAdNaturalClose // 广告播放结束或点击下载推广应用后关闭
};

typedef NS_ENUM(NSUInteger, KSCRewardVideoAdCacheStatus) {
    KSCRewardVideoAdCacheStatusNoAdData,     // 无广告
    KSCRewardVideoAdCacheStatusNoVideo,      // 有广告数据无视频缓存(调用displayAd:将使用流媒体播放)
    KSCRewardVideoAdCacheStatusCacheFinished // 有视频广告
};

@protocol KSCRewardVideoAdDelegate <NSObject>

/**
 *  @brief 广告缓存状态回调
 *  @discuss isFinished 返回YES时，才可调用-displayAd:error:
 *
 *  @param isFinished   缓存状态
 *  @param error        错误原因
 */
- (void)adInitComplete:(BOOL)isFinished error:(nullable NSError *)error;

/**
 *  广告视频将要播放
 */
- (void)adVideoWillDisplayed;

/**
 *  @brief 广告视频关闭
 *  @discuss 用户取消观看或播放完成都会调用该方法
 *
 *  @param durationTimes 广告播放时长,单位毫秒
 *  @param status        关闭方式：强制关闭/广告播放后自动关闭
 */
- (void)adVideoWillClosed:(NSTimeInterval)durationTimes closeStatus:(KSCAdClosedStatus)status;

/**
 *  广告落地页展示
 */
- (void)adPictureWillShowed;

/**
 *  广告落地页关闭
 *
 *  @param status 关闭方式：强制关闭/点击下载推广应用后关闭
 */
- (void)adPictureWillClosed:(KSCAdClosedStatus)status;

@end

@interface KSCRewardVideoAd : NSObject

/**
 *  返回单例对象
 */
+ (instancetype)sharedInstance;

/**
 *  初始化SDK
 *
 *  @param appId          应用ID
 *  @param adslotId       广告位ID
 *  @param delegate       KSCRewardVideoAdDelegate 回调对象
 */
- (void)startWithAppId:(NSString *)appId adslotId:(NSString *)adslotId delegate:(id <KSCRewardVideoAdDelegate>)delegate;

/**
 *  播放广告
 *
 *  @param rootViewController 父控制器
 */
- (void)displayAd:(UIViewController *)rootViewController;

/**
 *  配置开发环境
 *
 *  @param isDebug  YES:测试环境    NO:线上环境
 *  该字段影响统计数据，默认为测试环境。上线前务必修改为线上环境
 */
- (void)configEnvironment:(BOOL)isDebug;

/**
 *  SDK版本号
 */
- (NSString *)version;

/**
 *  广告缓存状态
 */
- (KSCRewardVideoAdCacheStatus)AdCacheStatus;

@end
NS_ASSUME_NONNULL_END
