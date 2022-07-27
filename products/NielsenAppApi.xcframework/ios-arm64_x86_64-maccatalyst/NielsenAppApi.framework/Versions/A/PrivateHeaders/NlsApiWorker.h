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

#import "NlsKeychainStorage.h"
#import "NlsDataProcess.h"
#import "NlsDataTransfer.h"
#import "NlsConfigManager.h"

typedef NS_ENUM(unsigned int, NielsenApiType) {
    NielsenApiTypeTrackEvent,
    NielsenApiTypeLegacy
};

@class NlsLogger;
@class NlsApiStatusManager;
@class NlsCache;
@class NlsStorage;
@class NlsErrorReporter;
@class NlsDataProcessRequestManager;
@class NlsFPIDManager;
@class NlsDeviceIdAccess;
@class NlsMappingDictionary;
@protocol NlsViewabilityTracker;

@class NlsCATLogger;
@protocol NlsCATLoggerEventOwner;

@interface NlsApiWorker : NSObject <NlsBaseDataProcessorDelegate>

@property (nonatomic, strong, readonly) dispatch_queue_t dataTransferQueue;
@property (nonatomic, strong, readonly) dispatch_queue_t dataCacheQueue;
@property (nonatomic, strong, readonly) dispatch_queue_t dataConfigQueue;
@property (nonatomic, strong, readonly) dispatch_queue_t dataGetTsvQueue;

@property (strong, readonly) NSThread *workerThread;

@property (strong, readonly) NlsConfigManager *config;
@property (strong, readonly) NlsDataTransfer *dataTransfer;
@property (strong, readonly) NlsKeychainStorage *keychainStorage;
@property (strong, readonly) NlsCache *meterDatabase;
@property (strong, readonly) NlsDeviceIdAccess *deviceIdAccess;
@property (strong, readonly) NlsErrorReporter *errorReporter;
@property (strong, readonly) NlsApiStatusManager *apiStatusManager;
@property (strong, readonly) NlsStorage *storage;
@property (strong, readonly, nullable) NlsLogger *logger;
@property (strong, readonly) NlsCATLogger *catLogger;
@property (strong, readonly, nonnull) NlsMappingDictionary *globals;
@property (strong, readonly, nonnull) NlsFPIDManager *fpidManager;
@property (strong, readonly) NlsDataProcessRequestManager *dataProcessRequestManager;
@property (strong, readonly) id<NlsViewabilityTracker> viewabilityTracker;
@property (strong, readonly) NSDictionary *appInfoDict;

@property (nonatomic, readonly) BOOL isOnline;

@property (nonatomic, strong, readonly) NSString *optOutURLString;

@property (assign) BOOL appDisableApi;

@property (nonatomic, weak) NielsenAppApi *sdkInstance;

- (instancetype)initWithAppInfo:(NSDictionary *)appInfoDict
                        apiType:(NielsenApiType)apiType
                     instanceId:(NSString *)instanceId
                         logger:(NlsLogger *)logger
               apiStatusManager:(NlsApiStatusManager *)apiStatusManager
                        storage:(NlsStorage *)storage
           catLoggerEventsOwner:(id<NlsCATLoggerEventOwner>)catLoggerEventsOwner;

- (void)sessionStart:(NSDictionary *)metadata;
- (void)loadMetadata:(NSDictionary *)metadata;
- (void)updateOTT:(NSDictionary *)ottInfo;
- (void)sendID3:(NSString *)payload;
- (void)playheadPosition:(long long)playheadPosition;
- (void)sessionForeground;
- (void)sessionShutdown;
- (void)sessionStopForType:(NlsSessionStopType)sessionStopType;
- (void)sessionEnd;
- (void)userOptOut:(BOOL)optOut;

- (void)restartConfigRetryTimer;
- (void)refreshDeviceIdAndFireUAIDPings:(BOOL)fireUAIDPings;
- (void)newSessionStartedForProcessor:(NlsBaseDataProcessor *)processor;
- (void)answerAliveWithIdentifier:(NSInteger)identifier appId:(NSString *)appId;

@end
