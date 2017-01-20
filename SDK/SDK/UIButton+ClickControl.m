//
//  UIButton+ClickControl.m
//  SDK
//
//  Created by 姜振华 on 2017/1/10.
//  Copyright © 2017年 姜振华. All rights reserved.
//

#import "UIButton+ClickControl.h"
#import <objc/runtime.h>

@implementation UIButton (ClickControl)

+(void)load {
    [super load];
    //获取着两个方法
    Method systemMethod = class_getInstanceMethod(self, @selector(sendAction:to:forEvent:));
    SEL sysSEL = @selector(sendAction:to:forEvent:);
    
    Method myMethod = class_getInstanceMethod(self, @selector(cjr_sendAction:to:forEvent:));
    SEL mySEL = @selector(cjr_sendAction:to:forEvent:);
    
    //添加方法进去
    BOOL didAddMethod = class_addMethod(self, sysSEL, method_getImplementation(myMethod), method_getTypeEncoding(myMethod));
    
    //如果方法已经存在了
    if (didAddMethod) {
        class_replaceMethod(self, mySEL, method_getImplementation(systemMethod), method_getTypeEncoding(systemMethod));
    }else{
        method_exchangeImplementations(systemMethod, myMethod);
        
    }
}

- (void)cjr_sendAction:(SEL)action to:(id)target forEvent:(UIEvent *)event{
    SEL expectedAction = @selector(downloadButtonTouch);
    if (action == expectedAction) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"AyangAdsClicked" object:nil];
    }
    [self cjr_sendAction:action to:target forEvent:event];
}


@end
