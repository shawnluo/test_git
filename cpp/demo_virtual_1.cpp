#include <iostream>
using namespace std;


class Shape {
public:
    virtual float getArea() = 0;
};


class Triangle: public Shape {
public:
    float getArea() {
        cout << "Triangle" << endl;
        return 0.0;
    }
};


class Circle: public Shape {
public:
    float getArea() {
        cout << "Circle" << endl;
        return 0.0;
    }
};


class AreaCaculator {
private:
    float result;

public:
    float getResult() const {
        return this->result;
    }

    float calculateArea(Shape& S) { // 注意： Must use reference, cannot declare paramter 'S'
                                    // to be of abstract type 'Shape'
        S.getArea();
        return 0.0;
    }
};



int main(void) {
    // Shape *shape;   // A class having a pure virtual function cannot be instantiated. 
                    // eg. The object of abstract class cannot be created.
                    // However, a pointer to the abstract base class or abstract class can be created

    // 0. basic. 直接实例化子类
    Triangle tri;
    tri.getArea();

    // 1. 使用基类Shape来调用子类的getArea()
    Shape *shape;  // 注意： 这里一定要用指针来实例化抽象类
    Triangle tri;
    shape = &tri;
    shape->getArea();

    // 2. 将子类Tri作为"Shape& S"类型传给AreaCaculator。跟第一种情况本质是一样的。
    AreaCaculator calc;
    Triangle tri;
    calc.calculateArea(tri); // 注意：写calculateArea()函数时，参数类型一定要是引用

    return 0;
}