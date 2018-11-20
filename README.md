# 剑指offer
## OC 编程题 
1. 写一个View 从屏幕顶端动画移动到底部
2. 写一个内联函数，将字符串@“#ff3344”换成相应的UIColor对象
3. 将字符串@“abcdefghijklmn”中的efg 截取出来替换成 gfe
4. 写一个取当前日期的方法，输入字符串，格式如下2010-02-19

## C 编程题
1. 编写一个程序将输入字符串中的大写字母转化为小写字母，并返回大写字母的个数
2. 编写一个函数，用来在一个给定的整形数组里面找出第2大的数。
3. 用递归方法判断一个数组是否为递增数组（使用递归时充分考虑递归终止条件，以及函数调用思想）
4. 构造学生成绩管理链表，并提供链表操作的函数
 
 typedef struct student
 {
         int idnum; //学生的编号，唯一性！！！
         float score;//学生的成绩
         struct stuent *next;
   } STU;
               
      (1)  写一函数ListCreate, 用来建立一个动态链表，初始时只有head节点，head节点不指向有效数据。
            STU *ListCreate (void);
            函数说明：函数用于返回一个指针，该指针为链表的头部节点。
             
    （2）写一函数ListInsert,用来向动态链表插入一结点，把新创建的节点插入到链表尾部。
             STU *ListInsert(STU *head, STU *new);
             函数说明：参数head表示头结点，new表示新节点，返回NULL表示失败，成功则返回新节点的地址。      
      (3）写一函数ListSort按照idnum(学号)从小到大排序链表
       void ListSort(STU *head);
       函数说明：参数head表示头部节点。
        
     (4)写一ListPrint函数，将链表中的各数据遍历输出
          void ListPrint(STU *head );
          函数说明：参数head表示头部节点
           
     (5）写一ListDel函数，用来删除动态链表中，指定的结点数据
       void del(STU *head, int id);
       函数说明：head表示头部节点，id表示学生的学号，每个号码都是唯一的。
     (6)尝试着将已经按照学号排好序的链表逆序，例如：
       head->num0->num1->num2->num3->num4则逆序后变为
       head->num4->num3->num2->num1->num0
       void reverse(STU *head);
       函数说明：head表示链表的头结点

