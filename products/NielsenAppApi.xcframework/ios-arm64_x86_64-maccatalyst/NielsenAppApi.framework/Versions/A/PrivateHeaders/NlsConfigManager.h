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

// Config URL template
#define vNonTrackingDomainDefaultName   @"nmrodam.com"
#define vTrackingDomainDefaultName   @"imrworldwide.com"
#define vCfgDefaultConfigUrl @"https://cdn-gl."vNonTrackingDomainDefaultName"/conf/|!nol_appid!|.json?devtypid=|!nol_devtypeid!|&devid=&devname=|!(nol_devname)!|&osver=|!(nol_osversion)!|&sysname=|!(nol_sysname)!|&bid=|!nol_bundleID!|"

// this page either HTML for mobile or JS for appleTV
#define kDefaultOptOutURLFormatUserChoice @"https://priv-policy.imrworldwide.com/priv/|!nol_devicetype!|/|![nol_localeCountryCode]!|/|![nol_language]!|/optout_legacy.html"
#define kDefaultOptOutURLFormatIDFA @"https://priv-policy.imrworldwide.com/priv/|!nol_devicetype!|/|![nol_localeCountryCode]!|/|![nol_language]!|/optout.html"

#define vCidNullDefault                 @"X100zdCIGeIlgZnkYj6UvQ=="
#define vVidTypeAdValue                 @"ad"
#define vVidTypeContentValue            @"content"
#define vVidTypeStaticValue             @"static"
#define vC3TypeAdValue                  @"st,a"
#define vC3TypeContentValue             @""

#define vDavStateStartValue             @"0"
#define vDavStateUpdateValue            @"1"
#define vDavStateStopValue              @"2"
#define vTsvDefaultValue                @"99"

#define vDefaultRawID3MaxLength         @"1800"
#if TARGET_OS_TV
#define vDefaultOfflinePingLimit        @"8"
#else
#define vDefaultOfflinePingLimit        @"300"
#endif
#define vDefaultCreditValue             30
#define vDefaultMaxPendingPingRetry     @"5"
#define vDefaultSegLength               5
#define vDefaultSegDuration             60
#define vDefaultSegmentNumber           0
#define vCfgDefaultConfigValidPeriod    7 // days
#define vCfgDefaultConfigRefresh        86400 // 24 hours
#define vCfgDefaultConfigRetryShort         5 // seconds
#define vCfgDefaultConfigRetryLong          21600 // 6 hours
#define vCfgDefaultConfigRetryShortCount    5

#define vCfgDefaultClientId             @"NA"
#define vCfgDefaultVCID                 @"NA"

#define vCfgDefaultNmspc                @"NOLCMB"

#define vCfgDefaultEnableVendorID       kTrue
#define vCfgDefaultHashVendorID         kFalse

#define vCfgRequestMethodGet                    @"GET"
#define vCfgRequestMethodPost                   @"POST"

#define vInactivePeriod                 420 // 7 min

#define vCfgDefaultRequestMethod                    @"GET"

#define vDtDefaultPendingPingDelay      1
#define vDtDefaultTransferRetry         90
#define vDtDefaultMaxIntervalThreshold     90
#define vDtDefaultMinId3IntervalThreshold     15
#define vDtDefaultMinCmsIntervalThreshold     2
#define vDtDefaultMaxStationThreshold     10
#define vDcrStaticTimerGap              5
#define vDefaultContentTypesList        @"content,radio"
#define vDefaultStaticTypesList         @"static,text"
#define vDefaultAdTypesList             @"preroll,midroll,postroll,ad"
#define vDefaultID3DelimiterValue       [NlsStrUtil uriEncodedString:@"|"]
#define vDefaultEvtDataDelimiterValue        @"~"
#define vDefaultStationId               @"defaultStationId"
#define vDefaultUserAgent               @"NLSDK (|!nol_osversion!|,|! nol_devtypeid!| Build/|!nol_sdkver!|) |!nol_appid!|/|!nol_appver!|"
#define vDefaultShortPingPrefix         @"S"
#define vDefaultDurationPingPrefix      @"D"
#define vDefaultViewPingPrefix          @"V"
#define vDefaultViewabilityPingPrefix   @"VW"
#define vDefaultPauseEventTimeoutPlayhead @"15"
#define vDefaultPauseEventTimeoutID3      @"15"
#define vDefaultLaunchPingLimit           @"200"
#define vDefaultUAIDRefreshInterval       @"86400"
#define vDefaultFPIDRefreshInterval       180

