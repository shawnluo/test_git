# C++11的智能指针与垃圾回收

### **1.智能指针为什么存在？**

因为C++没有自动回收内存的机制，因此每一次new出来的动态内存必须手动delete回去。而智能指针可以解决这个问题。

## **2.智能指针的大致描述是什么？**

智能指针：自动负责释放所指向的对象，实际上它利用了栈的机制，每一个智能指针都是一个模板类，调用智能指针实际上是创建了一个智能指针的对象，对象生命周期到达尽头的时候，会自动调用智能指针的析构函数，在析构函数里，释放掉它管理的内存，从而避免手动delete。

## 3. weak_ptr

和 shared_ptr、unique_ptr 类型指针一样，weak_ptr 智能指针也是以模板类的方式实现的。`weak_ptr<T>`（ T 为指针所指数据的类型）定义在 `<memory>`头文件，并位于 std 命名空间中。

该类型指针通常不单独使用（没有实际用处），只能和 shared_ptr 类型指针搭配使用。可以视为 shared_ptr 指针的一种辅助工具。借助 weak_ptr 类型指针可以获取 shared_ptr 指针的一些状态信息，比如有多少指向相同的 shared_ptr 指针、通过 `expired()`判断shared_ptr 指针指向的堆内存是否已经被释放等等。

weak_ptr 类型指针并不会影响所指堆内存空间的引用计数。当 weak_ptr 指针的指向和某一 shared_ptr 指针相同时，weak_ptr 指针并不会使所指堆内存的引用计数加 1；同样，当 weak_ptr 指针被释放时，之前所指堆内存的引用计数也不会因此而减 1。它不具有普通指针的行为，没有重载 `operator*`和 `->`，这也就意味着，weak_ptr 类型指针只能访问所指的堆内存，而无法修改它。

weak_ptr可以使用一个非常重要的成员函数 `lock()`从被观测的shared_ptr获得一个可用的shared_ptr对象， 从而操作资源。但当 `expired()==true`的时候，`lock()`函数将返回一个存储空指针的shared_ptr。

## 简单例子

### 五种智能指针指向数组的方法

```c++
shared_ptr 与 deleter (函数对象)
template<typename T>
struct array_deleter {
	void operator()(T const* p)
	{
		delete[] p;
	}
};

std::shared_ptr<int> sp(new int[10], array_deleter<int>());
shared_ptr 与 deleter (lambda 表达式)
std::shared_ptr<int> sp(new int[10], [](int* p) {delete[]p; });
shared_ptr 与 deleter ( std::default_delete)
std::shared_ptr<int> sp(new int[10], std::default_delete<int[]>());
使用 unique_ptr
std::unique_ptr<int[]> up(new int[10]); //@ unique_ptr 会自动调用 delete[]
使用 vector<int>
typedef std::vector<int> iarray;
std::shared_ptr<iarray> sp(new iarray(10));
```


### 数组的智能指针的限制

unique_ptr 的数组智能指针，没有* 和 -> 操作，但支持下标操作[]。
shared_ptr 的数组智能指针，有 * 和 -> 操作，但不支持下标操作[]，只能通过 get() 去访问数组的元素。
**shared_ptr 的数组智能指针，必须要自定义deleter。**

```c++
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class test{
public:
  explicit test(int d = 0) : data(d){cout << "new" << data << endl;}
  ~test(){cout << "del" << data << endl;}
  void fun(){cout << data << endl;}
public:
  int data;
};
unique_ptr 与数组：

int main()
{
	unique_ptr<test[]> up(new test[2]);
	up[0].data = 1;
	up[1].data = 2;
	up[0].fun();
	up[1].fun();

	return 0;
}
shared_ptr 与数组：

int main()
{
	shared_ptr<test[]> sp(new test[2], [](test *p) { delete[] p; });
	(sp.get())->data = 2;
	(sp.get()+1)->data = 3;

	(sp.get())->fun();
	(sp.get()+1)->fun();

	return 0;
}
```


