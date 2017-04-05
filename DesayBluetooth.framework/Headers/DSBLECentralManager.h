//
//  DSBLECentralManager.h
//  DesayBluetoothKit
//
//  Created by Desay on 16/6/29.
//  Copyright © 2016年 desay. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>




@class DSBLEPeripheral;

//扫描外设的规则
/**
 *  This function will be call when CentralManager did Discover Peripheral
 *  Filter On Discover Peripherals
 *
 *  @param peripheral            Discover Peripheral
 *  @param advertisementData     advertisement Data
 *  @param peripheralName        peripheral Name
 *  @param uuid                  Peripheral uuid
 *  @param RSSI                  Peripheral RSSI
 *
 *  @return if return NO ,this Peripheral will be Filtr
 */
typedef BOOL (^DSBLECentralManagerFilterOnDiscoverPeripheralsCallBack)(CBPeripheral *_Nonnull peripheral,NSDictionary<NSString *, id> *_Nullable advertisementData,NSString *_Nullable peripheralName, CBUUID *_Nullable uuid, NSNumber *_Nullable RSSI);

//断开block
/**
 *  This function will be call when CentralManager did Disconnect Peripheral 
 *
 *  @param peripheral Disconnect DSBLEPeripheral
 *  @param error      Disconnect error
 */
typedef void (^DSBLECentralManagerDisconnectPeripheralCallback)(CBPeripheral *_Nullable peripheral, NSError *_Nullable error);

//检测蓝牙状态变化block
/**
 *  This function will be call when CentralManager Did Update State
 *
 *  @param state CentralManager State
 */
typedef void (^DSBLECentralManagerNotifyStateCallback)(CBCentralManagerState state);

//扫描超时block
/**
 *  This function will be call when CentralManager Discovered Overtime
 *
 *  @param discoveredPeripheralArray discovered Peripheral Array
 */
typedef void (^DSBLECentralManagerDiscoveredOvertimeCallback)(NSMutableArray *_Nullable discoveredPeripheralArray);

//数据传输模式
typedef NS_ENUM(NSInteger, DSBLEDataTransmitMode) {
    /**
     *  Data Transmit Normal
     */
    DSBLEDataTransmitNormal= 0,//普通传输
    /**
     *  Data Transmit Sync
     */
    DSBLEDataTransmitSync//同步数据
};

@interface DSBLECentralManager : NSObject

/**
 *  Data Transmit Mode link @'DSBLEDataTransmitMode'
 */
@property (nonatomic) DSBLEDataTransmitMode dataTransmitMode;

/**
 *  Central Manager State
 */
@property (nonatomic) CBCentralManagerState state;
@property (nonatomic) BOOL isOpenLog;//是否打开日志

/**
 *  link @'DSBLECentralManagerNotifyStateCallback'
 */
@property(nonatomic,copy)DSBLECentralManagerNotifyStateCallback _Nullable centralManagerNotifyStateCallback;

/**
 *  link @'DSBLECentralManagerFilterOnDiscoverPeripheralsCallBack'
 */
@property(nonatomic,copy)DSBLECentralManagerFilterOnDiscoverPeripheralsCallBack _Nullable centralManagerFilterOnDiscoverPeripherals;

/**
 *  link @'DSBLECentralManagerDiscoveredOvertimeCallback'
 */
@property(nonatomic,copy)DSBLECentralManagerDiscoveredOvertimeCallback _Nonnull centralManagerDiscoveredOvertimeCallback;

/**
 *  link @'DSBLECentralManagerDisconnectPeripheralCallback'
 */
@property(nonatomic,copy)DSBLECentralManagerDisconnectPeripheralCallback _Nullable centralManagerDisconnectPeripheralCallback;

+ (DSBLECentralManager* _Nonnull)shareManager;

+ (void)APIVersion;

/*
 Deprecated
 */
+ (void)securityKey:(NSString *_Nonnull)securityKey;

/**
 *   enable log
 *   @param open             it is a bool , YES -> open ,NO -> close.
 */
