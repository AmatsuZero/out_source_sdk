//
//  SXUMobAdLocationMgr.h
//  AFTest
//
//  Created by Henray Luo on 2016/12/20.
//  Copyright © 2016年 Henray Luo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface SXUMobAdLocationManager : NSObject

+ (instancetype)sharedLocationManager;

@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

@end
