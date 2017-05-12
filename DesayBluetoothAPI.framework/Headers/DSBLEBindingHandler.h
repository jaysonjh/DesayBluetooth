//
//  WMBindingViewModel.h
//  vifit
//
//  Created by jayson jiang on 16/3/1.
//  Copyright © 2016年 Jayson Jiang. All rights reserved.
//

#import <Foundation/Foundation.h>
@class DSBLEBindingDevice;
typedef NS_ENUM(NSInteger,DSBLEBindingState) {
    DSBLEBindingStateIdel=0,// in ready 准备中
    DSBLEBindingStateConnecting=1,// connecting 连接
    DSBLEBindingStateBond=2,// bound 绑定
    DSBLEBindingStateActive=3,// active 激活
    DSBLEBindingStateSuccess=4,// successed 成功
    DSBLEBindingStateFail=5,// failed 失败
    DSBLEBindingStateOTA=6// OTA 设备处于OTA中
};

@protocol DSBLEBindingResultProtocol <NSObject>

/**
 *  正常绑定流程
 *  normal binding process
 *  @param state 绑定状态 binding state
 */
- (void)bindingResult:(DSBLEBindingState )state;

/**
 *  强制OTA流程
 *  force OTA process
 */
- (void)bindingOTA:(NSString *)mac deviceClass:(NSString *)className vendor:(NSString *)vendor;
@end

@interface DSBLEBindingHandler : NSObject
@property (weak,nonatomic) id<DSBLEBindingResultProtocol> delegate;
@property (strong,nonatomic) DSBLEBindingDevice *device;

/**
 *  发起绑定手环的操作
 *  initiate binding bracelet operation
 */
- (void)startBondDevice:(DSBLEBindingDevice*)device;

@end
