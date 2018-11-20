//
//  stu_list.h
//  faceOffer
//
//  Created by chance on 2018/11/20.
//  Copyright © 2018 chancelee. All rights reserved.
//

#ifndef stu_list_h
#define stu_list_h

//学生成绩链表练习

typedef struct student{
    int idnum;
    float score;
    struct student*next;
}STU,*STU_LIST;

#include <stdio.h>


/**
 建立一个动态链表，初始时只有head节点，head节点不指向有效数据

 @return 返回一个指针，该指针为链表的头部节点
 */
STU* ListCreate (void);



/**
 用来向动态链表插入一结点，把新创建的节点插入到链表尾部

 @param head 头结点
 @param new 新节点
 @return NULL表示失败，成功则返回新节点的地址
 */
STU *ListInsert(STU *head, STU *new);

STU *ListInsert2(STU *head);




/**
 将链表中的各数据遍历输出

 @param head 头部节点
 */
void ListPrint(STU *head );


/**
 按照idnum(学号)从小到大排序链表

 @param head 头部节点
 */
void ListSort(STU *head);

/**
 链表删除

 @param head 头结点
 @param id id
 */
void del(STU *head, int id);




/**
  已经按照学号排好序的链表逆序
  head->num0->num1->num2->num3->num4则逆序后变为
        head->num4->num3->num2->num1->num0
  @param head 头结点
  */
void reverse(STU *head);





void stu_list_test(void);

#endif /* stu_list_h */
