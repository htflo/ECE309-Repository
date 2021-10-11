#include <list> // templatized list for ints
#include <iostream>
#include <cmath>

using namespace std;

// To keep things simple for now, we’ll just assume
// integers
class IntegerSet {
public:
   virtual bool insert(int) = 0;
   virtual bool find(int) const = 0;
   virtual bool remove(int) = 0;

  virtual void print() {}
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
    // check if item is in list
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

class IntegerSetHT : public IntegerSet {
protected:
   int size;
  int probeDistance;
  int empty_since_start;
  int empty_after_removal;
  
   int hash(int key) const {
     int val = (key * 997) % size;
     return std::abs(val);
   }

  // struct { int data; bool valid; } 
  
   int *table;  // pointer to the table
public:

  IntegerSetHT(int htsize=1000);
  
  // override ABC
  bool insert(int) override; //override keyword asks compiler to do extra checks
  bool find(int) const override;
  bool remove(int) override;
  void print() override;
};

IntegerSetHT::IntegerSetHT(int htsize)
{
  empty_since_start = -1;
  empty_after_removal = -2;
  
  if (htsize <= 0)
    htsize = 1;

  probeDistance = 5;
  
  size = htsize;
   // allocate table
   
   table = new int[size]; // allocates the hash table

   // initialize table to be empty
   for(int i=0; i<size; i++)
      table[i] = empty_since_start; // -1 means empty  (bad idea)
}


bool IntegerSetHT::insert(int data)
{
  int index = hash(data);
  int bucketsProbed=0; 

  while (bucketsProbed++ < probeDistance) { 
    if (table[index] == data) return false;// make sure data not present
    if (table[index] < 0) {
      table[index] = data;
      return true;
    } 
    index = (index+1)%size; // (% size) lets us wrap around to first index
  }

  // didn’t insert data.  what do we do? -- need to resize table
  //any problems here? Is this complete?
  return false;
}

bool IntegerSetHT::find(int data) const
{
   // is data in the table?
  int index = hash(data);
   int bucketsProbed=0;
   while (table[index] != empty_since_start && bucketsProbed++ < probeDistance) 
   { 
      if (table[index] == data)
         return true;
      index = (index+1)%size; // (% size) lets us wrap around to first index
   }
   return false;

}

bool IntegerSetHT::remove(int data)
{
  int index = hash(data);
  int bucketsProbed=0;
  while (table[index] != empty_since_start && bucketsProbed++ < probeDistance) 
    { 
      if (table[index] == data) {
	table[index] = empty_after_removal;
	return true;
      }
      index = (index+1)%size; // (% size) lets us wrap around to first index
    }

  return false;
}

void IntegerSetHT::print()
{
  for (int i=0; i<size; i++)
    if ( table[i] != -1)
      cout << table[i] << ", ";
  
  cout << endl;
}

int main()
{
  //IntegerSet * set = new IntegerSetHT();
  
  IntegerSet & set = *(new IntegerSetHT());

  set.insert(5);
  set.insert(1);
  set.insert(1);
  set.insert(5);
  set.insert(2);
  
  set.print();

  if ( set.find(100) )
    {
      cout << "My set has 100!" << endl;
    }
  else
    {
      cout << "Didn't find 100" << endl;
    }

  if ( set.find(2) )
    {
      cout << "My set has 2!" << endl;
    }

  set.remove(5);

   if ( set.find(5) == false )
    {
      cout << "My set does not have 5!" << endl;
    }

  
  set.print();
  
  return 0;
}



