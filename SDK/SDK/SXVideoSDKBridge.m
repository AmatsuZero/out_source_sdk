//
//  SXVideoSDKBridge.m
//  SDK
//
//  Created by 姜振华 on 2016/12/26.
//  Copyright © 2016年 姜振华. All rights reserved.
//

#import "SXVideoSDKBridge.h"
//UnityAds
#import <UnityAds/UnityAds.h>
#import <UnityAds/UADSMediationMetaData.h>
#import <UnityAds/UADSPlayerMetaData.h>
//ayang
#import <KSCAdvertiseSDK/KSCAdvertiseSDK.h>
//Vungle
#import <VungleSDK/VungleSDK.h>
#import "SXVideoAd.h"
#import "SXRequestUtil.h"

static NSErrorDomain const errorDomain = @"com.sixianglianchuang.integratedsdk";

static NSString* playfailednotification = @"playfailed";

@interface SXCacheSuccessCount : NSObject

@property(nonatomic,assign)NSInteger successCount;
@property(nonatomic,assign)BOOL isVungleReady;
@property(nonatomic,assign)BOOL isAyangReady;
@property(nonatomic,assign)BOOL isUnityAdsReady;
@property(nonatomic,assign)BOOL isUnityAdsClicked;
@property(nonatomic,assign)BOOL isAyangAdsClicked;

@end

@implementation SXCacheSuccessCount

-(instancetype)init{
    if (self = [super init]) {
        _successCount = 0;
    }
    return self;
}

-(void)setSuccessCount:(NSInteger)successCount {
    _successCount = successCount;
    if (successCount != 0) {
         [[NSNotificationCenter defaultCenter] postNotificationName:@"CacheReady" object:@(_successCount)];
    }
}

@end

@interface SXVideoSDKBridge ()
<
UnityAdsDelegate,
KSCRewardVideoAdDelegate,
VungleSDKDelegate,
UnityAdsExtendedDelegate
>

@property(nonatomic,strong)KSCRewardVideoAd* kscawardad;
@property(nonatomic,strong)VungleSDK* vunglesdk;
@property(nonatomic,strong)SXCacheSuccessCount* successCount;
@property(nonatomic,assign)BOOL isClickedPlay;
@property(nonatomic,weak)UIViewController* controller;
@property(nonatomic,copy)NSString* unityASDKId;
@property(nonatomic,copy)NSString* kscAdsSDKId;
@property(nonatomic,copy)NSString* adslotId;
@property(nonatomic,copy)NSString* vungleSDKId;

-(void)setDelegate:(id<SXRewardVideoAdDelegate>)delegate;
/**
 广告点击统计

 @param type SDK类型
 */
-(void)adsClicked:(SXSDKType)type;

@end

static NSDate* playDate = nil;

@implementation SXVideoSDKBridge

-(instancetype)initWithCallbackDelegate:(id<SXRewardVideoAdDelegate>)delegate testMode:(BOOL)flag initInfo:(NSDictionary*)infos{
    if (self = [super init]) {
        _delegate = delegate;
        
        _unityASDKId = infos[@"1"][@"adslotId"];
        _kscAdsSDKId = infos[@"3"][@"appId"];
        _adslotId = infos[@"3"][@"adslotId"];
        _vungleSDKId = infos[@"2"][@"adslotId"];
        //初始化UnityAds
        [UnityAds initialize:_unityASDKId delegate:self testMode:flag];
        //初始化ayang
        _kscawardad = [KSCRewardVideoAd sharedInstance];
        [_kscawardad startWithAppId:_kscAdsSDKId adslotId:_adslotId delegate:self];
        [_kscawardad configEnvironment:flag];
        //初始化vungle
        _vunglesdk = [VungleSDK sharedSDK];
        [_vunglesdk startWithAppId:_vungleSDKId];
         _vunglesdk.delegate = self;
        [self enableDebugMode:flag];
        _successCount = [[SXCacheSuccessCount alloc]init];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(cacheReady:) name:@"CacheReady" object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(ayangAdsClicked) name:@"AyangAdsClicked" object:nil];
        [self outTimeTask];
    }
    return self;
}

-(void)outTimeTask {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(30 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if (_successCount.successCount > 0 && _configuration && _successCount.successCount != 3) {
            if (!_successCount.isUnityAdsReady) {
                [_configuration removeObjectForKey:@"1"];
                _successCount.isUnityAdsReady = false;
            }
            if (!_successCount.isVungleReady) {
                [_configuration removeObjectForKey:@"2"];
                _successCount.isVungleReady = false;
            }
            if (!_successCount.isAyangReady) {
                [_configuration removeObjectForKey:@"3"];
                _successCount.isAyangReady = false;
            }
            [_delegate adInitComplete:_configuration!=nil];
        }
    });
}