+(void)enableLog:(BOOL)open;

//蓝牙是否打开状态
/**
 *   bluetooth Open
 *
 *  @return if return is YES , bluetooth is Open
 */
- (BOOL)bluetoothOpen;

//是否正在扫描
/**
 *  CentrallManager is Scaning
 *
 *  @return if return is YES , CentrallManager is Scaning
 */
- (BOOL)isScanning;

//扫描到的Peripheral array
/**
 *  discovered Peripheral Array
 *
 */
- (NSMutableArray *_Nullable)discoveredPeripheralArray;

//当前连接中的Peripheral array
/**
 *  CentrallManager connected Peripheral Array
 *
 */
- (NSMutableArray *_Nullable)connectedPeripheralArray;

//扫描外设
/**
 *  scan For Known Peripheral by name array
 *
 *  @param nameArray    peripheral name array
 *  @param serviceUUIDs peripheral service UUIDs array
 *  @param overtime     scan overtime
 *  @param options      scan options
 *  @param callBack     callback
 */
- (void)scanForKnownPeripheralNames:(NSArray<NSString *> *_Nullable)nameArray
                           services:(NSArray<CBUUID *> *_Nullable)serviceUUIDs
                 discoveredOvertime:(NSTimeInterval)overtime
                            options:(NSDictionary<NSString *,id> *_Nullable)options
                           callBack:(void(^ _Nullable )(CBPeripheral *_Nullable peripheral, NSDictionary *_Nullable dic, NSNumber *_Nullable RSSI, NSError *_Nullable error))callBack;

//扫描外设
/**
 *   scan For Known Peripheral by mac array
 *
 *  @param macArray     peripheral mac array
 *  @param serviceUUIDs peripheral service UUIDs array
 *  @param overtime     scan overtime
 *  @param options      scan options
 *  @param callBack     callback
 */
- (void)scanForKnownPeripheralMACs:(NSArray<NSString *> *_Nullable)macArray
                          services:(NSArray<CBUUID *> *_Nullable)serviceUUIDs
                discoveredOvertime:(NSTimeInterval)overtime
                           options:(NSDictionary<NSString *,id> *_Nullable)options
                          callBack:(void(^ _Nullable )(CBPeripheral *_Nullable peripheral, NSDictionary *_Nullable dic, NSNumber *_Nullable RSSI, NSError *_Nullable error))callBack;

//连接外设
/**
 *  connect Peripheral By Identifier
 *
 *  @param peripheralIdentifier peripheral Identifier
 *  @param callBack             callback
 */
- (void)connectPeripheralByIdentifier:(NSUUID *_Nonnull)peripheralIdentifier
                             callBack:(void(^_Nullable)(DSBLEPeripheral *_Nullable peripheral, NSError *_Nullable error))callBack;
//连接外设
/**
 *  connect Peripheral
 *
 *  @param peripheral peripheral
 *  @param callBack   callback
 */
- (void)connectPeripheral:(CBPeripheral * _Nonnull )peripheral
                 callBack:(void(^_Nullable)(DSBLEPeripheral *_Nullable peripheral, NSError *_Nullable error))callBack;


//恢复外设并连接外设
/**
 *  CentrallManager retrieve And Connect Peripherals By Identifiers
 *
 *  @param peripheralIdentifiers peripheral Identifiers  array
 *  @param callBack              callback
 *
 *  @return if return is NO , the callback will not be execute, you should star scan peripheral
 */
- (BOOL)retrieveAndConnectPeripheralsByIdentifiers:(NSArray< NSUUID*> *_Nonnull)peripheralIdentifiers
                                          callBack:(void(^_Nullable)(DSBLEPeripheral *_Nullable peripheral , NSError *_Nullable error))callBack;

- (NSArray *_Nullable)retrieveConnectedPeripheralsWithServices:(NSArray< CBUUID*> *_Nonnull)peripheralUUIDs;

