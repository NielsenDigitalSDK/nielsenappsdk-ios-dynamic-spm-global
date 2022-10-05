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

typedef NS_ENUM(unsigned int, LogCode)
{
    LogCodeFailedParseStartInfo = 1, // 1. Failed to parse the play() JSON string
    LogCodeFailedParseMetadata, // 2. Failed to parse the loadMetadata() JSON string
    LogCodeFailedProcessID3, // 3. Failed to process ID3 data on a data processor
    LogCodeFailedReceiveConfig, // 4. Failed to receive configuration file from Census
    LogCodeFailedParseConfig, // 5. Failed to parse the config file JSON string
    LogCodeFailedStartProcessor, // 6. Failed to create SDK processor
    LogCodeFailedCreateUrl, // 7. Failed to generate URL due to missing mandatory parameter
    LogCodeFailedCreateRequest, // 8. Failed to create request in HTTP client
    LogCodeFailedSendHttpRequest, // 9. Failed sending HTTP or HTTPS request
    LogCodeFailedSendPing, // 10. Failed to send ping
    LogCodeFailedSendTSV, // 11. Failed to send TSV request
    LogCodeFailedSendStationRequest, // 12. Failed to send StationId request
    LogCodeFailedAccessDatabase, // 13. Failed to read/write from/to database table
    LogCodeException, // 14. Any exception handled by SDK code
    LogCodeInvalidPlayheadPosition, // 15. Invalid playhead position
    LogCodeLongAd, // 16. Long ad
    LogCodeIncorrectSfcode, // 17. Incorrect client supplied sfcode
    LogCodeHemUidExceedLimit, // 18. Exceeded limit of nol_hemUidCharLimit characters
    LogCodeViewabilityUnableFindView // 19. Viewability unable to find a view with the specificed tag
};

typedef NS_ENUM(unsigned int, LogCodeImmediate)
{
    LogCodeImmediateDBLocked = 1001 // 1001. DB locked failure
};

@class NlsApiWorker;

@interface NlsErrorCollection : NSObject

- (void)addErrorWithCode:(NSUInteger)code message:(NSString *)message;
- (void)resetCollection;

- (int)numberOfErrorsCollected;
- (NSArray *)stringsForCollection;

@end

