//
//  SXRequestUtil.m
//  SDK
//
//  Created by 姜振华 on 2016/12/29.
//  Copyright © 2016年 姜振华. All rights reserved.
//

#import "SXRequestUtil.h"
#import "KsMobadsApi54.pbobjc.h"
#import "Reachability.h"

#import  <CoreTelephony/CTTelephonyNetworkInfo.h>
#import  <CoreTelephony/CTCarrier.h>

//辅助类
#import "UIDevice+SXUMobAdExtension.h"
#import "UIApplication+SXUMobAdExtension.h"
#import "SXUMobAdLocationManager.h"
#import "NSDictionary+PlainObjectToDictionary.h"
#import "NSString+JSONConversion.h"
#import "GTMBase64.h"

// 获取 idfa
#import <AdSupport/AdSupport.h>

// 椰子传媒 API 测试服务器地址
#define kTestServerURL      @"http://120.92.44.245/sdk/test/def"
#define kOnLineServerURL    @"http://track.ksyun.com/track/"


// 椰子传媒 API 版本
#define AyangMobadsApiMajor  5;
#define AyangMobadsApiMinor  3;
#define AyangMobadsApiMicro  0;

// 各类广告View的尺寸。
#define kSXUAdViewBannerSize480x75              CGSizeMake(480, 75)
#define kSXUAdViewBannerSize640x100             CGSizeMake(640, 100)
#define kSXUAdViewSplashSize640x960             CGSizeMake(640, 960)
#define kSXUAdViewInterstitialSize300x250       CGSizeMake(300, 250)

// 广告位类型。 说明:Banner=1，插屏=2，开屏=4，原 生=8，奖励视频=9.
typedef enum _AdslotType
{
    AdslotTypeBanner            = 1,
    AdslotTypenterstitial       = 2,
    AdslotTypeSplash            = 4,
    AdslotTypeNative            = 8,
    AdslotTypeVideo             = 9,
} AdslotType;

typedef enum _AdslotSize {
    AdslotSize480x75 = 0,
    AdslotSize640x100,
    AdslotSize640x960,
    AdslotSize300x250,
    AdslotSizeNative,
    AdslotSizeVideo,
} AdslotSize;

@interface SXReferenceSDK ()

//将自己转换成加密后的字符串
-(NSString*)convertToBase64String;

@end

@implementation SXReferenceSDK

+(instancetype)createSDK:(NSString*)vid slotId:(NSString*)slotId appId:(NSString*)appId channelRate:(NSDictionary*)rate errorCode:(NSInteger)code info:(NSString*)info event:(UpLoadEvent)event {
    SXReferenceSDK* sdk = [SXReferenceSDK new];
    sdk.api_version = @"1.0.0";
    sdk.request_id = [NSUUID UUID].UUIDString;
    sdk.vid = vid;
    sdk.slot_id = slotId;
    sdk.app_id = appId;
    sdk.u_type = @(2);
    sdk.user_id = [[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString];
    sdk.event = @(event);
    NSMutableDictionary* newDic = [NSMutableDictionary dictionary];
    NSArray* allkeys = rate.allKeys;
    for (NSString* key in allkeys) {
        switch (key.integerValue) {
            case 1:
                newDic[@"202"] = rate[key];
                break;
            case 2:
                newDic[@"201"] = rate[key];
                break;
            case 3:
                newDic[@"203"] = rate[key];
                break;
            default:
                break;
        }
    }
    sdk.channel_rata = newDic;
    sdk.error_code = @(code);
    sdk.ifo = info;
    
    return sdk;
}

-(NSString*)convertToBase64String {
    //1. 将自己转换成字典
    NSDictionary* dic = [NSDictionary getObjectData:self];
    //2. 字典再转换成Data
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dic options:NSJSONWritingPrettyPrinted error:nil];;
    //3. 转换成加密字符串
    return [GTMBase64 stringByWebSafeEncodingData:jsonData padded:YES];
}

@end

@interface SXRequestUtil()

//请求Session
@property (nonatomic, strong)NSURLSession * requestSession;

+ (SXLCVersion*)apiVersion;
+ (SXLCDevice*)device;
+ (SXLCAdSlot*)adslotWithID:(NSString *)adslotID size:(int)type adCount:(int)adCount;
+ (SXLCNetwork*)network;
+ (SXLCGps*)gps;

@end

@implementation SXRequestUtil

+ (instancetype)sharedNetUtil {
    static SXRequestUtil * mgr = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if (mgr == nil) {
            mgr = [[self alloc] init];
        }
    });
    return mgr;
}

