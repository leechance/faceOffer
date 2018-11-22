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

#define MIN(A,B) ((A)>(B)?(B):(A)) //福西软件


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


void testHong(void){
   int min= MIN(100, 200);
    
    
    //福西软件
    int a[3] = {9,10,11};
    int b = 10;
    int *p = a;
    
    //int ret = MIN(*p++, b); 等同于
    int ret   =(*p++)>b?b:(*p++);
    //分析 *p++=9，b=10,所以 int ret= *p++ 此时*p++=10
    //所以 int ret=10,由于 *p++出现了2次，所以在赋值给ret之后 *p=11
    
}

void defineA(void){
//  a）一个整型数
    int a=10;
    //a的数据类型为 int
    printf("a地址 =%p\n",&a);//0x7ffee8f0cedc
    printf("a =%d\n",a);
    
    
//  b）一个指向整型数的指针
    int *b=&a;
    // b= int * 0x7ffee8f0cedc    0x00007ffee8f0cedc
    // b的数据类型 int *
    printf("*b =%d\n",*b);

    
//  c）一个指向指针的指针，它指向的指针式指向一个整型数
    int **c=&b;
    // c = (int **)0x00007ffeedaa4ed0
    // c数据类型就是 int **
    //       *c= (int *)0x00007ffeedaa4edc
    printf("*cc =%d\n",**c);
    
//    d）一个有10个整型数的数组
    int d[10]={1,2,3,4,5,6,7,8,9,0};
    //d  数据类型是 int [10]
    // (lldb) p d
    //(int [10]) $1 = ([0] = 1, [1] = 2, [2] = 3, [3] = 4, [4] = 5, [5] = 6, [6] = 7, [7] = 8, [8] = 9, [9] = 0)

//    e）一个有10个指针的数组，该指针式指向一个整型数的
    int *e[10];
    // e的数据类型 是 int *[10]
    // (lldb) p e
//    (int *[10]) $0 = {
//        [0] = 0x0000000000000000
//        [1] = 0x00000000000130a8
//        [2] = 0x0000000000000015
//        [3] = 0x0000000000000000
//        [4] = 0x02e8042e4032003b
//        [5] = 0x0000000000000000
//        [6] = 0x0000003000000010
//        [7] = 0x00007ffee4fa1f50
//        [8] = 0x00007ffee4fa1e60
//        [9] = 0x02e8042e4032003b
//    }
//    (lldb) p e[0]
//    (int *) $1 = 0x0000000000000000
//    (lldb) p e[1]
//    (int *) $2 = 0x00000000000130a8
    
//    f）一个指向有10个整型数数组的指针
    int (*f)[10];
//    (lldb)p f
//    (int (*)[10]) $0 = 0x00007ffee3969e00;
//    lldb) p f[1]
//    (int [10]) $1 = ([0] = 204096240, [1] = 1, [2] = 260690344, [3] = 1, [4] = 0, [5] = 0, [6] = 204145743, [7] = 1, [8] = 0, [9] = 0)
//    (lldb) p f[1][1]
//    (int) $2 = 1
//
    
//    g）一个指向函数的指针，该函数有一个整型参数，并返回一个整型数
    int (*func)(int);
    
    //(lldb) p func
    //(int (*)(int)) $0 = 0x000000010f1b6e04 (faceOffer`ListPrint + 68 at stu_list.c:101)
    
    
//    h）一个有10个指针的数组，该数组里指针指向一个函数，该函数有一个整型参数并返回一个整型数
    int (*funcg[10])(int);
    /*
     (lldb) p funcg
     (int (*[10])(int)) $2 = {
     [0] = 0x00007ffee8fb0dd0 (0x00007ffee8fb0dd0)
     [1] = 0xe6619d4a5a4c0066 (0xe6619d4a5a4c0066)
     [2] = 0x0000000000000000
     [3] = 0x0000000000000000
     [4] = 0x00007ffee8fb0ee0 (0x00007ffee8fb0ee0)
     [5] = 0x0000000106c5ce04 (faceOffer`ListPrint + 68 at stu_list.c:101)
     [6] = 0x00007ffee8fb0e00 (0x00007ffee8fb0e00)
     [7] = 0x000000155a4c0066 (0x000000155a4c0066)
     [8] = 0x0000000000000000
     [9] = 0x0000600001038340 (0x0000600001038340)
     }
     (lldb) p funcg[0]
     (int (*)(int)) $3 = 0x00007ffee8fb0dd0 (0x00007ffee8fb0dd0)
     */

}

//给定一个整型变量a，写两段代码，第一个设置a的bit3，第二个清除a的bit3，以上两个操作中，要保持其它位不变。
// C语言位运算及其用法（https://blog.csdn.net/wx2306/article/details/79346694）
#define BIT3 (0x1 << 3)
static int a=100000;
void set_bit3(void)
{
    a |= BIT3;
    
}
void clear_bit3(void)
{
    a &= ~BIT3;
    
    
}



//指出代码的重大错误并改正
void allocBuf(char*buf,int size){
    //字符串不能用malloc申请空间
    memset(buf, '\0', size*sizeof(char));
    
}
void testBuf(void){
    char buf[5];
    int i,count;
    allocBuf(buf, 5);
    for (i=0; i<4; i++)
        buf[i]=96+rand()%10;
    for (i=0; i<5; i++) {
        printf("%d-%c\n",i+1,buf[i]);
    }
    printf("%s\n",buf);
}

#define MAX_LEN 1024
void reverseString(char*str){
    int n=strlen(str);
    int i;
    char temp;
    
    for(i=0;i<(n/2);i++){
        temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
        
    }
 
    
}
