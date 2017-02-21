//
//  WMBluetoothConfiguration.h
//  Vifit
//
//  Created by jayson jiang on 16/2/19.
//  Copyright © 2016年 Jayson Jiang. All rights reserved.
//

#ifndef DSBLEConfiguration_h
#define DSBLEConfiguration_h



/**
 *  蓝牙DebugLog打印控制
 *  flag of bluetooth debug log 
 */
//static BOOL kWMBluetoothDebugLog  = YES;

/**
 *  B103设备
 *  B103 device
 */
extern NSString *const BLE_B103_NAME;

/**
 *  B521设备，兼容B502 
 *  B521 device, compatible with B502
 */
extern NSString *const BLE_B521_NAME;

/**
 *  Lenovo设备
 *  Lenovo device
 */
//extern NSString *const BLE_Lenovo_NAME;

/**
 * Str \r\n
 */
extern NSString *const BLE_STRRETURN;

/**
 * Str \n
 */
extern NSString *const BLE_STRN;

/**
 * Result OK
 */
extern NSString *const BLE_RESULTOK;

/**
 * Result ERR
 */
extern NSString *const BLE_RESULTERR;

#endif /* WMBluetoothConfiguration_h */
