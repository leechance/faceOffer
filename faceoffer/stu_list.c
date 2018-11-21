//
//  stu_list.c
//  faceOffer
//
//  Created by chance on 2018/11/20.
//  Copyright © 2018 chancelee. All rights reserved.
//

#include "stu_list.h"
#include <stdlib.h>
#include <time.h>

STU* ListCreate (void){
    
    STU_LIST head= malloc(sizeof(STU));
    if (head==NULL) {
        printf("头结点申请空间失败！");
        return NULL;
    }
    head->next=NULL;
    return head;
}

//插入节点
/*
    int a=100;
    int *p=NULL;
    p=&a;
    为什么P指向NULL还能赋值,但是变量P还是存在栈空间的，P之前什么也不指，现在指向了a的地址
 
   STU_LIST p;
   如果 p是空，P是能够赋值新值的，但是，p->next会报错，这一点尤其注意，也就是对于空地址的取值，
   回报空指针的错误
 
 
 
 */
STU *ListInsert(STU *head, STU *new){
    
  //工作指针,总是利用头结点找到最后一个节点
   STU_LIST p =head;
    while (p->next!=NULL) {
        p=p->next;
    }
    
    
    if (head==NULL) {
        printf("头结点申请空间失败！");
        return NULL;
    }else{
        
        if (new==NULL) {
            printf("新节点申请空间失败！");
            return NULL;
        }else{
            new->next=NULL;
            p->next=new;
        }
        
        return new;
    }
    
}

//对于节点的idnum,和成绩取随机值
STU *ListInsert2(STU *head){
    
    //那是因为rand()生成的是伪随机数，需要种子来产生不同的随机数。
    // 如果在预编译时声明#include<time>,则可用生成种子的函数 srand((unsigned)time(NULL)) ，因为时间值可以看成是一个随机的量（即每一时刻都不同），所以就生成了变化的伪随机数
    srand((unsigned)time(NULL));
    
    if (head==NULL) {
        printf("头结点申请空间失败！");
        return NULL;
    }else{
       STU* new= malloc(sizeof(STU));
        if (new==NULL) {
            printf("节点申请空间失败！");
            return NULL;
        }
        
        new->idnum=rand()%1000+1000;
        //随机生成一个0~100的浮点数
        new->score=rand() /(double)(RAND_MAX/100);
        new->next=NULL;
        
        head->next=new;
        
        return new;
    }
    
}


void ListPrint(STU *head ){
    //指向第一个节点
    STU_LIST p =head->next;
    while (p!=NULL) {
        printf("学生id:\t%d\t%f\n",p->idnum,p->score);
        
        p=p->next;
    }
}


//1004 1006 1001 1009
//索引从1开始
STU* getNode(STU*head,int index ){
    STU_LIST p =head;
    int count=1;
    if (index==1) {
        //返回第一个节点
        return p->next;
    }else{
        while (p->next!=NULL) {
          
            if(index==count){
                return p;
            }
            index++;
            p=p->next;
        }
    }
    return p;
   
}

//获取链表长度
int getLength(STU *head){
    int count=0;
    STU_LIST p=head;
    while (p->next!=NULL) {
        count++;
        p=p->next;
    }
    
    return count;
}
//交换节点数据
void swap(STU* stu1,STU*stu2){
    int tempId=stu1->idnum;
    stu1->idnum=stu2->idnum;
    stu2->idnum=tempId;
    
    int tempScore=stu1->score;
    stu1->score=stu2->score;
    stu2->score=tempScore;
    
}

//链表的排序的关键是之前的节点
//1004 1006 1001 1009
//本质上讲，链表的排序与数组的排序在算法上有很多相通的地方，但是由于单向链表只能向后访问的特殊性，那些要求随机访问的排序算法在链表的排序上并不能施展手脚，所以只能采用相邻比较的排序方法：冒泡法，而且只能从前向后冒泡。链表的另一个问题是由于长度不是已知的，所以终止条件只能通过节点是否为空进行判断，而每次的循环次数也是如此。下面是两种排序方法，一种求出长度再排序，另一种直接进行排序
//参考链接 https://www.cnblogs.com/torresliang/p/4798099.html

void ListSort(STU *head){
    
    int n= getLength(head);
    if (n > 1) {// 至少两个节点才能排序；
        for (int i = 0; i < n; i++) {
            STU *temp = head;
            for (int j = 0; j < n - i - 1; j++) {// 相邻比较，前者小则互换值。（升序排列）
                if (temp->idnum>temp->next->idnum) {
                    swap(temp, temp->next);
                }
                temp = temp->next;// 指针右移
            }
        }
    }

    
}
//（已经是升序的情况下）逆序
// 1,2,3,4,5
STU* reverse(STU *head){


    STU*  reversed = NULL;
    STU*  current = head;
    STU*  temp = NULL;
    while(current != NULL){
        temp = current;
        current = current->next;
        temp->next = reversed;
        reversed = temp;
    }
    head = reversed;
    
    //重新生成一个Head
    STU* preHead=malloc(sizeof(STU));
    preHead->next=head;
    
    return preHead;

}

void del(STU *head, int id){
    STU_LIST p=head;
    int count=0;
    while (p->next!=NULL) {
        
        if (p->idnum==id) {
            STU*pre_stu=getNode(head, count-1);
            pre_stu->next=p->next;
            free(p);
            break;
        }
        count++;
        p=p->next;
    }
}



void stu_list_test(void){
    //生成头结点
    STU*head=ListCreate();
    
    STU*new1=malloc(sizeof(STU));
    new1->idnum=1004;
    new1->score=65;
    ListInsert(head, new1);
    
    STU*new2=malloc(sizeof(STU));
    new2->idnum=1006;
    new2->score=72;
    ListInsert(head, new2);
    
    STU*new3=malloc(sizeof(STU));
    new3->idnum=1001;
    new3->score=99;
    
    ListInsert(head, new3);
    
    STU*new4=malloc(sizeof(STU));
    new4->idnum=1009;
    new4->score=43;
    ListInsert(head, new4);
    ListPrint(head);
    
   STU* s1= getNode(head, 1);
    
    //排序
    ListSort(head);
    printf("排序后：\n");
    ListPrint(head);
    
    
   STU*newHead= reverse(head);
    printf("逆序后：\n");
    //逆序之后 如果不传入新的head在打印就打不出来
    ListPrint(newHead);

    //删除
    del(head, 1004);
    printf("删除后：\n");
    ListPrint(newHead);


    
}
