//
//  SXVideoAd.m
//  SDK
//
//  Created by 姜振华 on 2016/12/26.
//  Copyright © 2016年 姜振华. All rights reserved.
//

#import "SXVideoAd.h"
#import "SXVideoSDKBridge.h"
#import "SXRequestUtil.h"
#import "UIButton+ClickControl.h"

typedef void(^callback)(id data, BOOL enableOptimazation);

@interface SXVideoAd ()

//桥接对象
@property(nonatomic,strong)SXVideoSDKBridge* bridge;
//在不启动优化配置时的配比配置
@property(nonatomic,strong)NSMutableDictionary* configuration;
//播放SDK的类型
@property(nonatomic,assign)SXSDKType playType;
//展现控制器
@property(nonatomic,weak)UIViewController* controller;

@property(nonatomic,strong)NSString* appId;
@property(nonatomic,strong)NSString* adslotId;

/**
 是否开启自定优化，默认是NO
 */
@property(nonatomic,assign)bool enableOptimazation;

/**
 按照服务器下发的配置文件生成随机数，来决定播放那种类型的广告

 @param configuration 服务器下发的配置文件
 @return 播放SDK的类型
 */
-(int)generateRandom:(NSDictionary*)configuration;

@end

@implementation SXVideoAd


+(instancetype)sharedInstance {
    static SXVideoAd* singleton = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        singleton = [SXVideoAd new];
    });
    return singleton;
}

static id<SXRewardVideoAdDelegate> privateDelegate = nil;

-(void)setDelegate:(id<SXRewardVideoAdDelegate>)delegate {
    @try {
        if (!self.bridge) {
            privateDelegate = delegate;
        } else {
            self.bridge.delegate = delegate;
            privateDelegate = nil;
        }
    } @catch (NSException *exception) {
        [self uploadBreakException:@"设置代理崩溃"];
        return;
    }
}

-(NSString *)appId {
    return _bridge.appid;
}

- (NSString *)adslotId {
    return _bridge.soltid;
}

-(NSMutableDictionary *)configuration {
    return _bridge.configuration;
}

-(void)setConfiguration:(NSMutableDictionary *)configuration {
    _bridge.configuration = configuration;
}

-(instancetype)init {
    if (self = [super init]) {
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(playFailedHandler:) name:@"playfailed" object:nil];
    }
    return self;
}

//这里应该是向服务器请求配置文件，并设置桥接对象
- (void)startWithAppId:(nonnull NSString *)appId adslotId:(nonnull NSString *)adslotId delegate:(nullable id <SXRewardVideoAdDelegate>)delegate enableOptimazation:(BOOL)enableOptimazation {
        if (!self.bridge) {//防止被反复初始化
            bool isDegub = NO;
#ifdef DEBUG
            isDegub = YES;
#endif
            [self setDelegate:delegate];
            __block typeof(self) weakSelf = self;
            //初始化网络请求工具，并发送请求
            [[SXRequestUtil sharedNetUtil] requestAdsWithAppID:appId adslotId:adslotId adCount:1 enableOptimazation:enableOptimazation  success:^(id responseData, BOOL flag, NSString* vid) {
                @try {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        weakSelf.bridge = [[SXVideoSDKBridge alloc] initWithCallbackDelegate:privateDelegate testMode:isDegub initInfo:responseData];
                        weakSelf.bridge.appid = appId;
                        weakSelf.bridge.soltid = adslotId;
                        weakSelf.bridge.vid = vid;
                        weakSelf.enableOptimazation = flag;
                        if (enableOptimazation) {
                            weakSelf.playType = responseData;
                        } else {
                            weakSelf.configuration = responseData;
                        }
                    });

                } @catch (NSException *exception) {
                    [self uploadBreakException:@"初始化崩溃"];
                }
              } failure:^(NSError *error) {
                [weakSelf.bridge.delegate adDidError:error withMessage:@"请求配置参数失败！"];
                [weakSelf.bridge uploadErrorStatics:error.code message:@"请求配置参数失败！" SDKType:SXSDKTypeIntegratedSDK event:UpLoadEventOtherEvents];
            }];
        }
}

