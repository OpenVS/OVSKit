//
//  OVSRequest.h
//  OVSKit
//
//  Created by Xu Liu on 2017-05-15.
//  Copyright © 2017 The Top AI Technology Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OVSHelper.h"

///define the security method.
typedef NS_ENUM(NSInteger, RequestDataSecurity) {
	RequestDataSecurity_None = 0,
	RequestDataSecurity_DeviceKey,
	RequestDataSecurity_GeneralKey,
	RequestDataSecurity_OVS_DeviceKey,
	RequestDataSecurity_OVS_GeneralKey
	
};

///define the url request method.
typedef NS_ENUM(NSInteger, URLRequestMethod) {
	URLRequestMethod_POST = 0,
	URLRequestMethod_GET,
	URLRequestMethod_DELETE,
	URLRequestMethod_PUT,
	URLRequestMethod_PATCH
};

/// error entity is used to get extra information, when a request failed.
typedef NS_ENUM(NSInteger, URLErrorEntity) {
	URLErrorEntity_Body,
	URLErrorEntity_Server,
	URLErrorEntity_ContentType,
	URLErrorEntity_StatusCode
};

/// content type enum to decide in which way to convert the paramters
typedef NS_ENUM(NSInteger, RequestContentType) {
	RequestContentType_ApplicationJSON,
	RequestContentType_MultipartFormData,
	RequestContentType_Default
};



///define request task to hold all the request task parameters and callback functions
typedef void(^UploadingCallback)(NSURLSessionTask * task, NSUInteger bytesWritten, NSUInteger totalBytesWritten, NSUInteger totalBytesExpected);
typedef void(^DownloadingCallback)(NSURLSessionTask * task, NSUInteger bytesWritten, NSUInteger totalBytesWritten, NSUInteger totalBytesExpected);
typedef void(^CompletionCallback)(NSData * data, NSURLResponse * response, NSError * error, NSInteger statusCode, RequestDataSecurity security, NSDictionary * responseHeader);
typedef BOOL(^RedirectCallback)(NSString * url, NSURLResponse * response, NSURLRequest * newRequest);
typedef void(^successCallback)(NSInteger statusCode, NSData * responseData, NSDictionary * responseHeader);
typedef void(^errorCallback)(NSInteger statusCode, NSString * message, NSError * error, NSDictionary * responseHeader);

/**
	this is used for multipart-form-data parameter
	name is the key for the form data
	filename is the name of the data you want to give
	data is the binary data of the file
	mimeType is the type of this data file. normally, it can be: image/jpg, image/png, video/mp4 and so on
*/
@interface MultipartFormDataParam : NSObject
@property (nonatomic, strong) NSString * name;
@property (nonatomic, strong) NSString * fileName;
@property (nonatomic, strong) NSString * mimeType;
@property (nonatomic, strong) NSData * data;
-(id)init:(NSString *)name fileName: (NSString *)fileName mimeType:(NSString *)mimeType data:(NSData *)data;
@end


@interface OVSRequest : NSObject<NSURLSessionDelegate, NSURLSessionTaskDelegate, NSURLSessionDataDelegate>
@property(nonatomic, assign) BOOL allowInsecureNetworkConnection;
@property(nonatomic, assign) double defaultRequestTimeout;
@property(nonatomic, strong) NSString * accessToken;
+(OVSRequest *)sharedInstance;


///general request method, it accepts any method type
-(void)requestV3:(URLRequestMethod)method url:(NSString *)url params:(NSDictionary *)params timeoutInterval:(double)timeoutInterval isBodyParams:(BOOL)isBodyParams extraHeader:(NSDictionary*)extraHeader security:(RequestDataSecurity)security contentType:(RequestContentType)contentType dispatchQueue:(dispatch_queue_t)dispatchQueue forDownloading:(BOOL)forDownloading uploadProgress:(UploadingCallback)uploadProgress downloadProgress:(DownloadingCallback)downloadProgress onRedirect:(RedirectCallback)onRedirect onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

-(void)request:(URLRequestMethod)method url:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

-(void)requestV1:(URLRequestMethod)method url:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader security:(RequestDataSecurity)security  onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

-(void)requestV2:(URLRequestMethod)method url:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader security:(RequestDataSecurity)security contentType:(RequestContentType)contentType forDownloading:(BOOL)forDownloading uploadProgress:(UploadingCallback)uploadProgress downloadProgress:(DownloadingCallback)downloadProgress onRedirect:(RedirectCallback)onRedirect onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;


///post request method
-(void)postV3:(NSString *)url params:(NSDictionary *)params timeoutInterval:(double)timeoutInterval isBodyParams:(BOOL)isBodyParams extraHeader:(NSDictionary*)extraHeader security:(RequestDataSecurity)security contentType:(RequestContentType)contentType dispatchQueue:(dispatch_queue_t)dispatchQueue forDownloading:(BOOL)forDownloading uploadProgress:(UploadingCallback)uploadProgress downloadProgress:(DownloadingCallback)downloadProgress onRedirect:(RedirectCallback)onRedirect onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