-(void)setConfiguration:(NSMutableDictionary *)configuration {
    _unityASDKId = configuration[@"1"][@"adslotId"];
    _kscAdsSDKId = configuration[@"3"][@"appId"];
    _adslotId = configuration[@"3"][@"adslotId"];
    _vungleSDKId = configuration[@"2"][@"adslotId"];
    NSMutableDictionary* newDic = [NSMutableDictionary new];
    newDic[@"1"] = configuration[@"1"][@"weight"];
    newDic[@"2"] = configuration[@"2"][@"weight"];
    newDic[@"3"] = configuration[@"3"][@"weight"];
    _configuration = newDic;
}

-(void)cacheReady:(NSNotification*)notification {
    BOOL isReady = [notification.object integerValue] > 0;
    [self.delegate adInitComplete:isReady];
}

-(void)displayAd:(UIViewController *)rootViewController withType:(SXSDKType)type {
    
    self.controller = rootViewController;
    self.isClickedPlay = YES;
    
    switch (type) {
        case SXSDKTypeUnity:{
            [self.delegate adWillDisplayed];
            playDate = [NSDate date];
            [UnityAds show:rootViewController];
        }
            break;
            
        case SXSDKTypeAyang:{
            [self.kscawardad displayAd:rootViewController];
        }
            break;
            
        case SXSDKTypeVungle:{
            NSError* error;
            if ([self.vunglesdk playAd:rootViewController error:&error]) {
                [self adDidShow:SXSDKTypeVungle];
            }
            if (error) {
//                 [self.delegate adDidError:error withMessage:@"播放出错"];
                 [[NSNotificationCenter defaultCenter] postNotificationName:playfailednotification object:@(SXSDKTypeVungle) userInfo:@{@"message":@"Vungle播放出错",@"error":error}];
            }
        }
            break;
            
        default:{
            NSError* error = [NSError errorWithDomain:errorDomain code:SXAdvertiseSDKPlayFailed userInfo:@"无法播放广告"];
            if (!self.configuration || self.configuration.allKeys.count == 0) {
                [self.delegate adDidError:error withMessage:@"没有配比，无法播放！"];
            } else {
                [self.delegate adDidError:error withMessage:@"无法播放！"];
            }
        }
            break;
    }
}

-(void)clearSuccessCount {
    self.successCount.successCount = 0;
    self.successCount.isUnityAdsReady = false;
    self.successCount.isVungleReady = false;
    self.successCount.isAyangReady = false;
}

-(void)enableDebugMode:(BOOL)flag {
    [self.vunglesdk setLoggingEnabled:flag];
    [UnityAds setDebugMode:flag];
}

-(NSDictionary *)getVersions {
    
    return @{
             @"UnityAds":[UnityAds getVersion],
             @"Ayange":[self.kscawardad version],
             @"Vungle":[self.vunglesdk debugInfo][@"version"]
             };
}

-(void)ayangAdsClicked {
    self.successCount.isAyangAdsClicked = true;
    [self adsClicked:SXSDKTypeAyang];
}

-(BOOL)isCacheReady:(SXSDKType)type {
    switch (type) {
        case SXSDKTypeUnity:
            return [UnityAds isInitialized] && [UnityAds isReady];
        
        case SXSDKTypeVungle:
            return [self.vunglesdk isAdPlayable];
            
        case SXSDKTypeAyang:
            return [self.kscawardad AdCacheStatus] != KSCRewardVideoAdCacheStatusNoAdData;
            
        default:
            return YES;
    }
}

#pragma mark UnityAds Delegate
- (void)unityAdsReady:(NSString *)placementId {
    
    self.successCount.successCount += ([UnityAds isReady] ? 1 : 0);
    self.successCount.isUnityAdsReady = [UnityAds isReady];
    static dispatch_once_t onceToken;
 
    if (![UnityAds isReady]) {
        [self uploadErrorStatics:SXAdvertiseNoCaheData message:@"广告缓存失败" SDKType:SXSDKTypeUnity event:UpLoadEventOtherEvents];
    }
}

- (void)unityAdsDidError:(UnityAdsError)error withMessage:(NSString *)message {
    NSError* erro = [NSError errorWithDomain:errorDomain code:error userInfo:message];
    [[NSNotificationCenter defaultCenter] postNotificationName:playfailednotification object:@(SXSDKTypeUnity) userInfo:message];
}

