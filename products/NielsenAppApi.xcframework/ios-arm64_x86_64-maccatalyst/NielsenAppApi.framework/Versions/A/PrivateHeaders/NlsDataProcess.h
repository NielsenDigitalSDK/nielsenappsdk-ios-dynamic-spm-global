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
#import "NlsID3MeterConstants.h"
#import "NlsBaseDataProcessor.h"

@class NlsID3Tag;
@class NlsDataProcessRequest;

@interface NlsDataProcess : NlsBaseDataProcessor

@property (nonatomic, strong) NlsID3Tag *pId3Tag;
@property (nonatomic) BOOL contentPlaybackEnded;
@property (nonatomic) NlsContentType content;
@property (nonatomic) NSInteger lastContentPlayhead;

// two variables below are introduced in order to implement
// non ad view pattern pausing on ad interruption
@property (nonatomic) NSString *previousNonAdActiveContent;
@property (nonatomic) NSString *previousNonAdAssetId;

@property (nonatomic) int viewPatternSource;
@property (nonatomic, strong) NlsDataProcessRequest *currentDataProcessRequest;

- (void)newPatternObject;

@end

@protocol NlsEventDataProcessDelegate <NSObject>

- (void)pauseDetectedWithOffset:(long long)value withArrivalTime:(NSTimeInterval)arrivalTime;

@optional

- (void)adDetectedWithArrivalTime:(NSTimeInterval)arrivalTime;

@end
