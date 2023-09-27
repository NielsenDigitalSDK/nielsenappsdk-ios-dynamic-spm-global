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
#import "NlsConfigManager.h"
#import "NlsViewPattern.h"
#import "NlsCache.h"
#import "NlsDataProcess.h"


typedef NS_ENUM(unsigned int, NielsenProductType) {
    ID3RawProduct = 0,
    DprPatternProduct,
    DprId3PatternProduct,
    MtvrPatternProduct,
    OCRProduct,
    LegacyProduct,
    DrmPatternProduct,
    DcrVideoPatternProduct,
    DcrStaticProduct,
    VriProduct,
    OtherProduct
};

typedef NS_ENUM(NSUInteger, NlsContentType) {
    NlsContentTypeContent,
    NlsContentTypePreroll,
    NlsContentTypeMidroll,
    NlsContentTypePostroll,
    NlsContentTypeAd,
    NlsContentTypeStatic,
    NlsContentTypeOther
};

typedef NS_ENUM(NSUInteger, NlsSessionStopType) {
    NlsSessionStopTypeOnPlay = 0,
    NlsSessionStopTypeOnAdInterruption,
    NlsSessionStopTypeOnAssetIdChange,
    NlsSessionStopTypeOnStop
};

@class NlsBaseDataProcessor;
@class NlsUrlParser;
@class NlsMappingDictionary;
@class NlsApiWorker;

@protocol NlsBaseDataProcessorDelegate <NSObject>
@optional
- (void)pingStoredForUpload:(NielsenProductType)processorType;
@end

@interface NlsBaseDataProcessor : NSObject <NlsViewPatternDelegate>
@property(nonatomic, strong) dispatch_queue_t dataTransferQueue;
@property(nonatomic, strong) dispatch_queue_t dataCacheQueue;

@property(nonatomic, strong) dispatch_queue_t dataProcessQueue;
@property(nonatomic) NielsenProductType processorType;
@property(nonatomic, weak) id<NlsBaseDataProcessorDelegate> delegate;
@property(nonatomic, strong) NSMutableArray *requiredMetadataParams;
@property(nonatomic, readonly) NSDictionary* lastPingDictionary;
@property(nonatomic) BOOL isViewabilityProcessor;

// removing protected file
@property (nonatomic, weak) NlsConfigManager *config;
@property (nonatomic, readwrite) NlsApiWorker *worker;
@property (nonatomic, weak) NlsCache *meterDatabase;

//config url
@property (nonatomic, strong) NSString *url;

@property (nonatomic, strong) NSDictionary *tagConfigDefaultDict;
@property (nonatomic) int processorId;
@property (nonatomic) BOOL disableFlag;

@property (nonatomic, readwrite) NlsMappingDictionary *cmsInfoDict;
@property (atomic, strong) NSDictionary *playInfoDict;

@property (nonatomic) SessionType inSessionType;
@property (nonatomic, strong) NSString *cadence;
@property (nonatomic) int maxPingCount;
@property (nonatomic) int currentPingCount;
@property (nonatomic) BOOL delayedPings;
@property (nonatomic) BOOL unifiedEnabled;
@property (nonatomic) NSTimeInterval backgroundThreshold;
@property (nonatomic) NSTimeInterval startTime;
@property (nonatomic, strong) NSString *sessionId;
@property (nonatomic, strong) NSString *sessionIdPending;

@property (nonatomic, weak) NlsUrlParser* pingUrlParser;

@property (nonatomic, strong) NSString *nolTimer;
@property (nonatomic) int segmentLength;
@property (nonatomic) int segmentBaseDuration;
@property (nonatomic) int creditValue;
@property (nonatomic, strong) NSString *defaultBreakout;
@property (nonatomic, strong) NSString *creditFlag;
@property (nonatomic, strong) NSString *segmentPrefix;
@property (nonatomic, strong) NSString *shortPingPrefix;
@property (nonatomic) int sendQualifier;
@property (nonatomic) int minIntervalThreshold;
@property (nonatomic) int maxIntervalThreshold;
@property (nonatomic) int shortPingFormatValue;
@property (nonatomic) int defaultSegmentNumber;

//have to be moved to NlsDataProcess class
@property (nonatomic, strong) NSString *cidNull;

@property(nonatomic, readonly) BOOL measurePauseForViewability;


- (NlsContentType)defineContentTypeFromMetadata:(NSDictionary *)data;
- (NSInteger)getTagConfigIntValue:(NSString *)tag withDefault:(NSInteger)nDefault;
- (long long)adjustPosition:(long long)playheadPosition;
- (BOOL)nolVariablesWithTimer:(long long)playheadPosition;
- (BOOL)createPingForDictionary:(NSDictionary*)dictionary withArrivalTime:(NSTimeInterval)arrivalTime;
- (BOOL)createPingForDictionary:(NSDictionary*)dictionary withArrivalTime:(NSTimeInterval)arrivalTime andStartTime:(long long)startTime;
- (void)applyOnPingCreateLogicWithImmediately:(BOOL)immediately;
- (BOOL)chkDisable:(NSString *)strDisableFlag;
- (BOOL)preparePingToSend:(NSTimeInterval)arrivalTime immediately:(BOOL)bImmed;
- (void)configureActiveContentAndVidType:(NlsMappingDictionary *)eventDictionary;
- (BOOL)applyOnAssetIdChangeFilter;
- (void)applyOnMetadataDetectedFilterLogic;
- (void)applyOnEndDetectedFilterLogic;
- (void)logMissedRequiredParams:(NSArray *)requiredParams inDictionary:(NSDictionary *)inputData;
- (void)setDefaultTimerValue;
- (void)restartProcessor;
- (void)resetMetadataInfo;
- (BOOL)isDurationPingFromDictionary:(NSDictionary *)dictionary;
- (void)configureCMSInfoDictionary:(NlsMappingDictionary *)inputCmsDictionary;
- (NSDictionary *)viewabilityDictionary;

- (instancetype)initWithWorker:(id)meterWorker withPid:(NSInteger)pid;
- (BOOL)validateInputMetadata:(NSDictionary *)inputData withType:(NlsContentType)inputType;
- (void)flushPendingWithArrivalTime:(NSTimeInterval)arrivalTime immediately:(BOOL)immediately;
- (void)processStart:(NSDictionary *)metadata withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processID3:(NSString *)data withDtvrGuid:(NSString *)dtvrGuid andArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processPlayheadPosition:(long long)playheadPosition withArrivalTime:(NSTimeInterval) arrivalTime;
- (void)processMetadata:(NSDictionary *)metadata withDcrGuid:(NSString *)dcrGuid andArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processOTT:(NSDictionary *)ottInfo withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processShutdownWithArrivalTime:(NSTimeInterval)arrivalTime forceUpload:(BOOL)forceUpload;
- (void)processBackgroundWithArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processStopForType:(NlsSessionStopType)sessionStopType withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processEndWithArrivalTime:(NSTimeInterval)arrivalTime internalCall:(BOOL)internal;
- (void)processMuteChanged:(BOOL)value withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processAddedPlayheadWithValue:(long long)value withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processRewindTo:(long long)playhead withValue:(long long)value withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processForwardTo:(long long)playhead withValue:(long long)value withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processPauseWithArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processAppDisable:(BOOL)appDisable;
- (void)processAdWithArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processStaticEndWithArrivalTime:(NSTimeInterval)arrivalTime;
+ (NielsenProductType)processorTypeForProduct:(NSString*)product;
- (void)logPingWithDuration:(int)duration;
- (NSString *)parseFormattedString:(NSString *)formattedString;

@end
