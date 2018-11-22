# 未雨绸缪，潇湘夜雨
---
## OC 编程题 
1. 写一个View 从屏幕顶端动画移动到底部
2. 写一个内联函数，将字符串@“#ff3344”换成相应的UIColor对象
3. 将字符串@“abcdefghijklmn”中的efg 截取出来替换成 gfe
4. 写一个取当前日期的方法，输入字符串，格式如下2010-02-19
5. 不用存取器的方法，重写TestClass类(福西)

        @interface TestClass :NSObject{
            NSString *str;
        }
        @property(retain)NSString *str;
        @end
        
        @implementation TestClass
        @synthesize str = _str;
        @end
答

    @interface TestClass :NSObject{
        NSString*str;
    }
    -(void)setStr:（NSString *）str;
    -(NSString *)str;
    @end
    @implementation TestClass
    -(void)setStr:（NSString *）str{
        if(str!=_str){
            [_str release];
            _str = [str retain];
            }
        }
    -(NSString *)str{
        return[ str autorelease];
    }
    @end


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

13. [静态方法和实例方法](https://blog.csdn.net/ygh5123687/article/details/72939863)（班德尔）
        
        静态方法就是类方法，实例方法就是对象方法
       
14.  将字符串以 abcdef|123以 | 分割，输出结果  （班德尔）
    
    -(void)separateString{
        NSString*targetSting=@"abcdefg|123";
        NSArray*arr=[targetSting componentsSeparatedByString:@"|"];
        for (NSString*str in arr) {
        NSLog(@"str=%@",str);
        }
    }

15. 100个人依次数123123，数23的退出最后剩哪个？123123 OC实现（班德尔）（未实现）

16. What happen when a floating point value is assigned to an integer variable?

        当一个浮点型数据赋值给整型变量时会发生？
        答案：取整，浮点型缩短
        说明：基础
  
  17.下面输出值（具体看反编译代码）    
  
        int x=3;
        printf("%d",x++ + ++x);//8
        printf("x=%d",x);     //5
        

当一个浮点型数据赋值给整型变量时会发生？

答案：取整，浮点型缩短

说明：基础

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
    
10. OC 快速排序（百度笔试), 说说快速排序算法的基本思路或过程（福西）
  -  [iOS算法笔记-快速排序-OC实现](https://www.jianshu.com/p/34e920acfe1c)
  -  [C语言快速排序的实现](https://github.com/chancelee/C_Language_Study/blob/master/ruanjiankaifa/basic/ArrayTest.c)
11. [OC 的nil,Nil,NSNull,NULLd的区别](https://www.jianshu.com/p/2b44e1c346e7)
   
        nil：指向oc中对象的空指针
        Nil：指向oc中类的空指针

          //Nil类对象的书面空值
            Class someClass = Nil;
            someClass    Class    0x0    0x0000000000000000
            
            (lldb) po someClass
                nil
            (lldb) p someClass
                (Class) $1 = nil
            
            int a= someClass; a的值为0
            
            What is "Nil" in Objective-C? “Nil”在OC中是什么？
            答案：(void *)0
            说明：'NULL','nil'以及'Nil'是指向0地址的空指针。'nil'和'Nil'在OC中被定义为"DARWIN_NULL"，也就是(void *)0

            
        NULL：指向其他类型的空指针，如一个c类型的内存指针
        NSNull：在集合对象中，表示空值的对象
        若obj为nil：
        ［obj message］将返回NO,而不是NSException
        若obj为NSNull:
        ［obj message］将抛出异常NSException
     
     12.   说一下下面的地址：
        s1,s2,s4地址是一样的
      
        NSString*s1=@"hello world";
        NSString*s2=@"hello world";
        NSString*s3=[NSString stringWithFormat:@"hello world"];
        NSString*s4=[[NSString alloc]initWithString:@"hello world"];  
        
        (lldb) p s1
        (__NSCFConstantString *) $1 = 0x000000010a6d2bb8 @"hello world"
        (lldb) p s2
        (__NSCFConstantString *) $2 = 0x000000010a6d2bb8 @"hello world"
        (lldb) p s3
        (__NSCFString *) $3 = 0x0000600001a8a3a0 @"hello world"
        (lldb) p s4
        (__NSCFConstantString *) $4 = 0x000000010a6d2bb8 @"hello world"

13. [题目1](https://www.cnblogs.com/blogoflzh/p/4732834.html)
      [题目2](https://blog.csdn.net/iosevanhuang/article/details/8922352)

14 .Does the Objective-C compiler treats the identifiers of an enumeration as integer constants?

        OC的编译器将枚举型当作整型来处理么？
        答案：显然是的
        说明：基础
        
15.Objective-C中有无私有成员？有无私有方法？如何区分类方法和实例方法？（福西）

    Objective-C 并没有绝对的私有变量和私有方法。开始挺纳闷的。我们在 .m 中实现的方法，不在.h 中声明，外界不就不能访问到了吗？
    首先，我们先来看一下私有的定义：私有是指只能够在本类内部使用或访问，但是不能在类的外部被访问。
   [为什么说 Objective-C 没有私有方法和私有变量](https://blog.csdn.net/u014744233/article/details/53540779)
   
   16.Block与函数有何异同？block有何优点？(福西)
                
        第一个区别，函数指针是对一个函数地址的引用，这个函数在编译的时候就已经确定了。而block是一个函数对象，是在程序运行过程中产生的。在一个作用域中生成的block对象分配在栈(stack)上，和其他所有分配在栈上的对象一样，离开这个作用域，就不存在了。
        Block允许开发者在两个对象之间将任意的语句当做数据进行传递，往往这要比引用定义在别处的函数直观。
        
        1. 函数指针仅仅是一个地址，不具备函数原型信息，没有类型限制，比如一个指向变量的指针同样可以指向一个函数，但是block作为函数对象，是有部分函数信息的，类型限制更明确。
        2. block方式便于实现真正的“函数式”编程，让函数成为基本的运算元，往更远的方向说，真正的函数式语言可以去掉寄存器(请参考冯诺依曼机器基本架构)，提高程序的执行效率，近段时间的语言都支持lambda语法，包括JS、C++、Python、Ruby等，可见各个编程语言为改进冯诺依曼架构做出的努力和准备
        3. 提高程序的健壮性， 定义函数的代码会位于程序的代码段，如果函数内部出现内存溢出，就会直接导致crash，因为代码段是不可写的；block作为函数对象在运行时生成，位于栈内，即使出现内存溢出，一般也不会直接导致crash.

17. Objective-C中发送消息（如，[object message]）,与c++成员函数或者是c的函数调用，有何区别和联系？--待补充（福西）
     1）C没有成员方法，只有函数调用，函数地址在编译的时候就已经确定
     2）C++成员方法
     3）OC的方法调用本质是发消息
     
18. 以下代码有什么问题？（福西）
    
        （将一个int类型的参数转换为NSNumber类型，并返回）
        -（NSNumber *）number：（int）num{
            return  [[NSNumber alloc]initWithInt:num]；
         }    
     
      这个问题，在非ARC 会有问题，对于基本类型，不需要管理内存的，
      使用 NSNumber alloc]init 势必考虑内存释放的问题
      而使用 [NSNumber numberWith]不必考虑内存
      
   

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
10. UIButton的继承结构（微享科技）
    
        UIButton-->UIControl-->UIView->UIResponder-->NSObject
11. NSOperation的并发被非并发的区别（微享科技）

     [链接](https://www.jianshu.com/p/813f7d58935d)
     
        如果需要自定义并发执行的 Operation，必须重写 start、main、isExecuting、isFinished、isAsynchronous 方法。
        在 operation 的 main 方法里面，必须提供 autorelease pool,因为你的 operation 完成后需要销毁。
        一旦你的 operation 开始了，必须通过 KVO，告诉所有的监听者，现在该operation的执行状态。
        调用时，如果需要并发执行 Operation，必须调用performOperation:方法，当然，也可以改为自定义其他方法或者直接在start方法添加多线程调用。
        对于自定义的 Operation 类，如果不需要并发执行，可以直接调用start方法.
        
12. [Objective-C中的@property和@synthesize用法](https://www.cnblogs.com/AnnieBabygn/p/7742628.html)     （微享科技） 
   
        synthesize可以自己定义
13. NSCoder是做什么的？（微享科技）        
     [详细](https://www.jianshu.com/p/3a4a495a950a)
     
14. CAAnimation对代理是强引用的（微享科技）

        /* The delegate of the animation. This object is retained for the
        * lifetime of the animation object. Defaults to nil. See below for the
        * supported delegate methods. */
        @property(nullable, strong) id <CAAnimationDelegate> delegate;     
        
  15. 关于iOS里IBOutlet对象的内存管理(微享科技)
    
            当加载nib文件的时候， table会被初始化，这时候它的retain count是1， 然后建立nib文件里对象的连接
            这时候会调用到你定义的属性的set方法， 因为你定义成了retain， 所以这时候table的retain count变成了2, 属性的getter/setter会用到autorelease，这时候就会变成3！
  
            推荐IBoutlet的属性定义成assign（weak）就可以了！
            
16. IOS开发之如何自定义UITabBarController（班德尔笔试题）
      [详解](https://www.cnblogs.com/jerehedu/p/5141270.html)
      
17.你用过动画效果吗？请举例说明 ？（班德尔笔试题）
   [详解](https://blog.csdn.net/aaaaazq/article/details/80736594)
   
18.  实现一个cell,有标题和内容 （班德尔笔试题）
 [详解](https://www.cnblogs.com/soley/p/5418544.html)
 
 19. 解释一下http，如何下载一张图片代码实现 （班德尔笔试题）
    [iOS开发—使用GCD下载图片](https://blog.csdn.net/shichunxue/article/details/78495630)
    [iOS 加载高清大图片](https://www.jianshu.com/p/52e3535dd37c)
20. 简述对view，viewcontroller, calayer和window的理解（班德尔笔试题）
      [详解](https://blog.csdn.net/yoyo_lzj/article/details/50682280?utm_source=blogxgwz6)
      
21. InitWithNibName：boundle；/dealloc/loadView/viewDidLoad/viewDidUnload 调用顺序，每个方法应该做的工作是什么？（福西）

   *  [macOS 和 iOS 中 Nib 文件实现原理以及最佳实践](https://www.jianshu.com/p/d937da4b27cc)
   *  [iOS程序执行顺序和UIViewController 的生命周期(整理)](https://www.jianshu.com/p/d60b388b19f5)

22. 说明UiView 类属性 frame/center/bounds的联系与区别，改变bounds的值会不会对frame和center造成改变。（福西）
- [详解UIView的frame、bounds和center属性](https://www.jianshu.com/p/c16c32c45862)

        Frame指的是：该view在父view坐标系统中的位置和大小（参照点是父类的坐标系统）
        Bounds指的是：该view在本身坐标系统中的位置和大小（参照点是本身的坐标系统）
        center：描述当前视图的中心点在其父视图中的位置。
        改变 bounds
        1. 它可以修改自己坐标系的原点位置，影响“子view”的显示位置。
        2. bounds，它可以通过改变宽高，改变自身的frame，进而影响到再父视图的显示位置和大小。
- [bounds改变的影响](https://www.jianshu.com/p/7973f69dc920)
    
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
      
13. 编写一个标准的strcpy函数
    [代码](https://github.com/chancelee/C_Language_Study/blob/master/ruanjiankaifa/basic/StringTest.h)
 14.描述Vector,List,Map的各自使用情形（C++）
    
        map是关联式的，vector、list、deque是序列式的。
        map：底层机制RB-tree（红黑树），元素自动排序，键值对。
 
        vector：操作方式与array相似，动态空间增长。是连续性空间，支持随机访问。
            优点：
            内存动态增长，不需要指定内存大小。
            支持随机访问，即支持[]和vector.at()。
            缺点：
            在内部进行插入删除操作效率低。
            只能在vector的最后进行push和pop。
            
            list：对空间的运用有绝对的精准，一点也不浪费。删除插入简单，但不支持随机访问。双向线性列表。
                优点：
                方便插入和删除。
                可在两端push、pop。
                    缺点：不能随机访问。

15 单链表倒转（C）

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

16. 判断字符串是否回文"abcdcba" (C)
17. 找出第二大的数，判断各种输入异常 （C）
            
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
18. 去掉一个由英文字母组成的字符串的重复字符 gggggoogoooood， 去掉之后变成：god.(未实现 C)
19. 按照个位十位百位依次打印

        while (n>0) {
            printf("%2d",n%10);
            n/=10;
        }
 20.计算机模拟扑克牌出现对的概率（不包括大小王）     （未实现）  

21.简单设计一个俄罗斯方块游戏（结构设计）（未实现）


22. 公用体 
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
23. 计算机中的堆和栈分别是什么？关于堆和栈的区别（福西）
   
   - [从不同角度解释 堆和栈](http://drivers.160.com/xtwt/221415kAMWN.html）
        
    堆和栈的要点：
        堆，队列优先，先进先出（FIFO—first in first out）。
        栈，先进后出（FILO—First-In/Last-Out）。
   
    一般情况下，如果有人把堆栈合起来说，那它的意思是栈，可不是堆。
    堆和栈的对比分析：
    1、堆栈空间分配
        栈（操作系统）：由操作系统自动分配释放 ，存放函数的参数值，局部变量的值等。其操作方式类似于数据结构中的栈。
        堆（操作系统）： 一般由程序员分配释放， 若程序员不释放，程序结束时可能由OS回收，分配方式倒是类似于链表
    2、堆栈缓存方式
        栈使用的是一级缓存， 他们通常都是被调用时处于存储空间中，调用完毕立即释放。
        堆则是存放在二级缓存中，生命周期由虚拟机的垃圾回收算法来决定（并不是一旦成为孤儿对象就能被回收）。所以调用这些对象的速度要相对来得低一些。
    3、堆栈数据结构区别
        堆（数据结构）：堆可以被看成是一棵树，如：堆排序。
        栈（数据结构）：一种先进后出的数据结构。
   
   24. 设置一绝对地址为0x67a9的整型变量的值为0xaa66
   - [链接](https://blog.csdn.net/plutus_sutulp/article/details/8628619?utm_source=blogxgwz1)
   
   25.    指出这段代码的重大错误，并改正。（高新）
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
26. 字符串逆序显示函数（输入ABC,修改为CBA）
   
    void reverseString(char*s);
  - [字符串逆序](https://blog.csdn.net/m0_37888031/article/details/77896594)
