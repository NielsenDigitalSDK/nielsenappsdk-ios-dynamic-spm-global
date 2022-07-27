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
#import "NlsErrorCollection.h"
#import "NlsLogger.h"

#define kMethodName NSStringFromSelector(_cmd)

@interface NlsErrorReporter : NSObject

@property (nonatomic, weak) NlsLogger *logger;

- (instancetype)initWithWorker:(id)worker;

// method takes variable numbers of arguments, the format string and the variable arguments are expected
- (void)reportErrorWithCode:(LogCode)code format:(NSString *)format, ...;
- (void)reportErrorWithCode:(LogCode)code message:(NSString *)message;
- (void)reportException:(NSException *)exception inMethod:(NSString *)method;

// start/restart error reporting timer
- (void)startReporting;
- (void)restartReporting;

- (void)processShutdown;
- (void)cleanup;

// this API will be used to fire error pings
// immediately without saving to the database
- (void)reportImmediateErrorWithCode:(LogCodeImmediate)code format:(NSString *)format, ...;
- (void)reportImmediateErrorWithCode:(LogCodeImmediate)code message:(NSString *)message;

@end
