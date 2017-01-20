//
//  SXRewardVideoAdDelegate.h
//  SDK
//
//  Created by 姜振华 on 2016/12/26.
//  Copyright © 2016年 姜振华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Constants.h"

@protocol SXRewardVideoAdDelegate <NSObject>

@optional
/**
 广告缓存状态回调

 @param isFinished 缓存是否成功
 */
- (void)adInitComplete:(BOOL)isFinished;

/**
 出现错误

 @param error 错误类型
 @param message 错误描述
 */
- (void)adDidError:(NSError*)error withMessage:(NSString *)message;

/**
 *  广告视频将要播放
 */
- (void)adWillDisplayed;


/**
 广告播放完毕

 @param status 正常播放完毕关闭/用户强制关闭
 @param duration 广告停留时间
 @param isclicked 用户是否点击了广告
 @discussion 由于UnityAds SDK广告视频和后面广告页展示是在一起的，没有分开提供回调。所以这里统计的停留时间是指从打开广告到整个窗口关闭的时间
 */
- (void)adWillClosed:(SXAdClosedStatus)status duration:(NSTimeInterval)duration isUserClickTheLink:(BOOL)isclicked;

@end
