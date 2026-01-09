#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual double area() = 0; // Pure virtual function (Abstract)
    void info() {
        cout << "ShapeName: " << name << endl;
    }
};

class Circle : public Shape {
protected:
    double radius;
public:
    Circle(string n, double r) : Shape(n), radius(r) {}
    double area() override {
        return M_PI * pow(radius, 2);
    }
};

class Cylinder : public Circle {
    double length;
public:
    Cylinder(string n, double r, double l) : Circle(n, r), length(l) {}
    double volume() {
        return this->area() * length;
    }
};

class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(string n, double w, double h) : Shape(n), width(w), height(h) {}
    double area() override {
        return width * height;
    }
};

class Polygon : public Rectangle {
    double n;
public:
    Polygon(string n_name, double w, double h, double n_val) 
        : Rectangle(n_name, w, h), n(n_val) {}
    double area() override {
        return 0.5 * width * height * n;
    }
    double volume() {
        return this->area() * height;
    }
};

int main() {
    cout << fixed << setprecision(2);

    Circle cir1("MyCircle", 5.0);
    cir1.info();
    cout << "CircleArea: " << cir1.area() << "\n_______________________________\n";

    Cylinder cy1("MyCylinder", 4.0, 10.0);
    cy1.info();
    cout << "CylinderVolume: " << cy1.volume() << "\n_______________________________\n";

    Rectangle rec1("MyRectangle", 2.0, 6.0);
    rec1.info();
    cout << "RectangleArea: " << rec1.area() << "\n_______________________________\n";

    Polygon pol1("MyPolygon", 4.0, 10.0, 6.0);
    pol1.info();
    cout << "PolygonArea: " << pol1.area() << endl;
    cout << "PolygonVolume: " << pol1.volume() << endl;

    return 0;
}