- (NSURLSession *)requestSession {
    if (!_requestSession) {
        NSURLSessionConfiguration * config = [NSURLSessionConfiguration ephemeralSessionConfiguration];
        config.requestCachePolicy = NSURLRequestReloadIgnoringCacheData;
        [config setTimeoutIntervalForRequest:60.0];
        [config setHTTPAdditionalHeaders:@{@"User-Agent":@"Mozilla/5.0 (iPhone; CPU iPhone OS 9_1 like Mac OS X) AppleWebKit/601.1.46 (KHTML, like Gecko) Version/9.0 Mobile/13B143 Safari/601.1"}];
        NSOperationQueue* queue = [[NSOperationQueue alloc] init];
        queue.name = [[NSBundle mainBundle] objectForInfoDictionaryKey:(NSString*)kCFBundleVersionKey];
        queue.qualityOfService = NSQualityOfServiceBackground;
        _requestSession = [NSURLSession sessionWithConfiguration:config delegate:nil delegateQueue:queue];
    }
    return _requestSession;
}

- (void)requestAdsWithAppID:(NSString *)appID
                   adslotId:(NSString *)adslotId
                    adCount:(int)adCount
         enableOptimazation:(BOOL)enableOptimazation
                    success:(void (^)(id responseData, BOOL isEnabled, NSString* vid))success
                    failure:(void (^)(NSError *error))failure
{
    
    SXLCMobadsRequest *request  = [[SXLCMobadsRequest alloc] init];
    request.requestId       = [NSString stringWithUUID];
    request.apiVersion      = [SXRequestUtil apiVersion];
    request.app             = [SXRequestUtil appWithAppID:appID];
    request.adslot          = [SXRequestUtil adslotWithID:adslotId size:AdslotSizeVideo adCount:adCount];
    request.device          = [SXRequestUtil device];
    request.network         = [SXRequestUtil network];
    request.gps             = [SXRequestUtil gps];
    request.isDebug         = YES;
    
    NSData *requestData = [request data];
    
    NSURL* url= nil;
#ifdef DEBUG
    url = [NSURL URLWithString:kTestServerURL];
#else
    url = [NSURL URLWithString:kOnLineServerURL];
#endif
    
    NSMutableURLRequest* req = [NSMutableURLRequest requestWithURL:url];
    req.HTTPMethod = @"POST";
    req.HTTPBody = requestData;
    
    NSURLSessionDataTask* getConfigurationTask = [self.requestSession dataTaskWithRequest:req completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        SXReferenceSDK* sdk = nil;
        if (error){
            failure(error);
        } else {
            NSError * err = nil;
            SXLCMobadsResponse* rep = [SXLCMobadsResponse parseFromData:data error:&err];
            if (err) {
                failure(err);
            } else {
                if (rep.automaticPro) {//是否自动优化广告
                    NSString* vid = [SXRequestUtil generateVid];
                    success(rep, rep.automaticPro, vid);
                    sdk = [SXReferenceSDK createSDK:[SXRequestUtil generateVid] slotId:adslotId appId:appID channelRate:nil errorCode:0 info:error.localizedDescription event:0];
                } else {//不开启
                    NSMutableDictionary* dic = [NSMutableDictionary dictionary];
                    NSMutableDictionary* conf = [NSMutableDictionary dictionary];
                    for (SXLCAdStrategy* strategy in rep.adStrategyArray) {
                        @autoreleasepool {
                            NSString* key = nil;
                            switch (strategy.channelType) {
                                case SXLCAdStrategy_ChannelType_ChannelUnit:
                                    key = @"1";
                                    break;
                                case SXLCAdStrategy_ChannelType_ChannelVung:
                                    key = @"2";
                                    break;
                                case SXLCAdStrategy_ChannelType_ChannelKs:
                                    key = @"3";
                                    break;
                                default:
                                    break;
                            }
                            NSString* k = [NSString stringWithFormat:@"%i",strategy.channelType];
                            conf[k] = @(strategy.weight);
                            //记录appid和广告位id
                            NSDictionary* info = @{@"appId":strategy.appId,@"adslotId":strategy.adslotId,@"weight":@(strategy.weight)};
                            dic[key] = info;
                        }
                    }
                    NSString* vid = [SXRequestUtil generateVid];
                    success(dic, rep.automaticPro,vid);
                    sdk = [SXReferenceSDK createSDK:vid slotId:adslotId appId:appID channelRate:conf errorCode:0 info:@"反馈上报" event:0];
                }
            }
        }
        //反馈上报
        [self uploadStatistic:SXUploadEventTypeFeedback channel:SXChannelCodeBaidu SDK:sdk];
    }];
    
    [getConfigurationTask resume];
}

