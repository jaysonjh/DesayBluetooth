//
//  DSBLESyncRequestDataModel.h
//  DesayBluetoothSDKDemo
//
//  Created by Desay on 16/6/29.
//  Copyright © 2016年 zhuya. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  Sync Request Data Model. if you want sync data in DSBLEDataTransmitSync mode, you must implementation @'configModelWhenStartSyncRequestByData' in     DSBLEBaseProtocol subclass
 */
@interface DSBLESyncRequestDataModel : NSObject

/**
 *  data type. eg: 1 byte，0 is sport data type，1 is sleep data type
 */
@property(nonatomic,assign) NSInteger type;

/**
 *  valid Data Number.
 */
@property(nonatomic,assign) NSInteger validDataNumber;

/**
 *  this packet's Size
 */
@property(nonatomic,assign) NSInteger packetSize;

/**
 *  this packet's index
 */
@property(nonatomic,assign) NSInteger packetIndex;
/**
 *  total Packet Count
 */
@property(nonatomic,assign) NSInteger totalPacketCount;

//AT+DATA:type,validdataNum,packetSize, packetnum ,totalPacketCount,crc,en\r\n
//type:一位，0代表为运动数据，1为睡眠数据
//validdataNum：三位，标示本包数据有效个数，单位为byte
//packetSize：三位，表示一个数据包的大小，单位为byte
//packetIndex：三位，包序号
//totalPacketCount：三位，包总数


@end
