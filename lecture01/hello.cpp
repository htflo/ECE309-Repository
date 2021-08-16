#include <stdio.h>

struct Rectangle {
private:
  int width; // member variable
   int length;
public:
  Rectangle() {
    length = 1;
    width = 1;
  }
  Rectangle(int length, int width) // this is a constructor
  {
    this->length = length;
    this->width = width;
  }

  int area() { 
       return length * width; 
   }
};

int main()
{
  Rectangle r;
  Rectangle s(5,10);
  // instance of Rectangle object
   //r.init(5,10);
   printf("area = %d\n", r.area()); // print the area by calling area function
   return 0;
}
