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
    float getResult() {
        return this->result;
    }

    float calculateArea(Shape& S) {
        S.getArea();
        return 0.0;
    }
};



int main(void) {
    Shape *shape;
    AreaCaculator calc;

    Triangle tri;
    shape = &tri;
    shape->getArea();
    calc.calculateArea(tri);

    Circle cir;
    shape = &cir;
    shape->getArea();
    calc.calculateArea(cir);

    return 0;
}