//
//  SXUMobAdLocationMgr.m
//  AFTest
//
//  Created by Henray Luo on 2016/12/20.
//  Copyright © 2016年 Henray Luo. All rights reserved.
//

#import "SXUMobAdLocationManager.h"

@interface SXUMobAdLocationManager () <CLLocationManagerDelegate>

@property (nonatomic, strong) CLLocationManager *locationMgr;
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

@end

@implementation SXUMobAdLocationManager

+ (instancetype)sharedLocationManager
{
    static SXUMobAdLocationManager* mgr = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        if (mgr == nil) {
            mgr = [[self alloc] init];
        }
    });
    return mgr;
}

#pragma mark - CLLocationManagerDelegate
-(void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status {
    if (kCLAuthorizationStatusAuthorizedWhenInUse == status || kCLAuthorizationStatusAuthorizedAlways == status) {
        [self.locationMgr startUpdatingLocation];
    }
}

- (void)locationManager:(CLLocationManager *)manager
    didUpdateToLocation:(CLLocation *)newLocation
           fromLocation:(CLLocation *)oldLocation
{
    NSLog(@"Get Location = %f,%f",newLocation.coordinate.latitude,newLocation.coordinate.longitude);
    _coordinate = newLocation.coordinate;
    [self.locationMgr startUpdatingLocation];
}

- (void)locationManager:(CLLocationManager *)manager
       didFailWithError:(NSError *)error
{
    NSLog(@"Get Location Error = %@",error);
}

#pragma mark - property -

- (CLLocationManager *)locationMgr
{
    if (!_locationMgr) {
        _locationMgr = [[CLLocationManager alloc] init];
        _locationMgr.delegate = self;
        _locationMgr.desiredAccuracy = kCLLocationAccuracyBest;
        _locationMgr.distanceFilter = 5.0;
    }
    return _locationMgr;
}

@end
