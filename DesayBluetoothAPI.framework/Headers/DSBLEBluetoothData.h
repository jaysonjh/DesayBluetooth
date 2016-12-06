//
//  WMBluetoothData.h
//  vifit
//
//  Created by jayson jiang on 16/2/20.
//  Copyright © 2016年 Jayson Jiang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DSBLEBluetoothData : NSObject

@property (strong,nonatomic) NSString *deviceName;
@property (strong,nonatomic) NSString *factoryClassName;
@property (strong,nonatomic) NSString *deviceClassName;
@property (strong,nonatomic) NSString *manufactorCode;

@end

