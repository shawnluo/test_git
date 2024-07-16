#include <iostream>
class Shape {
public:
    virtual void draw() const = 0;
    int data = 100;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Circle" << std::endl;
        data = 1000;    // ng
    }
};

class Rectangle:public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Rectangle" << std::endl;
    }
};

int main(void) {
    Circle circle;
    Rectangle rectangle;

    Shape* ptrShape = &circle;
    ptrShape->draw();

    ptrShape = &rectangle;
    ptrShape->draw();

    return 0;
}