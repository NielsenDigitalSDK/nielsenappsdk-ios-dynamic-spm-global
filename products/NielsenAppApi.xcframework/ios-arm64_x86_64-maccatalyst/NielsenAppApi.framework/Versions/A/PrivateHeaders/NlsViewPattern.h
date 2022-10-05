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
#import "NlsLogger.h"

typedef NS_ENUM(unsigned int, SessionType)
{
    SESSION_IMPRESSION, // "impression"
    SESSION_VIEW,       // "episode"
    SESSION_PATTERN,    // "interval"
    SESSION_STREAM,
    SESSION_DAYPART,
    SESSION_VRIVIDEO   // "modcadence"
};

@class NlsViewPattern;

@protocol NlsViewPatternDelegate <NSObject>

@optional
- (void)didSessionStartedForViewPattern:(NlsViewPattern*)viewPattern;
- (void)didAddedPlayheadWithValue:(long long)value forViewPattern:(NlsViewPattern*)viewPattern withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)didDetectRewindTo:(long long)playhead withValue:(long long)value forViewPattern:(NlsViewPattern*)viewPattern withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)didDetectForwardTo:(long long)playhead withValue:(long long)value forViewPattern:(NlsViewPattern*)viewPattern withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)didSessionChangedForViewPattern:(NlsViewPattern*)viewPattern;

@end

@interface NlsViewPattern : NSObject

@property (nonatomic, strong) NSString* stationId;
@property (nonatomic) BOOL enableForcePingMode;
@property (nonatomic) NSTimeInterval lastViewTime;
@property (nonatomic, readonly) int sessionTotalViewedSeconds;
@property (nonatomic, readonly) int segmentTotalViewedSeconds;

- (id)initWithSegmentSize:(int)inSzSeg
                 slotSize:(int)inSzSlot
              winSlotSize:(int)inSzWinSlot
            sendQualifier:(int)sendQualifier
              sessionType:(SessionType)inSessionType
              creditPause:(BOOL)creditPause
             minThreshold:(int)minThreshold
             maxThreshold:(int)maxThreshold
                 maxPings:(int)maxPings
              shortFormat:(int)inShortPingFormatValue
     defaultSegmentNumber:(int)defaultSegmentNumber
                   logger:(NlsLogger *)logger
                 delegate:(id<NlsViewPatternDelegate>)delegate;

- (BOOL)addCurrentPosition:(long long)position realPosition:(long long)realPosition withArrivalTime:(NSTimeInterval)arrivalTime;

- (int)pingWithParamsFlag:(char)creditFlag
           shortPingState:(BOOL)isShortPingActive
              immediately:(BOOL)isImmediately
                  pattern:(NSString **)pattern
                  station:(NSString **)station
                  segment:(int *)pSegment
                    timer:(long long *)pPingTimer
      segmentPlaybackTime:(int *)pSegmentPlaybackTime
      sessionPlaybackTime:(int *)pSessionPlaybackTime;

- (void)resetOnStationChange;

- (void)resetOnOttTransition;

@end
