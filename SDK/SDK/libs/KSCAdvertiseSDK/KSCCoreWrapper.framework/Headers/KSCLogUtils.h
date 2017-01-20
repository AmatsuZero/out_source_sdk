//
//  KSCLogUtils.h
//  KSCLogUtils
//
//  Created by zhai chunlin on 16/6/24.
//  Copyright © 2016年 KSC. All rights reserved.
//


#define KSCSDKInfoFile [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/KSCLog.txt"]
#define KSCLogUtilsSingleton   [KSCLogUtils sharedInstance]

FOUNDATION_EXPORT void KSCLog(NSString *format, ...);

@interface KSCLogUtils : NSObject

/**
 *  KSCLog 开关
 */
@property (nonatomic, assign) BOOL logEnable;

+ (instancetype)sharedInstance;

/**
 * 存入本地Log文件
 */
- (void)saveLog:(NSString *)logString;

/**
 *  显示本地Log
 */
+ (void)showSDKInfo;

/**
 * 替换某段字符串，用于本地LOG隐藏
 */
+ (NSString *)stringHiddenWithString:(NSString *)string count:(int)count replacement:(NSString *)replacement;

@end

