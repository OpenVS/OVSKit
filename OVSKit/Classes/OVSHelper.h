//
//  OVSHelper.h
//  OVSKit
//
//  Created by Xu Liu on 2017-05-16.
//  Copyright © 2017 The Top AI Technology Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OVSGlobal.h"
#import "OVSDataManager.h"
#import "OVSLog.h"
#import <sys/utsname.h>
#import "OVSLog.h"

typedef NS_ENUM(NSUInteger, OVSCurrencySymbol) {
	OVS_Currency_US_Dollar = 0,		//usa dollar
	OVS_Currency_CAD_Dollar,		//canadian dollar
	OVS_Currency_RMB_Yuan,			//chinese yuan
	OVS_Currency_Euro				//euro
};


@interface OVSHelper : NSObject
+(OVSHelper *_Nonnull)sharedInstance;


-(NSString *_Nonnull)urlEncoding:(NSString *_Nonnull)string;
-(NSString *_Nonnull)urlDecoding:(NSString *_Nonnull)string;

-(NSString *_Nonnull)getDocPath:(NSString *_Nonnull)fileNameOrPath;
-(NSString *_Nonnull)getBldPath:(NSString *_Nonnull)fileName;

-(UIColor *_Nullable)colorWithHexString:(NSString *_Nonnull)stringToConvert alpha:(float)alpha;

-(NSData *_Nullable)dataFromJSONObject:(NSDictionary *_Nonnull)object;
-(NSData *_Nullable)dataFromJSONArray:(NSArray *_Nonnull)array;
-(NSMutableDictionary *_Nullable)objectFromJSONData:(NSData *_Nonnull)data;
-(NSMutableArray * _Nullable)arrayFromJSONData:(NSData * _Nonnull)data;

-(NSString *_Nonnull)generateUUID;
-(NSString *_Nonnull)getDeviceModel;

-(NSString *_Nonnull)getAppVersion;
-(NSString *_Nonnull)getAppBuild;
-(NSString *_Nonnull)getAppName;

-(double)firstInstallTimestamp;

-(void)getRGBWithHexString:(NSString *_Nullable)stringToConvert r:(unsigned int *_Nullable)r g:(unsigned int *_Nullable)g b:(unsigned int *_Nullable)b;
/**
 this function is used to decide whether this is a production build or development build.
 most of the time, this flag is used for deciding the push notification certificate.
 */
-(BOOL)isProductionBuild;

-(BOOL)createFolderOnPath:(NSString * _Nonnull)path;
-(BOOL)isFolderExisted:(NSString * _Nonnull)folderPath;
-(BOOL)isFileExisted:(NSString * _Nonnull)filePath;


//Handle push notification token
-(NSString *_Nonnull)getPushDeviceToken;
-(void)setPushDeviceToken:(NSString *_Nonnull)token;

-(UIImage*_Nullable)imageWithBorderFromImage:(UIImage*_Nullable)source withBorderColor:(NSString *_Nullable)hexBorderColorCode  withBgColor:(NSString *_Nullable)hexBgColorCode;


//get the total width of a string based on a font-size
-(double)getStringWidthByFont:(UIFont * _Nonnull)font forString:(NSString * _Nonnull)string padding:(CGFloat)padding;

/** this function get a pop up dialog to alert user
 @brief this is a quick way to pop up a dialog to let the user response.
 @param presenter is the view controller which wants to pop up the dialog
 @param title this is the title of the pop up
 @param message this is the content of the pop up dialog
 @param buttons this is an array of buttons, that you want to let the user to confirm
 @param completion this is a callback block, so that you can know which button the user clicked.
 */
-(void)alert:(UIViewController * _Nonnull)presenter title:(NSString * _Nullable)title message:(NSString * _Nullable)message buttons:(NSArray*_Nullable)buttons onCompletion:(void(^_Nullable)(NSString * _Nullable responseButton))completion;



///get currency symbol
-(NSString * _Nonnull)getCurrencySymbol:(OVSCurrencySymbol)symbol;


///this function is used to check whether a file is existed in bundle
-(BOOL)fileExistedInBundle:(NSString * _Nonnull)fileName;
@end
