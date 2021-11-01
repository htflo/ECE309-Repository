#include <set>
#include <iostream>

using namespace std;

class gtthan {
public:
  bool operator() (const string &a, const string &b) const
  {
    return a > b;
  }  
};


int main() {
  set<string,gtthan> s;

  s.insert("milk"); // insert an item, O(log n)
  s.insert("eggs");
  s.insert("flour");


  for(auto i = s.begin(); i!=s.end(); i++)
    cout << *i << " ";

  cout << endl;

  
  auto it = s.find("flour"); // O(log n) search time
  if (it!=s.end()) 
     s.erase(it);  // O(log n), remove it!

  
  for(auto i = s.begin(); i!=s.end(); i++)
    cout << *i << " ";

  cout << endl;

  return 0;
}
