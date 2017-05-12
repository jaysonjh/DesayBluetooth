//
//  DSBluetoothPeripheral.h
//  DesayBluetoothKit
//
//  Created by Desay on 16/6/29.
//  Copyright © 2016年 desay. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CoreBluetooth/CoreBluetooth.h>


@class DSBLEBaseProtocol;

/**
 *  This function will be call when Peripheral did Discover Services
 *
 *  @param servicesArray services Array
 *  @param error         error
 */
typedef void (^DSBELPeripheralDiscoverServicesCallBack)( NSArray *_Nullable servicesArray, NSError *_Nullable error);

/**
 *  This function will be call when Peripheral did Write Data To Characteristic
 *
 *  @param peripheral     peripheral
 *  @param characteristic peripheral's characteristic
 *  @param error          error
 */
typedef void (^DSBELPeripheralDidWriteDataToCharacteristicCallBack)(CBPeripheral *_Nullable peripheral,CBCharacteristic *_Nullable characteristic, NSError *_Nullable error);

/**
 *  This function will be call when Peripheral Receive Data From Characteristic
 *
 *  @param peripheral     peripheral
 *  @param characteristic peripheral's characteristic
 *  @param appendData     Receive data(append)
 *  @param error          error
 */
typedef void (^DSBELPeripheralReceiveDataFromCharacteristicCallBack)(CBPeripheral *_Nullable peripheral,CBCharacteristic *_Nullable characteristic,NSData *_Nullable appendData, NSError *_Nullable error);

/**
 *  This function will be call when Peripheral Receive Data Complete
 *
 *  @param peripheral     peripheral
 *  @param characteristic peripheral's characteristic
 *  @param data           Receive data(append)
 *  @param error          error
 */
typedef void (^DSBELPeripheralReceiveCompleteDataFromCharacteristicCallBack)(CBPeripheral *_Nullable peripheral,CBCharacteristic *_Nullable characteristic,NSData *_Nullable data, NSError *_Nullable error);

/**
 *  This function will be call when Peripheral Notify Characteristic
 *
 *  @param error error
 */
typedef void (^DSBELPeripheralNotifyCharacteristicCallback)( NSError *_Nullable error);

/**
 *  手环主动发的数据callback
 *
 *  @param peripheral     peripheral
 *  @param characteristic peripheral's characteristic
 *  @param data           Receive data(append)
 *  @param error          error
 */
typedef void (^DSBELPeripheralReceiveAutoDataCallBack)(CBPeripheral *_Nullable peripheral,CBCharacteristic *_Nullable characteristic,NSData *_Nullable data, NSError *_Nullable error);

/**
 *  Peripheral Model Protocol
 */
@protocol DSBLEPeripheralModelProtocol <NSObject>

- (void)peripheralModelProtocol;

@end




@interface DSBLEPeripheral : NSObject

@property (nonatomic,copy)   CBPeripheral * _Nullable myPeripheral;
@property (nonatomic,strong) DSBLEBaseProtocol * _Nullable baseProtocol;
@property (nonatomic,strong) id<DSBLEPeripheralModelProtocol>  _Nullable model;

/**
 *  link @'DSBELPeripheralDiscoverServicesCallBack'
 */
@property (nonatomic,copy) DSBELPeripheralDiscoverServicesCallBack _Nullable peripheralDiscoverServicesCallback;

/**
 *  link @'DSBELPeripheralDidWriteDataToCharacteristicCallBack'
 */
@property (nonatomic,copy) DSBELPeripheralDidWriteDataToCharacteristicCallBack _Nullable peripheralWriteDataToCharacteristicCallback;

/**
 *  link @'DSBELPeripheralReceiveDataFromCharacteristicCallBack'
 */
@property (nonatomic,copy) DSBELPeripheralReceiveDataFromCharacteristicCallBack _Nullable peripheralReceiveDataFromCharacteristicCallBack;

/**
 *  link @'DSBELPeripheralReceiveCompleteDataFromCharacteristicCallBack'
 */
@property (nonatomic,copy) DSBELPeripheralReceiveCompleteDataFromCharacteristicCallBack _Nullable peripheralReceiveCompleteDataFromCharacteristicCallBack;

/**
 *  link @'DSBELPeripheralNotifyCharacteristicCallback'
 */
@property (nonatomic,copy) DSBELPeripheralNotifyCharacteristicCallback _Nullable peripheralNotifyCharacteristicCallback;

/**
 *  link @'DSBELPeripheralReceiveAutoDataCallBack'
 */
@property (nonatomic,copy) DSBELPeripheralReceiveAutoDataCallBack _Nullable peripheralReceiveAutoDataCallBack;

/*
 *is Connected
 */
- (BOOL)isConnected;

/**
 *  init
 *
 *  @param central    CBCentralManager
 *  @param peripheral CBPeripheral
 *
 *  @return DSBLEPeripheral instancet
 */
