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

#ifndef NielsenID3Meter_ID3MeterConstants_h
#define NielsenID3Meter_ID3MeterConstants_h

//
// This is the build version of the VI API
//
#define VIVersion @"1.0.0"

/**
 Nielsen web view commands
 */
#define kNielsenWebOptOut @"nielsenappsdk://1"
#define kNielsenWebOptIn @"nielsenappsdk://0"

#define kCfgDefaultLogInterval (60*60) // 1 hour
#define kError @"ErrorStatus"
#define kEvent @"EventStatus"
#define kTimeStamp @"TimeStamp"

/*Error Descriptions*/
#define kNSErrorLocalizedDescriptionKey @"NSLocalizedDescriptionKey"

#define kNetworkConnectionFailureDescription @"SDK Unable to Get Response from Server"
#define kUnableToContactServerDescription @"SDK Could not connect to server"
#define kFileWriteFailureDescription @"SDK Could not write to file"
#define kFileReadFailureDescription @"SDK Could not read data from file"
#define kNullValuePassedDescription @"Empty value Found."
#define kEmptyAppVersion  @"Cannot initialize API Object without an AppVersion"
#define kEmptyAppId  @"Cannot initialize API Object without an AppId"
#define kErrorDomain @"AppApiApplicationErrors"
#define kExceptionHandlerDomain @"AppApiExceptions"

/*Exception Keys*/
#define kID3MeterExceptionName @"AppApiExceptionName"
#define kID3MeterExceptionReason @"AppApiExceptionReason"
#define kID3MeterExceptionCallStackReturnAddresses @"AppApiExceptionCallStackReturnAddresses"
#define kID3MeterExceptionCallStackSymbols @"AppApiExceptionCallStackSymbols"
#define kID3MeterExceptionUserInfo @"AppApiExceptionUserInfo"

/*Event Descriptions*/
#define kMeterObjectInitiated @"Nielsen App SDK Version, %@ is initialized by the Player..."
#define kID3MeterStop  @"Nielsen App SDK is stopping ..."
#define kID3MeterShutdown  @"Nielsen App SDK is shutting down ..."

#endif