-(void)postV2:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader security:(RequestDataSecurity)security forDownloading:(BOOL)forDownloading uploadProgress:(UploadingCallback)uploadProgress downloadProgress:(DownloadingCallback)downloadProgress onRedirect:(RedirectCallback)onRedirect onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

-(void)postV1:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader security:(RequestDataSecurity)security onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

-(void)post:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;


///get request method
-(void)getV1:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader forDownloading:(BOOL)forDownloading uploadProgress:(UploadingCallback)uploadProgress downloadProgress:(DownloadingCallback)downloadProgress onRedirect:(RedirectCallback)onRedirect onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;
-(void)get:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;
-(void)getV2:(NSString *)url params:(NSDictionary *)params timeoutInterval:(double)timeoutInterval isBodyParams:(BOOL)isBodyParams extraHeader:(NSDictionary*)extraHeader contentType:(RequestContentType)contentType dispatchQueue:(dispatch_queue_t)dispatchQueue forDownloading:(BOOL)forDownloading uploadProgress:(UploadingCallback)uploadProgress downloadProgress:(DownloadingCallback)downloadProgress onRedirect:(RedirectCallback)onRedirect onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

///put request method
-(void)putV2:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader security:(RequestDataSecurity)security forDownloading:(BOOL)forDownloading uploadProgress:(UploadingCallback)uploadProgress downloadProgress:(DownloadingCallback)downloadProgress onRedirect:(RedirectCallback)onRedirect onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

-(void)putV1:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader security:(RequestDataSecurity)security onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

-(void)put:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

-(void)putV3:(NSString *)url params:(NSDictionary *)params timeoutInterval:(double)timeoutInterval isBodyParams:(BOOL)isBodyParams extraHeader:(NSDictionary*)extraHeader security:(RequestDataSecurity)security contentType:(RequestContentType)contentType dispatchQueue:(dispatch_queue_t)dispatchQueue forDownloading:(BOOL)forDownloading uploadProgress:(UploadingCallback)uploadProgress downloadProgress:(DownloadingCallback)downloadProgress onRedirect:(RedirectCallback)onRedirect onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

///delete request method
-(void)deleteV2:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader security:(RequestDataSecurity)security forDownloading:(BOOL)forDownloading uploadProgress:(UploadingCallback)uploadProgress downloadProgress:(DownloadingCallback)downloadProgress onRedirect:(RedirectCallback)onRedirect onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;
-(void)deleteV1:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader security:(RequestDataSecurity)security onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;
-(void)delete:(NSString *)url params:(NSDictionary *)params extraHeader:(NSDictionary*)extraHeader onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;
-(void)deleteV3:(NSString *)url params:(NSDictionary *)params timeoutInterval:(double)timeoutInterval isBodyParams:(BOOL)isBodyParams extraHeader:(NSDictionary*)extraHeader security:(RequestDataSecurity)security contentType:(RequestContentType)contentType dispatchQueue:(dispatch_queue_t)dispatchQueue forDownloading:(BOOL)forDownloading uploadProgress:(UploadingCallback)uploadProgress downloadProgress:(DownloadingCallback)downloadProgress onRedirect:(RedirectCallback)onRedirect onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

///post data request method
-(void)postDataV2:(NSString *)url params:(NSDictionary *)params formParams:(NSArray<MultipartFormDataParam *> *)formParams extraHeader:(NSDictionary *)extraHeader security:(RequestDataSecurity)security forDownloading:(BOOL)forDownloading uploadProgress:(UploadingCallback)uploadProgress downloadProgress:(DownloadingCallback)downloadProgress onRedirect:(RedirectCallback)onRedirect onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;
-(void)postDataV3:(NSString *)url params:(NSDictionary *)params formParams:(NSArray<MultipartFormDataParam *> *)formParams timeoutInterval:(double)timeoutInterval  isBodyParams:(BOOL)isBodyParams extraHeader:(NSDictionary *)extraHeader security:(RequestDataSecurity)security dispatchQueue:(dispatch_queue_t)dispatchQueue forDownloading:(BOOL)forDownloading uploadProgress:(UploadingCallback)uploadProgress downloadProgress:(DownloadingCallback)downloadProgress onRedirect:(RedirectCallback)onRedirect onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;
-(void)postData:(NSString *)url params:(NSDictionary *)params formParams:(NSArray<MultipartFormDataParam *> *)formParams extraHeader:(NSDictionary *)extraHeader onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;
-(void)postDataV1:(NSString *)url params:(NSDictionary *)params formParams:(NSArray<MultipartFormDataParam *> *)formParams extraHeader:(NSDictionary *)extraHeader security:(RequestDataSecurity)security onSuccess:(successCallback)onSuccess onFailure:(errorCallback)onFailure;

@end
