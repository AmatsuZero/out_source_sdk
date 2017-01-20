//
//  UIApplication+SXUMobAdAppInfo.m
//  AFTest
//
//  Created by Henray Luo on 2016/12/20.
//  Copyright © 2016年 Henray Luo. All rights reserved.
//

#import "UIApplication+SXUMobAdExtension.h"

@implementation UIApplication (SXUMobAdExtension)

+ (uint32_t)appMajorVersion
{
    NSArray *vArray = [[UIApplication appVersion] componentsSeparatedByString:@"."];
    return vArray.count>0 ? [vArray[0] intValue] : 0;
}

+ (uint32_t)appminorVersion
{
    NSArray *vArray = [[UIApplication appVersion] componentsSeparatedByString:@"."];
    return vArray.count>1 ? [vArray[1] intValue] : 0;
}

+ (uint32_t)appMicroVersion
{
    NSArray *vArray = [[UIApplication appVersion] componentsSeparatedByString:@"."];
    return vArray.count>2 ? [vArray[2] intValue] : 0;
}

+ (NSString *)appVersion
{
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    NSString *appVersion = [infoDictionary objectForKey:@"CFBundleShortVersionString"];
    return appVersion;
}

+ (NSString *)appIdentifier
{
    
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    NSString *identifier = [infoDictionary objectForKey:@"CFBundleIdentifier"];
    return identifier;
}

@end
