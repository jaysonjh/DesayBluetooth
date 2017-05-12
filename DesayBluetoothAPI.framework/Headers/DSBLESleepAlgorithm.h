//
//  WMSleepAlgorithm.h
//  meizu
//
//  Created by jayson jiang on 16/7/25.
//  Copyright © 2016年 Jayson Jiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

/**
 *  UserDefault Key
 */
extern NSString * const kConfigurationFileName;
extern NSString * const kWakeupThresh;
//extern NSString * const kMinTimeLightSleep;
extern NSString * const kMinPercLightSleep;
extern NSString * const kSitThresh;
extern NSString * const kTakeThresh;

@class DSBLESleepInfo;

@interface DSBLESleepAlgorithm : NSObject

+ (instancetype)shareSleepAlgorithm;
/**
 *  分析睡眠数据
 *
 *  @param rawData 睡眠原始数据
 *
 *  @return 睡眠状态 NSArray<WMSleepInfo *>
 */
- (NSArray<DSBLESleepInfo *> *)analyzeSleepRawData:(NSArray *)rawData;

@end



/**
 *  睡眠算法参数设置
 */
@interface DSBLESleepAlgorithmConfiguration : NSObject

/**
 *  设置的醒来时长阈值
 */
@property (assign,nonatomic) NSUInteger wakeupThresh;
/**
 *  有效睡眠的最小浅睡时长
 */
//@property (assign,nonatomic) NSUInteger minTimeLightSleep;
/**
 *  有效睡眠的最小浅睡比例
 */
@property (assign,nonatomic) CGFloat minPercLightSleep;

/**
 *  久坐时长阈值
 */
@property (assign,nonatomic) NSUInteger sitThresh;

/**
 *  睡眠阈值
 */
@property (assign,nonatomic) NSUInteger takeThresh;

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


@end
