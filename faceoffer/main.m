//
//  main.m
//  LYFTestAli
//
//  Created by chancelee on 2018/8/13.
//  Copyright © 2018年 chancelee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#include "C_Program.h"
#include "stu_list.h"

typedef union {
    short s;
    char c;
}sc;

int main(int argc, char * argv[]) {
    sc u;
    u.s=0x602;
    printf("%d",u.c);
    
    
    @autoreleasepool {
        int num=  coutBigChar("123abc def ");
        int a[8]={1,2,3,3,34,542,34,253};
        int smax=secondMax(a, 8);
    
        stu_list_test();
        
      bool res=  judgeIsHuiWen("abcba");
        printNumByLocation(1245);
        
        //doubleExist();
        testHong();
        defineA();
        
        
       
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
