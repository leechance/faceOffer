#  独孤九剑

## 前言
- 按照考察的内容范围划分 Foundation , CocoaTouch（UIKit框架），第三方SDK，第三方组件， 开发遇到的问题，BUG,
- 按照考察的形式 ：编程，简答，深入思考
- 按照 热点划分：内存问题,多线程问题,动画,自定义组件,设计模式,runtime,runloop,KVC,KVO


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

6. 怎样实现一个 Memory Cache(九州瑞研)

        主要是思路：
- [iOS开发之缓存框架、内存缓存、磁盘缓存等](https://www.2cto.com/kf/201606/517537.html)
- [TMCache源码分析(一)---TMMemoryCache内存缓存](https://www.jianshu.com/p/a8a45c12d2d2)
- [TMCache源码分析(二)---TMDiskCache磁盘缓存](https://www.jianshu.com/p/b45b48b1f716)

7. 如何在有一个属性名和值的情况，给一个对象赋值(九州瑞研)

        对象名.属性名 = 值
        obj.name = v;
        
8. GBK 如何转换为 UTF-8 (3字节)，如何转成Unicode.（2字节）(九州瑞研)

        NSStringEncoding eco=CFStringConvertEncodingToNSStringEncoding(
        kCFStringEncodingGB_18030_2000);
        urlStr = [urlStr stringByAddingPercentEscapesUsingEncoding:eco];
        NSURL * url=[NSURL URLWithString:urlStr];
        
9. 如何实现一个带删除线的 UILabel（九州瑞研） 
- [UILabel添加删除线（全部方法详解，看这个就够了）](https://www.jianshu.com/p/d45656256aa9)

        1）用CG重绘 drawRect
        2）RTLabel 开源的富文本
        
10. 如何让 imageNamed 同时兼容 3.x 及 4.x ,7.x系统，以及不失去缓存,imageNamed自动缓存不会消失       

        按照3.X和4.X,7.X的分辨率做3张图片，
        test.png    
        test@2x.png  
        test@3x.png
        NSString *path = [[NSBundle mainBundle] pathForResource:@"xxx" ofType:@"png"];
        UIImage *iv = [[UIImage alloc] initWithContentsOfFile:path];

12. 如何实现一个异步的 UIImageView 开启异步线程下载图片，或用三方库进行一步操作

        SDWebImageCache

13. 如何实现像 Settings 一样的界面

        用TableView、UISwitch  
        
14. 如何实现滚动到底部自动加载，以及显示一个 loading cell      (上拉刷新原理) 

        用scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate方法计算是否触底，调用异步刷新事件
        scrollViewDidScroll
        
15. 如何实现从外部打开程序

        在项目的Info.plist文件中 添加一个 URL types 节点就可以了
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"http://www.baidu.com"]];
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"tel://18533221222"]];
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"sms://18533221222"]];

16.  如何将图片添加到照片库  

    UIImage *img = [UIImage imageWithNamed:@”123.ppng”];
    UIImageWriteToSavedPhotosAlbum(img, nil, nil, nil);

17. Undo, Redo 如何实现

        UIMenuItem
        
18.  NSCoding（archive，unarchive）

    -（id）initWithCoder:(NSCoder *)coder; 
    -(void) encodeWithCoder:(NSCoder*)coder;

19.  Objective-C 求素数
20.  Objective-C 判断是否回文
21. 写一个protocal或者delegate
22. 写一个单例
23. html加载本地的xml文件，或者js文件
24. iPhone开发的两种方式是什么，各自的优缺点（代码和xib）
    


## OC 简答题

### 1、写出打印语句 

    NSLog(); 

### 2、解释类、对象、实例方法和实例成员 （解释很弹性的，不同人，不同的书籍的解释都不一样，主要看  解释的角度）

    类：一类事物的抽象，有成员和方法。 
    对象：类的实例化和具体化 
    实例方法：主要和类方法区别，类方法声明时前面用加号，实例方法声明时用减号 
    实例成员：主要和类成员区分，类成员加static，实例成员不需要。 

### 3、类名、方法名、成员名、函数名、宏定义首字母哪些大写，哪些小写 

    大写：类名，宏定义 
    小写：方法名，成员名，函数名 

### 4、@public，@protected，@private区别 （C++）

    @public：完全公开，在程序的任何地方都可以调用 
    @private：和@public相反，只能在该类内部不调用 
    @protected：只有自己和自己的子类可以调用 


