//
//  DSBLEPeripheralModel.h
//  Purifit
//
//  Created by ran on 16/8/23.
//  Copyright © 2016年 Jayson Jiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DesayBluetooth/DSBLEPeripheral.h>
#import "DSBLEBluetoothData.h"


/**
 @brief DSBLEPeripheralModel,stored Peropheral's identifier,MAC address,name,Device Info,and state（DFU Mode/Normal Mode）.
 */
@interface DSBLEPeripheralModel : NSObject<DSBLEPeripheralModelProtocol>

/**
 @brief Peripheral Mode
 0 = Normal mode, All function of bracelet is ready to use.
 1 = DFU mode,Only use to upgrade bracelet.
 */
@property (nonatomic,assign) NSInteger state;

/**
 MAC Address
 */
@property (nonatomic,copy) NSString *mac;

/**
 UUID of Peripheral
 */
@property (nonatomic,copy) NSString *identifier;

/**
 Peripheral name
 */
@property (nonatomic,copy) NSString *name;

/**
 Bracelet information of BT-protocol
 @see DSBLEBluetoothData
 */
@property (nonatomic,strong) DSBLEBluetoothData *deviceInfo;

@end
