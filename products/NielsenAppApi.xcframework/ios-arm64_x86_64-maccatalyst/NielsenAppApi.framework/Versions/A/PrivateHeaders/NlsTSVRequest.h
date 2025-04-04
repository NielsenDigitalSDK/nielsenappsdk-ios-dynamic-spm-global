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
#import "NlsDataProcessRequest.h"

//
// To avoid multiple requests for the same fdcid:
// All TSV request will be queued up.
// First, check global for TSV based on fdcid
// If match found, copy else issue request to server
// If request gets TSV, save it to global to share with request from other data process
// If no TSV is returned, request will be retried on next fd-cid
//

@interface NlsTSVRequest : NlsDataProcessRequest

@property (nonatomic) NSString *rawID3;
@property (nonatomic) NSString *cidValue;

@end