- (void)unityAdsDidFinish:(NSString *)placementId
          withFinishState:(UnityAdsFinishState)state {
    
    SXAdClosedStatus status = 0;
    //计算从开始到结束的时长
    NSTimeInterval duration = [[NSDate date] timeIntervalSinceDate:playDate];
    playDate = nil;
    
    switch (state) {
        case kUnityAdsFinishStateSkipped:
            status = SXAdForceClose;
            break;
        case kUnityAdsFinishStateCompleted:
            status = SXAdNaturalClose;
            break;
        case kUnityAdsFinishStateError: {
            NSError* error = [NSError errorWithDomain:errorDomain code:kUnityAdsFinishStateError userInfo:@"广告未能成功播放"];
            [[NSNotificationCenter defaultCenter] postNotificationName:playfailednotification object:@(SXSDKTypeUnity) userInfo:@{@"message":@"Unity播放出错",@"error":error}];
        }
            break;
    }
    
    [self adsPicDidiShow:SXSDKTypeUnity];
    [self adClosed:SXSDKTypeUnity];
    [self.delegate adWillClosed:status duration:duration isUserClickTheLink:status==SXAdNaturalClose && self.successCount.isUnityAdsClicked];
    self.successCount.isUnityAdsClicked = false;
}

-(void)unityAdsDidStart:(NSString *)placementId {
    [self adDidShow:SXSDKTypeUnity];
    self.isClickedPlay = NO;
}

//UnityAds 广告点击事件
- (void)unityAdsDidClick:(NSString *)placementId {
    self.successCount.isUnityAdsClicked = true;
    [self adsClicked:SXSDKTypeUnity];
}

#pragma mark VungleSDKDelegate

/**
 Vungle缓存状态的回调
 
 @discussion 根据文档解释，返回NO可能是由于广告视频文件损坏，或者是系统清除了缓存。但只要开发者没有在控制面板关闭掉Exchange，就仍能通过流媒体的方式播放
 @param isAdPlayable 是否可以播放广告
 */
-(void)vungleSDKAdPlayableChanged:(BOOL)isAdPlayable {
    
    self.successCount.successCount += (isAdPlayable ? 1 : 0);
    self.successCount.isVungleReady = isAdPlayable;

    if (!isAdPlayable) {
       [self uploadErrorStatics:SXAdvertiseNoCaheData message:@"广告缓存失败" SDKType:SXSDKTypeVungle event:UpLoadEventOtherEvents];
    }
}

-(void)vungleSDKwillShowAd {
    [self.delegate adWillDisplayed];
    [self adDidShow:SXSDKTypeVungle];
    self.isClickedPlay = NO;
}

- (void)vungleSDKwillCloseAdWithViewInfo:(NSDictionary *)viewInfo willPresentProductSheet:(BOOL)willPresentProductSheet {
    NSTimeInterval duration = [viewInfo[@"playTime"] floatValue];
    BOOL clicked = [viewInfo[@"didDownload"] boolValue];
    if (clicked) [self adsClicked:SXSDKTypeVungle];
    [self adsPicDidiShow:SXSDKTypeVungle];
    [self adClosed:SXSDKTypeVungle];
    [self.delegate adWillClosed:[viewInfo[@"completedView"] boolValue] duration:duration isUserClickTheLink:clicked];
}

static BOOL isRetried;

#pragma mark AyangDelegate
- (void)adInitComplete:(BOOL)isFinished error:(nullable NSError *)error {
    
    self.successCount.successCount += (isFinished ? 1 : 0);
    self.successCount.isAyangReady = isFinished;
 
    switch (error.code) {
        case KSCAdvertiseRequestFailed:
        case KSCAdvertiseResponseParameterFailed:
        {//请求广告失败，将无法播放视频广告，需重新初始化以请求广告
            self.successCount.isAyangReady = false;
            if (isRetried) {
                [self uploadErrorStatics:error.code message:error.localizedDescription SDKType:SXSDKTypeAyang event:UpLoadEventOtherEvents];
                if (self.isClickedPlay) {
                    [[NSNotificationCenter defaultCenter] postNotificationName:playfailednotification object:@(SXSDKTypeAyang) userInfo:@"Ayang播放出错"];
                } else {
                    //修改配比
                    if (self.configuration[[NSString stringWithFormat:@"%i",SXSDKTypeAyang]]) {
                        [self.configuration removeObjectForKey:[NSString stringWithFormat:@"%i",SXSDKTypeAyang]];
                    }
                }
//                self.isClickedPlay= NO;
            } else {
                isRetried = YES;
                [self.kscawardad startWithAppId:self.kscAdsSDKId adslotId:self.adslotId delegate:self];
            }
        }
            break;
        case KSCAdvertiseParameterInvalid:
        case KSCAdvertisePlayerInitFailed:{
            [self uploadErrorStatics:error.code message:error.localizedDescription SDKType:SXSDKTypeAyang event:UpLoadEventPlayStart];
            if (self.isClickedPlay) {
                [[NSNotificationCenter defaultCenter] postNotificationName:playfailednotification object:@(SXSDKTypeAyang) userInfo:@"Ayang播放出错"];
            }else {
                //修改配比
                if (self.configuration[[NSString stringWithFormat:@"%i",SXSDKTypeAyang]]) {
                    [self.configuration removeObjectForKey:[NSString stringWithFormat:@"%i",SXSDKTypeAyang]];
                }
            }
        }
        
        case KSCAdvertiseCacheFailed:{
            if (self.isClickedPlay) {
                [self.kscawardad displayAd:self.controller];
                [self uploadErrorStatics:error.code message:error.localizedDescription SDKType:SXSDKTypeAyang event:UpLoadEventPlayStart];
            } else {
                [self uploadErrorStatics:SXAdvertiseNoCaheData message:error.localizedDescription SDKType:SXSDKTypeAyang event:UpLoadEventOtherEvents];
            }
        }
            
        default:
            break;
    }
}

