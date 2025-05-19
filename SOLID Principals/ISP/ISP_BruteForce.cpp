#include<iostream>
#include <stdexcept>

using namespace std;

class Shape{
  public:
   virtual double area()=0;
   virtual double volume()=0;
};

// Rectangle shape
class Rectangle : public Shape{
    private:
      double height;
      double width;

    public:
       Rectangle(double h, double w){
        this->height=h;
        this->width=w;
       }

       double area() override{
        return height*width;
       }
      // ------ Unnecessary method --------
       double volume() override{
        throw logic_error("Volume not applicable for Rectangle..");
       }
};

// Square shape
class Square : public Shape{
private:
    double side;

public:
    Square(double s){
        this->side=s;
    }

    double area() override {
        return side * side;
    }
 // ------ Unnecessary method --------
    double volume() override {
        throw logic_error("Volume not applicable for Square");
    }
};


// Cube shape
class Cube : public Shape{
private:
    double side;

public:
    Cube(double s){
        this->side=s;
    }

    double area() override {
        return 6 * side * side;
    }

    double volume() override {
        return side * side * side;
    }
};


int main(){
    Shape *square = new Square(6);
    Shape *rectangle = new Rectangle(4,2);
    Shape *cube = new Cube(4);


    cout << "Square Area: " << square->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;

    try {
        cout << "Square Volume: " << square->volume() << endl;
    } catch (logic_error& e) {
        cout << "Exception: " << e.what() << endl;
    }
    
    return 0;
}