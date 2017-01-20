//
//  KSCNetworkHTTPManager.h
//  KSCCoreWrapper
//
//  Created by zcl_kingsoft on 16/7/29.
//  Copyright © 2016年 KSC. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN
@interface KSCNetworkHTTPManager : NSObject

/**
 *  返回 KSCNetWorkHTTPManager 实例
 */
+ (instancetype)HTTPManage;

/**
 *  返回 KSCNetWorkHTTPManager 实例
 *
 *  @param queue    请求完成bolck回调队列
 */
- (instancetype)initWithCompleteQueue:(_Nullable dispatch_queue_t)queue;

/**
 *  同步GET请求
 */
- (NSURLSessionDataTask *)SyncGET:(NSString *)URLString
                          success:(void (^)(NSURLSessionDataTask * _Nonnull dataTask, id _Nullable responseObject))success
                          failure:(void (^)(NSURLSessionDataTask * _Nullable dataTask, NSError * _Nonnull responseObject))failure;

/**
 *  同步POST请求
 */
- (NSURLSessionDataTask *)SyncPOST:(NSString *)URLString
                        parameters:(id)parameters
                           success:(void (^)(NSURLSessionDataTask * _Nonnull dataTask, id _Nullable responseObject))success
                           failure:(void (^)(NSURLSessionDataTask * _Nullable dataTask, NSError * _Nonnull responseObject))failure;

/**
 *  异步GET请求
 */
- (NSURLSessionDataTask *)AsyncGET:(NSString *)URLString
                           success:(void (^)(NSURLSessionDataTask * _Nonnull dataTask, id _Nullable responseObject))success
                           failure:(void (^)(NSURLSessionDataTask * _Nullable dataTask, NSError * _Nonnull responseObject))failure;

/**
 *  异步POST请求
 */
- (NSURLSessionDataTask *)AsyncPOST:(NSString *)URLString
                         parameters:(id)parameters
                            success:(void (^)(NSURLSessionDataTask * _Nonnull dataTask, id _Nullable responseObject))success
                            failure:(void (^)(NSURLSessionDataTask * _Nullable dataTask, NSError * _Nonnull responseObject))failure;

/**
 *  同步请求 自定义request
 */
- (NSURLSessionDataTask *)SyncRequest:(NSURLRequest *)request
                              success:(void (^)(NSURLSessionDataTask * _Nonnull dataTask, id _Nullable responseObject))success
                              failure:(void (^)(NSURLSessionDataTask * _Nullable dataTask, NSError * _Nonnull responseObject))failure;

/**
 *  异步请求 自定义request
 */
- (NSURLSessionDataTask *)AsyncRequest:(NSURLRequest *)request
                               success:(void (^)(NSURLSessionDataTask * _Nonnull dataTask, id _Nullable responseObject))success
                               failure:(void (^)(NSURLSessionDataTask * _Nullable dataTask, NSError * _Nonnull responseObject))failure;

@end
NS_ASSUME_NONNULL_END
