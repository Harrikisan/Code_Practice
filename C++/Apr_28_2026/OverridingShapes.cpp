#include <iostream>
using namespace std;

class Shape {
protected:
    double width;
    double height;

public:
    Shape(double w, double h): width(w), height(h) {}
    virtual double area() = 0; // abstract class
};

class Circle : public Shape {
public:
    Circle(double r): Shape(r, r) {}

    double area() override {
        return 3.14 * width * width;
    }
};

class Triangle : public Shape {
public:
    Triangle(double b, double h): Shape(b, h) {}

    double area() override {
        return (width * height) / 2;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(double w, double h): Shape(w, h) {}

    double area() override {
        return width * height;
    }
};

int main() {
    int choice;
    cout<<"Choose shape:\n1. Circle\n2. Triangle\n3. Rectangle\n";
    cin>>choice;

    double width, height;

    switch(choice) {
        case 1:
            cout<<"Enter radius: ";
            cin>>width;
            {
                Circle c(width);
                cout<<"Area: "<<c.area()<<endl;
            }
            break;

        case 2:
            cout<<"Enter base and height: ";
            cin>>width>>height;
            {
                Triangle t(width, height);
                cout<<"Area: "<<t.area()<<endl;
            }
            break;

        case 3:
            cout<<"Enter width and height: ";
            cin>>width>>height;
            {
                Rectangle r(width, height);
                cout<<"Area: "<<r.area()<<endl;
            }
            break;

        default:
            cout<<"Invalid choice!"<<endl;
    }

    return 0;
}