```c++



class myClass {
public:
	myClass() {
		cout << "Constructor invoked" << endl;
	}
	~myClass() {
		cout << "Desstructor invoked" << endl;
	}
};

/* 初始smart ptr的方法：
	shared_ptr<myClass> shPtr1 = make_shared<myClass>(); // 不能分开定义。如先定义shPtr1，然后再调用make_shared，是非法的。
	unique_ptr<int>shPtr1(new int(25));	// 另一种初始化的方法

	auto p = make_unique<int[]>(5);	// 创造指针数组p, 成员数有5个
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] = 5;
	auto p = make_shared<int[]>(5);	// 只被高版本c++ 17及以上才支持。未尝试成功！
*/




int main() {
	// 1. shared ptr
	shared_ptr<myClass> shPtr1 = make_shared<myClass>(); // 不能分开定义。如先定义shPtr1，然后再调用make_shared，是非法的。
	unique_ptr<int>shPtr1(new int(25));	// 另一种初始化的方法

	cout << "Shared count" << shPtr1.use_count() << endl;

	shared_ptr<myClass> shPtr2 = shPtr1;
	cout << "Shared count" << shPtr1.use_count() << endl;

	// 2. unique ptr
	unique_ptr<int> unPtr1 = make_unique<int>(168);
	cout << *unPtr1 << endl;	// 168

	unique_ptr<int> unPtr2 = unPtr1;	// fail
	unique_ptr<int> unPtr2 = move(unPtr1);  // move owership of pointing to 168 to unPtr2
	cout << *unPtr1 << endl;	// fail
	cout << *unPtr2 << endl;	// 168

	// unique ptr
	{
	unique_ptr<myClass> unPtr1 = make_unique<myClass>();
	unique_ptr<int> unPtr2 = unPtr1;	// fail
	}	// destructor function will be called when meeting right bracket "}".

	// 3. weak_ptr
	weak_ptr<int> wePtr;
	{
	shared_ptr<int>shPtr = make_shared<int>(25);
	wePtr = shPtr;
	cout << wePtr.expired() << endl;	// 0   shPtr没有释放
	cout << shPtr.use_count() << endl;	// 1
	cout << wePtr.use_count() << endl;	// 1

	wePtr.reset();
	cout << wePtr.use_count() << endl;	// 0
	cout << shPtr.use_count() << endl;	// 1

	shared_ptr<int> sh_ptr = wePtr.lock();
	cout << *sh_ptr << " " << *shPtr << endl;	// 25 25
	*sh_ptr = 100;
	cout << *sh_ptr << " " << *shPtr << endl;	// 100 100
	}
	cout << wePtr.expired() << endl;	// 1	shPtr已经释放了

	cout << "exit main" << endl;
	return 0;
}
```

## 一、share_ptr

share_ptr是C++11新添加的智能指针，它限定的资源可以被多个指针共享。

 **只有指向动态分配的对象的指针才能交给 shared_ptr 对象托管。** 将指向普通局部变量、全局变量的指针交给 shared_ptr 托管，编译时不会有问题，但程序运行时会出错，因为不能析构一个并没有指向动态分配的内存空间的指针。

```c++
int main(void) {
    shared_ptr<string> pa(new string("CHN"));
    shared_ptr<string> pb(new string("USA"));

    cout << "*pa: " << *pa << endl;
    cout << "pa.use_count: " << pa.use_count() << endl; // 1

    cout << "*pb: " << *pb << endl;
    cout << "pb.use_count: " << pb.use_count() << endl; // 1

    pa = pb;
    cout << *pa << endl;
    cout << pa.use_count() << endl; // 2：pa 和 pb指向同一个资源 USA了，该资源的计数为2，所以pb、pb都输出2
    cout << pb.use_count() << endl;

    pa.reset();
    pb.reset();
    cout << pa.use_count() << endl;
    cout << pb.use_count() << endl;

    /* 
        下面是不合法的:
        p1 和 p2 并不会共享同一个对p的托管计数。而是各自将对p的托管技术都记为1，因为 p2 无法知道 p 已经被 p1 托管过。
        这样，当 p1 消亡时要析构 p，p2 消亡时要再次析构 p，这会导致程序崩溃。
     */
    string* p = new string("abc");
    // shared_ptr<string> p1(p), p2(p);
    shared_ptr<string> p1(p);
    shared_ptr<string> p2(p);

    return 0;
}
```

