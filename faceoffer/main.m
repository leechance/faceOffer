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
    int n;
     scanf("%ld", &n);
    
     scanf("%ld", &n);
    
     scanf("%ld", &n);
    sc u;
    u.s=0x602;
    printf("%d",u.c);
    
    //空字符串
    char*s="";
    printf("s的地址：%p\n",&s);
    printf("s占用的字节数：%d\n",sizeof(s));
    
    char*s1=NULL;
    printf("s1的地址：%p\n",&s1);
    printf("s1占用的字节数：%d",sizeof(s1));
    
    swtichCompare(10,20);
    
    coinQuestion();
    dataWidthForBigNum();
    
    
    
    
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
        
        set_bit3();
        clear_bit3();
        testBuf();
        reverseString("abcDEF");
       
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
