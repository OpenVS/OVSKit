//
//  OVSLanguageManager.h
//  OVSKit
//
//  Created by Xu Liu on 2017-06-23.
//  Copyright © 2017 The Top AI Technology Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OVSLanguageCode.h"
#import "OVSDataManager.h"
#import "OVSLog.h"
#import "OVSGlobal.h"
#import "OVSHelper.h"
#import <UIKit/UIKit.h>

///this macro defines the function to return corresponding language content. if can not find the data, use default English version.
#define l(stringInfo) ([[OVSLanguageManager sharedInstance] getInfoByCurrentUsingLanguageCode:(stringInfo)])


@interface OVSLanguageManager : NSObject

+(OVSLanguageManager *)sharedInstance;

/// this function will reload the language table to cache again.
-(void)reloadLanguageTable;


///this function will return current user's iOS system language
-(NSString *)getCurrentSystemLanguageCode;

///set current app using language, if can not find from server, use the default language code.
-(void)setCurrentUsingLanguageCode:(OVSLanguageCode)languageCode;

///this function will get current used language for the app.
-(NSString *)getCurrentUsingLanguageCode;

///this function return the translated information based on the selected language code.
-(NSString *)getInfoByCurrentUsingLanguageCode:(NSString *)info;

@end