+(NSString*)generateVid {
    NSString* base = [NSString stringWithUUID];
    NSString* randomPart = [NSString stringWithFormat:@"%d",arc4random_uniform(1000000)];
    return [base stringByAppendingString:randomPart];
}

-(void)uploadStatistic:(SXUploadEventType)type channel:(SXChannelCode)channel SDK:(SXReferenceSDK *)sdk {
    NSString* ref = [NSString stringWithFormat:@"type=%@&channel=%@&sdk=%@",@(type),@(channel),[sdk convertToBase64String]];
    ref = [ref stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLQueryAllowedCharacterSet]];
    NSString* url = [NSString stringWithFormat:@"http://track.ksyun.com/track/sdk?%@",ref];
#ifdef DEBUG
    url = [NSString stringWithFormat:@"http://120.92.44.245/track/sdk?%@",ref];
#endif
    NSURL* URL = [NSURL URLWithString:url];
    [[self.requestSession dataTaskWithURL:URL completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        NSLog(@"%@",error);
    }] resume];
}

+ (SXLCVersion*)apiVersion
{
    SXLCVersion *apiVersion = [[SXLCVersion alloc] init];
    apiVersion.major = AyangMobadsApiMajor;
    apiVersion.minor = AyangMobadsApiMinor;
    apiVersion.micro = AyangMobadsApiMicro;
    
    return apiVersion;
}

+ (SXLCApp*)appWithAppID:(NSString *)appID
{
    SXLCApp *app = [[SXLCApp alloc] init];
    app.appId = appID;
    app.channelId = @"1";
    
    SXLCVersion *appVersion = [[SXLCVersion alloc] init];
    appVersion.major = [UIApplication appMajorVersion];
    appVersion.minor = [UIApplication appminorVersion];
    appVersion.micro = [UIApplication appMicroVersion];
    
    app.appVersion = appVersion;
    app.appPackage = [UIApplication appIdentifier];
    
    return app;
}

+ (SXLCAdSlot*)adslotWithID:(NSString *)adslotID size:(int)type adCount:(int)adCount
{
    SXLCAdSlot *adslot = [[SXLCAdSlot alloc] init];
    
    adslot.adslotId = adslotID; // 开屏 ： julx2mnw 、插屏 ：vfjxinne、 横幅 ： mfyrrfeb 信息流 ： vzbyzvth
    adslot.ads = adCount;
    
    SXLCSize *size = [[SXLCSize alloc] init];
    
    if (type==AdslotSize480x75)
    {
        size.width = kSXUAdViewBannerSize480x75.width;
        size.height = kSXUAdViewBannerSize480x75.height;
        adslot.adslotType = AdslotTypeBanner;
    }
    else if (type==AdslotSize640x100)
    {
        size.width = kSXUAdViewBannerSize640x100.width;
        size.height = kSXUAdViewBannerSize640x100.height;
        adslot.adslotType = AdslotTypeBanner;
    }
    else if (type==AdslotSize640x960)
    {
        size.width = kSXUAdViewSplashSize640x960.width;
        size.height = kSXUAdViewSplashSize640x960.height;
        adslot.adslotType = AdslotTypeSplash;
    }
    else if (type==AdslotTypenterstitial)
    {
        size.width = kSXUAdViewInterstitialSize300x250.width;
        size.height = kSXUAdViewInterstitialSize300x250.height;
    }
    else if (type==AdslotTypeNative){
        adslot.adslotType = AdslotTypeNative;
    }
    else if (type==AdslotSizeVideo)
    {
        adslot.adslotType = AdslotTypeVideo;
        
        SXLCVideo *video = [[SXLCVideo alloc] init];
        video.title = nil;
        video.contentLength = 0;
        video.copyright = SXLCVideo_CopyRight_CrNone;
        adslot.video = video;
        
        adslot.video = video;
    }
    adslot.adslotSize = size;
    
    // 1.3.5 视频贴片 可选。
    
    
    return adslot;
}

