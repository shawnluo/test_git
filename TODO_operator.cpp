#include <iostream>


/*
运算符重载是为了解决类对象之间的运算的，通常的运算符只用于算术运算，如常量int之间，因为编译器已经定义了；
而一个类两个对象之间成员进行运算必须重新定义，让编译器在遇到对象运算时能按我们要求的进行运算，这就是运算符重载的意义，
即重定义运算符，
因此你可以看到，运算符重载就是为类对象服务的，那么两个对象的成员进行运算那必须先获得对象本身啦，
所以运算符重载参数必须含有类指针或引用，这是主要客户。 

运算符重载的声明operator 关键字告诉 编译器，它是一个运算符重载，后面是相关运算符的符号，如+。
返回类型是在使用这个运算符时获得的类型。对于这个+运算符重载，返回类型与包含类一样，但这种情况并不是必需的。
两个参数就是要操作的对象。
对于二元运算符（带两个参数），如+和－运算符，第一个参数是放在运算符左边的值，第二个参数是放在运算符右边的值。
*/

// 1.重载为类的成员函数

class complex
{
public:
    complex() {
        real = image = 0;
    }

    complex(double r, double i) {
        real = r;
        image = i;
    }
    complex operator+(const complex &c);
    complex operator-(const complex &c);
    complex operator*(const complex &c);
    complex operator/(const complex &c);
    friend void printf(const complex &c);

private:
    double real, image;
};

inline complex complex::operator+(const complex &c) {
    return complex(real + c.real, image + c.image);
}

inline complex complex::operator-(const complex &c) {
    return complex(real - c.real, image - c.image);
}

inline complex complex::operator*(const complex &c) {
    return complex(real * c.real - image * c.image, real * c.image + image * c.real);
}

inline complex complex::operator/(const complex &c) {
    return complex((real * c.real + image * c.image) / (c.real * c.real + c.image * c.image),
                   (image * c.real - real * c.image) / (c.real * c.real + c.image * c.image));
}


int main(void) {
    complex d1(1, 2);
    complex d2(3, 4);
    complex d3;

    d3 = d1 + d2;
    // cout << complex.print

    return 0;
}

#if 0
// 2.重载为类的友员函数

#include <iostream.h>

    class complex
{
public:
    complex()
    {
        real = image = 0;
    }
    complex(double r, double i)
    {
        real = r;
        image = i;
    }
    friend complex operator+(const complex &c1, const complex &c2);
    friend complex operator-(const complex &c1, const complex &c2);
    friend complex operator*(const complex &c1, const complex &c2);
    friend complex operator/(const complex &c1, const complex &c2);
    friend void printf(const complex &c);

private:
    double real, image;
};
inline complex complex::operator+(const complex &c1, const complex &c2)
{
    return complex(c1.real + c2.real, c1.image + c2.image);
}
inline complex complex::operator-(const complex &c1, const complex &c2)
{
    return complex(c1.real - c2.real, c1.image - c2.image);
}
inline complex complex::operator*(const complex &c1, const complex &c2)
{
    return complex(c1.real * c2.real - c1.image * c2.image, c1.real * c2.image + c1.image * c2.real);
}
inline complex complex::operator/(const complex &c1, const complex &c2)
{
    return complex((c1.real * c2.real + c1.image * c2.image) / (c2.real * c2.real + c2.image * c2.image),
                   (c1.image * c2.real - c1.real * c2.image) / (c2.real * c2.real + c2.image * c2.image));
}
#endif