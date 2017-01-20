//
//  KSCUserInfoUtils.h
//  KSCCoreWrapper
//
//  Created by zhai chunlin on 16/6/24.
//  Copyright © 2016年 KSC. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(SInt32, KSCNetworkConnectionType) {
    KSCNetworkConnectionTypeConnectionUnknown = 0,
    KSCNetworkConnectionTypeCellUnknown = 1,
    KSCNetworkConnectionTypeCell2G = 2,
    KSCNetworkConnectionTypeCell3G = 3,
    KSCNetworkConnectionTypeCell4G = 4,
    KSCNetworkConnectionTypeCell5G = 5,
    KSCNetworkConnectionTypeWifi = 100,
    KSCNetworkConnectionTypeEthernet = 101,
    KSCNetworkConnectionTypeNewType = 999,
};

typedef NS_ENUM(SInt32, KSCNetworkOperatorType) {
    KSCNetworkOperatorTypeUnknownOperator = 0,
    KSCNetworkOperatorTypeChinaMobile = 1,
    KSCNetworkOperatorTypeChinaTelecom = 2,
    KSCNetworkOperatorTypeChinaUnicom = 3,
    KSCNetworkOperatorTypeOtherOperator = 99,
};

NS_ASSUME_NONNULL_BEGIN
@interface KSCUserInfoUtils : NSObject

/**
 *  idfv: 适用于对内：例如分析用户在应用内的行为等
 *  来源：iOS6.0及以后
 
 *  说明：顾名思义，是给Vendor标识用户用的，每个设备在所属同一个Vender的应用里，都有相同的值。其中
    的Vender是指应用提供商，但准确点说，是通过BundleID的DNS反转的前两部分进行匹配，如果相同就是同
    一个Vender，例如对于com.somecompany.appone,com.somecompany.apptwo 这两个BundleID来
    说，就属于同一个Vender，共享同一个idfv的值。和idfa不同的是，idfv的值是一定能取到的，所以非常
    适合于作为内部用户行为分析的主id，来标识用户，替代OpenUDID。
 
 *  注意：如果用户将属于此Vender的所有App卸载，则idfv的值会被重置，即再重装此Vender的App，idfv的
    值和之前不同。
 */
+ (nullable NSString *)IDFV;

/**
 *  idfa: 适用于对外：例如广告推广，换量等跨应用的用户追踪等
 *  来源：iOS6.0及以后
 
 *  说明：直译就是广告id， 在同一个设备上的所有App都会取到相同的值，是苹果专门给各广告提供商用来追踪
 用户而设的，用户可以在 设置|隐私|广告追踪 里重置此id的值，或限制此id的使用，故此id有可能会取不
 到值，但好在Apple默认是允许追踪的，而且一般用户都不知道有这么个设置，所以基本上用来监测推广效
 果，是戳戳有余了。
 
 *  注意：由于idfa会出现取不到的情况，故绝不可以作为业务分析的主id，来识别用户。
 */
+ (nullable NSString *)IDFA;

/**
 *  keychain 保存IDFV作为唯一标识
 */
+ (nullable NSString *)uniqueIdentification;

/**
 *  获取设备网络类型
 */
+ (KSCNetworkConnectionType)netWorkStates;

/**
 *  运营商类型
 */
+ (KSCNetworkOperatorType)operatorType;

/**
 *  获取设备运营商
 */
+ (nullable NSString *)deviceCarrierName;

/**
 *  设备架构
 */
+ (nullable NSString*)deviceVersionInfo;

/**
 *  获取设备类型
 */
+ (NSString *)currentDeviceModel;

/**
 *  mac地址
 */
+ (NSString *)macAddress;

/**
 *  获取设备电量 误差5%
 */
+ (float)deviceBatteryInfo;

/**
 *  获取总内存
 */
+ (uint64_t)deviceTotalMemorySize;

/**
 *  获取可用内存
 */
+ (uint64_t)deviceAvailableDiskSize;

/**
 *  获取总磁盘容量
 */
+ (uint64_t)deviceTotalDiskSize;

/**
 *  获取 Bundle ID
 */
+ (nullable NSString *)applicationBundleIdentifier;

/**
 *  获取应用发布版本号(CFBundleShortVersionString)
 */
+ (nullable NSString *)applicationVersion;

/**
 *  获取 时间戳
 */
+ (nullable NSString *)timeStamp;

/**
 *  获取本机IP地址
 */
+ (nullable NSString *)localIPAddress:(BOOL)preferIPv4;

/**
 *  获取公网IP地址
 */
+ (nullable NSString *)publicIPAddress;

/**
 *  判断设备是否越狱
 */
+ (BOOL)isJailBreak;

/**
 *  获取当前时间，按指定格式返回
 */
+ (nullable NSString *)currentTimeWithFormat:(nonnull NSString *)format;

@end
NS_ASSUME_NONNULL_END