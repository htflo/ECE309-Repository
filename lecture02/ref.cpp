#include <iostream>

void swap(int &a, int &b) {
  int tmp = a;
  std::cout << "This is the int version!\n";
  a = b;
  b = tmp;
}

void swap(double &a, double &b) {
  double tmp = a;
  std::cout << "This is the double version!\n";
  a = b;
  b = tmp;
}

int main() {
  // Try changing this to double and see
  // what happens!
  int x, y;

  std::cout << "Enter x y: ";
  std::cin >> x >> y;

  std::cout << "x=" << x << " y=" << y << "\n";

  // compiler picks the function that’s
  // the best match, in this case, the
  // one that takes integer arguments
  swap(x,y);  

  std::cout << "x=" << x << " y=" << y << "\n";
  
  return 0;
}
