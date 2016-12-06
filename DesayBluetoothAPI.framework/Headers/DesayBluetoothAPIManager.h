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




@protocol DSBLEAPIManagerScanConnectDelegate <NSObject>
@optional

/**
 * 监控蓝牙状态
 * Monitor bluetooth state
 */
- (void)DSBLEAPIManagerNotifyState:(CBCentralManagerState)state;

/**
 * 扫描出设备后回调此API
 * invoke this API when devices is scanned
 */
- (void)DSBLEAPIManagerDidDiscoverPeripheral:(nullable DSBLEBindingDevice *)device;

/**
 * 连接设备成功可以通信后回调此API
 * invoke this API when connect to device and communicate with it successfully
 */
- (void)DSBLEAPIManagerDidConnectPeripheral:(nullable DSBLEPeripheral *)peripheral error:(nullable NSError *)error;

/**
 * 设备断开回调此API
 * invoke this API when device did disconnect
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

+ (void)APIVersion;
+ (nonnull DesayBluetoothAPIManager *)shareManager;
- (nonnull DSBLEBluetoothData *)getDeviceInfo:(nonnull NSString *)deviceName;
- (nullable DSBLEBluetoothData *)getCurrentDeviceInfo;
- (nullable DSBLEPeripheral *)currentDevice;
- (nullable DSBLEPeripheralModel *)currentDeviceModel;
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
