#  C/C++ 面试题
## 前言 
Objective-C是基于C的，所以一些公司更看重基础

## C 面试题
### 1. 编写一个程序将输入字符串中的大写字母转化为小写字母，并返回大写字母的个数
### 2. 编写一个函数，用来在一个给定的整形数组里面找出第2大的数。
### 3. 用递归方法判断一个数组是否为递增数组（使用递归时充分考虑递归终止条件，以及函数调用思想）
### 4. 构造学生成绩管理链表，并提供链表操作的函数

        typedef struct student{
        int idnum; //学生的编号，唯一性！！！
        float score;//学生的成绩
        struct stuent *next;
        } STU; 
        
    - [代码链接](https://github.com/chancelee/faceOffer/blob/master/faceoffer/stu_list.h)


### 5. 用链表模拟一个栈，数组模拟栈的思想就是将入栈的数据以数组方式模拟，现在用链表存储的方式来模拟，要求自己定义栈数据的形式，实现栈常用的操作：
- [链接](https://github.com/chancelee/C_Language_Study/blob/master/ruanjiankaifa/ds/LinkStack.c)
### 6. 得到一个field在结构体的偏移量 C++（百度笔试）
- [链接](https://blog.csdn.net/submorino/article/details/43956695)
### 7. 引用和指针的区别 C++（百度笔试)
- [c++引用与指针的区别](https://www.cnblogs.com/sexybear/p/C_pointer.html)

        ★ 相同点：
        1. 都是地址的概念；
        指针指向一块内存，它的内容是所指内存的地址；引用是某块内存的别名。
        
        ★ 区别：
        1. 指针是一个实体，而引用仅是个别名；
        2. 引用使用时无需解引用（*），指针需要解引用；
        3. 引用只能在定义时被初始化一次，之后不可变；指针可变；
    
### 8. float x 与零值比较的if语句 C（百度笔试)
-   [详解](https://blog.csdn.net/azhang00000/article/details/5357134)

        const float EPSINON = 0.00001; 
        if ((x >= - EPSINON) && (x <= EPSINON) 
        不可将浮点变量用“==”或“！=”与数字比较，应该设法转化成“>=”或“<=”此类形式。 
        
### 9. 如何引用一个已经定义过的全局变量 C（百度笔试）
- [详解](https://blog.csdn.net/ad35f2/article/details/44134985)
### 10. static全局变量与普通变量的区别，局部变量呢？ C（百度笔试）    
- [详解](https://www.cnblogs.com/felix-kun/p/5404058.html)
### 11. 队列和栈的区别     （百度笔试） 
- [详解](https://blog.csdn.net/bbc955625132551/article/details/72773285)
### 12. 写一个单链表，要求可以插入数据可删除单个数据（百度笔试） 
- [详解](https://github.com/chancelee/C_Language_Study/blob/master/ruanjiankaifa/ds/LinkList.c)

### 13. 编写一个标准的strcpy函数
- [代码](https://github.com/chancelee/C_Language_Study/blob/master/ruanjiankaifa/basic/StringTest.h)
### 14. 描述Vector,List,Map的各自使用情形（C++）

        map是关联式的，vector、list、deque是序列式的。
        map：底层机制RB-tree（红黑树），元素自动排序，键值对。

        vector：操作方式与array相似，动态空间增长。是连续性空间，支持随机访问。
            优点：
                内存动态增长，不需要指定内存大小。
                支持随机访问，即支持[]和vector.at()。
            缺点：在内部进行插入删除操作效率低。只能在vector的最后进行push和pop。
        list：对空间的运用有绝对的精准，一点也不浪费。删除插入简单，但不支持随机访问。双向线性列表。
         优点：方便插入和删除。可在两端push、pop。 缺点：不能随机访问。
                              
### 15. 单链表倒转（C）

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
 
###  16. 判断字符串是否回文"abcdcba" (C)
###  17. 找出第二大的数，判断各种输入异常 （C）
 
    int n;
    while(1){
    scanf(“%d”,&n);
    if(n==1){
        printf("。。。。。")
    }
    if(n>=2){
        break;
    }
    }
###  18. 去掉一个由英文字母组成的字符串的重复字符 gggggoogoooood， 去掉之后变成：god.(未实现 C)
###  19. 按照个位十位百位依次打印
 
    while (n>0) {
    printf("%2d",n%10);
    n/=10;
    }
 ### 20.计算机模拟扑克牌出现对的概率（不包括大小王）     （未实现）  
 
###  21.简单设计一个俄罗斯方块游戏（结构设计）（未实现）
 
 
 ### 22. 共用体 
 [详解](https://blog.csdn.net/qq_16628781/article/details/72529228)
 
    在C语言中，给我们提供了分配和操作一块内存的方式，那就是union关键字。union关键字，定义union下面的成员变量共享一块内存，每一个成员在任一时刻有且只有一个成员使用此块内存。
    因为C语言只管分配一段空间，至于里面放什么内容，系统都不会管。结构体strcut也是如此。
      typedef union {
        short s;
        char c;
       }sc;
              
       int main(int argc, char * argv[]) {
             sc u;
             u.s=0x602;
              printf("%d",u.c);
              reurn 0
            }
       u.c的值是2
       
### 23. 计算机中的堆和栈分别是什么？关于堆和栈的区别（福西） 
        - [从不同角度解释 堆和栈](http://drivers.160.com/xtwt/221415kAMWN.html）
                                  
### 24. 设置一绝对地址为0x67a9的整型变量的值为0xaa66
   - [链接](https://blog.csdn.net/plutus_sutulp/article/details/8628619?utm_source=blogxgwz1)
   
### 25. 指出这段代码的重大错误，并改正。（高新）
- [关于 malloc和memset这对兄弟](https://blog.csdn.net/a351945755/article/details/20142809)

        void allocBuf(char*buf,int size){
        buf=(char*)malloc(size*sizeof(char));
        memset(buf, 0, size*sizeof(char));
        }
        void testBuf(void){
        char*buf=NULL;
        int i,count;
        allocBuf(buf, 5);
        for (i=0; i<5; i++)
        buf[i]=rand()%10;
        for (i=0; i<4; i++) {
        printf("%d-%d",i+1,buf[i]+buf[i+1]);
        }
        free(buf);
        }
        更改如下
        
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
### 26. 字符串逆序显示函数（输入ABC,修改为CBA）(高新)

        void reverseString(char*s);
- [字符串逆序](https://blog.csdn.net/m0_37888031/article/details/77896594)
### 27. extern C的作用
- [extern C的作用详解](https://www.cnblogs.com/carsonzhu/p/5272271.html)

### 28. 判断是否为空串、空字符串和空值
    
        空值是NULL，意思是没有存入内存的数据
        空字符串 指的是""这个
        两者字节数不一样

        1）空字符串也就是空串
        char*s="";
        printf("s的地址：%p\n",&s);
        
        (lldb) p s
        (char *) $3 = 0x0000000105efab5d ""
        (lldb) p s[0]
        (char) $4 = '\0'
        (lldb) p s[1]
        (char) $5 = '%'
        (lldb) p s[2]
        (char) $6 = '@'
        (lldb) p s[3]
        (char) $7 = '%'
        (lldb) p s[4]
        (char) $8 = '@'
        (lldb) p s[5]
        (char) $9 = '\0'
        (lldb) p s[6]
        (char) $10 = 's'
        (lldb) p s[7]
        (char) $11 = 't'
        (lldb) p s[8]
        (char) $12 = 'a'
        (lldb) p s[9]
        (char) $13 = 't'
        (lldb) 
        
        printf("s占用的字节数：%d",sizeof(s));占8个字节
        为什么s[8]还有值，因为 字符串是静态存储区，所以还有值
        
        2)空字符串（空串）
        char*s1=NULL;
        printf("s1的地址：%p\n",&s1);
        printf("s1占用的字节数：%d",sizeof(s1));
        
        s1的地址：0x7ffeeb629f98
        s1占用的字节数：8(lldb) po s[0]
        <nil>
        (lldb) po s[1]
        '%'
        (lldb) po s[2]
        '@'
        (lldb) po s[3]
        '%'
        s和s1存储的内容不一样，s第一个元素是’\0‘;s1第一个元素的是空
        但是作为指针都是占用8个字节

### 29. 判断是否为空串、空字符串和空值
- [对于一个频繁使用的短小函数,在C语言中应用什么实现,在C++中应用什么实现?](https://blog.csdn.net/hejianhua/article/details/6716803)

- 在C中，常用预处理语句#define来代替一个函数定义
- C++ 使用内联函数

### 30. switch 比较两个数的大小

        void swtichCompare(int a,int b){
        switch(a>b){
            case true:
                printf("%d>%d\n",a,b);
                break;
            case false:
                printf("%d<=%d\n",a,b);
                break;
            }
        }
    
## C++ 面试题
### 1.new和malloc区别

### 2.Static修饰的变量和函数的意义分别是什么

### 3.Copy构造函数，什么时候会调用？

### 4.析构函数可以为虚函数吗？为什么？

### 5.typedef    /  const int *const p;

