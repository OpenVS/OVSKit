//
//  OVSDataManager.h
//  OVSKit
//
//  Created by Xu Liu on 2017-05-28.
//  Copyright © 2017 The Top AI Technology Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonCryptor.h>
#import <zlib.h>
#import "OVSGlobal.h"

@interface OVSDataManager : NSObject

/// this is the general key which is individual to different app and it is assigned from the individual app.
@property(nonatomic, nullable, strong) NSString * generalAES_Key;
/// this is the general iv which is individual to different app and it is assigend from the individual app.
@property(nonatomic, nullable, strong) NSString * generalAES_IV;

///this is the key which is different from individual device and it is generated in the app when the app first installed.
@property (nonatomic, nullable, strong) NSString * deviceAES_Key;
///this is the iv which is different from individual device and it is generated in the app when the app first installed.
@property (nonatomic, nullable, strong) NSString * deviceAES_IV;

+(OVSDataManager * _Nonnull)sharedInstance;

/**************************************************************************
 *					Compress/Uncompress Data
 *************************************************************************/
/** 
 Returns a data object containing a Zlib decompressed copy of the receivers contents.
 */
-(NSData *_Nullable)zlibInflate:(NSData *_Nonnull)data;
/**
 Returns a data object containing a Zlib compressed copy of the receivers contents.
 */
- (NSData *_Nullable)zlibDeflate:(NSData *_Nonnull)data;

/** 
 Returns a data object containing a Gzip decompressed copy of the receivers contents.
 */
-(NSData *_Nullable)gzipInflate:(NSData *_Nonnull)data;
/** 
 Returns a data object containing a Gzip compressed copy of the receivers contents.
 */
-(NSData *_Nullable)gzipDeflate:(NSData *_Nonnull)data;

/**************************************************************************
 *					Store Data to UserDefaults with Encryption
 *************************************************************************/

/**
 set a String value to user defaults with encryption
 @param object the String object which will be encrypted
 @param key the identifier of this String object.
 */
-(void)setUserDefaultsObject:(NSString * _Nonnull)object forKey:(NSString * _Nonnull)key;

//get object from user default with a key
-(NSString * _Nullable)getUserDefaultObjectByKey:(NSString * _Nonnull)key;



/**************************************************************************
 *					Store Data to KeyChain
 *************************************************************************/

/** 
	@abstract this function will save the key/object pair in the keychain
	@param object The object to save. Must be an object that could be archived with NSKeyedArchiver.
	@param key The key identifying the object to save.
	@return @p YES if saved successfully, @p NO otherwise.
 */
-(BOOL)useKeyChainToSaveValue:(id _Nonnull)object forKey:(NSString * _Nonnull)key;

/**
	@abstract loads the object with specified @p key from the Keychain.
	@param key The key identifying the object to load.
	@return The object identified by @p key or nil if it doesn't exist.
 */
-(id _Nullable)getObjectFromKeyChainWithKey:(NSString * _Nonnull)key;

/**
 @abstract Deletes the object with specified @p key from the Keychain.
 @param key The key identifying the object to delete.
 @return @p YES if deletion was successful, @p NO if the object was not found or some other error ocurred.
 */
-(BOOL)deleteObjectFromKeyChainByKey:(NSString * _Nonnull)key;



/**************************************************************************
 *					Encrypt/Decrypt Data
 *************************************************************************/

/**
  this function will generate a new pair of key and iv for this device.
  this is a very dangerous function, once you call this function, you need to register the device key and iv to the server again.
 */
-(void)updateDeviceKeyAndIV;


///every time when we try to use this class, we need to call this loadGeneralKeyIv function.
-(void)setGeneralKeyPair:(NSString *_Nullable)key iv:(NSString *_Nullable)iv;


/**
 @abstract encrypt the data based on the preset general key and IV
 @param original the original data
 @return encrypted binary data
 @see
 OpenSSL usages as below to decrypt/encrypt binary data
 @code
	-- decode binary image with key and iv
	openssl enc -aes256 -K 2034F6E32958647FDFF75D265B455EBF40C80E6D597092B3A802B3E5863F8781 -p -nosalt -iv 010932650CDD998833CC0AFF9AFF00F1 -d -in encrypted.jpeg -out decrypted.jpeg
 
	-- encode binary image with key and iv
	openssl enc -aes256 -K 2034F6E32958647FDFF75D265B455EBF40C80E6D597092B3A802B3E5863F8781 -p -nosalt -iv 010932650CDD998833CC0AFF9AFF00F1 -e -in original.jpeg -out ecrypted_data.jpeg
 
	-- API Call Example
 let image = UIImage(named:"test_image.jpeg")
 let cryptor:OVSDataManager = OVSDataManager()
 let imageData = UIImageJPEGRepresentation(image!, 1)
 let encryptedData = cryptor.generalKeyPairEncryption(forData:imageData)
 saveImageDocumentDirectory(imageData: encryptedData)
 let decryptedData = cryptor.generalKeyPairDecryption(forData:encryptedData)
 let decryptedImage = UIImage(data: decryptedData!)
 dogImage.image = decryptedImage!
 @endcode
 */
-(nullable NSData *)generalKeyPairEncryptionForData:(nullable NSData *) original;

