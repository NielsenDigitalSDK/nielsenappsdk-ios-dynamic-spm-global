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

@class NlsUtil;
/// Enumeration contains all the types of log levels
/// supported by NlsLogger. If some level is enabled then
/// all the log mnessages with this level and higher level
/// are added to the console and the log file
///
typedef NS_ENUM(unsigned int, LogMessageLevel) {
    
    /// Logging is completely disabled
    LevelNone,
    
    /// Only critical errors are logged
    /// This level is set by default when a logger instance
    /// is created for non-DEBUG buulds
    LevelCritical,
    
    /// Info level is used by clients to
    /// see log messages about API calls they make
    /// and other information messages
    LevelInfo,
    
    /// Error level is used to notify about some serous
    /// errors in the SDK
    LevelError,
    
    /// Warning level is used to warn about some non-serous
    /// issues in the SDK
    LevelWarn,
    
    /// All the debug messages are logged with the Debug level.
    /// This level is enabled by default in the DEBUG builds
    /// (automator, sample players). Debug logs are mostly used
    /// by the dev and QA teams during the SDK development
    LevelDebug
};

@interface NlsLogger : NSObject

@property (nonatomic, assign) LogMessageLevel logLevel;
@property (nonatomic, strong) NSString *playerId ;
@property (nonatomic, assign) NSInteger instanceId;
@property (nonatomic, strong) NSString *appId;
@property (nonatomic, readonly) BOOL enabled;
@property (nonatomic) BOOL fileLoggingEnabled;

// method takes variable numbers of arguments, the format string and the variable arguments are expected
- (void)logWithLevel:(LogMessageLevel)messageLevel format:(NSString *)format, ...;

// mehtod takes the final log message
- (void)logWithLevel:(LogMessageLevel)messageLevel message:(NSString *)message;

// mehtod takes the final log message and print it to the file and to the console of needed
- (void)logWithLevel:(LogMessageLevel)messageLevel message:(NSString *)message fileOnly:(BOOL)fileOnly;

// use this method only if NlsLogger object is unavailable
+ (void)postLogLevel:(LogMessageLevel)messageLevel message:(NSString *)message;

// Synchronous task needed to flush all the asynchronous logs
- (void)cleanup;

@end

@interface NlsLogger (Configuration)

+ (LogMessageLevel)logLevelFromDevDebugFlag:(NSString *)devDebug;

@end
