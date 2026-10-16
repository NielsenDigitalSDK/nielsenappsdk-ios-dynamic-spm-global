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

#import "NielsenAppApiEnums.h"

@class NlsApiWorker;
@class NlsLogger;
@class NlsCATLogger;
@protocol NlsCATLoggerEventOwner;

@interface NielsenAppApi (Private)

@property (readonly) NlsApiWorker *worker;
@property (readonly) NlsLogger *logger;

@property (readonly) NSString *apiTypeSuffix;
@property (readonly) NSString *integrationTypeSuffix;
@property (readonly) NSString *environmentSuffix;

- (instancetype)initWithAppInfo:(id)appInfo
                        apiType:(NielsenApiType)apiType
                       delegate:(id<NielsenAppApiDelegate>)delegate
           catLoggerEventsOwner:(id<NlsCATLoggerEventOwner>)catLoggerEventsOwner;

- (void)logBoolCATData:(BOOL)boolData forEventType:(NSString *)eventType fromEventsOwner:(id<NlsCATLoggerEventOwner>)eventsOwner;
- (void)logCATData:(id)data forEventType:(NSString *)eventType fromEventsOwner:(id<NlsCATLoggerEventOwner>)eventsOwner;

@end

