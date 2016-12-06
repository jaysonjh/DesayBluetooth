//
//  WMBluetoothNormalCommandHandler.h
//  vifit
//
//  Created by jayson jiang on 16/3/14.
//  Copyright © 2016年 Jayson Jiang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DSBLEAPIModel.h"

@class DSBLEAlarmModel;
@class DSBLESedentary;
@class DSBLEAppNotify;

typedef void (^DSBLECentralAPIDataCallback)(NSString *_Nullable dataString, NSError *_Nullable error);

@interface DSBLENormalCommandSendHandler : NSObject

/**
 * 版本号
 * Version
 */
- (void)sendVERCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 重置手环
 * Reset bracelet
 */
- (void)sendRESETCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 绑定手环
 * Bind bracelet
 */
- (void)sendUSERBONDCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 激活手环
 * Active bracelet
 */
- (void)sendACTCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 设置用户信息 -> 身高,体重
 * To set user info -> Height, Weight
 */
- (void)sendUSERINFO:(nonnull NSNumber*)height weight:(nonnull NSNumber *)weight Callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 获取设备SN号
 * Achieve SN
 */
- (void)sendGETSNCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 获取设备电量
 * Achieve battery life
 */
- (void)sendGETPOWERCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 保存计步
 * Save step count
 */
- (void)sendSTEPSTOCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 开启or关闭 实时计步上报 open-> YES 开启， open->NO 关闭
 * real-time step reporting
 */
- (void)sendUPSTEPOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 语言设置
 * To set language
 */
- (void)sendLANSET:(BLELanguageType)type callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 目标设置
 * To set step target
 */
- (void)sendDESTSET:(nonnull NSNumber *)stepCount callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 闹钟1
 * alarm1
 */
- (void)sendALARM1:(nonnull DSBLEAlarmModel *)alarm callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 闹钟2
 * alarm2
 */
- (void)sendALARM2:(nonnull DSBLEAlarmModel *)alarm callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 抬手显示 0关 2左手 3右手
 * To set raise hand display 0-off 2-left hand 3-right hand
 */
- (void)sendHANDSUPSET:(nonnull NSNumber *)wearHabit callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 久坐提醒
 * To set sedentary reminder
 */
- (void)sendSETSIT:(nonnull DSBLESedentary *)sedentary callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 找手环
 * Find bracelet
 */
- (void)sendFINDBANDCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 升级指令
 * OTA command
 */
- (void)sendUPGBCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 查询设备的时区
 * Query device's time zone
 */
- (void)sendTIMEZONECallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 设置设备的时区
 * To set device's time zone
 *
 * @pram timezoneInterval  eg. NSTimeInterval timezoneInterval = [[NSTimeZone systemTimeZone] secondsFromGMT];
 */
- (void)sendTIMEZONESet:(NSTimeInterval )timezoneInterval callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 设置设备的时间
 * To set device's time
 *
 * @pram timeString  eg. NSDateFormatter *time = [NSDate ble_shareDateFormatter:@"yyyyMMddHHmmss"];
                         NSString *timeString = [time stringFromDate:[NSDate date]];
                         [self sendTIMEZONESet:timeString callback:.........];
 */
- (void)sendTIMESet:(nonnull NSString * )timeString callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 * 开启心率测试   发送该指令并接收到数据后 需要手动关闭心率测试 调用 @link @"sendCloseHEARTRATECallback:"
 * Turn on heart rate test
 */
- (void)sendOpenHEARTRATECallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 关闭心率测试
 * Turn off heart rate test
 */
- (void)sendCloseHEARTRATECallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * ANCS设置
 * To set ANCS
 */
- (void)sendANCSSET:(nonnull DSBLEAppNotify *)appNotify callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * SYNC提示  @pram show YES->显示  NO->关闭
 * To set sync display
 */
- (void)sendSYNCSHOW:(BOOL)show callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 开启 or 关闭远程拍照  @pram open YES->开启  NO->关闭
 * Turn on / off remote take photo
 */
- (void)sendREMOTECAMERAOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 开启 or 关闭 找手机功能  @pram open YES->开启  NO->关闭
 * Turn on / off find phone
 */
- (void)sendFINDPHONESETOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 开启 or 关闭 音乐控制  @pram open YES->开启  NO->关闭
 * Turn on / off music control
 */
- (void)sendMUSICCRLSETOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 开启 or 关闭 单位设置  @pram open YES->公里  NO->英里
 * Turn on / off unit setting
 */
- (void)sendUNITSETOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 开启 or 关闭 智能防丢  @pram open YES->开启  NO->关闭
 * Turn on / off anti-lost
 */
- (void)sendANTILOSTSETOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 开启 or 关闭 心率  @pram open YES->开启  NO->关闭
 * Turn on / off heart rate monitor
 */
- (void)sendHRMONITORSETOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 开启 or 关闭 音乐状态  @pram open YES->开启  NO->关闭
 * Turn on / off music state
 */
- (void)sendMUSICPLYOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 开启 or 关闭 24小时时间格式
 * Turn on / off 24 hour system
 * @pram open YES->开启24小时  NO->12小时 时间格式
 */
- (void)send24HoursTIMEFORMATOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 开启 or 关闭 专项运动
 * Turn on / off special sport
 * @param open YES->开启 专项运动 NO->关闭 专项运动
 */
- (void)sendSPERUNOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 回写步数
 * write back step
 * @param step 回写的步数 write-back step
 */
- (void)sendPACE:(nonnull NSNumber *)step callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 用于兼容老项目
 * compatible with old project
 */
- (void)sendALARM1String:(nonnull NSString *)alarmString callback:(nonnull DSBLECentralAPIDataCallback)callback;
- (void)sendALARM2String:(nonnull NSString *)alarmString callback:(nonnull DSBLECentralAPIDataCallback)callback;

@end
