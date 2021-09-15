#include <iostream>
#include "Queue.h"

void Queue::push(string item)
{
   // append item to the end
   list.append(item);
   listSize++;
}

void Queue::pop()
{
  List<string>::iterator it; // null iterator
  // user removeAfter to remove from head
  if (!empty()) 
    listSize --;

  list.removeAfter(it);
}

string& Queue::peek()
{  //Warning: don’t call on an empty list!
  auto it = list.begin(); // get the head 
  return it.getItem(); // return the head’s item
}

bool Queue::empty()
{
   return list.empty();
}

int Queue::size() {
  return listSize;  
}


using std::cin;

int main()
{
  string s;
  Queue q;
  
  while(true) {
    cin >> s;
    if (s == "quit")
      break;

    q.push(s);
  }

  while(!q.empty())
    {
      cout << q.peek() << ", ";
      q.pop();
    }

  return 0;
}