- (_Nonnull instancetype)initWithCentralManager:(CBCentralManager*_Nonnull)central
                                     peripheral:(CBPeripheral *_Nonnull)peripheral;

//扫描服务
/**
 *  discover Services
 *  Extras： centralManager did Connect Peripheral
 *
 *  @param serviceUUIDs    service UUID array
 *  @param callback        callback
 */
- (void)discoverServices:( NSArray<CBUUID *> *_Nullable)serviceUUIDs
                callback:(void(^_Nullable)(NSArray *_Nullable  servicesArray, NSError *_Nullable  error))callback;

//走baseProtocol 中配置的notifyCharacteristic
/**
 *  This function will auto call the function @'notifyCharacteristic' in @'DSBLEBaseProtocol' subclass

 *  notify Characteristic
 */
- (void)notifyCharacteristic;

/**
 *  This function will auto call the function @'notifyCharacteristic' in @'DSBLEBaseProtocol' subclass
 *
 *  @param callBack callBack
 */
- (void)notifyCharacteristicCallBack:(void (^_Nullable)( NSError *_Nullable))callBack;

//走其它的notifyCharacteristic
/**
 *  notify Characteristic By Array （manually）
 *
 *  @param array notify Characteristic's uuid array
 */
- (void)notifyCharacteristicByArray:(NSArray<CBUUID*>*_Nullable)array;

//直接写数据
/**
 *  write Data to Characteristic
 *
 *  @param data               data
 *  @param characteristicUUID characteristic's UUID
 */
- (void)writeData:(NSData *_Nonnull)data toCharacteristic:(CBUUID *_Nonnull)characteristicUUID;

/**
 *  write Data to Characteristic by CBCharacteristicWriteType
 *
 *  @param data               data
 *  @param characteristicUUID characteristic's UUID
 *  @param type               link @'CBCharacteristicWriteType'
 */
- (void)writeData:(NSData *_Nonnull)data toCharacteristic:(CBUUID *_Nonnull)characteristicUUID type:(CBCharacteristicWriteType)type;//

//直接写数据 block 返回
/**
 *  write Data to Characteristic with callBack / receiveDataCallBack / receiveCompleteDataCallBack
 *
 *  @param command                     command （id），you must  implementation @'convertCommandToData' in     DSBLEBaseProtocol subclass

 *  @param characteristicUUID          characteristic's UUID
 *  @param writeDataCallBack           write Data callback
 *  @param receiveDataCallBack         receive Data callback
 *  @param receiveCompleteDataCallBack receive Data Complete CallBack
 */
- (void)writeCommand:(id _Nonnull )command
    toCharacteristic:(CBUUID *_Nonnull)characteristicUUID
            callBack:(void (^_Nullable)(CBPeripheral * _Nullable,CBCharacteristic *_Nullable, NSError *_Nullable))writeDataCallBack
 receiveDataCallBack:(void(^_Nullable)(CBPeripheral *_Nullable,CBCharacteristic *_Nullable,NSData *_Nullable, NSError *_Nullable))receiveDataCallBack
receiveCompleteDataCallBack:(void(^_Nullable)(CBPeripheral *_Nullable,CBCharacteristic *_Nullable,NSData *_Nullable, NSError *_Nullable))receiveCompleteDataCallBack;

/**
 *  write Data to Characteristic with CBCharacteristicWriteType / callBack / receiveDataCallBack /receiveCompleteDataCallBack
 *
 *  @param command                     command （id），you must  implementation @'convertCommandToData' in     DSBLEBaseProtocol subclass
 *  @param characteristicUUID          characteristic's UUID
 *  @param type                        link @'CBCharacteristicWriteType'
 *  @param writeDataCallBack           write Data callback
 *  @param receiveDataCallBack         receive Data callback
 *  @param receiveCompleteDataCallBack receive Data Complete CallBack
 */
- (void)writeCommand:(id _Nonnull )command
    toCharacteristic:(CBUUID *_Nonnull)characteristicUUID
                type:(CBCharacteristicWriteType)type
            callBack:(void (^_Nullable)(CBPeripheral * _Nullable,CBCharacteristic *_Nullable, NSError *_Nullable))writeDataCallBack
 receiveDataCallBack:(void(^_Nullable)(CBPeripheral *_Nullable,CBCharacteristic *_Nullable,NSData *_Nullable, NSError *_Nullable))receiveDataCallBack
receiveCompleteDataCallBack:(void(^_Nullable)(CBPeripheral *_Nullable,CBCharacteristic *_Nullable,NSData *_Nullable, NSError *_Nullable))receiveCompleteDataCallBack;


//断开设备后清理指令队列数据
- (void)clearWriteDataArray;

- (void)turnOffCharacteristicByUUID:(CBUUID *_Nonnull)uuid;

- (void)turnOnCharacteristicByUUID:(CBUUID *_Nonnull)uuid;

@end