#define kProductConfigID3RawValue @"id3"
#define kProductConfigMTVRValue @"mtvr"
#define kProductConfigDPRValue @"dpr"
#define kProductConfigDCRStaticValue @"dcrstatic"
#define kProductConfigOCRValue @"ocr"
#define kProductConfigVCValue @"vc"
#define kProductConfigDRMValue @"drm"
#define kProductConfigDPRID3Value @"dprid3"
#define kProductConfigDCRVideoValue @"dcrvideo"
#define kProductConfigVRIValue @"vrivideo"

#define kCadenceConfigIntervalValue @"interval"
#define kCadenceConfigEpisodeValue @"episode"
#define kCadenceConfigStreamValue @"stream"
#define kCadenceConfigImpressionValue @"impression"
#define kCadenceConfigAppStartValue @"appstart"
#define kCadenceConfigQualEpisodeValue @"daypart"
#define kCadenceConfigAdDurationValue @"streamduration"
#define kCadenceConfigModCadenceValue @"modcadence"

#define kAdLoadLinearDefaultValue       @"1"
#define kAdLoadDynamicDefaultValue      @"2"
#define kAdLoadLinearValueRange         @"1,linear"
#define kAdLoadDynamicValueRange        @"2,dynamic"

#define kAdModelDefaultValue   @"0"
#define kAdModelValueRange     @"0,1,2"

static NSNotificationName NotificationNameConfigManagerDeviceUserAgentReady = @"NotificationNameConfigManagerDeviceUserAgentReady";

typedef NS_ENUM(int, NielsenMeterMessageTypes) {
    InvalidMsgType = -1,
	ID3PcPatternType = 0,
	ID3FdPatternType,
	DPRPatternType,
	ID3RawType,
	EndSessionMsgType,
	PlayHeadMsgType,
	MetadataMsgType,
	StartSessionMsgType,
    StopSessionMsgType,
    OTTMsgType,
    ErrorMsgType,
    MuteMsgType,
    OptOutMsgType,
    SessionMsgType,
    EMMMsgType,
    CloseMsgType,
    StaticEndMsgType
};

typedef NS_ENUM(unsigned int, ConfigStatus) {
    Unavailable, // request was not performed or server responded with HTTP error
    Empty,
    Valid,
    Invalid, // parsing error
    ServerError // valid config with error message
};

@protocol NlsConfigManagerDelegate <NSObject>
- (void)obtainConfigCompletedWithResult:(BOOL)success;
@end

@interface NlsConfigManager : NSObject

@property (nonatomic, readonly) NSUInteger totalProcessors;
@property (nonatomic, readonly) BOOL configReady;
@property (nonatomic, readonly) ConfigStatus configStatus;
@property (nonatomic, readonly) NSInteger logReportInterval;
@property (nonatomic, readonly) NSInteger configRefreshInterval;
@property (nonatomic, readonly) NSString *requestMethod;
@property (nonatomic, readonly) NSString *deviceUserAgent;
@property (nonatomic) BOOL cancelled;
@property (nonatomic, weak) id<NlsConfigManagerDelegate> delegate;

- (instancetype)initWithWorker:(id)worker delegate:(id<NlsConfigManagerDelegate>)delegate;

// Obtain config from the server or cache, parse, setup config properties accordingly and respond to delegate
- (void)refreshConfig;

// Send hello or goodbye request
- (void)handleAppDisabled:(BOOL)disable;

// Getting tag info for specific processor
- (NSDictionary *)tagInfoForProcessorWithIndex:(NSUInteger)idxTag;

// has to be called on worker thread
- (void)stopConfigRetryTimer;

@end
