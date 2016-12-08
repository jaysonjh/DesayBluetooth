//
//  DSBLEUtils.h
//  DesayBluetoothKit
//
//  Created by Desay on 16/6/29.
//  Copyright © 2016年 desay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CBUUID;
@class CBCharacteristic;
@interface DSBLEUtils : NSObject

+ (CBUUID *)genUUIDByHexValue:(__uint64_t)hexString
                baseAddressHi:(__uint64_t)ADDRESS_HI
                baseAddressLO:(__uint64_t)ADDRESS_LO;

+ (NSString *)genUUIDStringByHexValue:(__uint64_t)hexString
                        baseAddressHi:(__uint64_t)ADDRESS_HI
                        baseAddressLO:(__uint64_t)ADDRESS_LO;

//十六进制转换为普通字符串的。
+ (NSString *)convertHexStringToString:(NSString *)hexString;
//普通字符串转换为十六进制
+ (NSString *)ConvertStringToHexString:(NSString *)string;
//int转data
+(NSData *)ConvertIntToData:(NSInteger)i;
//data转int
+(NSInteger)ConvertDataToInt:(NSData *)data;
//十六进制转换为普通字符串的。
+ (NSData *)ConvertHexStringToData:(NSString *)hexString;
//根据UUIDString查找CBCharacteristic
+(CBCharacteristic *)findCharacteristicFormServices:(NSMutableArray *)services
                                         UUIDString:(NSString *)UUIDString;


+ (NSString *)getMacAddress:(NSData *)advData;
/**
 *  解析Mac地址
 *
 *  @param uuidArray 二进制mac地址
 *
 *  @return MAC地址 Str
 */
+ (NSString *)parseMacAddress:(NSArray *)uuidArray;


/**
 Generate array of NSUUID objects to feed into [YMSCBCentralManager retrievePeripheralsWithIdentifiers:]
 */
+ (NSArray *)genStoredPeripheralUUID;

/**
 Save UUID in `storedPeripherals`.
 
 @param UUID peripheral UUID
 */
+ (void)saveUUID:(NSUUID *)UUID;

/**
 Delete UUID in `storedPeripherals`.
 
 @param UUID peripheral UUID
 */
+ (void)deleteUUID:(NSUUID *)UUID;


@end
