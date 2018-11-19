//
//  LYFScrollView.h
//  LYFTestAli
//
//  Created by chancelee on 2018/8/14.
//  Copyright © 2018年 chancelee. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^LYFScrollViewContentOffsetAction)(CGFloat contentOffsetY);

@interface LYFScrollView : UIScrollView

/// 偏移事件
@property (nonatomic, copy) LYFScrollViewContentOffsetAction contentOffsetAction;

@end
