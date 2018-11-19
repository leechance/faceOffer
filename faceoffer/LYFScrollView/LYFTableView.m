//
//  LYFTableView.m
//  LYFTestAli
//
//  Created by chancelee on 2018/8/14.
//  Copyright © 2018年 chancelee. All rights reserved.
//

#import "LYFTableView.h"
#import "UIView+Frame.h"
#import "TestAnimationViewController.h"


#define kRowHeight 50.f

@interface LYFTableView() <UITableViewDataSource, UITableViewDelegate>

@end

static NSString *tableViewCell = @"UITableViewCell";

@implementation LYFTableView
{
    NSMutableArray*dataSourceArray;
}

-(instancetype)initWithFrame:(CGRect)frame style:(UITableViewStyle)style {
    if (self = [super initWithFrame:frame style:style]) {
        self.dataSource = self;
        self.delegate = self;
        
        dataSourceArray=[[NSMutableArray alloc]initWithArray:@[@"实现一个view从顶部移到底部的动画",@"测多岁的老是；发"]];
    }
    
    return self;
}

#pragma mark - Set方法
-(void)setRowNumber:(NSInteger)rowNumber {
    _rowNumber = rowNumber;
    
    // 重置高度为：行数（rowNumber） *  行高（kRowHeight）
    self.lyf_height = rowNumber * kRowHeight;
    
    [self reloadData];
}

#pragma mark - UITableViewDataSource
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return dataSourceArray.count;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:tableViewCell];
    
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:tableViewCell];
    }
    
    cell.textLabel.text = dataSourceArray[indexPath.row];
    
    return cell;
}

#pragma mark - UITableViewDelegate
-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return kRowHeight;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    TestAnimationViewController*testAnimationVC=[[TestAnimationViewController alloc]init];
    
  
    UINavigationController*nav=[UIApplication sharedApplication].delegate.window.rootViewController;
    [nav pushViewController:testAnimationVC animated:YES];
}

-(void)scrollViewDidScroll:(UIScrollView *)scrollView {
    if (self.contentOffsetAction) {
        self.contentOffsetAction(scrollView.contentOffset.y);
    }
}

#pragma mark - 超出的部分可以点击
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event
{
    for (UIView *subview in [self.subviews reverseObjectEnumerator]) {
        
        CGPoint convertedPoint = [subview convertPoint:point fromView:self];
        UIView *hitTestView = [subview hitTest:convertedPoint withEvent:event];
        if (hitTestView) {
            return hitTestView;
        }
    }
    return [super hitTest:point withEvent:event];
}

@end
