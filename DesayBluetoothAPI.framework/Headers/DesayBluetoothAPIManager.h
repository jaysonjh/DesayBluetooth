//
//  DesayBluetoothAPIManager.h
//  DesayBluetoothAPI
//
//  Created by ran on 16/9/7.
//  Copyright © 2016年 Desay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DesayBluetooth/DesayBluetooth.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "DSBLEAPIModel.h"
#import "DSBLEAutoCommandReceiveHandler.h"
#import "DSBLEScanConnectHandler.h"
#import "DSBLEBindingHandler.h"
#import "DSBLENormalCommandSendHandler.h"
#import "DSBLESyncHandler.h"
#import <DesayBluetooth/DSBLEPeripheral.h>
@class DSBLEBluetoothData;
@class DSBLEOriginalSleepInfo;
@class DSBLESportInfo;
@class DSBLEHeartrate;
@class DSBLEPeripheralModel;


#define DSBLEAPIManager [DesayBluetoothAPIManager shareManager]

/**
 * 获取 扫描 连接 断开手环的Handler
 * Achieve the handler that can scan, connect or disconnect
 */
#define DSBLEAPIShareScanConnectHandler [[DesayBluetoothAPIManager shareManager] findScanConnectHandler]

/**
 * 获取 手环主动发数据给app 的Handler
 * Achieve the handler that can send data to app by bracelet actively
 */
#define DSBLEAPIShareAutoCommandReceiveHandler [[DesayBluetoothAPIManager shareManager] findAutoCommandReceiveHandler]

/**
 * 获取 app发指令给手环 的Handler
 * Achieve the handler that can send data to bracelet by app
 */
#define DSBLEAPIShareNormalCommandSendHandler [[DesayBluetoothAPIManager shareManager] findNormalCommandSendHandler]

/**
 * 获取 绑定手环 的Handler
 * Achieve the handler of binding bracelet
 */
#define DSBLEAPIShareBindingHandler [[DesayBluetoothAPIManager shareManager] findBindingHandler]

/**
 * 获取 同步手环数据 的Handler
 * Achieve the handler of data synchronization
 */
#define DSBLEAPIShareSyncHandler [[DesayBluetoothAPIManager shareManager] findSyncHandler]


#define WMBLE_CMD(cmd,name) \
[DesayBluetoothAPIManager getCommand:cmd deviceName:name]

#define WMBLE_KEY(cmd,name) \
[DesayBluetoothAPIManager getKey:cmd deviceName:name]

/**
 @brief DSBLEScanConnectHandler supports multi this delegate,whose adding and removing should appear in pairs.Once add delegate, it must be removed in the Handler before dealloc.
 
 @discussion
 * Add Delegate
    1. [DSBLEAPIShareScanConnectHandler addTarget:(id) delegate delegateQueue:(dispatch_queue_t) queue]
    2. [DSBLEAPIShareScanConnectHandler addTargetOnGlobalQueue:(id)delegate]
 * Remove Delegate
    * [DSBLEAPIShareScanConnectHandler removeTarget:(id)delegate]
 */
@protocol DSBLEAPIManagerScanConnectDelegate <NSObject>
@optional

/**
 Monitor bluetooth state
 @param state bluetooth state
 */
- (void)DSBLEAPIManagerNotifyState:(CBCentralManagerState)state;

/**
 @brief Invoke this API when devices is scanned

 @param device Device information inclued mac,name,rssi,state,advData
 @see DSBLEBindingDevice
 */
- (void)DSBLEAPIManagerDidDiscoverPeripheral:(nullable DSBLEBindingDevice *)device;

/**
 @brief 连接设备成功可以通信后回调此API
 invoke this API when connect to device and communicate with it successfully

 @param peripheral Remote peripheral devices
 @param error Connect peripheral issue
 */
- (void)DSBLEAPIManagerDidConnectPeripheral:(nullable DSBLEPeripheral *)peripheral error:(nullable NSError *)error;

/**
 @brief 设备断开回调此API
 invoke this API when device did disconnect

 @param peripheral Remote peripheral devices
 @param error Disconnect peripheral issue
 */
- (void)DSBLEAPIManagerDidDisconnectPeripheral:(nullable CBPeripheral *)peripheral error:(nullable NSError *)error;
 
