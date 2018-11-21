//
//  C_Program.c
//  faceOffer
//
//  Created by chance on 2018/11/20.
//  Copyright © 2018 chancelee. All rights reserved.
//

#include "C_Program.h"
#include <string.h>
#include <stdlib.h>

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

int secondMax(int a[],int n){
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

//判断字符串是否回文
bool judgeIsHuiWen(char*s){
    
    //字符串的长度abcabc =5
    int length=strlen(s);
    //注意边界 a[0]~a[length-1]
    //遍历只需要遍历一半就好
    for (int i=0; i<=length/2; i++) {
        if (s[i]!=s[length-1-i]) {
            return false;
            
        }else{
            continue;
        }
    }
    return true;
}
//思路，gggooodd
char* removeSameChar(char*src){
//    int length=(int)strlen(src);
//    char*target=(char*)malloc(length*sizeof(char));
//     char temp=src[0];
//    target[0]=src[0];
//    int count=0;
//    for (int i=1;i<length;i++) {
//       
//        if (src[i]!=src[0]&&src[i]!=temp) {
//            temp=src[i];
//            count++;
//            target[count]=src[i];
//        }
//    }
    
    
    
    return "";
}

void printNumByLocation(int n){
    
    while (n>0) {
        printf("%2d",n%10);
        n/=10;
    }
}
void doubleExist(void){
    // 1,2,3,4,5,6,7,8,9,10,J,Q,K
    // 1,2,3,4,5,6,7,8,9,10,J,Q,K
    // 1,2,3,4,5,6,7,8,9,10,J,Q,K
    // 1,2,3,4,5,6,7,8,9,10,J,Q,K
    int totalcount=0;//总的组合数
    int sameCount=0;//对出现的次数
    
    for (int i=0; i<52; i++) {
        for (int j=i+1; j<52; j++) {
            totalcount++;
        }
    }
    
    
    
    float exist= sameCount/(float)totalcount;
    printf("出现对的概率：%f\n",exist);
    
}
