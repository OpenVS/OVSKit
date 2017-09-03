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
-(NSString * _Nonnull)getCurrentHumanReadableDateTime;

//convert the utc timestamp to est yyyy-MM-dd HH:mm:ss
-(NSString * _Nonnull)convertUTCTimestampToESTYMdHms:(double)utcTimestamp;
@end