-(void)adVideoWillDisplayed {
    playDate = [NSDate date];
    self.isClickedPlay = NO;
    isRetried = NO;
    [self.delegate adWillDisplayed];
}

-(void)adVideoWillClosed:(NSTimeInterval)durationTimes closeStatus:(KSCAdClosedStatus)status {
    if (status == KSCAdForceClose) {
        NSTimeInterval duration = [[NSDate date] timeIntervalSinceDate:playDate];
        playDate = nil;
        [self.delegate adWillClosed:status duration:duration isUserClickTheLink:self.successCount.isAyangAdsClicked];
    }
}

-(void)adPictureWillClosed:(KSCAdClosedStatus)status {
    if (status == KSCAdNaturalClose) {
        [self ayangAdsClicked];
    }
    NSTimeInterval duration = [[NSDate date] timeIntervalSinceDate:playDate];
    playDate = nil;
    [self adClosed:SXSDKTypeAyang];
    [self.delegate adWillClosed:status duration:duration isUserClickTheLink:self.successCount.isAyangAdsClicked];
    self.successCount.isAyangAdsClicked = false;
}

-(void)adPictureWillShowed {
    [self adsPicDidiShow:SXSDKTypeAyang];
}

#pragma mark 统计/上传
-(void)adsClicked:(SXSDKType)type {
    SXReferenceSDK* sdk = [SXReferenceSDK createSDK:self.vid slotId:self.soltid appId:self.appid channelRate:self.configuration errorCode:0 info:@"广告点击" event:0];
    [[SXRequestUtil sharedNetUtil] uploadStatistic:SXUploadEventTypeClicked channel:[self getChannelCode:type] SDK:sdk];
}

-(void)adsPicDidiShow:(SXSDKType)type {
    SXReferenceSDK* sdk = [SXReferenceSDK createSDK:self.vid slotId:self.soltid appId:self.appid channelRate:self.configuration errorCode:0 info:@"广告展示" event:0];
    [[SXRequestUtil sharedNetUtil] uploadStatistic:SXUploadEventTypeShow channel:[self getChannelCode:type] SDK:sdk];
}

-(void)uploadErrorStatics:(int)errorCode message:(NSString*)message SDKType:(SXSDKType)type event:(UpLoadEvent)event{
    SXReferenceSDK* sdk = [SXReferenceSDK createSDK:self.vid slotId:self.soltid appId:self.appid channelRate:self.configuration errorCode:errorCode info:message event:event];
    [[SXRequestUtil sharedNetUtil] uploadStatistic:SXUploadEventTypeError channel:[self getChannelCode:type] SDK:sdk];
}

-(void)adDidShow:(SXSDKType)type {
    SXReferenceSDK* sdk = [SXReferenceSDK createSDK:self.vid slotId:self.soltid appId:self.appid channelRate:self.configuration errorCode:0 info:@"视频播放" event:UpLoadEventPlayStart];
    [[SXRequestUtil sharedNetUtil] uploadStatistic:SXUploadEventTypeVideoPlayed channel:[self getChannelCode:type] SDK:sdk];
}

-(void)adClosed:(SXSDKType)type {
    SXReferenceSDK* sdk = [SXReferenceSDK createSDK:self.vid slotId:self.soltid appId:self.appid channelRate:self.configuration errorCode:0 info:@"广告关闭" event:UpLoadEventPlayEnd];
    [[SXRequestUtil sharedNetUtil] uploadStatistic:SXUploadEventTypeAdClosed channel:[self getChannelCode:type] SDK:sdk];
}

-(SXChannelCode)getChannelCode:(SXSDKType)type {
    NSInteger t;
    switch (type) {
        case SXSDKTypeUnity:
            t = SXChannelCodeUnity;
            break;
        case SXSDKTypeVungle:
            t = SXChannelCodeVungle;
            break;
        case SXSDKTypeAyang:
            t = SXChannelCodeKs;
            break;
        default:
            t = SXChannelCodeBaidu;
            break;
    }
    return t;
}

-(void)dealloc {
    [[VungleSDK sharedSDK] setDelegate:nil];
    [UnityAds setDelegate:nil];
    [KSCRewardVideoAd sharedInstance];
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
