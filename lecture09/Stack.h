// Stack.h

#include "List.h"
#include <string>

using std::string;

class Stack {
private:
  int listSize;
   List<string> list; // use singly linked list
public:
   Stack() { listSize = 0; }
   void push(string);
   void pop();
   string& peek();
   bool empty();
   int size();
};
