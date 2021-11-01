#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weird {
public:
  int x;
  int y;
  Weird():x(5), y(6){}
};

int main() {
  vector<Weird> w;
  
  vector<string> l; // declare a vector for holding strings
  l.push_back("eggs");
  l.push_back("milk");

  // use an iterator to insert into the middle
  auto it = l.begin(); // it points to “eggs”

  it++; // now it points to “milk”

  l.insert(it, "flour"); // insert flour before “milk”, cost O(1)

  
  for (auto i = l.begin(); i != l.end(); i++)
    {
      cout << (*i) << std::endl; 
    }


  for (size_t j = 0; j < l.size(); j++)
    {
      cout << l[j] << std::endl;
    }
  
  /*
  Weird ww;
  w.push_back(ww);
  auto k = w.begin();

  cout << k->x << std::endl;
  */
  
  return 0;
}