/**
 @abstract decrypt the data based on the preset general key and IV
 @param encryptedData the encrypted data
 @return original binary data
 @see
 OpenSSL usages as below to decrypt/encrypt binary data
 @code
	-- decode binary image with key and iv
	openssl enc -aes256 -K 2034F6E32958647FDFF75D265B455EBF40C80E6D597092B3A802B3E5863F8781 -p -nosalt -iv 010932650CDD998833CC0AFF9AFF00F1 -d -in encrypted.jpeg -out decrypted.jpeg
 
	-- encode binary image with key and iv
	openssl enc -aes256 -K 2034F6E32958647FDFF75D265B455EBF40C80E6D597092B3A802B3E5863F8781 -p -nosalt -iv 010932650CDD998833CC0AFF9AFF00F1 -e -in original.jpeg -out ecrypted_data.jpeg
 
	-- API Call Example
 let image = UIImage(named:"test_image.jpeg")
 let cryptor:OVSDataManager = OVSDataManager()
 let imageData = UIImageJPEGRepresentation(image!, 1)
 let encryptedData = cryptor.generalKeyPairEncryption(forData:imageData)
 saveImageDocumentDirectory(imageData: encryptedData)
 let decryptedData = cryptor.generalKeyPairDecryption(forData:encryptedData)
 let decryptedImage = UIImage(data: decryptedData!)
 dogImage.image = decryptedImage!
 @endcode
 */
-(nullable NSData *)generalKeyPairDecryptionForData:(nullable NSData *) encryptedData;


/**
 @abstract encrypt the data based on the preset device individual key and IV
 @param original the original data
 @return encrypted binary data
 @see
 OpenSSL usages as below to decrypt/encrypt binary data
 @code
	-- decode binary image with key and iv
	openssl enc -aes256 -K 2034F6E32958647FDFF75D265B455EBF40C80E6D597092B3A802B3E5863F8781 -p -nosalt -iv 010932650CDD998833CC0AFF9AFF00F1 -d -in encrypted.jpeg -out decrypted.jpeg
 
	-- encode binary image with key and iv
	openssl enc -aes256 -K 2034F6E32958647FDFF75D265B455EBF40C80E6D597092B3A802B3E5863F8781 -p -nosalt -iv 010932650CDD998833CC0AFF9AFF00F1 -e -in original.jpeg -out ecrypted_data.jpeg
 
	-- API Call Example
 let image = UIImage(named:"test_image.jpeg")
 let cryptor:OVSDataManager = OVSDataManager()
 let imageData = UIImageJPEGRepresentation(image!, 1)
 let encryptedData = cryptor.encryptData(imageData)
 saveImageDocumentDirectory(imageData: encryptedData)
 let decryptedData = cryptor.decryptData(encryptedData)
 let decryptedImage = UIImage(data: decryptedData!)
 dogImage.image = decryptedImage!
 @endcode
 */
-(nullable NSData *)encryptData:(nullable NSData *) original;

/**
 @abstract decrypt the data based on the preset general key and IV
 @param encryptedData the encrypted data
 @return original binary data
 @see
 OpenSSL usages as below to decrypt/encrypt binary data
 @code
	-- decode binary image with key and iv
	openssl enc -aes256 -K 2034F6E32958647FDFF75D265B455EBF40C80E6D597092B3A802B3E5863F8781 -p -nosalt -iv 010932650CDD998833CC0AFF9AFF00F1 -d -in encrypted.jpeg -out decrypted.jpeg
 
	-- encode binary image with key and iv
	openssl enc -aes256 -K 2034F6E32958647FDFF75D265B455EBF40C80E6D597092B3A802B3E5863F8781 -p -nosalt -iv 010932650CDD998833CC0AFF9AFF00F1 -e -in original.jpeg -out ecrypted_data.jpeg
 
 -- API Call Example
 let image = UIImage(named:"test_image.jpeg")
 let cryptor:OVSDataManager = OVSDataManager()
 let imageData = UIImageJPEGRepresentation(image!, 1)
 let encryptedData = cryptor.encryptData(imageData)
 saveImageDocumentDirectory(imageData: encryptedData)
 let decryptedData = cryptor.decryptData(encryptedData)
 let decryptedImage = UIImage(data: decryptedData!)
 dogImage.image = decryptedImage!
 @endcode
 */
-(nullable NSData *)decryptData:(nullable NSData *) encryptedData;



/**
 this function is used to generate the 64 bytes random key, which will be used for the AES key
 @return a 32 characters random key for 64 bytes
 */
-(NSString * _Nonnull)createAES_Key;


/**
 this function is used to generate the 32 bytes IV, which can be used for the AES IV
 @return a 16 characters random IV for 32 bytes.
 */
-(NSString * _Nonnull)createAES_IV;

/**
 encrypt text with device key and iv
 @param plainText the original text
 @return the encrypted text from original text
 */
-(NSString *_Nonnull)encryptText:(nullable NSString *)plainText;

/**
 decrypt text with device key and iv
 @param encryptedText the encrypted text from OVS encrypt function
 @return the original text
 */
-(NSString *_Nonnull)decryptText:(nullable NSString *)encryptedText;

/**
 encrypt text with general key and iv
 @param plainText the original text
 @return the encrypted text from original text
 */
-(NSString *_Nonnull)generalKeyPairEncryptionForText:(nullable NSString *)plainText;

/**
 decrypt text with general key and iv
 @param encryptedText the encrypted text from OVS encrypt function
 @return the original text
 */
-(NSString *_Nonnull)generalKeyPairDecryptionForText:(nullable NSString *)encryptedText;
@end
