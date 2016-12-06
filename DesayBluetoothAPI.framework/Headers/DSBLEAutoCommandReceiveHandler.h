//
//  DSBLEAutoCommandHandler.h
//  DesayBluetoothAPI
//
//  Created by ran on 16/9/13.
//  Copyright © 2016年 Desay. All rights reserved.
//

#import <Foundation/Foundation.h>
@class DSBLECommandMessage;

typedef void (^DSBLECentralAPIReceiveDataCallback)(NSString * _Nullable dataString, NSError *_Nullable error);


@interface DSBLEAutoCommandReceiveHandler : NSObject

/**
 * 获取 实时计步结果
 * achieve real-time step data via this callback
 */
@property (nonatomic,copy)DSBLECentralAPIReceiveDataCallback _Nullable receiveUPSTEPDataCallback;

/**
 * 获取 找手机
 * achieve find phone data via this callback
 */
@property (nonatomic,copy)DSBLECentralAPIReceiveDataCallback  _Nullable receiveFINDCELLPHONEDataCallback;

/**
 * 获取 测试心率结果
 * achieve test heart rate data via this callback
 */
@property (nonatomic,copy)DSBLECentralAPIReceiveDataCallback  _Nullable receiveHEARTRATEDataCallback;

/**
 * 获取 专项运动 事件
 * achieve special sport event via this callback
 */
@property (nonatomic,copy)DSBLECentralAPIReceiveDataCallback  _Nullable receiveSPERUNDatacallback;

/**
 * 获取 拍照 事件
 * achieve shotting event via this callback
 */
@property (nonatomic,copy)DSBLECentralAPIReceiveDataCallback  _Nullable receiveTAKEPHOTODataCallback;

/**
 * 获取 播放音乐 事件
 * achieve playing event via this callback
 */
@property (nonatomic,copy)DSBLECentralAPIReceiveDataCallback  _Nullable receivePLAYMUSICDataCallback;

/**
 * 获取 停止音乐 事件
 * achieve stopping event via this callback
 */
@property (nonatomic,copy)DSBLECentralAPIReceiveDataCallback  _Nullable receiveSTOPMUSICDataCallback;

/**
 * 获取 暂停音乐 事件
 * achieve pausing event via this callback
 */
@property (nonatomic,copy)DSBLECentralAPIReceiveDataCallback  _Nullable receivePAUSEMUSICDataCallback;

/**
 * 获取 下一首音乐 事件
 * achieve next event via this callback
 */
@property (nonatomic,copy)DSBLECentralAPIReceiveDataCallback  _Nullable receiveNEXTMUSICDataCallback;

/**
 * 获取 上一首音乐 事件
 * achieve previous event via this callback
 */
@property (nonatomic,copy)DSBLECentralAPIReceiveDataCallback  _Nullable receivePREMUSICDataCallback;

/**
 * 转发数据
 * forward data
 */
- (void)handlerForwardMessage:(DSBLECommandMessage *_Nullable)msg;
@end
