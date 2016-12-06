//
//  DSBLECommandMessage.h
//  vifit
//
//  Created by jayson jiang on 16/3/5.
//  Copyright © 2016年 Jayson Jiang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DSBLECommandMessage : NSObject
@property (nonatomic,strong,nullable) NSString *command;
@property (nonatomic,strong,nullable) NSString *body;
@property (strong,nonatomic,nonnull) NSString *deviceName;

@end
