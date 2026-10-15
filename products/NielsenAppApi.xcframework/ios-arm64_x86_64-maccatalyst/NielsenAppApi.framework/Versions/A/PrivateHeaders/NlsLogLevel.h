/**
 * App SDK Application
 *
 * Copyright (C) 2025, The Nielsen Company (US) LLC. All Rights Reserved.
 *
 * Software contains the Confidential Information of Nielsen and is subject to your relevant agreements with Nielsen.
 *
 * remarks:
 *
 */

#import <os/log.h>
#import <Foundation/Foundation.h>

// Forward declaration for macros
@class NlsLogger;

// MARK: - Logging Macros

#define LOG_WITH_TIMESTAMP(message) \
os_log_info([NlsLogger sharedLogHandle], "[%lld] %{public}@", (long long)([[NSDate date] timeIntervalSince1970]), message);

#define NLS_LOG_INFO(format, ...) \
os_log_info([NlsLogger sharedLogHandle], format, ##__VA_ARGS__)

#define NLS_LOG_DEBUG(format, ...) \
os_log_debug([NlsLogger sharedLogHandle], "%{public}" format, ##__VA_ARGS__)

// MARK: - Log Level Enum

@class NlsUtil;

/// Enumeration contains all the types of log levels
/// supported by NlsLogger. If some level is enabled then
/// all the log messages with this level and higher level
/// are added to the console and the log file
///
typedef NS_ENUM(NSUInteger, LogMessageLevel) {
    
    /// Logging is completely disabled
    LevelNone = 0,
    
    /// Only critical errors are logged
    /// This level is set by default when a logger instance
    /// is created for non-DEBUG builds
    LevelCritical,
    
    /// Info level is used by clients to
    /// see log messages about API calls they make
    /// and other information messages
    LevelInfo,
    
    /// Error level is used to notify about some serious
    /// errors in the SDK
    LevelError,
    
    /// Warning level is used to warn about some non-serious
    /// issues in the SDK
    LevelWarn,
    
    /// All the debug messages are logged with the Debug level.
    /// This level is enabled by default in the DEBUG builds
    /// (automator, sample players). Debug logs are mostly used
    /// by the dev and QA teams during the SDK development
    LevelDebug
};