### 5、如何声明一个带两个参数的实例方法和如何调用（举例说明） 

    声明：-(void)methodForParameter1:(NSString *)p1 Parameter2:(NSString *)p2; 
    调用：[self methodForParameter1:@"" Parameter2:@""]; 

### 6、@property (nonatomic, retain) Example *example; 

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
    
### 7、static关键字的作用，extern关键字的作用 (C++)

    static:定义全局变量；定义类成员；定义内部函数 
    extern：声明外部变量和外部函数，所声明的变量和函数可能不在本文件内定义或实现 


### 8、解释self 

    self就是实例本身，在类里用self来调用自身的方法 
### 9、什么时候使用继承？什么时候使用类别 

    给一个类增加新的数据成员时用继承 
    只是想扩展类的方法或覆盖原来的方法时用类别 
### 10、如何声明一个类 

    @class Example        C++定义类的方式
    @interface Example  OC定义类的方式
    @end 

### 11、写出1－2个与动态调用有关的方法 

    respondsToSelector 、
    performSelector、
    conformsToProtocol、
    isKindOfClass、
    isMemberOfClass 

### 12、写一个协议（举例），协议有什么用 

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

### 13. [静态方法和实例方法](https://blog.csdn.net/ygh5123687/article/details/72939863)（班德尔）

        静态方法就是类方法，实例方法就是对象方法

### 14.  将字符串以 abcdef|123以 | 分割，输出结果  （班德尔）

    -(void)separateString{
    NSString*targetSting=@"abcdefg|123";
    NSArray*arr=[targetSting componentsSeparatedByString:@"|"];
    for (NSString*str in arr) {
        NSLog(@"str=%@",str);
        }
    }

### 15. 100个人依次数123123，数23的退出最后剩哪个？123123 OC实现（班德尔）（未实现）

### 16. What happen when a floating point value is assigned to an integer variable?

        当一个浮点型数据赋值给整型变量时会发生？
        答案：取整，浮点型缩短
        说明：基础

### 17.下面输出值（具体看反编译代码）    

    int x=3;
    printf("%d",x++ + ++x);//8
    printf("x=%d",x);     //5


### 18.当一个浮点型数据赋值给整型变量时会发生？

    答案：取整，浮点型缩短

    说明：基础
   
### 19.UITableView有时候不太流畅，有什么优化方案   
  
    使用多线程和异步加载数据
### 20. UIimageView怎么使其有单击，双击事件

    userInteraction = yes
    
### 21. 两个多线程怎么通讯，两个非UI线程怎么通讯 ,共享数据  
   
### 22. 将一组数据永久保存到手机里，怎样做？

    Nsuserdefaults, plist, db
    
### 23. 实现一个横向划动的表格，有什么思路    
   
  
   
    

---
### Foundation 

### 1、存放数字用哪个类，存放CGRect用什么类型 

    存放数字用NSNumber 
    存放CGRect用NSValue 

### 2、快速枚举（举例） 

    NSArray *array = [NSArray array]; 
    for (id object in array)  
    { 
    [object test]; 
    } 
### 3、有哪些集合类和存放二进制数据类 (百度笔试)

    NSArray/NSMutableArray，NSDictionary/NSMutableDictionary，NSSet/NSMutableSet/NSCountedSet,
    NSData存放二进制数据 
    
### 4、文件处理用哪些类（写1－2个） 

    NSFileManager
    NSUserDefaults 
    open, fopen（C的api）

### 5、解释retain、copy、assgin、autorelease 

    retain，copy：计数器加一，区别是retain是原对象计数器加一，
    copy是创建一个新对象后，新对象计数器加一 
    assgin：简单复制，计数器不变 
    autorelease：内存延迟释放，计数器延迟减一 

### 6、写出归档相关类 

    NSKeyedArchiver、
    NSKeyedUnarchiver 

### 7、写出xml解析和网络相关类 

    xml解析：NSXMLParser, kissXML GDATA
    网络：NSConnection 

### 8、常用的xml/json解析和http请求第三方包各写出一个 

    xml：kissxml 
    json：SBJSon 
    http请求：ASIHttpRequest SDWebImage, 异步图片加载器(界面流畅)
    异步mp3 异步video
### 9、代理和通知的区别 

    代理是垂直的，通知可以平行的 

### 10. OC 快速排序（百度笔试), 说说快速排序算法的基本思路或过程（福西）

