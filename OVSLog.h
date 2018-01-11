//
//  OVSLog.h
//  OVSKit
//
//  Created by Xu Liu on 2017-05-16.
//  Copyright © 2017 The Top AI Technology Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OVSDate.h"


#define log4OVS(logLevel,logInfo) ([[OVSLog sharedInstance] log:(logLevel) info:([NSString stringWithFormat:@"%s\n%s (+%d)\n:%@\n",__FILE__,__PRETTY_FUNCTION__,__LINE__,(logInfo)])])

#define log4OVSx(logLevel,logInfo,logParams) ([[OVSLog sharedInstance] log:(logLevel) info:([NSString stringWithFormat:@"%s\n%s (+%d)\n:%@\n",__FILE__,__PRETTY_FUNCTION__,__LINE__,(logInfo)]) params:(logParams)])

typedef NS_ENUM(NSUInteger, OVSLogType) {
	LogLevelCrash,
	LogLevelError,
	LogLevelWarning,
	LogLevelNormal,
	LogLevelDetails,
	LogLevelTracking	// this is for statisic purpose in the dashboard for the app client.
};

@interface OVSLog : NSObject
///indicates how many records we are going to log. default is 1000
@property(nonatomic, assign) int logBufferMaxSize;
@property(nonatomic, strong) NSMutableArray * logSets;
@property(nonatomic, assign) OVSLogType currentLevel;
@property(nonatomic, assign) double previousTimestamp;
@property(nonatomic, assign) double flushIntervalInSec;		//default is 60 seconds
+(OVSLog *)sharedInstance;

///log necessary information the app.
-(void)log:(OVSLogType)type info:(NSString *)info;

///this log funciton accepts the parameters of the log, normally it is used to the user events
-(void)log:(OVSLogType)type info:(NSString *)info params:(NSDictionary *)params;

///this function return a human reabable log
-(NSString *)getHumanReadableSystemLog;

/** this function will flush the in memory log information to disk, so that, we can permanently save it.
 * if the function finish flushing the data to the disk, completion callback function will be called.
 */
-(void)flushLog2Disk:(void(^)(BOOL status, NSString * message))completion;
@end

