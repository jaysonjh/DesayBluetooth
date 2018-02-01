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

/**
 Time for heart rate
 */
@property (strong, nonatomic) NSString *time;

/**
 Heart rate
 */
@property (assign, nonatomic) NSInteger rate;

/**
 Type
 */
@property (assign, nonatomic) NSInteger type;

/**
 UTC for Date
 */
@property (strong, nonatomic) NSDate *utcTime;
@end

/**
 * 睡眠数据
 * sleep info class
 */
@interface DSBLESleepInfo : NSObject
//@property (strong, nonatomic) NSString *gdate;

/**
 Begin Time, UTC
 */
@property (strong, nonatomic) NSString *beginTime;

/**
 End Time,UTC
 */
@property (strong, nonatomic) NSString *endTime;

/**
 Sleep total duration,Unit:min.
 */
@property (strong, nonatomic) NSNumber *totalDuration;

/**
 Wake up times,@NS_DEPRECATED
 */
@property (strong, nonatomic) NSNumber *wakeTime;

/**
 Sleep quantity,@NS_DEPRECATED
 */
@property (strong, nonatomic) NSNumber *quantity;

/**
 Array for DSBLESleepState
 */
@property (strong, nonatomic) NSArray *sleepStates;

/**
 Array for DSBLEHeartrate @NS_DEPRECATED
 */
@property (strong, nonatomic) NSArray *heartrates;
@end

/**
 * 睡眠状态数据
 * sleep state class
 */
@interface DSBLESleepState : NSObject

/**
 Begin Time, UTC
 */
@property (strong, nonatomic) NSString *startTime;

/**
 End Time,UTC
 */
@property (strong, nonatomic) NSString *endTime;

/**
 state = 0 // awake
 state = 2 // shallow sleep
 state = 3 // deep sleep
 */
@property (assign, nonatomic) NSInteger state;

@end

/**
 * 运动数据
 * sport info class
 */
@interface DSBLESportInfo : NSObject
@property (strong ,nonatomic) NSString *startTime;


/**
 Time for step, UTC
 */
@property (strong ,nonatomic) NSString *endTime;


/**
 state=1 // sit
 state=2 // walk
 state=3 // walk quickly /run
 */
@property (strong ,nonatomic) NSNumber *state;
@property (strong ,nonatomic) NSNumber *distance;
@property (strong ,nonatomic) NSNumber *calorie;
@property (strong ,nonatomic) NSString *livenCode;
@property (strong ,nonatomic) NSNumber *gmode;

/**
 Step
 */
@property (strong ,nonatomic) NSNumber *step;
@property (strong ,nonatomic) NSArray *location;
@end


/**
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

/**
 Sedentary time.
 During this time,bracelet will calculate the steps,if not reach the min steps,bracelet will notify user.
 30=30 Min
 60=60 Min
 75=75 Min
 90=90 Min
 */
@property (assign,nonatomic) NSInteger sedentaryTime;

/**
 Yes for Sedentary reminder ON
 No for Sedentary reminde OFF
 */
@property (assign,nonatomic) BOOL swtich;

/**
 Date time for bracelet start check the Sedentary
 */
@property (strong,nonatomic) NSDate *startTime;

/**
 Date time for bracelet stop check the Sedentary
 */
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

/***以下字段是 印度客户定制***/
//Hike
extern NSString * const kDSBLEAPPNotifyHike;
//Facebook Messenger
extern NSString * const kDSBLEAPPNotifyFBMessenger;
//Gmail
extern NSString * const kDSBLEAPPNotifyGmail;
//Google Hangout
extern NSString * const kDSBLEAPPNotifyGoogleHangout;
//Snapchat
extern NSString * const kDSBLEAPPNotifySnapchat;
//Google Calendar
extern NSString * const kDSBLEAPPNotifyGoogleCalendar;
/***以上字段是 印度客户定制***/


/**
 * ANCS提示设置类
 * ANCS Setting class
 */
@interface DSBLEAppNotify : NSObject


/**
 Dictionary include All reminder setting 
 */
@property (strong,nonatomic) NSDictionary *appNotifyDict;

- (BOOL)appNotifyDictValueWithKey:(NSString *)key;

- (void)setAppNotify:(NSString *)key value:(BOOL)isOn;

- (NSDictionary *)appNotifyDict;

- (BOOL)isOn:(BOOL)isB103;

- (BOOL)isAppOn;
    
- (NSArray *)customerDIYNotifyKeys;

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
 * 睡眠原始数据端，由睡眠块组成
 * Sleep original data
 */
@interface DSBLEOriginalSleepInfo : NSObject

/**
 Begin Time(String), UTC
 */
@property (strong, nonatomic) NSString *startTime;

/**
 End Time(String),UTC
 */
@property (strong, nonatomic) NSString *endTime;

/**
 Array for sleep state.
 */
@property (strong, nonatomic) NSArray *stateCode;

/**
 sleep state count
 */
@property (assign, nonatomic) NSInteger stateNum;

/**
 state interval,10 min.
 */
@property (assign, nonatomic) NSInteger stateCyc;

/**
 Begin Time, UTC
 */
@property (strong, nonatomic) NSDate *startDate;

/**
 End Time,UTC
 */
@property (strong, nonatomic) NSDate *endDate;

#pragma Algorithm auxiliary params 算法辅助参数
@property (assign, nonatomic) BOOL isValid;
@property (assign, nonatomic) NSInteger staticTime;
@property (strong, nonatomic) NSArray *sleepInterval;
@end


/**
 * 睡眠原始数据块
 */
@interface DSBLEOriginalSleepBlock : NSObject

/**
 Time for sleep state.
 */
@property (strong, nonatomic) NSDate *sDate;

/**
 Time for sleep state.String.
 */
@property (strong, nonatomic) NSString *sTime;

/**
 sleep state
 */
@property (strong, nonatomic) NSNumber *value;

/**
 block type
 0 = Begin
 1 = Sleep
 2 = Sleep indeep
 3 = End
 */
@property (strong, nonatomic) NSNumber *blockType;

/**
 sDate timeinterval from 2010.1.1
 */
@property (strong, nonatomic) NSNumber *timeInterval;
@end

