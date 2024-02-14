explicit、implicit关键字详解

我们首先需要知道，explicit只能用来修饰只有一个参数的构造函数。

它的作用是表明该构造函数是显式的, 而非隐式的，跟它对应的另一个关键字是implicit，意思是隐藏的，类构造函数默认情况下即声明为implicit(隐式)。

那么它们的作用是什么呢？

我们通过代码看一下：

```c++
class CxString  // 没有使用explicit关键字的类声明, 即默认为隐式声明
{
public:
    char *_pstr;
    int _size;
    CxString(int size)
    {
    _size = size;                // string的预设大小
    _pstr = malloc(size + 1);    // 分配string的内存
    memset(_pstr, 0, size + 1);
    }
    CxString(const char *p)
    {
    int size = strlen(p);
    _pstr = malloc(size + 1);    // 分配string的内存
    strcpy(_pstr, p);            // 复制字符串
    _size = strlen(_pstr);
    }
    // 析构函数这里不讨论, 省略...
};

    // 下面是调用:

    CxString string1(24);     // 这样是可以的, 为CxString预分配24字节的大小的内存
    CxString string2 = 10;    // 这样是可以的, 为CxString预分配10字节的大小的内存
    CxString string3;         // 这样是不行的, 因为没有默认构造函数, 错误为: “CxString”: 没有合适的默认构造函数可用
    CxString string4("aaaa"); // 这样是可以的
    CxString string5 = "bbb"; // 这样也是可以的, 调用的是CxString(const char *p)
    CxString string6 = 'c';   // 这样也是可以的, 其实调用的是CxString(int size), 且size等于'c'的ascii码
    string1 = 2;              // 这样也是可以的, 为CxString预分配2字节的大小的内存
    string2 = 3;              // 这样也是可以的, 为CxString预分配3字节的大小的内存
    string3 = string1;        // 这样也是可以的, 但是只是编译没问题, 如果析构函数里用free释放_pstr内存指针的时候可能会报错, 完整的代码必须重载运算符"=", 并在其中处理内存释放
```


有人肯定会疑惑，上面的代码中, “CxString string2 = 10;” 这句为什么是可以的呢?
在C++中, 如果的构造函数只有一个参数时，那么在编译的时候就会有一个缺省的转换操作：
将该构造函数对应数据类型的数据转换为该类对象。也就是说 “CxString string2 = 10;” 这段代码, 编译器自动将整型转换为CxString类对象, 实际上等同于下面的操作:

CxString string2(10);
或
CxString temp(10);
CxString string2 = temp;

但是, 上面的代码中的_size代表的是字符串内存分配的大小，那么调用的第二句 “CxString string2 = 10;” 和第六句 “CxString string6 = ‘c’;” 就显得不伦不类，而且容易让人疑惑，可读性太低。

**有什么办法阻止这种用法呢? 答案就是使用explicit关键字。**

如下：

```c++
class CxString  // 使用关键字explicit的类声明, 显示转换
{
public:
    char *_pstr;
    int _size;
    explicit CxString(int size)
    {
    _size = size;
    // 代码同上, 省略...
    }
    CxString(const char *p)
    {
    // 代码同上, 省略...
    }
};

// 下面是调用:

    CxString string1(24);     // 这样是可以的
    CxString string2 = 10;    // 这样是不行的, 因为explicit关键字取消了隐式转换
    CxString string3;         // 这样是不行的, 因为没有默认构造函数
    CxString string4("aaaa"); // 这样是可以的
    CxString string5 = "bbb"; // 这样也是可以的, 调用的是CxString(const char *p)
    CxString string6 = 'c';   // 这样是不行的, 其实调用的是CxString(int size), 且size等于'c'的ascii码, 但explicit关键字取消了隐式转换
    string1 = 2;              // 这样也是不行的, 因为取消了隐式转换
    string2 = 3;              // 这样也是不行的, 因为取消了隐式转换
    string3 = string1;        // 这样也是不行的, 因为取消了隐式转换, 除非类实现操作符"="的重载
```


上面说过，explicit关键字只对有一个参数的类构造函数有效，如果类构造函数参数大于或等于两个时，是不会产生隐式转换的，所以explicit关键字也就无效了。

但是有一个例外，当除了第一个参数以外的其他参数都有默认值的时候，explicit关键字依然有效，此时，当调用构造函数时只传入一个参数，等效于只有一个参数的类构造函数。

举例如下:

```c++
class CxString  // 使用关键字explicit声明
{
public:
    int _age;
    int _size;
    explicit CxString(int age, int size = 0)
    {
    _age = age;
    _size = size;
    // 代码同上, 省略...
    }
    CxString(const char *p)
    {
    // 代码同上, 省略...
    }
};

    // 下面是调用:

    CxString string1(24);     // 这样是可以的
    CxString string2 = 10;    // 这样是不行的, 因为explicit关键字取消了隐式转换
    CxString string3;         // 这样是不行的, 因为没有默认构造函数
    string1 = 2;              // 这样也是不行的, 因为取消了隐式转换
    string2 = 3;              // 这样也是不行的, 因为取消了隐式转换
    string3 = string1;        // 这样也是不行的, 因为取消了隐式转换, 除非类实现操作符"="的重载
```
