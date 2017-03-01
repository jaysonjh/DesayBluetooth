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


/**
 @brief Callback block,return the value of bracelet.

 @param dataString value
 @param error If there is no error, here is nil.
 */
typedef void (^DSBLECentralAPIDataCallback)(NSString *_Nullable dataString, NSError *_Nullable error);

@interface DSBLENormalCommandSendHandler : NSObject

/**
 * @brief Sending check verison command and get value of version in the callback block.
 *
 * @param callback  dataString:[Type: NSString;Error status: "ERR";Normal status: version (string);Format: xxx.xxx.xxx;Example:     @”100.001.026”],Err:[If there is no error, here is nil.]
 * @discussion dataString Format:xxx.xxx.xxx,the first xxx is for user version.The second xxx is for internal version,this can use for check device upgrade or not.The third xxx is for vendor code.
 *
 */
- (void)sendVERCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending reset bracelet command and do some job in the callback block.

 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";]Err:[If there is no error, here is nil.]
 */
- (void)sendRESETCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending User binding command and do some job in the callback block.
 Thie function is one of bind procedure,it is used together with sendACTCallback.

 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";]Err:[If there is no error, here is nil.]
 @warning You can use [DSBLEBindingHandler startBondDevice:] instead of this function. [DSBLEBindingHandler startBondDevice:] incude all bind procedure and support all delegate for binding.)
 @see DSBLEBindingHandler
 */
- (void)sendUSERBONDCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending active bracelet command and do some job in the callback block.
 
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";]Err:[If there is no error, here is nil.]
 @warning You can use [DSBLEBindingHandler startBondDevice:] instead of this function. [DSBLEBindingHandler startBondDevice:] incude all bind procedure and support all delegate for binding.)
 @see DSBLEBindingHandler
 */
- (void)sendACTCallback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending height and weight to bracelet and do some job in the callback block.

 @param height User’s height(100-250),unit cm.
 @param weight User’s weight(25-200),unit kg.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: user info (string);Format:name,height,weight;Example: @"test,173,74"] Err:[If there is no error, here is nil.]
 @discussion dataString Format:xxx,xxx,xxx The first xxx is use for userName,this is not ready to open to API.So default set by API.The seconde xxx is height.The third xxx is weight.
 */
- (void)sendUSERINFO:(nonnull NSNumber*)height weight:(nonnull NSNumber *)weight Callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending get SN command and do some job in the callback block with this value.

 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: sn info (string);Example: @"1234567890"] Err:[If there is no error, here is nil.]
 */
- (void)sendGETSNCallback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending get remaining power command and do some job in the callback block with this value.

 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: power (string);Example: "90"] Err:[If there is no error, here is nil.]
 @discussion Power of Bracelet,the value is string, so you need to change the type to int.Example:"90",is mean 90% power left.
 */
- (void)sendGETPOWERCallback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending save steps command and do some job in the callback block with this value.

 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]
 @warning This function will ask bracelet save step immediately
 */
- (void)sendSTEPSTOCallback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending switch status of the live UPLOADSTEPS and do some job in the callback block.

 @param open YES = Open/NO = Close
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]
 @warning You need to send close up step command for normal operation.
 @discussion After invoke this function, it can get step notify in DSBLEAutoCommandReceiveHandler-receiveUPSTEPDataCallback.The receiveUPSTEPDataCallback must setting before use it.
 @see DSBLEAutoCommandReceiveHandler
 */
- (void)sendUPSTEPOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending app’s language type to bracelet and do some job in the callback block.

 @param type language type,EN= 0,CHS= 1,FR = 2,IT = 3,ES = 4,TR = 5,PL = 6,JP = 7,
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: type value;] Err:[If there is no error, here is nil.]
 */
- (void)sendLANSET:(BLELanguageType)type callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending step target to bracelet and do some job in the callback block.

 @param stepCount User’s step target(1000steps – 25000steps)
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: stepCount value;] Err:[If there is no error, here is nil.]
 @warning The dataString value. If there is an error, here is @”ERR”.Normally,the value is string, so you need to change the type to int
 */
