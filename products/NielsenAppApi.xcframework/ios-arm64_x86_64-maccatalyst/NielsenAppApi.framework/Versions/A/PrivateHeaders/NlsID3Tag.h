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
#import "NlsViewPattern.h"

#define NIELSEN_NOL_PC_OFFSET               @"nol_pcoffset"
#define NIELSEN_NOL_FD_OFFSET               @"nol_fdoffset"

#define NIELSEN_ID3TAG_LENGTH               249 // minimum length for the full ID3 tag package
#define NIELSEN_ID3TAG_PARTS                7
#define NIELSEN_ID3TAG_ID                   @"www.nielsen.com"
#define NIELSEN_ID3TAG_ZERO_CID             @"X100zdCIGeIlgZnkYj6UvQ=="
#define NIELSEN_ID3TAG_DEFAULT_BREAKOUT     @"77"
#define NIELSEN_TAG_FIELD_DELIMITER         @"/"
#define NIELSEN_TAG_FIELD_DELIMITER_CHAR    '/'

#define NIELSEN_TAG_EDU_TYPE_IDX            2
#define NIELSEN_TAG_EDU_DATA1_TYPE          0x2


enum NIELSEN_TAG_FIELDS
{
    NIELSEN_TAG_FIELD_ID,
    NIELSEN_TAG_FIELD_PCCID,
    NIELSEN_TAG_FIELD_FDCID,
    NIELSEN_TAG_FIELD_WATERMARKTAG,
    NIELSEN_TAG_FIELD_PC_TIMEOFFSET,
    NIELSEN_TAG_FIELD_FD_TIMEOFFSET,
    NIELSEN_TAG_FIELD_STREAMTYPE,
    NIELSEN_TAG_FIELD_MAX
};

@interface NlsID3Tag : NSObject

@property (nonatomic, readonly) NSString *sessionFdCid;
@property (nonatomic, readonly) NSString *sessionPcCid;
@property (nonatomic, readonly) NSString *pcTimeOffset;
@property (nonatomic, readonly) NSString *fdTimeOffset;
@property (nonatomic, readonly) NSString *newestFdCid;
@property (nonatomic, readonly) NSString *newestPcCid;
@property (nonatomic, readonly) NSString *breakout;
@property (nonatomic, readonly) NSString *nielsenUrl;
@property (nonatomic, readonly) NSString *watermarkTag;
@property (nonatomic, readonly) NSString *fullID3Tag;
@property (nonatomic, readonly) BOOL isInfoTag;
@property (nonatomic, readonly) BOOL isSessionCidChanged;
@property (nonatomic, readonly) BOOL isSessionPcCidChanged;
@property (nonatomic, readonly) BOOL isSessionFdCidChanged;
@property (nonatomic, readonly) BOOL isFdCidChanged;
@property (nonatomic, readonly) BOOL isZeroPcCid;
@property (nonatomic, readonly) BOOL isZeroFdCid;


@property (nonatomic) BOOL enableForcePingMode;
@property (nonatomic) int maxDaypartsNumber;
@property (nonatomic, strong) NSString *sessionTimerCid;

@property (nonatomic) int idxFieldPcOffset;
@property (nonatomic) int idxFieldFdOffset;
@property (nonatomic) int idxFieldBreakout;
@property (nonatomic) int idxFieldTagId;
@property (nonatomic) int idxFieldPcCid;
@property (nonatomic) int idxFieldFdCid;
@property (nonatomic) int idxFieldPdu;

@property (nonatomic, readonly) int sessionTotalViewedSeconds;
@property (nonatomic, readonly) int segmentTotalViewedSeconds;
@property (nonatomic) int processorType;
@property (nonatomic) BOOL didIntterupt;

@property (nonatomic, strong) NSString* lastKnownFdCid;

- (id)initID3TagWithSegmentSize:(int)segmentSize
                       slotSize:(int)slotSize
                    winSlotSize:(int)winSlotSize
                        nullCID:(NSString *)nullCID
                       breakout:(NSString *)defaultBreakout
                  sendQualifier:(int)sendQualifier
                    sessionType:(SessionType)inSessionType
                  processorType:(int)processorType
                    creditPause:(BOOL)creditPause
                   minThreshold:(int)minThreshold
                   maxThreshold:(int)maxThreshold
                         selTim:(NSString *)selTimer
                       maxPings:(int)maxPings
                    shortFormat:(int)inShortPingFormatValue
           defaultSegmentNumber:(int)defaultSegmentNumber
                         logger:(NlsLogger*)logger
            viewPatternDelegate:(id<NlsViewPatternDelegate>)viewPatternDelegate;


- (NSString *)validateId3Tag:(NSString *)id3Tag;
- (BOOL)isNewSessionNeededForID3Tag:(NSString *)id3Tag;
- (BOOL)isSessionCidChangedForTimer:(NSString *)timer withTag:(NSString *)id3Tag;

- (void)loadID3Tag:(NSString *)id3Tag logWatermarkTag:(BOOL)logWatermarkTag;
- (void)setStationId:(NSString *)stationId;

- (void)handleOttTransition;
- (BOOL)isTimerCidChanged:(NSString *)timer;
- (BOOL)addOffset:(long long)offset realPos:(long long)nRealPosition withArrivalTime:(NSTimeInterval)arrivalTime;
- (int)timerPingWithParamsFlag:(char)flag
                shortPingState:(BOOL)isShortPingActive
                   immediately:(BOOL)isImmediately
                      nolTimer:(NSString *)timer
                         pcCid:(NSString **)pcCid
                         fdCid:(NSString **)fdCid
                      breakout:(NSString **)breakout
                       pattern:(NSString **)pattern
                       station:(NSString **)station
                       segment:(int *)pSegment
                     timerPing:(long long *)pPingTimer
           segmentPlaybackTime:(int *)pSegmentPlaybackTime
           sessionPlaybackTime:(int *)pSessionPlaybackTime;
- (void)setDidInterrupt:(BOOL)didInterrupt;

@end
