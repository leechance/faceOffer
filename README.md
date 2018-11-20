# 剑指offer
---
## OC 编程题 
1. 写一个View 从屏幕顶端动画移动到底部
2. 写一个内联函数，将字符串@“#ff3344”换成相应的UIColor对象
3. 将字符串@“abcdefghijklmn”中的efg 截取出来替换成 gfe
4. 写一个取当前日期的方法，输入字符串，格式如下2010-02-19

## OC 简答题

1、写出打印语句 

       NSLog(); 
       
2、解释类、对象、实例方法和实例成员 （解释很弹性的，不同人，不同的书籍的解释都不一样，主要看  解释的角度）

        类：一类事物的抽象，有成员和方法。 
        对象：类的实例化和具体化 
        实例方法：主要和类方法区别，类方法声明时前面用加号，实例方法声明时用减号 
        实例成员：主要和类成员区分，类成员加static，实例成员不需要。 

3、类名、方法名、成员名、函数名、宏定义首字母哪些大写，哪些小写 
         
        大写：类名，宏定义 
        小写：方法名，成员名，函数名 
          
4、@public，@protected，@private区别 （C++）

    @public：完全公开，在程序的任何地方都可以调用 
    @private：和@public相反，只能在该类内部不调用 
    @protected：只有自己和自己的子类可以调用 


5、如何声明一个带两个参数的实例方法和如何调用（举例说明） 

    声明：-(void)methodForParameter1:(NSString *)p1 Parameter2:(NSString *)p2; 
    调用：[self methodForParameter1:@"" Parameter2:@""]; 

6、@property (nonatomic, retain) Example *example; 

            写出其setter和getter方法 
            getter 
                - (Example *)example { return _example; } 
          setter 
              -(void)setExample:(Example *)aExample 
                {  
                    if (example != aExample)  
                    {  
                        [example release];  
                        example = [aExample retain];  
                    } 
                } 
                
7、static关键字的作用，extern关键字的作用 (C++)

    static:定义全局变量；定义类成员；定义内部函数 
    extern：声明外部变量和外部函数，所声明的变量和函数可能不在本文件内定义或实现 


8、解释self 

    self就是实例本身，在类里用self来调用自身的方法 
9、什么时候使用继承？什么时候使用类别 

        给一个类增加新的数据成员时用继承 
        只是想扩展类的方法或覆盖原来的方法时用类别 
10、如何声明一个类 

    @class Example        C++定义类的方式
    @interface Example  OC定义类的方式
    @end 
    
11、写出1－2个与动态调用有关的方法 

      respondsToSelector 、
      performSelector、
      conformsToProtocol、
      isKindOfClass、
      isMemberOfClass 
      
12、写一个协议（举例），协议有什么用 

       @protocol ExampleProtocol <NSObject> 
          - (void)exampleProtocol; 
       @end 

      @interface ExampleClass : NSObject  
       {  
        id<ExampleProtocol> delegate;  
       }  
       @property (nonatomic,assign) id<ExampleProtocol> delegate;  
     @end 
一个通过协议对外提供接口。 

---
### Foundation 

1、存放数字用哪个类，存放CGRect用什么类型 

         存放数字用NSNumber 
         存放CGRect用NSValue 

2、快速枚举（举例） 

    NSArray *array = [NSArray array]; 
     for (id object in array)  
    { 
        [object test]; 
    } 
3、有哪些集合类和存放二进制数据类 

    NSArray/NSMutableArray，NSDictionary/NSMutableDictionary，NSSet/NSMutableSet/NSCountedSet,
    NSData存放二进制数据 
4、文件处理用哪些类（写1－2个） 

    NSFileManager
    NSUserDefaults 
    open, fopen（C的api）
    
5、解释retain、copy、assgin、autorelease 

          retain，copy：计数器加一，区别是retain是原对象计数器加一，
          copy是创建一个新对象后，新对象计数器加一 
          assgin：简单复制，计数器不变 
         autorelease：内存延迟释放，计数器延迟减一 
         
6、写出归档相关类 

    NSKeyedArchiver、
    NSKeyedUnarchiver 
    
7、写出xml解析和网络相关类 

    xml解析：NSXMLParser, kissXML GDATA
    网络：NSConnection 

8、常用的xml/json解析和http请求第三方包各写出一个 

    xml：kissxml 
    json：SBJSon 
    http请求：ASIHttpRequest SDWebImage, 异步图片加载器(界面流畅)
    异步mp3 异步video
9、代理和通知的区别 

    代理是垂直的，通知可以平行的 


### Cocoa
1、写出iphone编程中常用控件类名（不用很准确，写出五个以上）

    UILabel,UITextField,UITextView,UIButton,UISwitch, UISegmentedControl,UISlider,UIImageView ,UIScrollView,UITableView,UITabBarController,UINavigationController 


2、写出几个常用的设计模式（两个以上） 
    
    MVC设计模式 
    单例模式 
    代理模式 
    通知模式 
    工厂模式



---
## C 编程题
1. 编写一个程序将输入字符串中的大写字母转化为小写字母，并返回大写字母的个数

2. 编写一个函数，用来在一个给定的整形数组里面找出第2大的数。

3. 用递归方法判断一个数组是否为递增数组（使用递归时充分考虑递归终止条件，以及函数调用思想）

4. 构造学生成绩管理链表，并提供链表操作的函数
    
        typedef struct student{
            int idnum; //学生的编号，唯一性！！！
            float score;//学生的成绩
            struct stuent *next;
            } STU;
     ```          
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
       ```

5. 用链表模拟一个栈，数组模拟栈的思想就是将入栈的数据以数组方式模拟，现在用链表存储的方式来模拟，要求自己定义栈数据的形式，实现栈常用的操作：
[链接](https://github.com/chancelee/C_Language_Study/blob/master/ruanjiankaifa/ds/LinkStack.c)


