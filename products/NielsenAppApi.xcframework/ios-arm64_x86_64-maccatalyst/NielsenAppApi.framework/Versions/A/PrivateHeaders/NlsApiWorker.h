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
#import <UIKit/UIKit.h>
#import "NlsDataProcess.h"
#import "NlsDataTransfer.h"
#import "NlsConfigManager.h"

NS_ASSUME_NONNULL_BEGIN

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
@class NlsUtil;
@class NlsTSVResponse;
@class NlsTSVRequestManager;
@class NlsVaViewabilityStorage;
@class NlsVaViewabilityTracker;
@class NlsUserDefaultsStorage;
@class NielsenAppApi;

@class NlsCATLogger;
@protocol NlsCATLoggerEventOwner;

@interface NlsApiWorker : NSObject <NlsBaseDataProcessorDelegate>

@property (nonatomic, strong, readonly, nullable) dispatch_queue_t dataTransferQueue;
@property (nonatomic, strong, readonly, nullable) dispatch_queue_t dataCacheQueue;
@property (nonatomic, strong, readonly, nullable) dispatch_queue_t dataConfigQueue;
@property (nonatomic, strong, readonly, nullable) dispatch_queue_t dataGetTsvQueue;

@property (strong, readonly, nullable) NSThread *workerThread;

@property (strong, readonly, nullable) NlsConfigManager *config;
@property (strong, readonly, nullable) NlsDataTransfer *dataTransfer;
@property (strong, readonly, nullable) NlsUserDefaultsStorage *userDefaultsStorage;
@property (strong, readonly, nullable) NlsCache *meterDatabase;
@property (strong, readonly, nullable) NlsDeviceIdAccess *deviceIdAccess;
@property (strong, readonly, nullable) NlsErrorReporter *errorReporter;
@property (strong, readonly, nullable) NlsApiStatusManager *apiStatusManager;
@property (strong, readwrite, nullable) NlsStorage *storage;
@property (strong, readonly, nullable) NlsLogger *logger;
@property (strong, readonly, nullable) NlsCATLogger *catLogger;
@property (strong, readonly) NlsMappingDictionary *globals;
@property (strong, readonly) NlsFPIDManager *fpidManager;
@property (strong, readonly) NlsDataProcessRequestManager *dataProcessRequestManager;
@property (strong, readonly) NlsTSVRequestManager *tsvRequestManager;
@property (strong, readonly, nullable) NlsVaViewabilityStorage *viewabilityStorage;
@property (strong, readonly, nullable) NlsVaViewabilityTracker *viewabilityTracker;
@property (strong, readwrite) NSDictionary *cmsMapping;

@property (strong, readwrite) NSDictionary *appInfoDict;

@property (nonatomic, readonly) BOOL isOnline;

@property (nonatomic, strong, readonly) NSString *optOutURLString;

@property (assign) BOOL appDisableApi;

@property (nonatomic, weak, nullable) NielsenAppApi *sdkInstance;

- (instancetype)initWithAppInfo:(NSDictionary *)appInfoDict
                        apiType:(NielsenApiType)apiType
                     instanceId:(NSString *)instanceId
                         logger:(nullable NlsLogger *)logger
               apiStatusManager:(NlsApiStatusManager *)apiStatusManager
                        storage:(nullable NlsStorage *)storage
           catLoggerEventsOwner:(nullable id<NlsCATLoggerEventOwner>)catLoggerEventsOwner;

- (void)startViewabilityTrackerWith:(NSInteger)viewTag withParentView:(UIView *)parentView friendlyObstructions:(nullable NSArray<NSNumber *> *)friendlyObstructions;
- (void)sessionStart:(NSDictionary *)metadata;
- (void)loadMetadata:(NSDictionary *)metadata;
- (void)updateOTT:(NSDictionary *)ottInfo;
- (void)sendID3:(NSString *)payload;
- (void)playheadPosition:(long long)playheadPosition;
- (void)sessionForeground;
- (void)sessionBackground;
- (void)sessionShutdown;
- (void)sessionStopForType:(NlsSessionStopType)sessionStopType;
- (void)sessionEnd;
- (void)sessionStaticEnd;
- (void)userOptOut:(BOOL)optOut;
- (NSString *)userOptoutSharedStatus;
- (void)restartConfigRetryTimer;
- (void)refreshDeviceIdAndFireUAIDPings:(BOOL)fireUAIDPings;
- (void)newSessionStartedForProcessor:(NlsBaseDataProcessor *)processor;
- (void)answerAliveWithIdentifier:(NSInteger)identifier appId:(NSString *)appId;

@end

NS_ASSUME_NONNULL_END
