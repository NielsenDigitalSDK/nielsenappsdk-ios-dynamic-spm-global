/**
 * App SDK Application
 *
 * Copyright (C) 2020, The Nielsen Company (US) LLC. All Rights Reserved.
 *
 * Software contains the Confidential Information of Nielsen and is subject to your relevant agreements with Nielsen.
 *
 * remarks:
 *
 */

#import <Foundation/Foundation.h>

@class NlsApiWorker;

@interface NlsFPIDManager : NSObject

@property (nonatomic, readonly) NSString * _Nonnull vendorId;
@property (nonatomic, readonly) NSString * _Nonnull fpid;
@property (nonatomic, readonly) NSTimeInterval fpidCreationTimestamp;
@property (nonatomic, readonly) NSTimeInterval fpidLastAccessedTimestamp;
@property (nonatomic, readonly) NSTimeInterval fpidLastEMMSentTimestamp;

@property (nonatomic, readonly) NSTimeInterval lastEMMSentTimestampFromDefaults;

- (nullable instancetype)initWithWorker:(nullable NlsApiWorker *)worker;

- (void)handleConfigResponse;
- (void)refreshFpIdFromDefaults;
- (void)handleSessionPingSent:(BOOL)sent;
- (void)handleEMMPingSent:(BOOL)sent;

@end
