//
//  ViewController.m
//  Demo
//
//  Created by 姜振华 on 2016/12/26.
//  Copyright © 2016年 姜振华. All rights reserved.
//

#import "ViewController.h"
#import <SDK/SDK.h>

@interface ViewController ()
<
SXRewardVideoAdDelegate
>

@property(nonatomic,strong)SXVideoAd* sharedAd;
@property (weak, nonatomic) IBOutlet UIButton *ayang;
@property (weak, nonatomic) IBOutlet UITextView *console;
@property (nonatomic,strong)NSMutableAttributedString* consoleText;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //先禁用播放按钮
    self.ayang.enabled = NO;
    self.sharedAd = [SXVideoAd sharedInstance];
    [self.sharedAd setDelegate:self];
    // Do any additional setup after loading the view, typically from a nib.
    NSDictionary* Attributes = @{NSFontAttributeName:[UIFont fontWithName:@"Helvetica Neue" size:17],NSForegroundColorAttributeName:[UIColor greenColor]};
    self.consoleText = [[NSMutableAttributedString alloc]initWithString:@"初始化中....." attributes:Attributes];
}

-(BOOL)shouldAutorotate {
    return NO;
}

- (IBAction)playayang:(UIButton *)sender {
    if (![self.sharedAd isReady]) {
        [self createAttributeStringWithText:@"缓存失败" textColor:[UIColor redColor]];
    }
    [self.sharedAd displayAd:self];
}

-(void)createAttributeStringWithText:(NSString*)text textColor:(UIColor*)color {
    NSDictionary* Attributes = @{NSFontAttributeName:[UIFont fontWithName:@"Helvetica Neue" size:17],NSForegroundColorAttributeName:color};
    NSString* t = [@"\n" stringByAppendingString:text];
    NSAttributedString* reminder = [[NSAttributedString alloc]initWithString:t attributes:Attributes];
    [self.consoleText appendAttributedString:reminder];
    self.console.attributedText = self.consoleText;
    NSRange range = NSMakeRange(self.consoleText.length - 20, self.consoleText.length);
    [self.console scrollRangeToVisible:range];
}

#pragma mark SDK Delegate
-(void)adInitComplete:(BOOL)isFinished {
    self.ayang.enabled = isFinished;
    [self createAttributeStringWithText:@"广告缓存就绪" textColor:[UIColor greenColor]];
}

-(void)adWillDisplayed {
    [self createAttributeStringWithText:@"广告即将播放！" textColor:[UIColor yellowColor]];
}

-(void)adWillClosed:(SXAdClosedStatus)status duration:(NSTimeInterval)duration isUserClickTheLink:(BOOL)isclicked{
    NSString* t = [NSString stringWithFormat:@"广告播放完毕！\n停留时间:%.2fs \n是否点击广告: %@", duration, isclicked?@"是":@"否"];
    [self createAttributeStringWithText:t textColor:[UIColor greenColor]];
}

-(void)adDidError:(NSError *)error withMessage:(NSString *)message {
    NSString* t = [NSString stringWithFormat:@"播放出错！\n错误代码:%li \n描述信息: %@", (long)error.code, message];
    [self createAttributeStringWithText:t textColor:[UIColor redColor]];
}

@end
