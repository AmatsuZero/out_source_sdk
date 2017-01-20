//
//  NSString+JSONConversion.h
//  SDK
//
//  Created by 姜振华 on 2016/12/30.
//  Copyright © 2016年 姜振华. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (JSONConversion)

/*!
 
 * @brief 把格式化的JSON格式的字符串转换成字典
 
 * @param jsonString JSON格式的字符串
 
 * @return 返回字典
 
 */

+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;

+ (NSString*)dictionaryToJson:(NSDictionary *)dic;

@end
