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

@protocol NlsBaseDataProcessorDelegate <NSObject>
@optional
- (void)pingStoredForUpload:(NielsenProductType)processorType;
@end

@interface NlsBaseDataProcessor : NSObject <NlsViewPatternDelegate>

@property(nonatomic, strong) dispatch_queue_t dataProcessQueue;
@property(nonatomic) NielsenProductType processorType;
@property(nonatomic, weak) id<NlsBaseDataProcessorDelegate> delegate;
@property(nonatomic, strong) NSArray *requiredMetadataParams;
@property(nonatomic, readonly) NSDictionary* lastPingDictionary;
@property(nonatomic, readonly) NSString *viewabilityType;
@property(nonatomic, readonly) NSDictionary *additionalViewabilityParameters;

- (instancetype)initWithWorker:(id)meterWorker withPid:(NSInteger)pid;
- (void)processStart:(NSDictionary *)metadata withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processID3:(NSString *)data withDtvrGuid:(NSString *)dtvrGuid andArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processPlayheadPosition:(long long)playheadPosition withArrivalTime:(NSTimeInterval) arrivalTime;
- (void)processMetadata:(NSDictionary *)metadata withDcrGuid:(NSString *)dcrGuid andArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processOTT:(NSDictionary *)ottInfo withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processShutdownWithArrivalTime:(NSTimeInterval)arrivalTime forceUpload:(BOOL)forceUpload;
- (void)processStopForType:(NlsSessionStopType)sessionStopType withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processEndWithArrivalTime:(NSTimeInterval)arrivalTime internalCall:(BOOL)internal;
- (void)processMuteChanged:(BOOL)value withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processAddedPlayheadWithValue:(long long)value withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processZeroDurationSegment;
- (void)processForwardWithValue:(long long)value withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processRewindWithValue:(long long)value withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)processAppDisable:(BOOL)appDisable;
+ (NielsenProductType)processorTypeForProduct:(NSString*)product;
- (void)logPingWithDuration:(int)duration;
- (BOOL)validateInputMetadata:(NSDictionary *)inputData withType:(NlsContentType)inputType;
- (void)flushPendingWithArrivalTime:(NSTimeInterval)arrivalTime immediately:(BOOL)immediately;

@end