//恢复外设并连接外设
- (BOOL)retrieveConnectedPeripheralsWithServices:(NSArray< CBUUID*> *_Nonnull)peripheralUUIDs
                                        callBack:(void(^_Nullable)(DSBLEPeripheral *_Nullable peripheral , NSError *_Nullable error))callBack;

//通过Services 和 device name恢复外设并连接外设

- (BOOL)retrieveConnectedPeripheralsWithServices:(NSArray< CBUUID*> *_Nonnull)peripheralUUIDs
                                      deviceName:(NSString *_Nonnull)deviceName
                                        callBack:(void(^_Nullable)(DSBLEPeripheral *_Nullable peripheral , NSError *_Nullable error))callBack;

//停止扫描
/**
 *  CentrallManager stop Scan
 */
- (void)stopScanForPeripherals;

//断开所有设备
/**
 *  CentrallManager disconnect All Peripherals
 */
- (void)disconnectAllPeripherals;

//断开当前连接的设备
/**
 *  CentrallManager disconnect current Peripherals
 */
- (void)disconnectCurrentChannelConnectedPeripheral;

//放弃连接（当前扫描出来的设备）
/**
 *  CentrallManager cancel Current Connecting Peripheral
 */
- (void)cancelCurrentConnectingPeripheral:(CBPeripheral *_Nonnull)periphheral;


//添加断开重连接的设备
/**
 *  This function will be call by function @'centralManager:didDisconnectPeripheral:error:' in @'DSBLECentralManager' class when CentrallManager did Disconnect Peripheral
 
 *  add Peripheral To Need Reconnect Peripheral Array
 *
 *  @param peripheral peripheral
 */
-  (void)addPeripheralToNeedReconnectArray:(DSBLEPeripheral *_Nonnull)peripheral;

//删除需要重连接的设备
/**
 *  delete Peripheral From Need Reconnect Array
 *
 *  @param peripheral Peripheral
 */
-  (void)deletePeripheralFromNeedReconnectArray:(DSBLEPeripheral *_Nonnull)peripheral;

//获取当前扫描到的外设Array
/**
 *
 *  @return get Discovered Peripherals array
 */
- (NSMutableArray *_Nullable)getDiscoveredPeripherals;

//获取已连接的peripheral by peripheral‘s name
/**
 *  get Connected Peripheral By Name
 *
 *  @param peripheralName peripheral Name
 *
 *  @return Connected Peripheral
 */
- (DSBLEPeripheral *_Nullable)getConnectedPeripheralByName:(NSString *_Nonnull)peripheralName;

//获取已连接的peripheral by peripheral‘s uuid
/**
 *  get Connected Peripheral By UUID
 *
 *  @param uuid Peripheral uuid
 *
 *  @return Connected Peripheral
 */
- (DSBLEPeripheral *_Nullable)getConnectedPeripheralByUUID:(CBUUID *_Nonnull)uuid;

//获取当前正在连接使用的peripheral
/**
 *  get Current Connected Peripheral
 *
 *  @return Current Connected Peripheral
 */
- (DSBLEPeripheral *_Nullable)getCurrentChannelConnectedPeripheral;
//在已连接的peripheral array 中切换当前正在连接使用的peripheral by peripheral‘s uuid
/**
 *  change Connected Peripheral By UUID
 *
 *  @param uuid Peripheral uuid
 *
 *  @return if return is YES , change success
 */
- (BOOL)changeConnectedPeripheralByUUID:(CBUUID *_Nonnull)uuid;

//在已连接的peripheral array 中切换当前正在连接使用的peripheral by peripheral
/**
 *  change Connected Peripheral By Peripheral
 *
 *  @param peripheral peripheral
 *
 *  @return if return is YES , change success
 */
- (BOOL)changeConnectedPeripheralByPeripheral:(CBPeripheral *_Nonnull)peripheral;

//判断当前连接的外设状态是否连接
/**
 *   Current Channel Peripheral is Connected
 *

 *
 *  @return if return is YES , Peripheral Connected
 */
- (BOOL)isCurrentChannelPeripheralConnected;

@end
