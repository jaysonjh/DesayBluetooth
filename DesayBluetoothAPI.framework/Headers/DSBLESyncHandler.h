//
//  WMBluetoothPrepareSyncHandler.h
//  vifit
//
//  Created by jayson jiang on 16/3/25.
//  Copyright © 2016年 Jayson Jiang. All rights reserved.
//

#import <Foundation/Foundation.h>

@class WMBluetoothData;
@class DSBLEOriginalSleepInfo;
@class DSBLESportInfo;
@class DSBLEHeartrate;
@class DSBLESleepInfo;
@protocol DSBLESyncHandlerSyncProgressDelegate <NSObject>
@optional
/**
 *  同步数据 进度
 *  progress of data synchronization
 *  @param progress 进度值(0.0-1.0) progress value
 */
- (void)dataSyncProgress:(float) progress;

/**
 *  即将开始同步
 *  Sync is about to begin
 */
- (void)dataSyncWillStart;

/**
 *  同步即将结束
 *  Syncing is coming to an end
 */
- (void)dataSyncWillEnd;

/**
 *  同步出错
 *  An error occurred attempting to synchronize
 */
- (void)dataSyncError;

/* 同步后的数据
 * synchronized data
 * @pram sleepInfo 睡眠数据
 * @pram sportInfo 运动数据
 * @pram rateInfo 心率数据
 */
- (void)dataSyncFinishedWithSleepInfo:(nullable NSArray<DSBLESleepInfo *> *)sleepInfo sportInfo:(nullable NSArray<DSBLESportInfo *> *)sportInfo rateInfo:(nullable NSArray<DSBLEHeartrate *> *)rateInfo;

/* 同步后的数据
 * synchronized data
 * @pram originalSleepInfo 睡眠原始数据
 * @pram sportInfo 运动数据
 * @pram rateInfo 心率数据
 */

- (void)dataSyncFinishedWithOriginalSleepInfo:(nullable NSArray<DSBLEOriginalSleepInfo *> *)originalSleepInfo sportInfo:(nullable NSArray<DSBLESportInfo *> *)sportInfo rateInfo:(nullable NSArray<DSBLEHeartrate *> *)rateInfo;

@end

@interface DSBLESyncHandler : NSObject
@property (weak,nonatomic) id<DSBLESyncHandlerSyncProgressDelegate>_Nullable syncDelegate;
// 请求同步 request sync
- (void) handlerSyncRequest;
// 配置写数据的callback use for configuring writed data
- (void)configPeripheralWriteDataToCharacteristicCallback;

@end
