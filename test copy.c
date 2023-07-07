#include <iostream>
 // Abstract base class
class Shape {
public:
    // Pure virtual function
    virtual double area() const = 0;
};
 // Derived class
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
     // Implementation of the pure virtual function
    double area() const override {
        return length * width;
    }
};
 // Derived class
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
     // Implementation of the pure virtual function
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.5);
     // Accessing the area of rectangle and circle through base class pointers
    Shape* shape1 = &rectangle;
    Shape* shape2 = &circle;
     std::cout << "Area of rectangle: " << shape1->area() << std::endl;
    std::cout << "Area of circle: " << shape2->area() << std::endl;
     return 0;
}