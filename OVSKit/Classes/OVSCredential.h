//
//  OVSCredential.h
//  OVSKit
//
//  Created by Xu Liu on 2017-08-27.
//  Copyright © 2017 The Top AI Technology Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OVSCredential : NSObject
-(NSString * _Nonnull)getOpenVSKitGeneralKey;
-(NSString * _Nonnull)getOpenVSKitGeneralIV;
-(float)getOpenVSKitVersion;
+(OVSCredential * _Nonnull)sharedInstance;
@end
