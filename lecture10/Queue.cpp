#include <iostream>
#include "Queue.h"

void Queue::push(string item)
{
  qSize++;
  append(item);
}

void Queue::pop()
{
  if (qSize > 0)
    qSize--;
  // remove head of the queue
  removeAfter(iterator(nullptr));
}

string& Queue::peek()
{  //Warning: don’t call on an empty list!
  auto it = begin();
  return it.getItem();
}


size_t Queue::size()
{
  return qSize;
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

  print(q);
  
  cout << q.size() << endl;
  
  while(!q.empty())
    {
      cout << q.peek() << ", ";
      q.pop();
    }

  return 0;
}
