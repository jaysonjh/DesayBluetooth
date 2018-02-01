//
//  DSBLEScanDisconnectHandler.h
//  DesayBluetoothAPI
//
//  Created by ran on 16/9/13.
//  Copyright © 2016年 Desay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import<DesayBluetooth/DesayBluetooth.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "DSBLEAPIModel.h"
#import <DesayBluetooth/DSBLEPeripheral.h>

//use restore . created on 2017.9.11
typedef void (^DSBLEScanConnectHandlerRestorePeripheralsCallback)(NSArray<CBPeripheral *>* peripheralArray);

@interface DSBLEScanConnectHandler : NSObject

/**
 *  This block is use for restore Peripherals . when the function link @'- (void)centralManager:(CBCentralManager *)central willRestoreState:(NSDictionary<NSString *, id> *)dict' in CBCentralManager class be called, this function will call.
 */
- (void)restorePeripheralsCallback:(DSBLEScanConnectHandlerRestorePeripheralsCallback)callBack;

/**
 *  直接连接设备
 *  connect peripheral
 *
 *  @param peripheral
 */
- (void)connectionPeripheralByBindingDevice:(DSBLEBindingDevice *)bondDevice callBack:(void (^)( NSError *))callBack;

/**
 *  进行连接设备
 *  connect peripheral with mac address
 */
- (void)connectionByDeviceByMac:(NSString *) mac;
    
/**
 *  进行连接设备
 *  connect peripheral with Identifier
 */
- (void)connectionByDeviceByIdentifier:(NSString *)uuid;

/**
 * 是否已打开蓝牙
 * Is bluetooth turn on
 */
- (BOOL)bluetoothIsOn;

/**
 *  重新连接备
 *  reconnect peripheral
 */
- (id)reconnectionPeripheralsByDSBLEDevice:(DSBLEDevice*)device;


/**
 * 断开当前连接的设备
 * disconnect current peripheral
 */
- (void)disconnectCurrentPeripheral;

/**
 *  重新连接蓝牙设备
 *  reconnect peripheral with peripheral name
 *  @param name 设备的名字
 *
 *
 */
- (BOOL)reconnectionPeripheralsWithServicesByPeripheralName:(NSString *)name;

/**
 *  返回当前已经连接的设备实例
 *  return current connected peripheral
 *  @return WMBluetoothDevice子类
 */
- (DSBLEPeripheral *)currentDevice;

/**
 *  解析Mac地址
 *  parse mac address
 *  @param uuidArray 二进制mac地址 binary mac address
 *
 *  @return MAC地址 Str
 */
- (NSString *)parseMacAddress:(NSArray *)uuidArray;

/**
 * 断开所有设备
 * remove all peripherals
 */
- (void)removeAllPeripherals;

/**
 * 通过serviceUUIDs 检索连接的设备
 * retrieve connected peripheral by device name
 */
- (NSArray *)retrieveConnectedPeripheralsWithServicesByDeviceName:(NSString *)deviceName;

/**
 * 是否已连接
 * Is connected
 */
- (BOOL)isConnected;

/**
 * 开始扫描
 * start scan
 */
- (void)startScan;

/**
 * 停止扫描
 * stop scan
 */
- (void)stopScan;

/**
 * 停止扫描
 *  whether is scanning
 * YES -->  scanning,    NO-->not scan.
 */
- (BOOL)isScanning;


/**
 * 
 *  add delegate for @link DSBLEAPIManagerScanConnectDelegate in class @link DesayBluetoothAPIManager. To avoid repetition add delegate,you must call @link haveTargetOfClass: in this class before you add delegate.If you don't want use it ,you must remove it by @link removeTarget: in this class
 *  @param delegate id
 *  @param delegateQueue dispatch_queue_t
 */

- (void)addTarget:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;

/**
 *
 *  add delegate for @link DSBLEAPIManagerScanConnectDelegate in class @link DesayBluetoothAPIManager.  To avoid repetition add delegate,you must call @link haveTargetOfClass: in this class before you add delegate.If you don't want use it ,you must remove it by @link removeTarget: in this class
 *  @param delegate id
 */
- (void)addTargetOnGlobalQueue:(id)delegate;

/**
 *
 *  remove delegate for @link DSBLEAPIManagerScanConnectDelegate in class @link DesayBluetoothAPIManager
 *  @param delegate id
 */

- (void)removeTarget:(id)delegate;

/**
 *
 *  check the delegate of @link DSBLEAPIManagerScanConnectDelegate in class @link DesayBluetoothAPIManager
 *  @param aclass Class
 *  @return  * YES -->  had the delegate,    NO-->not have the delegate
 */

- (BOOL)haveTargetOfClass:(Class)aclass;

@end
