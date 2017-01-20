//
//  KSCDataUtils.h
//  KSCCoreWrapper
//
//  Created by zhai chunlin on 16/6/24.
//  Copyright © 2016年 KSC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface KSCDataUtils : NSObject

/**
 *  从info.plist获取对应key的value
 */
+ (nullable NSString *)infoPlistValueForKey:(nonnull NSString *)key;

/**
 *   NSArray or NSDictionary or subClass -> NSString
 */
+ (nullable NSString *)stringFromJsonObject:(nonnull id)jsonObject;

/**
 *  json string -> NSDictionary
 */
+ (nullable NSDictionary *)dictionaryWithJsonString:(nonnull NSString *)jsonString;

/**
 *  json string -> NSArray
 */
+ (nullable NSArray *)arrayWithJsonString:(nonnull NSString *)jsonString;

/**
 *  Json序列化转换
 */
+ (nullable id)JSONSerializableObjectForObject:(nonnull id)obj;

/**
 *  从Json串中获取对应key的value
 */
+ (nullable NSString *)jsonValueWithJsonString:(nonnull NSString *)jsonString key:(nonnull NSString *)key;

/**
 *  从 NSUserDefault 中获取对应key的value
 */
+ (nullable id)objectFromUserDefaultKey:(nonnull NSString *)key;

/**
 *  将key、value存进 NSUserDefault
 */
+ (void)saveUserDefaultValue:(nullable id)value forKey:(nonnull NSString *)key;

/**
 *  查看指定文件大小
 */
+ (unsigned long long)fileSizeFromPath:(NSString *)filePath;

/**
 *  字符串表示文件大小
 */
+ (nullable NSString *)fileSizeToString:(unsigned long long)fileSize;

/**
 *  动态加载
 */
+ (nullable Class)loadClass:(nullable NSString *)className;


/** 字符串处理 */

/**
 *  判断字符串是否为nil/@""/@"NULL"
 */
+ (BOOL)inspectEmptyString:(nullable NSString *)str;
/**
 *  获取cache路径
 */
+ (nullable NSString *)cachePath;

@end
NS_ASSUME_NONNULL_END
