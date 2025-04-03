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

#import "NlsDataProcess.h"
#import "NlsUrlParser.h"

typedef NS_ENUM(unsigned int, CidType) {
    CidTypeFD = 0,
    CidTypePC
};

@interface NlsID3DataProcessor : NlsDataProcess <NlsEventDataProcessDelegate>

- (void)processCidChange:(CidType)cidType withArrivalTime:(NSTimeInterval)arrivalTime tsvValue:(NSString **)tsvValue;
- (void)handleOffsetChangeEvent:(NSString*)newVod :(NSString*)offsetValue withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)handleBreakOutEvent:(NSString*)newVod :(NSString*)offsetValue withArrivalTime:(NSTimeInterval)arrivalTime;
- (void)handlePlayEvent:(NSTimeInterval)arrivalTime withOffset:(NSString*)offset;
- (void)handleStopEvent:(NSTimeInterval)arrivalTime;
- (void)handleAdModelEvent:(NSTimeInterval)arrivalTime latestOffset:(NSString*)offset;
- (void)handleEventDataOnCidChange;

- (void)startSubminutePingGenerationTimer;
- (void)invalidateSubminutePingGenerationTimer;

@end
