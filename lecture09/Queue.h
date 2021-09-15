// Queue.h

#include "List.h"
#include <string>

using std::string;

class Queue {
private:
  List<string> list; // use singly linked list
  int listSize;
  
public:
  Queue() { listSize = 0;}
  void push(string);
  void pop();
  string& peek();
  bool empty();
  int size();
};