- (void)sendDESTSET:(nonnull NSNumber *)stepCount callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending alarm1 to bracelet and do some job in the callback block.

 @param alarm DSBLEAlarmModel represents Alarm setting.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: alarm value(string);] Err:[If there is no error, here is nil.]
 @discussion Alarm1’s string. Eg:0,1,30,0730,0111110.The form is index(1 bit, 0 for alarm 1 and 1 for alrm2) +comma(1 bit) + switch(1 bit, 0 for off and 1 for on) +comma(1bit ) + smart wakeup time(2 bit, in minutes) +comma(1 bit)+ alarmtime(4bit, first two for hour and last for minute) + repeartday(7bit, first bit for Sunday, last bit for Saturday, others for weekday in sequence. 0 for off and 1 for on).
 */
- (void)sendALARM1:(nonnull DSBLEAlarmModel *)alarm callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending alarm2 to bracelet and do some job in the callback block.
 
 @param alarm DSBLEAlarmModel represents Alarm setting.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: alarm value(string);] Err:[If there is no error, here is nil.]
 @discussion Alarm2’s string. Eg:0,1,30,0730,0111110.The form is index(1 bit, 0 for alarm 1 and 1 for alrm2) +comma(1 bit) + switch(1 bit, 0 for off and 1 for on) +comma(1bit ) + smart wakeup time(2 bit, in minutes) +comma(1 bit)+ alarmtime(4bit, first two for hour and last for minute) + repeartday(7bit, first bit for Sunday, last bit for Saturday, others for weekday in sequence. 0 for off and 1 for on).
 */
- (void)sendALARM2:(nonnull DSBLEAlarmModel *)alarm callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending type of wear habit to bracelet and do some job in the callback block.
 
 @param wearHabit Which hand to wear,0 for off, 2 for left hand and 3 for right hand.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: wearHabit value;] Err:[If there is no error, here is nil.]
 */
- (void)sendHANDSUPSET:(nonnull NSNumber *)wearHabit callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending type of wear habit to bracelet and do some job in the callback block.
 
 @param wearHabit Which hand to wear,0 for off, 2 for left hand and 3 for right hand.
 @param startTime  start time.       eg.  8:00 ~ 19:00, you must send 0800.
 @param endTime   end  time.         eg.  8:00 ~ 19:00, you must send 1900.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: wearHabit value;] Err:[If there is no error, here is nil.]
 */
- (void)sendHANDSUPSET:(NSInteger )wearHabit startTime:(nonnull NSString *)startTime endTime:(nonnull NSString *)endTime callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending duration of sedentary and do some job in the callback block.

 @param sedentary DSBLESedentary represents sedentary setting.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: DSBLESedentary value(string);] Err:[If there is no error, here is nil.]
 @discussion DSBLESedentary value(string),Eg:"030,0900,1800,0",030 for interval,030 for starttime,030 for endtime,0 for on/off.
 */
- (void)sendSETSIT:(nonnull DSBLESedentary *)sedentary callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending find bracelet command and do some job in the callback block.Bracelet will vibrate.

 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]

 */
- (void)sendFINDBANDCallback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending upgrade command and do some job in the callback block.
 
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]
 
 @warning This function will let the bracelet change to DFU/OTA Mode.After call this function,Must use Chipset upgrade code to finished the next.
 */
- (void)sendUPGBCallback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending check timezone command and do some job in the callback block.Bracelet will return the timezone which set before.

 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: eg.”02800”;] Err:[If there is no error, here is nil.]
 
 @discussion dataString value,The value of timezone. eg. NSTimeInterval timezoneInterval = [[NSTimeZone systemTimeZone] secondsFromGMT];This timezone use for calculate the real time from API return sync data.

 */
- (void)sendTIMEZONECallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending timezone and do some job in the callback block. Bracelet will return the timezone which is sended.

 @param timezoneInterval Value of timezone. eg. NSTimeInterval timezoneInterval = [[NSTimeZone systemTimeZone] secondsFromGMT];
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: eg.”02800”;] Err:[If there is no error, here is nil.]

 */
