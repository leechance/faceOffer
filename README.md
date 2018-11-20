# 未雨绸缪，潇湘夜雨
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
3、有哪些集合类和存放二进制数据类 (百度笔试)

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
    
10. OC 快速排序（百度笔试）    
   [iOS算法笔记-快速排序-OC实现](https://www.jianshu.com/p/34e920acfe1c)
   [C语言快速排序的实现](https://github.com/chancelee/C_Language_Study/blob/master/ruanjiankaifa/basic/ArrayTest.c)
   
   
   

### Cocoa
1、写出iphone编程中常用控件类名（不用很准确，写出五个以上）

    UILabel,UITextField,UITextView,UIButton,UISwitch, UISegmentedControl,UISlider,UIImageView ,UIScrollView,UITableView,UITabBarController,UINavigationController 


2、写出几个常用的设计模式（两个以上） 
    
    MVC设计模式 
    单例模式 
    代理模式 
    通知模式 
    工厂模式
3. viewController中的didReceiveMemoryWarning 啥时候调用，默认如何处理（百度笔试）
    [iOS UIViewController 对内存警告的处理经验](https://blog.csdn.net/zuoanlangren/article/details/21996625)
4. OC 写俩个线程，对同一个变量 分布进行 +/-操作（百度笔试）    
5. OC中frame与bounds有什么不同(百度笔试）
    
        Frame指的是：该view在父view坐标系统中的位置和大小（参照点是父类的坐标系统）
        Bounds指的是：该view在本身坐标系统中的位置和大小（参照点是本身的坐标系统）
6. OC中有无多重继承，如何实现多重继承（百度笔试） 
            
        没有多重继承。
        cocoa中所有的类都是NSObject的子类，多继承在这里是用protocl委托代理来实现的，所以我们不用去考虑繁琐的多继承、虚基类的概念，多态特性在oc中拖过委托来实现。
7. 用OC写两个线程，对同一个变量 分别进行+/-操作（百度笔试）
     [在iOS中有几种方法来解决多线程访问同一个内存地址的互斥同步问题](https://blog.csdn.net/a_ellisa/article/details/51506233?utm_source=blogxgwz8)
8. OC中如何创建一个线程，要求可以一直工作，不会只执行一次就结束 （百度笔试）
    [两种方式：自动释放池和runloop](https://blog.csdn.net/jeffasd/article/details/51598086)
    追问如何结束~？
9. 写一个你所经历的项目架构或cocoa里的MVC设计模式（百度笔试）    
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
    [链接](https://github.com/chancelee/faceOffer/blob/master/faceoffer/stu_list.h)
      

5. 用链表模拟一个栈，数组模拟栈的思想就是将入栈的数据以数组方式模拟，现在用链表存储的方式来模拟，要求自己定义栈数据的形式，实现栈常用的操作：
[链接](https://github.com/chancelee/C_Language_Study/blob/master/ruanjiankaifa/ds/LinkStack.c)
6. 得到一个field在结构体的偏移量 C++（百度笔试）
 [链接](https://blog.csdn.net/submorino/article/details/43956695)
7. 引用和指针的区别 C++（百度笔试)
   [c++引用与指针的区别](https://www.cnblogs.com/sexybear/p/C_pointer.html)

            
            ★ 相同点：
            1. 都是地址的概念；
            指针指向一块内存，它的内容是所指内存的地址；引用是某块内存的别名。

            ★ 区别：
            1. 指针是一个实体，而引用仅是个别名；
            2. 引用使用时无需解引用（*），指针需要解引用；
            3. 引用只能在定义时被初始化一次，之后不可变；指针可变；
8. float x 与零值比较的if语句 C（百度笔试)
      [详解](https://blog.csdn.net/azhang00000/article/details/5357134)
      
        const float EPSINON = 0.00001; 
        if ((x >= - EPSINON) && (x <= EPSINON) 
        不可将浮点变量用“==”或“！=”与数字比较，应该设法转化成“>=”或“<=”此类形式。 
9. 如何引用一个已经定义过的全局变量 C（百度笔试）
    [详解](https://blog.csdn.net/ad35f2/article/details/44134985)
10. static全局变量与普通变量的区别，局部变量呢？ C（百度笔试）    
      [详解](https://www.cnblogs.com/felix-kun/p/5404058.html)
 11. 队列和栈的区别     （百度笔试） 
      [详解](https://blog.csdn.net/bbc955625132551/article/details/72773285)
12. 写一个单链表，要求可以插入数据可删除单个数据（百度笔试） 
      [详解](https://github.com/chancelee/C_Language_Study/blob/master/ruanjiankaifa/ds/LinkList.c)
