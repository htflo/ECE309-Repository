#include <iostream>
#include <string>
#include <list>

using namespace std;

class Weird {
public:
  int x;
  int y;
  Weird():x(5), y(6){}
};

int main() {
  list<Weird> w;
  
  list<string> l; // declare a list for holding strings
  l.push_back("eggs");
  l.push_back("milk");

  // use an iterator to insert into the middle
  list<string>::iterator it = l.begin(); // it points to “eggs”

  it++; // now it points to “milk”

  l.insert(it, "flour"); // insert flour before “milk”, cost O(1)

  using iterator = std::list<string>::iterator;
  
  for (auto i = l.begin(); i != l.end(); i++)
    {
      cout << (*i) << std::endl; 
    }


  Weird ww;
  w.push_back(ww);
  auto k = w.begin();

  cout << k->x << std::endl;

  
  return 0;
}

