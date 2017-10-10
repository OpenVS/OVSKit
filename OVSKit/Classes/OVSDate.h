//
//  OVSDate.h
//  OVSKit
//
//  Created by Xu Liu on 2017-05-16.
//  Copyright © 2017 The Top AI Technology Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OVSDate : NSObject
+(OVSDate * _Nonnull)sharedInstance;

///it returns a string of date: yyyy-MM-dd HH:mm:ss
-(NSString * _Nonnull)getLocalHumanReadableDateTime;

/// get current local date time with a given format "yyyy-MM-dd HH:mm:ss"
-(NSString * _Nonnull)getLocalHumanReadableDateTimeWithFormat:(NSString * _Nonnull)format;


//convert the utc timestamp to local yyyy-MM-dd HH:mm:ss
-(NSString * _Nonnull)convertToLocalYMdHmsFromUTCTimestamp:(double)utcTimestamp;

//convert the utc timestamp to local with given format 'yyyy-MM-dd HH:mm:ss'
-(NSString * _Nonnull)convertToLocalFromUTCTimestamp:(double)utcTimestamp format:(NSString * _Nullable)format;

//convert the utc timestamp to local date
-(NSDate * _Nonnull)convertToLocalDateFromUTCTimestamp:(double)utcTimestamp;



//convert the utc timestamp to timezone yyyy-MM-dd HH:mm:ss
-(NSString * _Nonnull)convertToLocalYMdHmsFromUTCTimestamp:(double)utcTimestamp withTimezone:(NSString * _Nullable)timezone;

//convert the utc timestamp to timezone with given format 'yyyy-MM-dd HH:mm:ss'
-(NSString * _Nonnull)convertToLocalFromUTCTimestamp:(double)utcTimestamp format:(NSString * _Nullable)format withTimezone:(NSString * _Nullable)timezone;

//convert the utc timestamp to timezone date
-(NSDate * _Nonnull)convertToLocalDateFromUTCTimestamp:(double)utcTimestamp withTimezone:(NSString * _Nullable)timezone;



//convert local to utc date
-(NSDate * _Nonnull)convertLocalToUTC;

//convert local to utc timestamp
-(double)convertLocalToUTCTimestamp;

//convert timezone to utc timestamp
-(NSDate * _Nullable)convertToUTCFromTimezoneDate:(NSDate * _Nullable)timezoneDate;


// dump timezone string
-(void)dumpSystemTimezone;


@end
