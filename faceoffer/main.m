//
//  main.m
//  LYFTestAli
//
//  Created by chancelee on 2018/8/13.
//  Copyright © 2018年 chancelee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#include <math.h>


//1.输入字符串中的大写字母转化为小写字母，并返回大写字母的个数
int coutBigChar(char*s){
    char*p=s;
    int count=0;
    while (*p!='\0') {
        count++;
        p++;
    }
    return count;
}
//2.编写一个函数，用来在一个给定的整形数组里面找出第2大的数。
// 1,3,4,2,9,9,6,7,4,
//方式一：排序，从打到小排序，然后依次比较a[0]
//方式二：
/*
 1）假设数组中的前两个元素就是最大和第二大，即max和smax；
 
 2）从数组的第二个元素开始遍历数组，当有元素大于max的时候，将max赋值给smax，再将最大的那个元素赋值给max；
 
 3）如果当前元素小于max，并且大于smax，那么就让smax当前元素。
 */

int seconMax(int a[],int n){
    if (n<=0) {
        return -1;
    }else if (n==1){
        return a[0];
    }else if(n==2){
        return a[0]>a[1]?a[1]:a[0];
    }else{
        int size=n;
        int max = a[0];         //最大值
        int smax = a[1];        //次大值
        for(int i = 0;i < size;i++)
        {
            if(a[i] > max)      //更新最大值和次大值
            {
                smax = max;
                max = a[i];
            }
            else if(a[i] < max && a[i] > smax)  //更新次大值
            {
                smax = a[i];
            }
        }
        
          return smax;
    }
}

//用递归方法判断一个数组是否为递增数组（使用递归时充分考虑递归终止条件，以及函数调用思想）
// 1,3,4,2,9,9,6,7,4

//用递归算法判断数组a[N]是否为一个递增数组。
//递归的方法，记录当前最大的，并且判断当前的是否比这个还大，大则继续，否则返回false结束：
bool judgeIncreaseArray(int a[], int n)
{
    if(n==1)
        return true;
    if( n==2 )
        return a[n-1] >= a[n-2];
    return judgeIncreaseArray( a,n-1) && ( a[n-1] >= a[n-2] );
}
bool judgeIncreaseArray2(int a[], int n)
{
    if(n==1)
        return true;
    return judgeIncreaseArray2(a, n-1)&&(a[n-1]>a[n-2]);
}


int main(int argc, char * argv[]) {
    @autoreleasepool {
        
        int num=  coutBigChar("123abc def ");
        int a[8]={1,2,3,3,34,542,34,253};
        int smax=seconMax(a, 8);
        
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