## 二、weak_ptr

　　weak_ptr是一种用于解决shared_ptr相互引用时产生死锁问题的智能指针。如果有两个shared_ptr相互引用，那么这两个shared_ptr指针的引用计数永远不会下降为0，资源永远不会释放。weak_ptr是对对象的一种弱引用，它不会增加对象的use_count，weak_ptr和shared_ptr可以相互转化，shared_ptr可以直接赋值给weak_ptr，weak_ptr也可以通过调用lock函数来获得shared_ptr。

1. **weak_ptr指针通常不单独使用，只能和 shared_ptr 类型指针搭配使用。将一个weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数。一旦最后一个指向对象的shared_ptr被销毁，对象就会被释放。即使有weak_ptr指向对象，对象也还是会被释放。**
2. **weak_ptr并没有重载operator->和operator *操作符，因此不可直接通过weak_ptr使用对象，典型的用法是调用其lock函数来获得shared_ptr示例，进而访问原始对象。**

　　先看一下两个shared_ptr指针互相引用导致的资源释放失败的例子

```cpp
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class B;
class A {
public:
    shared_ptr<B> pb_;
    ~A() {
        cout << "A delete\n";
    }
};
class B {
public:
    shared_ptr<A> pa_;
    ~B() {
        cout << "B delete\n";
    }
};

void fun() {
    shared_ptr<B> pb(new B());
    cout << "pb.use_count " << pb.use_count() << endl;//1
    shared_ptr<A> pa(new A());
    cout << "pa.use_count " << pa.use_count() << endl;//1

    pb->pa_ = pa;
    cout << "pb.use_count " << pb.use_count() << endl;//1
    cout << "pa.use_count " << pa.use_count() << endl;//2
    pa->pb_ = pb;
    //由于share_ptr是共享资源，所以pb所指向的资源的引用计数也会加1
    cout << "pb.use_count " << pb.use_count() << endl;//2
    cout << "pa.use_count " << pa.use_count() << endl;//2
}//程序结束时，没有调用A和B的析构函数

int main() {
    fun();
    system("pause");
    return 0;
}
```

输出结果：

```text
pb.use_count 1
pa.use_count 1
pb.use_count 1
pa.use_count 2
pb.use_count 2
pa.use_count 2
```

函数结束时，没有调用A和B的析构函数。

这就需要使用weak_ptr：把A中的shared_ptr `<B>` pb_改为weak_ptr `<B>` pb_weak，这样改为了弱引用，传递时不会增加pb引用计数use_count()的值，所以最终能够使A、B资源正常释放：

```cpp
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class B;
class A {
public:
    weak_ptr<B> pb_weak;
    ~A() {
        cout << "A delete\n";
    }
};
class B {
public:
    shared_ptr<A> pa_;
    ~B() {
        cout << "B delete\n";
    }
    void print() {
        cout << "This is B" << endl;
    }
};

void fun() {
    shared_ptr<B> pb(new B());
    cout << "pb.use_count " << pb.use_count() << endl;//1
    shared_ptr<A> pa(new A());
    cout << "pa.use_count " << pa.use_count() << endl;//1

    pb->pa_ = pa;
    cout << "pb.use_count " << pb.use_count() << endl;//1
    cout << "pa.use_count " << pa.use_count() << endl;//2

    pa->pb_weak = pb;
    cout << "pb.use_count " << pb.use_count() << endl;//1：弱引用不会增加所指资源的引用计数use_count()的值
    cout << "pa.use_count " << pa.use_count() << endl;//2

    shared_ptr<B> p = pa->pb_weak.lock();
    p->print();//不能通过weak_ptr直接访问对象的方法，须先转化为shared_ptr
    cout << "pb.use_count " << pb.use_count() << endl;//2
    cout << "pa.use_count " << pa.use_count() << endl;//2
}//函数结束时,调用A和B的析构函数

//资源B的引用计数一直就只有1，当pb析构时，B的计数减一，变为0，B得到释放，
//B释放的同时也会使A的计数减一，同时pa自己析构时也会使资源A的计数减一，那么A的计数为0，A得到释放。


int main() {
    fun();
    system("pause");
    return 0;
}
```

