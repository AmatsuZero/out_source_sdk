//
//  SXRequestUtil.h
//  SDK
//
//  Created by 姜振华 on 2016/12/29.
//  Copyright © 2016年 姜振华. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    SXUploadEventTypeError = 0,//错误
    SXUploadEventTypeRequest,//请求
    SXUploadEventTypeFeedback,//反馈
    SXUploadEventTypeShow,//展现
    SXUploadEventTypeClicked,//点击
    SXUploadEventTypeActivateFeedback,//激活回调
    SXUploadEventTypeVideoPlayed,//视频播放
    SXUploadEventTypeActivateReport,//激活上报
    SXUploadEventTypeAdClosed,//广告关闭
    SXUploadEventTypeAppDownload//应用下载
} SXUploadEventType;

typedef enum : NSUInteger {
    SXChannelCodePlatform = 0,
    SXChannelCodeBaidu = 1,
    SXChannelCodeTencent = 2,
    SXChannelCodeDirectPlay =3,
    SXChannelCodeInmobi = 4,
    SXChannelCodeKs = 201,
    SXChannelCodeVungle = 202,
    SXChannelCodeUnity = 203
} SXChannelCode;

typedef enum : NSUInteger {
    UpLoadEventPlayStart = 101000,
    UpLoadEventFullScreen,
    UpLoadEventPlayEnd,
    UpLoadEventClickPreviewPic,
    UpLoadEventForceCloseVideo,
    UpLoadEventOtherEvents = 0
} UpLoadEvent;

/**
 上传参数SDK。要转换成JSON格式并做base64编码
 */
@interface SXReferenceSDK : NSObject

/**
 api版本
 */
@property(nonatomic,copy)NSString* api_version;

/**
 请求ID（内部生成UUID），必填
 */
@property(nonatomic,copy)NSString* request_id;

/**
 曝光唯一标示
 */
@property(nonatomic,copy)NSString* vid;

/**
 广告位ID
 */
@property(nonatomic,copy)NSString* slot_id;

/**
 在mssp上传应用成功审核后，平台提供的应用ID
 */
@property(nonatomic,copy)NSString* app_id;

/**
 用户标识类型: 1-Android,2-ios,3-mac
 */
@property(nonatomic,strong)NSNumber* u_type;

/**
 终端的唯一标识,ios 为idfa 号,android 则为imei 号
 */
@property(nonatomic,copy)NSString* user_id;

/**
 渠道的权重比率数组（{"渠道编码":配置百分比值}）
 */
@property(nonatomic,copy)NSDictionary* channel_rata;

/**
 渠道的权重比率数组（{"渠道编码":配置百分比值}）
 */
@property(nonatomic,strong)NSNumber* error_code;

/**
 备注信息,可用于上报具体的错误信息（有错误提示信息时可填写）
 */
@property(nonatomic,copy)NSString* ifo;

/**
 事件编码:101000-开始播放;101002-播放结束;101001-视频全屏;101003-点击预览图播放视
 频;101009-视频播放被中途关闭;0-其他情况
 */
@property(nonatomic,strong)NSNumber* event;

+(instancetype)createSDK:(NSString*)vid slotId:(NSString*)slotId appId:(NSString*)appId channelRate:(NSDictionary*)rate errorCode:(NSInteger)code info:(NSString*)info event:(UpLoadEvent)event;

@end

/**
 网络请求工具
 */
@interface SXRequestUtil : NSObject

/**
 网络请求单例对象

 @return 单例对象
 */
+(instancetype) sharedNetUtil;

/**
 获取配置文件 。
 
 @param appID appID : @"j0g2phg7"
 @param adslotId 广告位ID ： @"vfjxinne"
 @param success 成功回调
 @param failure 失败回调
 */
- (void)requestAdsWithAppID:(NSString *)appID
                   adslotId:(NSString *)adslotId
                    adCount:(int)adCount
         enableOptimazation:(BOOL)enableOptimazation
                    success:(void (^)(id responseData, BOOL isEnabled, NSString* vid))success
                    failure:(void (^)(NSError *error))failure;


/**
 上报时间

 @param type 事件类型
 @param channel 渠道编号
 @param sdk SDK参数
 */
-(void)uploadStatistic:(SXUploadEventType)type
               channel:(SXChannelCode)channel
                   SDK:(SXReferenceSDK*)sdk;


/**
 生成Vid。目前是在原来requestID的基础上加上6位的随机数

 @return vid
 */
+(NSString*)generateVid;

@end
