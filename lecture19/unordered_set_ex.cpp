#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
  unordered_set<string> s;

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