输出结果：

```text
pb.use_count 1
pa.use_count 1
pb.use_count 1
pa.use_count 2
pb.use_count 1
pa.use_count 2
This is B
pb.use_count 2
pa.use_count 2
B delete
A delete
```

函数结束时，调用A和B的析构函数

## 三、unique_ptr

　　unique_ptr 是一个独享所有权的智能指针，它提供了严格意义上的所有权。它取代了C++98中的auto_ptr。

unique_ptr对象包装一个原始指针，并负责其生命周期。当该对象被销毁时，会在其析构函数中删除关联的原始指针。

unique_ptr具有->和*运算符重载符，因此它可以像普通指针一样使用。

```cpp
#include <iostream>
#include <memory>
using namespace std;

struct Task {
    int mId;
    Task(int id) :mId(id) {
        cout << "Task::Constructor" << endl;
    }
    ~Task() {
        cout << "Task::Destructor" << endl;
    }
};

int main() {
    // 通过原始指针创建 unique_ptr 实例
    //shared_ptr<Task> taskPtr(new Task(23));
    //int id = taskPtr->mId;

    //调用其lock函数来获得shared_ptr示例，进而访问原始对象。
    //weak_ptr<Task> weak1 = taskPtr;
    //int id = weak1.lock()->mId;

    unique_ptr<Task> taskPtr(new Task(23));
    int id = taskPtr->mId;

    cout << id << endl;

    return 0;
}
```

不管函数正常退出还是异常退出（由于某些异常），也会始终调用taskPtr的析构函数。因此，原始指针将始终被删除并防止内存泄漏。

输出结果：

```text
Task::Constructor
23
Task::Destructor
```

todo:

https://zhuanlan.zhihu.com/p/438238972

    C++智能指针出现是为了解决由于支持动态内存分配而导致的一些C++内存问题，比如内存泄漏，对象生命周期的管理，悬挂指针（dangling pointer）/空指针等问题；
    C++智能指针通过RAII设计模式去管理对象生命周期（动态内存管理），提供带少量异常类似普通指针的操作接口，在对象构造的时候分配内存，在对象作用域之外释放内存，帮助程序员管理动态内存；
    老的智能指针**auto_ptr**由于设计语义不好而导致很多不合理问题：不支持复制（拷贝构造函数）和赋值（operator =），但复制或赋值的时候不会提示出错。因为不能被复制，所以不能被放入容器中。而**被C++11弃用（deprecated），**引入 unique_ptr 来替代 auto_ptr**。

### unique_ptr

unique_ptr由C++11引入，旨在替代不安全的auto_ptr。unique_ptr是一种定义在< memory>中的智能指针。它持有对对象的独有权——两个unique_ptr不能指向一个对象，即unique_ptr不共享它的所管理的对象。它无法复制到其他unique_ptr，无法通过值传递到函数，也无法用于需要副本的任何标准模板库 （STL）算法。只能移动 unique_ptr，即对资源管理权限可以实现转移。这意味着，内存资源所有权可以转移到另一个unique_ptr，并且原始 unique_ptr 不再拥有此资源。实际使用中，建议将对象限制为由一个所有者所有，因为多个所有权会使程序逻辑变得复杂。因此，当需要智能指针用于纯 C++ 对象时，可使用 unique_ptr，而当构造 unique_ptr 时，可使用 make_unique Helper 函数。

下图演示了两个 unique_ptr 实例之间的所有权转换。

这里写图片描述