-(BOOL)isReady {
    BOOL ret = false;
    @try {
        ret = [self.bridge isCacheReady:self.playType];
    } @catch (NSException *exception) {
        return false;
    }
    return ret;
}

-(void)displayAd:(UIViewController *)rootViewController {
    [self displayAd:rootViewController isReTry:false];
}

-(void)displayAd:(UIViewController *)rootViewController isReTry:(BOOL)flag{
    @try {
        self.controller = rootViewController;
        if (self.enableOptimazation) {
            [self.bridge displayAd:rootViewController withType:self.playType];
        } else {
            self.playType = [self generateRandom:self.configuration];
            [self.bridge displayAd:rootViewController withType:self.playType];
        }
    } @catch (NSException *exception) {
         [self uploadBreakException:@"播放崩溃"];
    } @finally {
        __block typeof(self) weakSelf = self;
        [[SXRequestUtil sharedNetUtil] requestAdsWithAppID:self.appId adslotId:self.adslotId adCount:1 enableOptimazation:self.enableOptimazation  success:^(id responseData, BOOL flag, NSString* vid) {
            dispatch_async(dispatch_get_main_queue(), ^{
                [weakSelf.bridge clearSuccessCount];
            });
            weakSelf.enableOptimazation = flag;
            weakSelf.bridge.vid = flag?vid:weakSelf.bridge.vid;
            if (flag) {
                weakSelf.playType = responseData;
            } else {
                weakSelf.configuration = responseData;
            }
        } failure:^(NSError *error) {
            [weakSelf.bridge uploadErrorStatics:error.code message:@"请求配置参数失败！" SDKType:SXSDKTypeIntegratedSDK event:UpLoadEventOtherEvents];
        }];
        [self.bridge outTimeTask];
    }
}

-(int)generateRandom:(NSDictionary*)configuration {
    @try {
        unsigned int randcount = 0;//比例总数
        if(randcount == 0) {
            for (NSString* conf in configuration.allValues) {
                randcount += conf.integerValue;
            }
        }
        //参考onecat的建议，因为64为框架和32位框架生成的随机数是不同的（int_32和int_64）, 所以有越界风险，这里强转一下
        uint32_t dat = (uint32_t)arc4random()%randcount;//生成一个到最大区间的随机数字
        int max = 0;//步进多少
        for (NSString* type in configuration.allKeys) {
            max += [configuration[type] integerValue];
            if(dat < max) {//比较看落在哪一个区间
                return type.intValue;
            }
        }
    } @catch (NSException *exception) {
        [self uploadBreakException:@"生成随机数时崩溃"];
        return 0;
    }
}


- (void)uploadBreakException:(NSString*)exceptionReason
{
    SXRequestUtil* util = [SXRequestUtil sharedNetUtil];
    SXReferenceSDK* sdk = [SXReferenceSDK createSDK:[SXRequestUtil generateVid] slotId:self.adslotId appId:self.appId channelRate:self.configuration errorCode:SXAdvertiseSystemError info:exceptionReason event:UpLoadEventOtherEvents];
    [util uploadStatistic:SXUploadEventTypeError channel:SXChannelCodePlatform SDK:sdk];
}

-(NSString *)version {
    @try {
        NSMutableDictionary* dic = [NSMutableDictionary dictionaryWithDictionary:[self.bridge getVersions]];
        dic[@"SDKVersion"] = [[NSBundle mainBundle] objectForInfoDictionaryKey:(NSString*)kCFBundleVersionKey];
    } @catch (NSException *exception) {
        [self uploadBreakException:@"获取版本号崩溃"];
        return nil;
    }
}

-(void)playFailedHandler:(NSNotification*)notification {
    @try {
        SXSDKType sdktype = [notification.object integerValue];
        //修改配比
        [self.configuration removeObjectForKey:[NSString stringWithFormat:@"%i",sdktype]];
        //重新调用播放方法
        [self displayAd:self.controller isReTry:true];
    } @catch (NSException *exception) {
        [self uploadBreakException:@"尝试修改配比重新播放时崩溃"];
    }
}

-(void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

@end
