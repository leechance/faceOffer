//
//  ViewController.m
//  LYFTestAli
//
//  Created by chancelee on 2018/8/13.
//  Copyright © 2018年 chancelee. All rights reserved.
//

#import "ViewController.h"
#import "LYFScrollView.h"
#import "UIView+Frame.h"
#import "LYFNavigationView.h"

@interface ViewController ()

/// 背景的UIScrollView
@property (nonatomic, strong) LYFScrollView *scrollView;
/// navigation视图
@property (nonatomic, strong) LYFNavigationView *navigationView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //空对象
    NSNull*null=  [NSNull null];
    [ViewController class];
    
    //Nil类对象的书面空值
    Class someClass = Nil;
    int a= someClass;
    
    Class anotherClass = [NSString class];
    
    NSString*s1=@"hello world";
    NSString*s2=@"hello world";
    NSString*s3=[NSString stringWithFormat:@"hello world"];
    NSString*s4=[[NSString alloc]initWithString:@"hello world"];

    
    int x=3;
    printf("%d",x++ + ++x);//8
    printf("x=%d",x);     //5

   NSNumber*num= [[NSNumber alloc]initWithInt:x];
  
    
    //
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.navigationController.navigationBar.barTintColor = [UIColor colorWithRed:52.0 / 255.0 green:104.0 / 255.0 blue:206.0 / 255.0 alpha:1];
    self.navigationController.navigationBar.translucent = NO;
    [self.navigationController.navigationBar setBackgroundImage:nil forBarPosition:UIBarPositionAny barMetrics:UIBarMetricsDefault];
    [self.navigationController.navigationBar setShadowImage:[UIImage new]];
    
    UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithCustomView:self.navigationView];
    
    self.navigationItem.leftBarButtonItem = item;
    
    __weak __typeof(self)weakSelf = self;
    self.scrollView.contentOffsetAction = ^(CGFloat contentOffsetY) {
        weakSelf.navigationView.hidden = contentOffsetY < 50;
        if (contentOffsetY > 100) {
            weakSelf.navigationView.alpha = 1;
        } else if (contentOffsetY > 50) {
            weakSelf.navigationView.alpha = 1 - (100 - contentOffsetY) / 50.f;
        }
    };
}

#pragma mark - Get方法
-(LYFScrollView *)scrollView {
    if (!_scrollView) {
        _scrollView = [[LYFScrollView alloc] initWithFrame:CGRectMake(0, 0, self.view.lyf_width, self.view.lyf_height)];
        
        [self.view addSubview:_scrollView];
    }
    
    return _scrollView;
}

-(LYFNavigationView *)navigationView {
    if (!_navigationView) {
        _navigationView = [[LYFNavigationView alloc] initWithFrame:CGRectMake(0, 0, 120.f, 40.f)];
        _navigationView.hidden = YES;
    }
    
    return _navigationView;
}

@end
