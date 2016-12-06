//
//  DSBLEHeartrate.h
//  Dong
//
//  Created by jayson jiang on 15/10/13.
//  Copyright © 2015年 Desay. All rights reserved.
//

#import <Foundation/Foundation.h>
@class CBPeripheral;
typedef NS_ENUM(NSInteger,BLELanguageType) {
    BLE_LanguageType_EN     = 0,
    BLE_LanguageType_CHS    = 1,
    BLE_LanguageType_FR     = 2,
    BLE_LanguageType_IT     = 3,
    BLE_LanguageType_ES     = 4,
    BLE_LanguageType_TR     = 5,
    BLE_LanguageType_PL     = 6,
    BLE_LanguageType_JP     = 7,
};

/**
 * 心率数据
 * heart rate class
 */
@interface DSBLEHeartrate : NSObject
@property (strong, nonatomic) NSString *time;
@property (assign, nonatomic) NSInteger rate;
@property (assign, nonatomic) NSInteger type;
@property (strong, nonatomic) NSDate *utcTime;
@end

/**
 * 睡眠数据
 * sleep info class
 */
@interface DSBLESleepInfo : NSObject
//@property (strong, nonatomic) NSString *gdate;
@property (strong, nonatomic) NSString *beginTime;
@property (strong, nonatomic) NSString *endTime;
@property (strong, nonatomic) NSNumber *totalDuration;
@property (strong, nonatomic) NSNumber *wakeTime;
@property (strong, nonatomic) NSNumber *quantity;
@property (strong, nonatomic) NSArray *sleepStates;
@property (strong, nonatomic) NSArray *heartrates;
@end

/**
 * 睡眠状态数据
 * sleep state class
 */
@interface DSBLESleepState : NSObject
@property (strong, nonatomic) NSString *startTime;
@property (strong, nonatomic) NSString *endTime;
@property (assign, nonatomic) NSInteger state;

@end

/**
 * 运动数据
 * sport info class
 */
@interface DSBLESportInfo : NSObject
@property (strong ,nonatomic) NSString *startTime;
@property (strong ,nonatomic) NSString *endTime;
@property (strong ,nonatomic) NSNumber *state;
@property (strong ,nonatomic) NSNumber *distance;
@property (strong ,nonatomic) NSNumber *calorie;
@property (strong ,nonatomic) NSString *livenCode;
@property (strong ,nonatomic) NSNumber *gmode;
@property (strong ,nonatomic) NSNumber *step;
@property (strong ,nonatomic) NSArray *location;
@end


// alarm model

/**
 * 闹钟数据
 * alarm class
 */
@interface DSBLEAlarmModel : NSObject
/** Main switch 主开关*/
@property (nonatomic,assign) BOOL switchStatus;
/** Eg Time: 0800 */
@property (nonatomic,copy  ) NSString *alarmTime;
/** Monday switch 周一开关*/
@property (nonatomic) BOOL mondaySwitch;
/** Tuesday switch 周二开关*/
@property (nonatomic) BOOL tuesdaySwitch;
/** Wednesday swtich 周三开关*/
@property (nonatomic) BOOL wednesdaySwitch;
/** Thursday switch 周四开关*/
@property (nonatomic) BOOL thursdaySwitch;
/** Friday switch 周五开关*/
@property (nonatomic) BOOL fridaySwitch;
/** Saturday switch 周六开关*/
@property (nonatomic) BOOL saturdaySwitch;
/** Sunday switch 周日开关*/
@property (nonatomic) BOOL sundaySwitch;

@end

/**
 * 久坐数据
 * sedentary reminder class
 */
@interface DSBLESedentary : NSObject

@property (assign,nonatomic) NSInteger sedentaryTime;
@property (assign,nonatomic) BOOL swtich;
@property (strong,nonatomic) NSDate *startTime;
@property (strong,nonatomic) NSDate *endTime;

@end


/** phonecall 电话提醒*/
extern NSString * const kDSBLEAppNotifyPhoneCall;
/** message 信息提醒*/
extern NSString * const kDSBLEAppNotifyMessage;
/** wechat 微信提醒*/
extern NSString * const kDSBLEAppNotifyWechat;
/** QQ 扣扣提醒*/
extern NSString * const kDSBLEAppNotifyQQ;
/** Facebook 脸书提醒*/
extern NSString * const kDSBLEAppNotifyFacebook;
/** Twitter 推特提醒*/
extern NSString * const kDSBLEAppNotifyTwitter;
/** Email 邮件提醒*/
extern NSString * const kDSBLEAppNotifyEmail;
/** WhatsApp 提醒*/
extern NSString * const kDSBLEAppNotifyWhatsApp;
/** Instagram 提醒*/
extern NSString * const kDSBLEAppNotifyInstagram;
/** Line 提醒*/
extern NSString * const kDSBLEAppNotifyLine;
/** Skype 提醒*/
extern NSString * const kDSBLEAppNotifySkype;
/** Weibo 提醒*/
extern NSString * const kDSBLEAppNotifyWeibo;


/**
 * ANCS提示设置类
 * ANCS Setting class
 */
@interface DSBLEAppNotify : NSObject
@property (strong,nonatomic) NSDictionary *appNotifyDict;

- (BOOL)appNotifyDictValueWithKey:(NSString *)key;

- (void)setAppNotify:(NSString *)key value:(BOOL)isOn;

- (NSDictionary *)appNotifyDict;

- (BOOL)isOn:(BOOL)isB103;

- (BOOL)isAppOn;

- (NSString *)b103Description;
@end

/**
 *
 * 连接手环时，使用的设备信息类
 * device info class
 */
@interface DSBLEDevice : NSObject
@property (nonatomic, strong) NSString* dtype;

@property (nonatomic, strong) NSString* identifier;

@property (nonatomic, strong) NSString* mac;

@property (nonatomic, strong) NSString* name;

@property (nonatomic, strong) NSString* uid;
@end


/**
 * 绑定手环时使用的设备信息类
 * binding device info class
 */
@interface DSBLEBindingDevice : NSObject
@property (strong,nonatomic) NSUUID *identifier;
@property (strong,nonatomic) NSDictionary *advData;
@property (strong,nonatomic) NSNumber *rssi;
@property (strong,nonatomic) NSString *name;
@property (strong,nonatomic) NSString *mac;
@property (strong,nonatomic) NSNumber *state;
@property (strong,nonatomic) CBPeripheral *peripheral;
@end

/**
 * 睡眠原始数据
 * Sleep original data
 */
@interface DSBLEOriginalSleepInfo : NSObject
@property (strong, nonatomic) NSString *startTime;
@property (strong, nonatomic) NSString *endTime;
@property (strong, nonatomic) NSArray *stateCode;
@property (assign, nonatomic) NSInteger stateNum;
@property (assign, nonatomic) NSInteger stateCyc;
@property (strong, nonatomic) NSDate *startDate;
@property (strong, nonatomic) NSDate *endDate;

#pragma Algorithm auxiliary params 算法辅助参数
@property (assign, nonatomic) BOOL isValid;
@property (assign, nonatomic) NSInteger staticTime;
@property (strong, nonatomic) NSArray *sleepInterval;
@end

