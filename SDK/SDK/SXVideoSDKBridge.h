//
//  SXVideoSDKBridge.h
//  SDK
//
//  Created by 姜振华 on 2016/12/26.
//  Copyright © 2016年 姜振华. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SXRewardVideoAdDelegate.h"
#import <UIKit/UIViewController.h>
#import "Constants.h"

typedef NS_ENUM(NSUInteger, SXSDKType) {
    SXSDKTypeUnity = 1,//Unity
    SXSDKTypeVungle,//Vungle
    SXSDKTypeAyang,//Ayang
    SXSDKTypeIntegratedSDK
};

@interface SXVideoSDKBridge : NSObject

@property(nonatomic,weak)id<SXRewardVideoAdDelegate>delegate;
@property(nonatomic,copy)NSString* appid;
@property(nonatomic,copy)NSString* soltid;
@property(nonatomic,strong)NSString* vid;
@property(nonatomic,strong)NSMutableDictionary* configuration;

-(instancetype)initWithCallbackDelegate:(id<SXRewardVideoAdDelegate>)delegate testMode:(BOOL)flag initInfo:(NSDictionary*)infos;

-(void)displayAd:(UIViewController *)rootViewController withType:(SXSDKType)type;

-(void)enableDebugMode:(BOOL)flag;//Only for Unity/Vungle

-(NSDictionary*)getVersions;

-(void)uploadErrorStatics:(int)errorCode message:(NSString*)message SDKType:(SXSDKType)type event:(NSInteger)event;

-(BOOL)isCacheReady:(SXSDKType)type;

//超时任务检查
-(void)outTimeTask;

//清除成功计数
-(void)clearSuccessCount;

@end
