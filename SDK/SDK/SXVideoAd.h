//
//  SXVideoAd.h
//  SDK
//
//  Created by 姜振华 on 2016/12/26.
//  Copyright © 2016年 姜振华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SXRewardVideoAdDelegate.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString * const SXAdvertiseErrorDomain;
FOUNDATION_EXTERN NSString * const SXAdvertiseErrorKey;

@interface SXVideoAd : NSObject

/**
 *  返回单例对象
 */
+ (instancetype)sharedInstance;
/**
 如果初始化时没有设置代理，可以在这里设置

 @param delegate 代理对象
 */
-(void)setDelegate:(id <SXRewardVideoAdDelegate>)delegate;

/**
 *  初始化SDK
 *
 *  @param appId          应用ID
 *  @param adslotId       广告位ID
 *  @param delegate       回调对象
 */
- (void)startWithAppId:(nonnull NSString *)appId adslotId:(nonnull NSString *)adslotId delegate:(nullable id <SXRewardVideoAdDelegate>)delegate enableOptimazation:(BOOL)enableOptimazation;

/**
 *  播放广告
 */
-(void)displayAd:(UIViewController *)rootViewController;

/**
 *  SDK版本号
 */
- (NSString *)version;

/**
 缓存是否就绪可以播放

 @return 缓存是否就绪
 */
-(BOOL)isReady;

@end
NS_ASSUME_NONNULL_END
