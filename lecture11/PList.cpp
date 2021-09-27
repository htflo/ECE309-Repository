#include <iostream>
#include <string>
#include "List.h"

using namespace std;

class Object {
public:
  virtual void print() {
    cout << "Object";
  }
};

class IntObject : public Object {
public:
  int item;
  IntObject(int t):item(t) {}
  void print() { cout << item ; } // override
};

template <typename T>
class ObjT : public Object {
public:
  T item;
  ObjT(T t):item(t) {}
  void print() { cout << item ; } // override
};


int main()
{
  List<Object*> objList;

  objList.append( new Object() );

  IntObject *iptr = new IntObject(5);
  iptr->print(); cout << endl;
  
  objList.append( iptr );
  objList.append( new IntObject(100) );
  objList.append( new ObjT<string>("a string obj") );
  objList.append( new ObjT<double>(3.14) );
  
  for(auto it = objList.begin();
      it != objList.end();
      ++it)
    {
      it.getItem()->print();
      cout << endl;
    }

  cout << endl;
  
  return 0;
}