- (void)sendTIMEZONESet:(NSTimeInterval )timezoneInterval callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending time and do some job in the callback block.

 @param timeString eg. NSDateFormatter *time = [NSDate ble_shareDateFormatter:@"yyyyMMddHHmmss"];
 NSString *timeString = [time stringFromDate:[NSDate date]];
 
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: eg.”20161212090909”;] Err:[If there is no error, here is nil.]

 @discussion timeString value,format:"yyyyMMddHHmmss"
 */
- (void)sendTIMESet:(nonnull NSString * )timeString callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending open heart rate command and do some job in the callback block.

 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]

 @warning You need to send close heart rate command for normal operation. The new API,callback will not return the heart rate value.Use [DSBLEAutoCommandReceiveHandler setReceiveHEARTRATEDataCallback:] to get heart rate value.
 @see DSBLEAutoCommandReceiveHandler
 */
- (void)sendOpenHEARTRATECallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending close heart rate command and do some job in the callback block.
 
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]
 */
- (void)sendCloseHEARTRATECallback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending the setting of ANCS and do some job in the callback block.

 @param appNotify DSBLEAppNotify represents reminder setting.About phone call,sms and app reminder.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "0411" setting value;] Err:[If there is no error, here is nil.]
 
 @discussion dataString value,16H(String).Example:@”0411”,CallOn = 0x0001,MessageOn = 0x0002,QQOn = 0x0004,WechatOn = 0x0008,FacebookOn = 0x0010,TwitterOn = 0x0020,WhatsAppOn = 0x0040,InstagramOn = 0x0080,EmailOn = 0x0100,LineOn = 0x0200,SkypeOn = 0x0400;
 */
- (void)sendANCSSET:(nonnull DSBLEAppNotify *)appNotify callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending switch status of syncShow and do some job in the callback block.

 @param show YES display the icon of the function sync in the band. NO close the view of the function sync in the band.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]
 
 @warning You need to send sendSYNCSHOW:NO after sync finished.
 */
- (void)sendSYNCSHOW:(BOOL)show callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending switch status of remote control camera and do some job in the callback block.

 @param open Swich status,YES display the view of the function remote control camera in the bracelet. NO close the view of the function remote control camera in the bracelet.

 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]
 @warning You need to send sendREMOTECAMERAOpen:NO after exit the remote camera.
 */
- (void)sendREMOTECAMERAOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending switch status of find-phone and do some job in the callback block.

 @param open Swich status,YES display the view of the function find-phone in the bracelet. NO close the view of the function find-phone in the bracelet.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]

 */
- (void)sendFINDPHONESETOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending switch status of the music-control and do some job in the callback block.

 @param open Swich status,YES display the controller view of the music in the bracelet. NO close the controller view of the music in the bracelet.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]
 
 */
- (void)sendMUSICCRLSETOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending switch status of unit and do some job in the callback block.

 @param open Swich status,unit setting in the bracelet,YES->km  NO-> mile.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: open value;] Err:[If there is no error, here is nil.]
 */
- (void)sendUNITSETOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending switch status of anti-lost and do some job in the callback block.

 @param open Swich status,YES —> Turn on anti-lost.NO —> Turn  off anti-lost.

 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]
 */
- (void)sendANTILOSTSETOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending switch status of Heart rate monitor and do some job in the callback block.

 @param open Swich status,YES display the controller of the HR monitor in the bracelet. NO close the controller of the HR monitor in the bracelet.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]
 */
- (void)sendHRMONITORSETOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending switch status of Music status and do some job in the callback block.

 @param open Swich status,YES display the icon of play music in the bracelet. NO display the icon of Pause music in the bracelet.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "OK";] Err:[If there is no error, here is nil.]
 */
- (void)sendMUSICPLYOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief Sending switch status of 24 hourSystem and do some job in the callback block.

 @param open Swich status,YES 24 hourSystem. NO 12 hourSystem.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "0";] Err:[If there is no error, here is nil.]
 
 @discussion The return value,when send YES to 24 hourSystem,value = 1,send NO to 12 hourSystem,value = 0.
 */