-  [iOS算法笔记-快速排序-OC实现](https://www.jianshu.com/p/34e920acfe1c)
-  [C语言快速排序的实现](https://github.com/chancelee/C_Language_Study/blob/master/ruanjiankaifa/basic/ArrayTest.c)

### 11. [OC 的nil,Nil,NSNull,NULLd的区别](https://www.jianshu.com/p/2b44e1c346e7)

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

### 12.   说一下下面的地址：
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

### 13. [题目1](https://www.cnblogs.com/blogoflzh/p/4732834.html)
- [题目2](https://blog.csdn.net/iosevanhuang/article/details/8922352)

### 14 .Does the Objective-C compiler treats the identifiers of an enumeration as integer constants?

    OC的编译器将枚举型当作整型来处理么？
    答案：显然是的
    说明：基础

### 15.Objective-C中有无私有成员？有无私有方法？如何区分类方法和实例方法？（福西）

    Objective-C 并没有绝对的私有变量和私有方法。开始挺纳闷的。我们在 .m 中实现的方法，不在.h 中声明，外界不就不 能访问到了吗？
    首先，我们先来看一下私有的定义：私有是指只能够在本类内部使用或访问，但是不能在类的外部被访问。
- [为什么说 Objective-C 没有私有方法和私有变量](https://blog.csdn.net/u014744233/article/details/53540779)

### 16.Block与函数有何异同？block有何优点？(福西)

    第一个区别，函数指针是对一个函数地址的引用，这个函数在编译的时候就已经确定了。而block是一个函数对象，是在 程序运行过程中产生的。在一个作用域中生成的block对象分配在栈(stack)上，和其他所有分配在栈上的对象一样，离开 这个作用域，就不存在了。
    Block允许开发者在两个对象之间将任意的语句当做数据进行传递，往往这要比引用定义在别处的函数直观。
    
    1. 函数指针仅仅是一个地址，不具备函数原型信息，没有类型限制，比如一个指向变量的指针同样可以指向一个函数，  但是block作为函数对象，是有部分函数信息的，类型限制更明确。
    2. block方式便于实现真正的“函数式”编程，让函数成为基本的运算元，往更远的方向说，真正的函数式语言可以去掉寄  存器(请参考冯诺依曼机器基本架构)，提高程序的执行效率，近段时间的语言都支持lambda语法，包括JS、C++、    Python、Ruby等，可见各个编程语言为改进冯诺依曼架构做出的努力和准备
    3. 提高程序的健壮性， 定义函数的代码会位于程序的代码段，如果函数内部出现内存溢出，就会直接导致crash，因为   代码段是不可写的；block作为函数对象在运行时生成，位于栈内，即使出现内存溢出，一般也不会直接导致crash.

### 17. Objective-C中发送消息（如，[object message]）,与c++成员函数或者是c的函数调用，有何区别和联系？--待补充（福西）
    1）C没有成员方法，只有函数调用，函数地址在编译的时候就已经确定
    2）C++成员方法
    3）OC的方法调用本质是发消息

### 18. 以下代码有什么问题？（福西）

        （将一个int类型的参数转换为NSNumber类型，并返回）
        -（NSNumber *）number：（int）num{
        return  [[NSNumber alloc]initWithInt:num]；
        }    
        
        这个问题，在非ARC 会有问题，对于基本类型，不需要管理内存的，
        使用 NSNumber alloc]init 势必考虑内存释放的问题
        而使用 [NSNumber numberWith]不必考虑内存

### 19. 解释下面语句的意义。

        [[[MainLoop]initWithName:NONE]run:IMMDIATELY]
        初始化MainLoop对象，执行 run方法

### 20. OC实现一个顺序表类（高新）
- [OC语言实现一个简单的单链表](http://code.cocoachina.com/view/136821)

        #define Capacity 100
        typedef DataType int
        
        @interface Sequence{
            NSMutableArray*dataArray;//以可变数组存放节点数据
            int count;//节点数量
        }

        -(Sequence*)initSequenceList();
        -(void)insertData:(DataType)data;
        ....
        @end
        
### 21. 简述OPENGL ES 渲染流水线（未实现）

### 22. 谈谈如何编程实现一个2D动画系统（未实现）

### 23.  #import 跟#include 又什么区别,@class呢, #import<> 跟 #import””又什么区别? 

### 24. KVO 及其优势

### 25. NSNotification的同步和异步调用方法
- [NSNotification是同步还是异步？](https://blog.csdn.net/xubinlxb/article/details/52073803)

        当发送通知时，通知中心会一直等待所有的observer都收到并且处理了通知才会返回到poster；
        如果我们想改同步为异步，也是有办法的.
        办法1：
        让通知事件处理方法在子线程中执行
        办法2：
        可以通过NSNotificationQueue的enqueueNotification: postingStyle:和enqueueNotification: postingStyle: coalesceMask: forModes: 方法将通告放入队列，实现异步发送，在把通告放入队列之后，这些方法会立即将控制权返回给调用对象

### 26. 写一个工厂模式和单例模式。

### 27.在objective-c中，说明一下如何让一个函数或类变量成为一个私有的函数和类变量。
        category @private
- [Objective-C: 私有成员变量与私有方法](https://blog.csdn.net/u014268482/article/details/80580628)
    
        当在.h文件中未声明方法，只在.m文件中实现,此时无法在测试代码中向该对象方法发送调用消息。那么该方法则变成为对象的私有方法。
        私有方法与私有成员变量都不能被外界访问且显示，只能本类自己访问。

        注: 在@implementation中的成员变量与在@interface中声明的成员变量加上@private变量修饰符仍旧有地方不同: @interface中声明的成员变量加上@private变量修饰符虽然无法被外界访问到，但仍旧能被外界查看到
        
        重点: 在Objective-C没有真正的私有方法,对象可以通过选择器,调用对应的私有方法。原因: 因为OC中调用方法是消息机制，OC方法是动态绑定，只有在运行时才会去查看对象是否有该方法。
        
♠︎ #import 和 #include的区别.
#import是Objective-C导入头文件的关键字，#include是C/C++导入头文件的关键字,使用#import头文件会自动只导入一次，不会重复导入，相当于#include和#pragma once.
♠︎ @class的作用.
@class告诉编译器某个类的声明，当执行时，才去查看类的实现文件，可以解决头文件的相互包含的问题.
♠︎ #import<>和import””的区别.
#import<>用来包含系统的头文件，#import””用来包含用户头文件.
♠︎ import在其他语言和框架也有应用
比如 Python导入某块,ReactNative导入模块, java 导入Package都用import


### UIKit

### 1、写出iphone编程中常用控件类名（不用很准确，写出五个以上）

    UILabel,UITextField,UITextView,UIButton,UISwitch, UISegmentedControl,UISlider,UIImageView ,UIScrollView,UITableView,UITabBarController,UINavigationController 



### 3. viewController中的didReceiveMemoryWarning 啥时候调用，默认如何处理（百度笔试）
- [iOS UIViewController 对内存警告的处理经验](https://blog.csdn.net/zuoanlangren/article/details/21996625)

### 4. OC 写俩个线程，对同一个变量 分布进行 +/-操作（百度笔试）    

### 5. OC中frame与bounds有什么不同(百度笔试）

        Frame指的是：该view在父view坐标系统中的位置和大小（参照点是父类的坐标系统）
        Bounds指的是：该view在本身坐标系统中的位置和大小（参照点是本身的坐标系统）
        
### 6. OC中有无多重继承，如何实现多重继承（百度笔试） 

        没有多重继承。
        cocoa中所有的类都是NSObject的子类，多继承在这里是用protocl委托代理来实现的，所以我们不用去考虑繁琐的多继 承、虚基类的概念，多态特性在oc中拖过委托来实现。
        
### 7. 用OC写两个线程，对同一个变量 分别进行+/-操作（百度笔试）

- [在iOS中有几种方法来解决多线程访问同一个内存地址的互斥同步问题](https://blog.csdn.net/a_ellisa/article/details/51506233?utm_source=blogxgwz8)

### 8. OC中如何创建一个线程，要求可以一直工作，不会只执行一次就结束 （百度笔试）

- [两种方式：自动释放池和runloop](https://blog.csdn.net/jeffasd/article/details/51598086)
追问如何结束~？

### 9. 写一个你所经历的项目架构或cocoa里的MVC设计模式（百度笔试）

### 10. UIButton的继承结构（微享科技）

        UIButton-->UIControl-->UIView->UIResponder-->NSObject
        
### 11. NSOperation的并发被非并发的区别（微享科技）

- [链接](https://www.jianshu.com/p/813f7d58935d)

        如果需要自定义并发执行的 Operation，必须重写 start、main、isExecuting、isFinished、isAsynchronous 方法。
        在 operation 的 main 方法里面，必须提供 autorelease pool,因为你的 operation 完成后需要销毁。
        一旦你的 operation 开始了，必须通过 KVO，告诉所有的监听者，现在该operation的执行状态。
        调用时，如果需要并发执行 Operation，必须调用performOperation:方法，当然，也可以改为自定义其他方法或者直接在start方法添加多线程调用。
        对于自定义的 Operation 类，如果不需要并发执行，可以直接调用start方法.

### 12. [Objective-C中的@property和@synthesize用法](https://www.cnblogs.com/AnnieBabygn/p/7742628.html)     （微享科技） 

        synthesize可以自己定义
        
### 13. NSCoder是做什么的？（微享科技）        
    - [详细](https://www.jianshu.com/p/3a4a495a950a)

### 14. CAAnimation对代理是强引用的（微享科技）

        /* The delegate of the animation. This object is retained for the
        * lifetime of the animation object. Defaults to nil. See below for the
        * supported delegate methods. */
        @property(nullable, strong) id <CAAnimationDelegate> delegate;     

### 15. 关于iOS里IBOutlet对象的内存管理(微享科技)

        当加载nib文件的时候， table会被初始化，这时候它的retain count是1， 然后建立nib文件里对象的连接
        这时候会调用到你定义的属性的set方法， 因为你定义成了retain， 所以这时候table的retain count变成了2, 属性的getter/setter会用到autorelease，这时候就会变成3！
        推荐IBoutlet的属性定义成assign（weak）就可以了！

### 16. IOS开发之如何自定义UITabBarController（班德尔笔试题）
- [详解](https://www.cnblogs.com/jerehedu/p/5141270.html)

### 17.你用过动画效果吗？请举例说明 ？（班德尔笔试题）
- [详解](https://blog.csdn.net/aaaaazq/article/details/80736594)

### 18.  实现一个cell,有标题和内容 （班德尔笔试题）
- [详解](https://www.cnblogs.com/soley/p/5418544.html)

### 19. 解释一下http，如何下载一张图片代码实现 （班德尔笔试题）

- [iOS开发—使用GCD下载图片](https://blog.csdn.net/shichunxue/article/details/78495630)
- [iOS 加载高清大图片](https://www.jianshu.com/p/52e3535dd37c)

### 20. 简述对view，viewcontroller, calayer和window的理解（班德尔笔试题）
- [详解](https://blog.csdn.net/yoyo_lzj/article/details/50682280?utm_source=blogxgwz6)

### 21. InitWithNibName：boundle；/dealloc/loadView/viewDidLoad/viewDidUnload 调用顺序，每个方法应该做的工作是什么？（福西）

*  [macOS 和 iOS 中 Nib 文件实现原理以及最佳实践](https://www.jianshu.com/p/d937da4b27cc)
*  [iOS程序执行顺序和UIViewController 的生命周期(整理)](https://www.jianshu.com/p/d60b388b19f5)

### 22. 说明UiView 类属性 frame/center/bounds的联系与区别，改变bounds的值会不会对frame和center造成改变。（福西）
- [详解UIView的frame、bounds和center属性](https://www.jianshu.com/p/c16c32c45862)

        Frame指的是：该view在父view坐标系统中的位置和大小（参照点是父类的坐标系统）
        Bounds指的是：该view在本身坐标系统中的位置和大小（参照点是本身的坐标系统）
        center：描述当前视图的中心点在其父视图中的位置。
        改变 bounds
        1. 它可以修改自己坐标系的原点位置，影响“子view”的显示位置。
        2. bounds，它可以通过改变宽高，改变自身的frame，进而影响到再父视图的显示位置和大小。
        3. 如果一个固定大小的View 被做成动画来回移动，frame会变化，但是bounds不会变化
- [bounds改变的影响](https://www.jianshu.com/p/7973f69dc920)



### 23. 如何调用UIView的drawRect消息
#### layoutSubviews在以下情况下会被调用：
        1、init初始化不会触发layoutSubviews。
        2、addSubview会触发layoutSubviews。
        3、设置view的Frame会触发layoutSubviews，当然前提是frame的值设置前后发生了变化。
        4、滚动一个UIScrollView会触发layoutSubviews。
        5、旋转Screen会触发父UIView上的layoutSubviews事件。
        6、改变一个UIView大小的时候也会触发父UIView上的layoutSubviews事件。
        7、直接调用setLayoutSubviews。

#### drawRect在以下情况下会被调用：
    1、如果在UIView初始化时没有设置rect大小，将直接导致drawRect不被自动调用。drawRect 掉用是在Controller->loadView,    Controller->viewDidLoad 两方法之后掉用的.所以不用担心在 控制器中,这些View的drawRect就开始画了.这样可以在控制器中    设置一些值给View(如果这些View draw的时候需要用到某些变量 值).
    2、该方法在调用sizeToFit后被调用，所以可以先调用sizeToFit计算出size。然后系统自动调用drawRect:方法。
    3、通过设置contentMode属性值为UIViewContentModeRedraw。那么将在每次设置或更改frame的时候自动调用drawRect:。
    4、直接调用setNeedsDisplay，或者setNeedsDisplayInRect:触发drawRect:，但是有个前提条件是rect不能为0。
    以上1,2推荐；而3,4不提倡

#### drawRect方法使用注意点：
    1、 若使用UIView绘图，只能在drawRect：方法中获取相应的contextRef并绘图。如果在其他方法中获取将获取到一个   invalidate 的ref并且不能用于画图。drawRect：方法不能手动显示调用，必须通过调用setNeedsDisplay 或 者   setNeedsDisplayInRect，让系统自动调该方法。
    2、若使用calayer绘图，只能在drawInContext: 中（类似鱼drawRect）绘制，或者在delegate中的相应方法绘制。同样也是调 用setNeedDisplay等间接调用以上方法
    3、若要实时画图，不能使用gestureRecognizer，只能使用touchbegan等方法来掉用setNeedsDisplay实时刷新屏幕

### 24. UIView和ViewController的关系
 
        UIView是IOS中所有可视化控件的基类，比如UIButton，UITextField等，而UIViewController从字面意思可以看出，它是UIView的控制器，也就是管理者。它负责UIView的的创建，销毁，显示，隐藏，用户事件的处理响应。从UIViewController的头文件中可以看到，它有一个成员变量UIView *_view，其实这个变量就对应着.xib或storybard文件中的要类view。
### 25.[UILabel的文字在左上角显示](https://www.jianshu.com/p/6f3048db8f64) 

    重载textRectForBounds方法和drawTextInRect方法
    - (id)initWithFrame:(CGRect)frame {
        return [super initWithFrame:frame];
    }
    - (CGRect)textRectForBounds:(CGRect)bounds limitedToNumberOfLines:(NSInteger)numberOfLines {
        CGRect textRect = [super textRectForBounds:bounds limitedToNumberOfLines:numberOfLines];
        textRect.origin.y = bounds.origin.y;
        return textRect;
    }
    -(void)drawTextInRect:(CGRect)requestedRect {
        CGRect actualRect = [self textRectForBounds:requestedRect limitedToNumberOfLines:self.numberOfLines];
        [super drawTextInRect:actualRect];
    }


### 26. Objective-C 若有一个表有1000行,每一行包含一个不同的图像,每一个图像都是从不同的网址URL下载，您将采取什么方法，以保证表内图像滚动尽可能顺利。

    1）图片异步下载，回调到主线程更新UI
    2）图片是缓存到沙盒目录的，不必每次都会下载
    3）cell等高的复用Cell,cell不等高的话，将每一行的高度缓存
        
### 27. 

        

## Other

### 2. 你通常以怎样的数据格式跟服务端做数据交换 （九州瑞研）

        JSON、XML,   
        Sbjson/touchjson/   开源库
        Gdata, 
        主要使用http协议  

### 3. 你了解的第三方库，常用哪些 Framework      （九州瑞研） 

        ASIHTTPRrequest、TXML、TouchJSON、MBProgressHUD、 、FMDB、ZBarSDK、MinZIP





## iOS SDK

1. 如何实现Push 通知的机制（大致写下）

2. Key-Value Coding是什么？

        KVC是通过字符串标识符间接访问对象属性和关系的机制。
3. 说说Auto Release Pool，内存管理模式, GC, retain count     

        auto release pool内存自动释放池。放到池中的会在失效后自动释放
        内存管理模式：可以手动申请释放，使用auto release pool，使用ARC
        GC：Gabbage Collector垃圾回收 
        iOS 有没有GC Gabage Collector垃圾回收机制 mac os x 有 ios没有
        retain count：内存计数器
