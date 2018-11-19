//
//  TestAnimationViewController.m
//  FaceOffer
//
//  Created by chance on 2018/11/19.
//  Copyright © 2018 chance. All rights reserved.
//

#import "TestAnimationViewController.h"
#import "UIColor+Hex.h"



@interface TestAnimationViewController ()

@end

@implementation TestAnimationViewController
{
    NSMutableArray*dataSourceArray;
    __weak IBOutlet UIImageView *basketBall;
}
//将字符串@“abcdefghijklmn”中的efg 截取出来替换成 gfe
-(void)replaceString{
    NSString*targetSting=@"abcdefghijklmn";
    NSString*destSting=[targetSting stringByReplacingOccurrencesOfString:@"efg" withString:@"gfe"];
    NSLog(@"新字符串：%@",destSting);
}

//写一个取当前日期的方法，输入字符串，格式如下2010-02-19
//格式化日期，其实就是利用一个日期格式化对象把日期转换成字符串了
-(void)testDate{
    
     //先定义一个NSDateFormatter对象，
    // 然后给这个格式对象定义成自己想要的格式，然后用它去转化其他日期即可
    NSDate * nowDate = [NSDate date];
    
    NSDateFormatter *format1=[[NSDateFormatter alloc]init];
    [format1 setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
     NSString *str1=[format1 stringFromDate:nowDate];
    NSLog(@"str==%@",str1);
                                                                                                                                             

}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self replaceString];
    [self testDate];
    
    self.view.backgroundColor=[UIColor colorWithHexString:@"0x12237d"];
    self.view.backgroundColor=colorWithHexStr(@"0x12237d");
}


- (IBAction)touchBtn:(id)sender {
      [UIView beginAnimations:@"movement" context:nil];
      [UIView setAnimationCurve:UIViewAnimationCurveEaseIn]; //<label id="code.timingcurve.easeIn"/>
      [UIView setAnimationDuration:1.0f];
      [UIView setAnimationRepeatCount:3];
      [UIView setAnimationRepeatAutoreverses:YES];
      CGPoint center = basketBall.center;
      if(center.y > 85.0f) {
            center.y -= 295.0f;
            basketBall.center = center;
          } else {
                center.y += 295.0f;
                basketBall.center = center;
              }
      [UIView commitAnimations];

}



/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
