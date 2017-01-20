//
//  AFNetworkDownloader.h
//  AFNetworkTest
//
//  Created by zhai chunlin on 16/7/14.
//  Copyright © 2016年 ZCL. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const KSCNetworkDownloaderErrorDomain;
@interface KSCNetworkDownloader : NSObject

/**
 *  返回 KSCNetworkDownloader 实例
 *
 *  非单例
 */
+ (instancetype)downloader;


/**
 *  根据 configuration 返回 KSCNetworkDownloader 实例
 */
- (instancetype)initWithSessionConfiguration:(nullable NSURLSessionConfiguration *)configuration NS_DESIGNATED_INITIALIZER;


/**
 *  下载
 *
 *  @param URLString             url
 *  @param filePath              下载完成后会保存到cache/KSCNetworkDownloader/[fileName]
 *  @param downloadProgressBlock 下载进度
 *  @param completionHandler     下载完成
 *
 *  @return NSURLSessionDownloadTask 实例
 */
- (nullable NSURLSessionDownloadTask *)download:(NSString *)URLString
                                       filePath:(NSString *)filePath
                                       progress:(nullable void (^)(NSProgress *downloadProgress)) downloadProgressBlock
                              completionHandler:(nullable void (^)(NSURLResponse *response, NSURL * _Nullable filePath, NSError * _Nullable error))completionHandler;

/**
 *  取消任务
 */
- (void)cancel:(NSString *)URLString;

/**
 *  继续任务
 */
- (void)resume:(NSString *)URLString;

/**
 *  支持后台下载需要在 - (void)application:(UIApplication *)application handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)())completionHandler 中调用
 */
- (void)setDidFinishEventsForBackgroundURLSessionBlock:(void (^)(NSURLSession *session))block;

@end
NS_ASSUME_NONNULL_END
