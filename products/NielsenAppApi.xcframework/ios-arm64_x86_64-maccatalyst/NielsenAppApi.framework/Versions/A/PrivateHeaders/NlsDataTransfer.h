/**
 * App SDK Application
 *
 * Copyright (C) 2016, The Nielsen Company (US) LLC. All Rights Reserved.
 *
 * Software contains the Confidential Information of Nielsen and is subject to your relevant agreements with Nielsen.
 *
 * remarks:
 *
 */

#import <Foundation/Foundation.h>

@interface NlsDataTransfer : NSObject

- (instancetype)initWithWorker:(id)worker;

- (void)uploadData;
- (void)uploadErrors;

- (void)handleConfigRetryCompleted;

// complete uploading of the current ping and stop uploading
- (void)stopUploading;

// has to be called on the worker thread
- (void)stopUploadTimer;

// queue data pings uploading
- (void)queueUploadDataAsync;

// queue error pings uploading
- (void)queueUploadErrorsAsync;

@end
