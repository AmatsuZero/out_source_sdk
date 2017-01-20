//
//  CipherUtils.h
//  XinYouPlatform
//
//  Created by ajie on 2014-12-2.
//  Copyright (c) 2014年 ajie. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface KSCCipherUtils : NSObject

/**
 * md5加密
 */
+ (nullable NSString *)md5:(NSString *)text;

/**
 * 非对称加密
 */
+ (nullable NSData *)encryptRSA:(NSString *)publicKey plainData:(NSData *)plainData;

/**
 * base64解密
 */
+ (nullable NSData *)base64Decode:(NSString *)string;

/**
 * base64加密
 */
+ (nullable NSString *)base64Encode:(NSData *)data;

/**
 * DES加密
 */
+ (nullable NSString *)encryptModeDES:(NSString *)plainText key:(NSString *)key;

/**
 *  SHA1加密
 */
+ (nullable NSString *)hmacSha1:(NSString *)key text:(NSString *)text;

/**
 *  编码字符串
 */
+ (nullable NSString *)urlEncodedString:(NSString *)stringToEncode;

/**
 *  AES+Base64加密
 */
+ (nullable NSString *)encryptAESString:(NSString*)string appKey:(NSString*)key;

/**
 *  AES+Base64解密
 */
+ (nullable NSString *)decryptAESString:(NSString *)string appKey:(NSString *)key;

@end
NS_ASSUME_NONNULL_END