@end

@interface DesayBluetoothAPIManager : NSObject
/**
 *  查询蓝牙设备参数集
 *  Query params set of bluetooth device
 *
 *  @seealso CBCentralManagerScanOptionAllowDuplicatesKey
 *	@seealso CBCentralManagerScanOptionSolicitedServiceUUIDsKey
 *
 *  Default: CBCentralManagerScanOptionAllowDuplicatesKey：NO
 */
@property (strong,nonatomic) NSDictionary *_Nullable scanOptions;


/**
 Print API Version in console.
 */
+ (void)APIVersion;
/**
 @return YES--> debug,NO-->not debug.  if return YES ,the data from fitband will not removed after syn
 */
- (BOOL)APIMode;

/**
 @param isDebug YES--> debug,NO-->not debug.
 */
- (void)setAPIMode:(BOOL)isDebug;
/**
 Get DesayBluetoothAPIManager instance.
 @discussion DesayBluetoothAPIManager is singleton.
 @return DesayBluetoothAPIManager
 */
+ (nonnull DesayBluetoothAPIManager *)shareManager;


/**
 Get Bracelet information of BT-protocol

 @param deviceName Bracelet Name
 @return DSBLEBluetoothData
 */
- (nonnull DSBLEBluetoothData *)getDeviceInfo:(nonnull NSString *)deviceName;

/**
 Get Bracelet information of BT-protocol
 @return DSBLEBluetoothData of connected Bracelet
 */
- (nullable DSBLEBluetoothData *)getCurrentDeviceInfo;

/**
 Get current BLEPeripheral
 @return DSBLEPeripheral,The DSBLEPeripheral class represents remote peripheral devices.
 */
- (nullable DSBLEPeripheral *)currentDevice;

/**
 Get current BLEPeripheral information of Peripheral attributes.
 @return DSBLEPeripheralModel,stored Peropheral's identifier,MAC address,name,Device Info,and state（DFU Mode/Normal Mode）.
 */
- (nullable DSBLEPeripheralModel *)currentDeviceModel;

/**
 Get current BLEPeripheral connected state.
 @return YES connected, NO disConnected.
 */
- (BOOL )isCurrentChannelPeripheralConnected;

/**
 * 获取 app发指令给手环 的Handler
 * Achieve the handler that can send data to bracelet by app
 */
- (nonnull  DSBLENormalCommandSendHandler*)findNormalCommandSendHandler;

/**
 * 获取 手环主动发数据给app 的Handler
 * Achieve the handler that can send data to app by bracelet actively
 */
- (nonnull  DSBLEAutoCommandReceiveHandler*)findAutoCommandReceiveHandler;

/**
 * 获取 扫描 连接 断开手环的Handler
 * Achieve the handler that can scan, connect or disconnect
 */
- (nonnull  DSBLEScanConnectHandler *)findScanConnectHandler;

/**
 * 获取 绑定手环 的Handler
 * Achieve the handler of binding bracelet
 */
- (nonnull  DSBLEBindingHandler *)findBindingHandler;

/**
 * 获取 同步手环数据 的Handler
 * Achieve the handler of syncing data
 */
- (nonnull  DSBLESyncHandler *)findSyncHandler;



+ (nullable NSString *) getCommand:(nonnull NSString *)cmd deviceName:(nonnull NSString *)deviceName;

+ (nullable NSString *) getKey:(nonnull NSString *)cmd deviceName:(nonnull NSString *)deviceName;

- (void)sendData:(nullable NSArray *)data commandType:(nonnull NSString *)commandType callBack:(void (^_Nullable)(CBPeripheral * _Nullable,CBCharacteristic *_Nullable, NSError *_Nullable))writeDataCallBack
receiveDataCallBack:(void(^_Nullable)(CBPeripheral *_Nullable,CBCharacteristic *_Nullable,NSData *_Nullable, NSError *_Nullable))receiveDataCallBack
receiveCompleteDataCallBack:(void(^_Nullable)(CBPeripheral *_Nullable,CBCharacteristic *_Nullable,NSData *_Nullable, NSError *_Nullable))receiveCompleteDataCallBack;

@end