- (void)send24HoursTIMEFORMATOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending switch status of sport mode and do some job in the callback block.

 @param open Swich status,YES open sport mode. NO close sport mode.
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: "0";] Err:[If there is no error, here is nil.]
 
 @discussion The return value,when send YES to open sport mode ,value = 1,send NO to close sport mode,value = 1.
 */
- (void)sendSPERUNOpen:(BOOL)open callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 * 查询步数/回写步数，当步数参数step=0为查询步数，当不为0为回写步数
 * get step / write back step
 * @param step 回写的步数 write-back step
 */


/**
 @brief Sending pace and do some job in the callback block.

 @param step If step = @(0),mean get step from bracelet. Step != 0,mean set step to bracelet.Range (0~99999)
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: step from bracelet;] Err:[If there is no error, here is nil.]
 */
- (void)sendPACE:(nonnull NSNumber *)step callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending alarm1 to bracelet and do some job in the callback block.
 
 @param alarmString Alarm1’s string. Eg:0,1,30,0730,0111110.The form is index(1 bit, 0 for alarm 1 and 1 for alrm2) +comma(1 bit) + switch(1 bit, 0 for off and 1 for on) +comma(1bit ) + smart wakeup time(2 bit, in minutes) +comma(1 bit)+ alarmtime(4bit, first two for hour and last for minute) + repeartday(7bit, first bit for Sunday, last bit for Saturday, others for weekday in sequence. 0 for off and 1 for on).

 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: alarm value(string);] Err:[If there is no error, here is nil.]
 */
- (void)sendALARM1String:(nonnull NSString *)alarmString callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief Sending alarm2 to bracelet and do some job in the callback block.
 
 @param alarmString Alarm2’s string. Eg:0,1,30,0730,0111110.The form is index(1 bit, 0 for alarm 1 and 1 for alrm2) +comma(1 bit) + switch(1 bit, 0 for off and 1 for on) +comma(1bit ) + smart wakeup time(2 bit, in minutes) +comma(1 bit)+ alarmtime(4bit, first two for hour and last for minute) + repeartday(7bit, first bit for Sunday, last bit for Saturday, others for weekday in sequence. 0 for off and 1 for on).
 
 @param callback dataString:[Type: NSString;Error status: "ERR";Normal status: alarm value(string);] Err:[If there is no error, here is nil.]
 */
- (void)sendALARM2String:(nonnull NSString *)alarmString callback:(nonnull DSBLECentralAPIDataCallback)callback;


/**
 @brief for Lenovo, open no sleep .
 @param totleTime   open no sleep totle time. eg: "030", it‘s mean I Open no sleep 30min .
 */
- (void)openNoSleep:(nonnull NSString *)totleTime callback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief for Lenovo, close no sleep.
 */
- (void)closeNoSleepCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief for Lenovo, query No Sleep Time
 */
- (void)queryNoSleepTimeCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief for Lenovo, set Static Heart Rate
 @param heartRate   eg: 075 表示设置静态心率提醒值：75；参数为固定3十进制数。
 */
- (void)setStaticHeartRate:(nonnull NSString *)heartRate callback:(nonnull DSBLECentralAPIDataCallback)callback;
/**
 @brief for Lenovo, query Static Heart Rate */
- (void)queryStaticHeartRateCallback:(nonnull DSBLECentralAPIDataCallback)callback;
/**
 @brief for Lenovo, close Static Heart Rate
 */
- (void)closeStaticHeartRateCallback:(nonnull DSBLECentralAPIDataCallback)callback;

/**
 @brief for Lenovo, set dynamic Heart Rate
 @param heartRate   eg: 075 表示设置动态心率提醒值：75；参数为固定3十进制数。
 */
- (void)setDynamicHeartRate:(nonnull NSString *)heartRate callback:(nonnull DSBLECentralAPIDataCallback)callback;
/**
 @brief for Lenovo, query dynamic Heart Rate */
- (void)queryDynamicHeartRateCallback:(nonnull DSBLECentralAPIDataCallback)callback;
/**
 @brief for Lenovo, close dynamic Heart Rate
 */
- (void)closeDynamicHeartRateCallback:(nonnull DSBLECentralAPIDataCallback)callback;

@end
