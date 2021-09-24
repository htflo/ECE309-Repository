#include <iostream>

using namespace std;

class A {
   int a;
public:
   int b;
  //A() { a = 0; b = 0; cout << "init A()" << endl; }
   A(int x, int y) { a=x; b=y; cout << "init A(x,y)" << endl;}
};

class B : public A {
    int c;
public:
  B() : A(1,1), c(1) {
    
  }
  
  /*
    B(int w=0): A(w,0),c(2)  { // WORKS!
    cout << b << endl;  
    cout << c << endl;  
    }*/

  void print()
  {
    cout << c << endl;
  }
};


int main()
{
  B b;

  b.print();
  //  cout << b.a << std::endl;

  return 0;
}