![](https://pic2.zhimg.com/80/v2-0ee71e7dd3c1acb8d9eaafc8efc23421_720w.webp)

unique_ptr与原始指针一样有效，并可用于 STL 容器。将 unique_ptr 实例添加到 STL 容器很有效，因为通过 unique_ptr 的移动构造函数，不再需要进行复制操作。unique_ptr 指针与其所指对象的关系：在智能指针生命周期内，可以改变智能指针所指对象，如创建智能指针时通过构造函数指定、通过 reset 方法重新指定、通过 release 方法释放所有权、通过移动语义转移所有权，unique_ptr 还可能没有对象，这种情况被称为 empty。

#### unique_ptr 的基本操作有：

```c++
//智能指针的创建 
unique_ptr<int> u_i; //创建空智能指针
u_i.reset(new int(3)); //"绑定”动态对象 
unique_ptr<int> u_i2(new int(4));//创建时指定动态对象
unique_ptr<T,D> u(d);    //创建空unique_ptr,执行类型为T的对象，用类型为D的对象d来替代默认的删除器delete
 
//所有权的变化 
int *p_i = u_i2.release(); //释放所有权 
unique_ptr<string> u_s(new string("abc")); 
unique_ptr<string> u_s2 = std::move(u_s); //所有权转移(通过移动语义)，u_s所有权转移后，变成“空指针”
u_s2.reset(u_s.release());//所有权转移
u_s2=nullptr;//显式销毁所指对象，同时智能指针变为空指针。与u_s2.reset()等价
```

```c++
#include <iostream>
#include <string>
#include <memory>
using namespace std;
 
int main() {
    auto_ptr<string> films[5] ={
    	auto_ptr<string> (new string("Fowl Balls")),
        auto_ptr<string> (new string("Duck Walks")),
        auto_ptr<string> (new string("Chicken Runs")),
        auto_ptr<string> (new string("Turkey Errors")),
        auto_ptr<string> (new string("Goose Eggs"))
    };
  
    auto_ptr<string> pwin;
    // unique_ptr<string> pwin;   // fix it by using unique_ptr
    pwin = films[2]; // films[2] loses ownership. 将所有权从films[2]转让给pwin，此时films[2]不再引用该字符串从而变成空指针

    cout << "The nominees for best avian baseballl film are\n";
    for(int i = 0; i < 5; ++i) {
        cout << *films[i] << endl;
    }
     cout << "The winner is " << *pwin << endl;
    return 0;
}
```

```c++
#include <iostream>
#include <memory>
// using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::make_unique;
using std::make_shared;
using std::move;

class Song {
public:
    int duration;
    Song(string s1, string s2) : duration(5) {
        this->duration = s1.length() + s2.length();
    }
};

void UseRawPointer() {
    Song* pSong = new Song("Nothing on You", "Bruno Mars");
    delete pSong;
}

void UseSmartPointer() {
    // 1. unique_ptr - using new
    unique_ptr<Song> song2(new Song("show me", "the money!"));
    auto len = song2->duration;
    std::cout << len << std::endl;

    auto song3 = std::move(song2);
    len = song3->duration;
    std::cout << len << std::endl;

    // 2. unique_ptr - using make_unique
    auto song4 = make_unique<Song>("good", "bad");
    unique_ptr<Song> song5 = std::move(song4);

    // 3. shared_ptr - using new
    shared_ptr<Song> song_sp1(new Song("1", "2"));

    // 4. shared_ptr - using make_shared
    auto song_sp2 = make_shared<Song>("2", "3");
    cout << song_sp2.use_count() << endl;
    {
        auto song_sp3 = song_sp2;
        cout << song_sp3.use_count() << endl;
    }
    cout << song_sp2.use_count() << endl;

    // 5. weak_ptr
    weak_ptr<int> wp1;
    {
        shared_ptr<int>sp1 = make_shared`<int>`(25);
        wp1 = sp1;
        cout << "wp1.expired(): " << wp1.expired() << endl;
        cout << *sp1 << endl;
        weak_ptr<int> wp2(sp1);
        cout << wp2.expired() << endl;
    }
    cout << "wp1.expired(): " << wp1.expired() << endl;
}

int main(void) {
    UseRawPointer();
    UseSmartPointer();

    return 0;
}
```
