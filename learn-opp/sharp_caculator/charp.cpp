#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Shape
{
public:
    virtual double calculateArea()=0;
    virtual double calculatePerimeter()=0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    private:
        double r;
        double PI = 3.14159;

    public:
    Circle(double radius) : r(radius) {}
        
        double get_r(){return r;};

        double calculateArea(){
            double area = PI* r * r;
            return area;
        };
        double calculatePerimeter(){
            double perimeter = 2 * PI * r;
            return perimeter;
        };
};

class Rectangle : public Shape {
    private:
        double length;
        double width;

    public:
        Rectangle(double l, double w) : length(l), width(w){}
        
        double get_length(){return length;};
        double get_width(){return width;};

        double calculateArea(){
            double area = length * width;
            return area;
        };
        double calculatePerimeter(){
            double perimeter = (length + width) * 2;
            return perimeter;
        };
};

class Triangle : public Shape {
    private:
        double base;
        double a;
        double c;
        double heightbase;

    public:
        Triangle(double base, double heightbase, double a, double c)
        : base(base), heightbase(heightbase), a(a), c(c) {}
        
        double get_base(){return base;};
        double get_height(){return heightbase;};
        double get_a(){return a;};
        double get_c(){return c;};

        double calculateArea(){
            double area = base * heightbase / 2;
            return area;
        };
        double calculatePerimeter(){
            double perimeter = base + a + c;
            return perimeter;
        };
};

int main(){
    Shape* shapes[3];

    shapes[0] = new Circle(5.0);          // Circle with radius 5
    shapes[1] = new Rectangle(4.0, 6.0);  // Rectangle with length 4, width 6
    shapes[2] = new Triangle(3.0, 4.0, 5.0, 6.0); // Triangle with base 3, height 4, sides 5 and 6

    // Interact with shapes through the Shape interface
    for (int i = 0; i < 3; i++) {
        cout << "Shape " << i + 1 << ":\n";
        cout << "Area: " << shapes[i]->calculateArea() << "\n";
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << "\n";
        cout << "------------------------\n";
    }

    // Clean up memory
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}