//
//  DSBLENewSleepAlgorithm.h
//  Purifit
//
//  Created by jayson jiang on 2016/12/12.
//  Copyright © 2016年 Jayson Jiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@class DSBLESleepInfo;
@class DSBLEOriginalSleepInfo;
@class DSBLEOriginalSleepBlock;

@interface DSBLENewSleepAlgorithm : NSObject

/**
 Get Sleep Algorithm Instance(singleton)

 @return WMNewSleepAlgorithm
 */
+ (instancetype)shareSleepAlgorithm;

/**
 *  分析睡眠数据
 *
 *  @param rawData 睡眠原始数据
 *
 *  @return 睡眠状态 NSArray<WMSleepInfo *>
 */
- (NSArray<DSBLESleepInfo *> *)analyzeSleepRawData:(NSArray<DSBLEOriginalSleepBlock *> *)rawData;

@end


@interface DSBLENewSleepAlgorithmConfiguration : NSObject

/**
 *  加载默认设置
 *
 *  @return 睡眠参数
 */
+ (instancetype)algorithmConfiguration;

/**
 *  从文件中读取睡眠参数(用于日后可以网络下载参数，进行算法的变更)
 *
 *  @return 睡眠参数
 */
+ (instancetype)algorithmConfigurationFromUserDefault;

/**
 白天深睡眠的阈值(Integer),默认5
 */
@property (strong,nonatomic) NSNumber *maxDayDeepSleepThresh;

/**
 晚上深睡眠的阈值(Integer),默认16
 */
@property (strong,nonatomic) NSNumber *maxNightDeepSleepThresh;

/**
 浅睡眠占整体睡眠比例(float),默认20%
 */
@property (strong,nonatomic) NSNumber *ligntSleepPercentThresh;

/**
 睡眠连接-醒来的阈值(Integer),默认20
 */
@property (strong,nonatomic) NSNumber *wakeupThresh;

/**
 白天8~晚上10的有效睡眠阈值(Integer),默认4
 */
@property (strong,nonatomic) NSNumber *daySleepThresh;

/**
 其他时段有效睡眠阈值(Integer),默认2
 */
@property (strong,nonatomic) NSNumber *otherSleepThresh;
@end


