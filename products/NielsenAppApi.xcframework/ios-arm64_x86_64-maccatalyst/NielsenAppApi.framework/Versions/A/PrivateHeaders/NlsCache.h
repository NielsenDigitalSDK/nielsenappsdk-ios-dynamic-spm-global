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
#import "NlsConfigManager.h"

typedef NS_ENUM(unsigned int, NielsenMeterTables) {
    UploadMsgTable = 0,
    SessionDataTable,
    PendingPingsTable,
    DummyTable
};

@class NlsApiWorker;
@class NlsLogger;
@class NlsErrorReporter;

@interface NlsCache : NSObject

// Initialization of the instance.
// The given config determines which database tables will get created/opened.
- (instancetype)initWithErrorReporter:(NlsErrorReporter *)reporter appId:(NSString *)appId instanceId:(NSString *)instanceId;

// Add record of the given type to the database
// Return YES if successful, otherwise NO.
- (BOOL)insertRecord:(NSString *)record
              ofType:(NielsenMeterMessageTypes)msgType
             toTable:(NielsenMeterTables)tblType
     withArrivalTime:(NSTimeInterval)arrivalTime
         processorId:(NSInteger)processorId
         requestType:(NSString *)requestType
           userAgent:(NSString *)userAgent;

// Replaces existing record of the given type to the database
// For the scecified rowId
// Return YES if successful, otherwise NO.
- (BOOL)replaceRecord:(NSString *)record
             forRowId:(NSInteger)rowId
               ofType:(NielsenMeterMessageTypes)msgType
              toTable:(NielsenMeterTables)tblType
      withArrivalTime:(NSTimeInterval)arrivalTime
          processorId:(NSInteger)processorId
          requestType:(NSString *)requestType
            userAgent:(NSString *)userAgent;

// Returns array of rows sorted by time from a given table.
// Set paratemeter limit to 0 to get all rows
- (NSArray *)getRowsSortedByTimeFromTable:(NielsenMeterTables)tblType
                                withLimit:(NSUInteger)limit;

// Returns array of rows sorted by time from a given table excluding rows with specified ids
// Set paratemeter limit to 0 to get all rows
- (NSArray *)getRowsSortedByTimeFromTable:(NielsenMeterTables)tblType
                                withLimit:(NSUInteger)limit
                             exceptRowIDs:(NSArray *)exceptRowIds;

// Returns array of rows sorted by time from a given table
// excluding rows with specified ids for specified message type
// Set paratemeter limit to 0 to get all rows
- (NSArray *)getRowsSortedByTimeFromTable:(NielsenMeterTables)tblType
                                withLimit:(NSUInteger)limit
                           forMessageType:(NielsenMeterMessageTypes)messageType
                             exceptRowIDs:(NSArray *)exceptRowIds;

// Returns array of rows sorted by time from upload and pending table
// Maximum number of rows is specified in pendingPingsLimit in config (8 by default)
- (NSArray *)getNotUploadedRecordsWithLimit:(int)pingsLimit;

// Deletes one row from a given table at given row id
- (BOOL)deleteRowOfTable:(NielsenMeterTables)tblType atRow:(NSString *)row;

// Deletes all rows from a given table
- (BOOL)deleteRowsOfTable:(NielsenMeterTables)tblType;

// Returns number of records in a given table
- (int)getRowCountOfTable:(NielsenMeterTables)tblType;

// Deletes all records older that 10 days from a given table
- (void)deleteOldRecords:(NielsenMeterTables) tblType curTime:(NSTimeInterval)now;

// Deletes all newest records from pending table exceeded given limit
- (void)applyOfflineDataLimit:(int)pingsLimit;

// Move records from a source table to destination table
- (BOOL)moveRowsFromTable:(NielsenMeterTables)fromTblType toTable:(NielsenMeterTables)toTblType forRowIds:(NSArray *)rows withPendingLimit:(int)pingsLimit;

// Collect pings from old databases and inserts them to the current database
- (void)processDataFromOtherDatabasesWithLimit:(int)pingsLimit;

//#if TARGET_OS_TV

// Store pings from current database to NSUserDefaults
- (void)storeDataToDefaultsWithLimit:(int)pingsLimit;

// Collect pings from NSUserDefaults (TVOS specific) and inserts them to the current database
- (void)processDataFromDefaultsWithLimit:(int)pingsLimit;

//#endif

// Move pings from upload table to pending table for processing
- (void)collectPendingPingsWithLimit:(int)pingsLimit;

// Check if the database exists for a given appId and instanceId
+ (BOOL)databaseFileExistsForInstanceId:(NSString *)instanceId appId:(NSString *)appId withErrorLogger:(NlsLogger *)logger;

// Move old databases to 'old' subfolder for a given appId
+ (void)renameDatabaseFilesForAppId:(NSString *)appId withErrorLogger:(NlsLogger *)logger;

// Remove old databases on opt-out for a given appId and instanceId
+ (NSError *)removeDatabaseFileForInstanceId:(NSString *)instanceId appId:(NSString *)appId withErrorLogger:(NlsLogger *)logger;

// DB error
- (BOOL)initDummyTable;

@end
