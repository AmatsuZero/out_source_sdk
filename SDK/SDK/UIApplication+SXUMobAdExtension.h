//
//  UIApplication+SXUMobAdAppInfo.h
//  AFTest
//
//  Created by Henray Luo on 2016/12/20.
//  Copyright © 2016年 Henray Luo. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIApplication (SXUMobAdExtension)

+ (uint32_t)appMajorVersion;
+ (uint32_t)appminorVersion;
+ (uint32_t)appMicroVersion;

+ (NSString *)appIdentifier;

@end
