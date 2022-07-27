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

@class NlsErrorReporter;

#ifdef __cplusplus
extern "C" {
#endif

//safe version of dispatch_queue_create - set context to queue
// to check it in sync call and avoid deadlocks
dispatch_queue_t
dispatch_queue_create_safe(const char *label);

//safe version of dispatch_async - catches exceptions
//which were thrown during invacation of the code block
void
dispatch_async_safe(NlsErrorReporter *errorReporter, dispatch_queue_t queue, dispatch_block_t block);

//safe version of dispatch_async with finally block - catches exceptions
//which were thrown during invacation of the code block
//finaly block is executed if exception happens
void
dispatch_async_safe_finally(NlsErrorReporter *errorReporter, dispatch_queue_t queue, dispatch_block_t block, dispatch_block_t finallyBlock);

//safe version of dispatch_sync - catches exceptions
//which were thrown during invacation of the code block
void
dispatch_sync_safe(NlsErrorReporter *errorReporter, dispatch_queue_t queue, dispatch_block_t block);

//safe version of dispatch_async with the main queue:
//catches exceptions which were thrown during invacation of the code block
void
dispatch_async_safe_main_queue_with_check(NlsErrorReporter *errorReporter, dispatch_block_t block);

//safe version of dispatch_sync with the main queue:
//1. catches exceptions which were thrown during invacation of the code block
//2. has a check in order to prevent deadlock if the call was perform on the Main thread
void
dispatch_sync_safe_main_queue_with_check(NlsErrorReporter *errorReporter, dispatch_block_t block);

#ifdef __cplusplus
}
#endif
