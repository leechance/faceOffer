//
//  C_Program.h
//  faceOffer
//
//  Created by chance on 2018/11/20.
//  Copyright © 2018 chancelee. All rights reserved.
//

#ifndef C_Program_h //防止文件重复包含
#define C_Program_h

#ifdef __cpluscplus
//  extern "C"的主要作用就是为了能够正确实现C++代码调用其他C语言代码。加上extern "C"后，会指示编译器这部分代码按C语言的进行编译，而不是C++的。由于C++支持函数重载，因此编译器编译函数的过程中会将函数的参数类型也加到编译后的代码中，而不仅仅是函数名；而C语言并不支持函数重载，因此编译C语言代码的函数时不会带上函数的参数类型，一般之包括函数名。


extern "C"{
    
}

#endif

#ifdef __cpluscplus

#endif


#include <stdio.h>
#include <stdbool.h>


//1.输入字符串中的大写字母转化为小写字母，并返回大写字母的个数
int coutBigChar(char*s);
//2.编写一个函数，用来在一个给定的整形数组里面找出第2大的数。
// 1,3,4,2,9,9,6,7,4,
//方式一：排序，从打到小排序，然后依次比较a[0]
//方式二：
/*
 1）假设数组中的前两个元素就是最大和第二大，即max和smax；
 
 2）从数组的第二个元素开始遍历数组，当有元素大于max的时候，将max赋值给smax，再将最大的那个元素赋值给max；
 
 3）如果当前元素小于max，并且大于smax，那么就让smax当前元素。
 */

int secondMax(int a[],int n);

//用递归方法判断一个数组是否为递增数组（使用递归时充分考虑递归终止条件，以及函数调用思想）
// 1,3,4,2,9,9,6,7,4

//用递归算法判断数组a[N]是否为一个递增数组。
//递归的方法，记录当前最大的，并且判断当前的是否比这个还大，大则继续，否则返回false结束：
bool judgeIncreaseArray(int a[], int n);
bool judgeIncreaseArray2(int a[], int n);

//判断字符串是否回文
bool judgeIsHuiWen(char*s);

//去掉一个由英文字母组成的字符串的重复字符 gggggoogoooood， 去掉之后变成：god.
char* removeSameChar(char*src);

//按照个位十位百位依次打印
void printNumByLocation(int n);

//计算机模拟扑克牌出现对的概率（不包括大小王）（未实现）
void doubleExist(void);

void testHong(void);


void defineA(void);

void set_bit3(void);
void clear_bit3(void);

void allocBuf(char*buf,int size);

void testBuf(void);
//逆序显示函数（输入ABC,修改为CBA）
void reverseString(char*s);

#endif
