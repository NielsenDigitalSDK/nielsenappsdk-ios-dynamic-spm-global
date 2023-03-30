/**
* App SDK Application
*
* Copyright (C) 2016, The Nielsen Company (US) LLC. All Rights Reserved.
*
* Software contains the Confidential Information of Nielsen and is subject to your relevant agreements with Nielsen.
*
* remarks:
* the main App SDK object.
*/

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

/**
 Nielsen web view close command
 */
#define kNielsenWebClose @"nielsen://close"

@protocol NielsenAppApiDelegate;

@interface NielsenAppApi : NSObject

//
// R2 Api
//
/*
 Queries the Nielsen App Api version information.
 @returns whether user has opted out or not.
*/
@property (readonly) BOOL optOutStatus;

/**
 Enable / Disable metering for the app.
 Check the current disable status
 */
@property (assign) BOOL appDisableApi;

/**
 Enable / Disable logs for the app.
 Check the current logging status
 */
@property (assign) BOOL debug;

/**
 Deprecated. NielsenId is not used by the SDK anymore
 */
@property (readonly, nonnull) NSString *nielsenId __attribute((deprecated(("nielsenId is not used by the SDK anymore"))));

/**
 Retrieve Demographic ID
 */
@property (readonly, nonnull) NSString *demographicId;

/**
 Retrieve First Party ID
 */
@property (readonly, nonnull) NSString *firstPartyId;

/**
 Retrieve Vendor ID
 */
@property (readonly, nonnull) NSString *vendorId;

/**
 Get the URL of the web page that is used for giving user a chance to
 opt out from the Nielsen measurements.
 */
@property (readonly, nonnull) NSString *optOutURL;

/**
 Queries the Nielsen App Api version information.
 @returns NSString containing the version details.
 */
@property (readonly, nullable) NSString *meterVersion;

/**
 Queries the Nielsen App Api framework for the last event that occurred.
 @returns an NSDictionary object with the event information:
 */
@property (readonly, nullable) NSDictionary *lastEventDict;

/**
 Queries the Nielsen App Api framework for the last error that occurred.
 @returns an NSDictionary object with the error information:
 */
@property (readonly, nullable) NSDictionary *lastErrorDict;


/**
 Initializes the ID3Meter metering framework.
 @param appInfo - a JSON formatted NSString object or NSDictionary object that includes identifications of the app. Check documentation for proper key naming and values.
 @param delegate - object of a class that implements NielsenAppApiDelegate protocol
 @returns returns (id) pointer to object of a Meter object; nil if error occurred.
 */
- (nullable instancetype)initWithAppInfo:(nonnull id)appInfo delegate:(nullable id<NielsenAppApiDelegate>)delegate;

/**
 Initialize parameters for viewability and start observing viewability for the view
 */
- (void)trackViewability:(nonnull NSDictionary *)data;

/**
 Deprecated. NielsenId is not used by the SDK anymore
 */
- (nonnull NSString *)getNielsenId __attribute((deprecated(("nielsenId is not used by the SDK anymore"))));

/**
 Start playing a content.
 @param channelInfo - a JSON formatted NSString object or NSDictionary object that includes metadata of the channel. Check documentation for proper key naming and values.
    This should be availabe when user tap the play button.
 */
- (void)play:(nullable id)channelInfo;

/**
 Load metadata from content.
 @param metadata - a JSON formatted NSString object or NSDictionary object that includes metadata of either the content or ad. Check documentation for proper key naming and values. If available, metadata should come from video server or from ad manager before, during, or after a content. And, app may need to reformat it to json string per requirement from Nielsen
 */
- (void)loadMetadata:(nullable id)metadata;

/**
 Stop or pause playing an ad.
 Pause playing a content.
 */
- (void)stop;

/**
 End of the content play.
 */
- (void)end;

/**
 Current playhead position.
 @param playheadPos - a long integer value represents offset in second from the beginning of the content
 */
- (void)playheadPosition:(long long)playheadPos;

/**
 Send Nielsen ID3 tag data.
 @param data - a string captured from ID3 PRIV info field
 */
- (void)sendID3:(nonnull NSString *)data;

/**
 Force to send a new DCR static view and DCR static duration for previous session when provided loadMetadata is same.
 */
- (void)staticEnd;

/**
 Reporting OTT update event to the SDK.
 @param ottInfo - a JSON formatted NSString object or NSDictionary object that includes details about over-the-top status and device details. Check documentation for proper key naming and values.
 */
- (void)updateOTT:(nonnull id)ottInfo;

/**
 Get the URL of the web page that is used for giving user a chance to
 opt out from the Nielsen measurements.

 Deprecated. Will be removed in future release.
 Please use optOutURLString property instead
 */
- (nonnull NSString *)optOutURLString __attribute((deprecated(("Please use optOutURL property instead."))));

/**
 Disable metering for the app due to user opt out.
 @param optOut - a specific string that contains optout status.
 */
- (BOOL)userOptOut:(nonnull NSString *)optOut;

/**
 Queries the Nielsen App Api version information.
 @returns NSString containing the version details.
 
 Deprecated. Will be removed in future release.
 Please use meterVersion property instead
 */
- (nullable NSString *)getMeterVersion __attribute((deprecated(("Please use meterVersion property instead."))));

/**
 Queries the Nielsen App Api framework for the last event that occurred.
 @returns an NSDictionary object with the event information:

 Deprecated. Will be removed in future release.
 Please use lastEventDict property instead
 */
- (nullable NSDictionary *)getLastEventDict __attribute((deprecated(("Please use lastEventDict property instead."))));

/**
 Queries the Nielsen App Api framework for the last error that occurred.
 @returns an NSDictionary object with the error information:

 Deprecated. Will be removed in future release.
 Please use lastErrorDict property instead
 */
- (nullable NSDictionary *)getLastErrorDict __attribute((deprecated(("Please use lastErrorDict property instead."))));

@end

@protocol NielsenAppApiDelegate <NSObject>

@optional

/**
 Notifies about the last event that occurred in the Nielsen App Api framework.
 Provides a NSDictionary object with the event information.
 */
- (void)nielsenAppApi:(nonnull NielsenAppApi *)appApi eventOccurred:(nonnull NSDictionary *)event;

/**
 Notifies about the last error that occurred in the Nielsen App Api framework.
 Provides a NSDictionary object with the error information.
 */
- (void)nielsenAppApi:(nonnull NielsenAppApi *)appApi errorOccurred:(nonnull NSDictionary *)error;

@end

