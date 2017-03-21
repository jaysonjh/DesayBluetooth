//
//  DSBLEBaseProtocol.h
//  TestBle
//
//  Created by Desay on 16/6/29.
//  Copyright © 2016年 desay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DSBLESyncRequestDataModel;
@class DSBLEProtocolModel;
@class CBUUID;
@class CBPeripheral;
@class CBCharacteristic;

/**
 *  同步数据进度反馈接口
 */
@protocol WMBluetoothDataSyncProgressDelegate <NSObject>

@optional
/**
 *  进度
 *
 *  @param progress 进度值(0.0-1.0)
 */
- (void)dataSyncProgress:(float) progress;

- (void)dataSyncWillStart;

- (void)dataSyncWillEnd;


@end


@interface DSBLEBaseProtocol : NSObject

//同步进度反馈
@property (nonatomic,weak) id<WMBluetoothDataSyncProgressDelegate>  _Nullable syncProgressDelegate;

/**
 *  protocol class Name
 */
@property (nonatomic,copy) NSString *_Nonnull protocolClassName;//协议名字

/**
 *  This function will be call by @'DSBLEPeripheral' class，it muse be implementation by DSBLEBaseProtocol subclass
 *  Convert Command To Data
 *
 *  @param command command
 *
 *  @return The transformed data
 */
- (NSData *_Nonnull)convertCommandToData:(id _Nonnull)command;

//判断数据接收是否完毕
/**rxc
 *  This function will be call by function @'peripheral:didUpdateValueForCharacteristic:error:' in @'DSBLEPeripheral' class ，it muse be implementation by DSBLEBaseProtocol subclass

 
 *  tell the Data transmission is finished this time
 *
 *  @param characteristic @'peripheral:didUpdateValueForCharacteristic:error:'
 *
 *  @param peripheral     peripheral
 *
 *  @return tell the Data transmission is finished
 */
- (BOOL)isReceiveCompletedData:(NSData *_Nullable)data  characteristic:(CBCharacteristic *_Nullable)characteristic peripheral:(CBPeripheral *_Nullable)peripheral;


//配置需要订阅的特征 array
/**
 *  This function will be call by function @'notifyCharacteristic' in @'DSBLEPeripheral' class，it muse be implementation by DSBLEBaseProtocol subclass
 *  config characteristic Array who needs to subscribe
 *
 *  @return needs to Notify characteristic Array
 */
- (NSArray <CBUUID *>*_Nonnull)needNotifycharacteristicArray;

- (NSArray<CBUUID*>*_Nullable)serviceUUIDs;


//配置同步数据的model
/**
 *  This function will be call by function @'peripheral:didUpdateValueForCharacteristic:error:' in @'DSBLEPeripheral' class when Sync ，it muse be implementation by DSBLEBaseProtocol subclass
 *  config Sync model by received data
 *
 *  @param data received Data
 *
 *  @return Sync model
 */
- (DSBLESyncRequestDataModel *_Nonnull)configModelWhenStartSyncRequestByData:(NSData *_Nullable)data;

//过滤手环主动发的数据
/**
 *  This function will be call by function @'peripheral:didUpdateValueForCharacteristic:error:' in @'DSBLEPeripheral' class when Sync ，it muse be implementation by DSBLEBaseProtocol subclass
 *  config Sync model by received data
 *
 *  @param data received Data
 *
 *  @return BOOL
 */
- (BOOL)isFilterReceiveData:(NSData *_Nonnull)data;


//过滤手环主动发的心率数据

- (BOOL)isFilterHeartData:(NSData *_Nonnull)data;


@end
