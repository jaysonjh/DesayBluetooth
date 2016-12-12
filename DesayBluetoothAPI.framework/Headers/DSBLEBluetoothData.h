//
//  WMBluetoothData.h
//  vifit
//
//  Created by jayson jiang on 16/2/20.
//  Copyright © 2016年 Jayson Jiang. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Bracelet information of BT-protocol
 */
@interface DSBLEBluetoothData : NSObject

/**
 Bracelet Name
 */
@property (strong,nonatomic) NSString *deviceName;

/**
 Bracelet Factory Class Name
 */
@property (strong,nonatomic) NSString *factoryClassName;

/**
 Bracelet BT-protocol type
 */
@property (strong,nonatomic) NSString *deviceClassName;

/**
 Bracelet Vendor Code
 */
@property (strong,nonatomic) NSString *manufactorCode;

@end