+ (SXLCDevice*)device
{
    SXLCDevice *device = [[SXLCDevice alloc] init];
    
    SXLCUdId *udid = [[SXLCUdId alloc] init];
    NSString *idfa = [[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString];
    udid.idfa = idfa;
    
    if ([UIDevice currentDevice].ipAddressWIFI != nil &&
        [[UIDevice currentDevice].ipAddressWIFI isEqualToString:@""])
    {
        udid.mac = [UIDevice currentDevice].ipAddressWIFI;
    }
    //udid.imei = "";  // 要使用私有API，不能获取手机IMEI。
    //udid.androidId = @"";
    device.udid = udid;
    device.deviceType = [[UIDevice currentDevice] isPad] ? SXLCDevice_DeviceType_Tablet : SXLCDevice_DeviceType_Phone;
    device.osType = SXLCDevice_OsType_Ios;
    
    SXLCVersion *osVersion = [[SXLCVersion alloc] init];
    osVersion.major = [UIDevice systemMajorVersion];
    osVersion.minor = [UIDevice systemMinorVersion];
    osVersion.micro = [UIDevice systemMicroVersion];
    
    device.osVersion = osVersion;
    device.vendor = [@"Apple Inc" dataUsingEncoding:NSUTF8StringEncoding];
    device.model = [[UIDevice currentDevice].machineModel dataUsingEncoding:NSUTF8StringEncoding];
    
    return device;
}

+ (SXLCNetwork*)network
{
    SXLCNetwork *network = [[SXLCNetwork alloc] init];
    network.ipv4 = [UIDevice deviceWANIPAdress][@"cip"];
    CTTelephonyNetworkInfo  *networkInfo = [[ CTTelephonyNetworkInfo alloc ]init];
    network.connectionType = [self getNetconnType:networkInfo];
    network.operatorType = [self getProviderType:networkInfo];
    network.cellularId = networkInfo.subscriberCellularProvider.mobileNetworkCode;
    
    return network;
}

+(SXLCNetwork_OperatorType)getProviderType:(CTTelephonyNetworkInfo*)info {
    SXLCNetwork_OperatorType type;
    
    NSString* name = info.subscriberCellularProvider.carrierName;
    if (!name) {
        type = SXLCNetwork_OperatorType_UnknownOperator;
    } else if ([name  isEqual: @"中国移动"]) {
        type = SXLCNetwork_OperatorType_ChinaMobile;
    } else if ([name  isEqual: @"中国联通"]) {
        type = SXLCNetwork_OperatorType_ChinaUnicom;
    } else if ([name  isEqual: @"中国电信"]) {
        type = SXLCNetwork_OperatorType_ChinaTelecom;
    } else {
        type = SXLCNetwork_OperatorType_OtherOperator;
    }
    
    return type;
}

+ (SXLCNetwork_ConnectionType)getNetconnType:(CTTelephonyNetworkInfo*)info{
    
    SXLCNetwork_ConnectionType netconnType;
    
    Reachability *reach = [Reachability reachabilityWithHostName:@"www.apple.com"];
    
    switch ([reach currentReachabilityStatus]) {
        case NotReachable:// 没有网络
        {
            
            netconnType = SXLCNetwork_ConnectionType_ConnectionUnknown;
        }
            break;
            
        case ReachableViaWiFi:// Wifi
        {
            netconnType = SXLCNetwork_ConnectionType_Wifi;
        }
            break;
            
        case ReachableViaWWAN:// 手机自带网络
        {
            NSString *currentStatus = info.currentRadioAccessTechnology;
            
            if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyGPRS"]) {
                
                netconnType = SXLCNetwork_ConnectionType_Cell2G;
            }else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyEdge"]) {
                
                netconnType = SXLCNetwork_ConnectionType_Cell2G;
            }else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyWCDMA"]){
                
                netconnType = SXLCNetwork_ConnectionType_Cell3G;
            }else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyHSDPA"]){
                
                netconnType = SXLCNetwork_ConnectionType_Cell3G;
            }else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyHSUPA"]){
                
                netconnType = SXLCNetwork_ConnectionType_Cell3G;
            }else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyCDMA1x"]){
                
                netconnType = SXLCNetwork_ConnectionType_Cell2G;
            }else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyCDMAEVDORev0"]){
                
                netconnType = SXLCNetwork_ConnectionType_Cell3G;
            }else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyCDMAEVDORevA"]){
                
                netconnType = SXLCNetwork_ConnectionType_Cell3G;
            }else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyCDMAEVDORevB"]){
                
                netconnType = SXLCNetwork_ConnectionType_Cell3G;
            }else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyeHRPD"]){
                
                netconnType = SXLCNetwork_ConnectionType_ConnectionUnknown;
            }else if ([currentStatus isEqualToString:@"CTRadioAccessTechnologyLTE"]){
                
                netconnType = SXLCNetwork_ConnectionType_Cell4G ;
            }
        }
            break;
            
        default:
            break;
    }
    
    return netconnType;
}

+ (SXLCGps*)gps
{
    SXUMobAdLocationManager *mgr = [SXUMobAdLocationManager sharedLocationManager];
    
    SXLCGps *gps = [[SXLCGps alloc] init];
    gps.coordinateType  = SXLCGps_CoordinateType_Wgs84;
    gps.longitude       = mgr.coordinate.longitude;
    gps.latitude        = mgr.coordinate.latitude;
    gps.timestamp       = [[NSDate date] timeIntervalSince1970];
    
    return gps;
}

@end
