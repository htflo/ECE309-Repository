#include <iostream>
using namespace std;


class Shape { // ABSTRACT BASE CLASS
public:
  // pure virtual function
  // do dummy implementation
  virtual int area() = 0;
};

void print(Shape *s);

class Rectangle : public Shape {
protected:
  int w;
  int l;
public:
  Rectangle(int width=0, int length=0)
    :Shape(),w(width),l(length)
  {
  }

  virtual int area() {
    return w * l;
  }
};
  
class Square : public Rectangle {
public:
  Square(int side=0)
    :Rectangle(side,side)
  {
  }
};
  
class Circle : public Shape {
protected:
  int r;
public:
  Circle(int radius=0)
    :Shape(),r(radius)
  {
  }

  virtual int area() {
    return 3.14 * r * r;
  }
};

int main()
{
  //Shape p;
  Square q(5);
  
  Shape *c = new Circle(5);

  Shape *r = new Rectangle(5,6);

  Shape *s = new Square(5);

  cout << "area of circle: " << c->area() << endl;
  
  return 0;
}
