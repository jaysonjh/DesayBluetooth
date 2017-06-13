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
@class DSBLEOriginalSleepBlock;

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
 * @pram originalSleepblock original sleep state
 * @pram sportInfo sport data
 * @pram rateInfo heart rate data
 */
- (void)dataSyncFinishedWithOriginalSleepBlock:(nullable NSArray<DSBLEOriginalSleepBlock *> *)originalSleepInfo sportInfo:(nullable NSArray<DSBLESportInfo *> *)sportInfo rateInfo:(nullable NSArray<DSBLEHeartrate *> *)rateInfo;

@end

@interface DSBLESyncHandler : NSObject
@property (weak,nonatomic) id<DSBLESyncHandlerSyncProgressDelegate>_Nullable syncDelegate;
/* 请求同步 request sync
 */
- (void) handlerSyncRequest;
/* 配置写数据的callback use for configuring writed data
 */
- (void)configPeripheralWriteDataToCharacteristicCallback;

@end
