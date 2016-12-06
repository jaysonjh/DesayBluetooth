//
//  WMBluetoothDeviceUtils.h
//  vifit
//
//  Created by jayson jiang on 16/2/23.
//  Copyright © 2016年 Jayson Jiang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DSBLEDeviceUtils : NSObject
/**
 * 获取格式化的mac地址
 * Achieve specified mac address
 *
 * @param uuidArray 16进制数据 hex-encoded data
 *
 * @return 8位mac地址 8bit mac address
 */
+ (NSString *)parseMacAddress:(NSArray *)uuidArray;
+ (NSString *)fetchDeviceServiceUUIDByDeviceName:(NSString *)deviceName;
+ (NSString *)peripheralNameByManufactorCode:(NSString *)code;
@end
