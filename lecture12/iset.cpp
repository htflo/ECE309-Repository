#include <list> // templatized list for ints
#include <iostream>

using namespace std;

// To keep things simple for now, we’ll just assume
// integers
class IntegerSet {
public:
   virtual bool insert(int) = 0;
   virtual bool find(int) const = 0;
   virtual bool remove(int) = 0;
};

// IntegerSet using a list
class IntegerSetL : public IntegerSet {
   list<int> list;
public:
  bool insert(int item) {

    auto it = list.begin();
    
    // make sure item not in list
    for(;it!=list.end(); ++it)
    {
      if ( *it == item ) // *it is a overloaded dereference operator
	return false;
    }

    // add item to list
    list.push_back(item);
    return true;
  }
  
  bool find(int item) const
  {
    // make sure item not in list
    for(auto it = list.begin(); it!=list.end(); ++it) 
      if ( *it == item ) {
        return true;
      }
    return false;
  }
    
  bool remove(int item) {
    // make sure item not in list
    for(auto it = list.begin(); it!=list.end(); ++it)
      {
	if ( *it == item ) {
	  list.erase(it);
	  return true;
	}
      }
    return false;
  }

  void print() {
    for(auto it = list.begin(); it!=list.end(); it++)
      {
	cout << *it << ", ";
      }
    cout << endl;
  }
};

int main()
{
  IntegerSetL set;

  set.insert(5);
  set.insert(1);
  set.insert(1);
  set.insert(5);
  set.insert(-2);
  
  set.print();

  if ( set.find(100) )
    {
      cout << "My set has 100!" << endl;
    }
  else
    {
      cout << "Didn't find 100." << endl;
    }

  if ( set.find(-2) )
    {
      cout << "My set has -2!" << endl;
    }

  set.remove(5);
  set.print();
  
  return 0;
}



