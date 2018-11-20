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
    
}
