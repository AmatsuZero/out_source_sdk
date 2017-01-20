//
//  NSDictionary+PlainObjectToDictionary.h
//  SDK
//
//  Created by 姜振华 on 2016/12/30.
//  Copyright © 2016年 姜振华. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (PlainObjectToDictionary)

/**
 *  对象转换为字典
 *
 *  @param obj 需要转化的对象
 *
 *  @return 转换后的字典
 */
+ (NSDictionary*)getObjectData:(id)obj;

@end
