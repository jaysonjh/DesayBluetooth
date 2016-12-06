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

@interface DSBLEPeripheralModel : NSObject<DSBLEPeripheralModelProtocol>
@property (nonatomic,assign) NSInteger state;
@property (nonatomic,copy) NSString *mac;
@property (nonatomic,copy) NSString *identifier;
@property (nonatomic,copy) NSString *name;
@property (nonatomic,strong) DSBLEBluetoothData *deviceInfo;

@end
