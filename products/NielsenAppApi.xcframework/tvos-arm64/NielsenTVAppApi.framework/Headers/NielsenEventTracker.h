/**
* App SDK Application
*
* Copyright (C) 2016, The Nielsen Company (US) LLC. All Rights Reserved.
*
* Software contains the Confidential Information of Nielsen and is subject to your relevant agreements with Nielsen.
*
* remarks:
* New enhanced SDK API
*/

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

/**
 TrackEvent API parameters
 JSON dict possible keys
 */

#define TrackEventParamEvent @"event"
#define TrackEventParamType @"type"
#define TrackEventParamMetadata @"metadata"
#define TrackEventParamPlayheadPosition @"playheadPosition"
#define TrackEventParamId3Data @"id3Data"
#define TrackEventParamOttData @"ottData"
#define TrackEventParamOptout @"optout"
#define TrackEventParamBuffering @"buffering"
#define TrackEventParamButtonEvent @"buttonEvent"

/**
 TrackEvent API parameters
 Event possible values
 */

#define TrackEventParamEventPlayhead @"playhead"
#define TrackEventParamEventPause @"pause"
#define TrackEventParamEventComplete @"complete"
#define TrackEventParamEventAdStop @"adStop"

/**
 TrackEvent API parameters
 Parameter type possible values
 */

#define TrackEventParamTypeContent @"content"
#define TrackEventParamTypeAd @"ad"
#define TrackEventParamTypeStatic @"static"

/**
 TrackEvent API parameters
 Possible metadata types
 */

#define TrackEventParamMetadataContent @"content"
#define TrackEventParamMetadataAd @"ad"
#define TrackEventParamMetadataStatic @"static"
#define TrackEventParamMetadataAssetId @"assetId"

/**
 TrackEvent API parameters
 Ad metadata types
 */

#define TrackEventParamMetadataAdType   @"type"
#define TrackEventParamAdTypePreroll    @"preroll"
#define TrackEventParamAdTypeMidroll    @"midroll"
#define TrackEventParamAdTypePostroll   @"postroll"

/**
 TrackEvent API parameters
 Button event possible values
 */

#define TrackEventParamButtonPlay @"play"
#define TrackEventParamButtonPause @"pause"
#define TrackEventParamButtonResume @"resume"
#define TrackEventParamButtonStop @"stop"
#define TrackEventParamButtonForward @"forward"
#define TrackEventParamButtonRewind @"rewind"

/**
 Nielsen optout web view close command
 */

#define kNielsenWebClose @"nielsen://close"

@protocol NielsenEventTrackerDelegate;

@interface NielsenEventTracker : NSObject

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
 @param delegate - object of a class that implements NielsenEventTrackerDelegate protocol
 @returns returns (id) pointer to object of a Meter object; nil if error occurred.
 */
- (nullable instancetype)initWithAppInfo:(nonnull id)appInfo delegate:(nullable id<NielsenEventTrackerDelegate>)delegate;

/**
 Initialize parameters for viewability and start observing viewability for the view
 */
- (void)trackViewability:(nonnull NSDictionary *)data;

/**
 Main SDK API method for integration
 @param data - NSDictionary object that includes all the parameters required for reporting player updates to the SDK. Check documentation for proper key naming and values.
 */
- (void)trackEvent:(nonnull NSDictionary *)data;

@end

@protocol NielsenEventTrackerDelegate <NSObject>

@optional

/**
 Notifies about the last event that occurred in the Nielsen App Api framework.
 Provides a NSDictionary object with the event information.
 */
- (void)nielsenEventTracker:(nonnull NielsenEventTracker *)api eventOccurred:(nonnull NSDictionary *)event;

/**
 Notifies about the last error that occurred in the Nielsen App Api framework.
 Provides a NSDictionary object with the error information.
 */
- (void)nielsenEventTracker:(nonnull NielsenEventTracker *)api errorOccurred:(nonnull NSDictionary *)error;

@end

