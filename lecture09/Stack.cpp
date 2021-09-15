#include "Stack.h"

void Stack::push(string item)
{
  List<string>::iterator it; // null iterator
   // append item to the end
  list.insertAfter(it,item);
  listSize ++;
}

void Stack::pop()
{
  List<string>::iterator it; // null iterator
    
  // user removeAfter to remove from head
  if (!empty()) 
    listSize --;

  list.removeAfter(it);
}

string& Stack::peek()
{  //Warning: don’t call on an empty list!
  auto it = list.begin(); // get the head 
  return it.getItem(); // return the head’s item
}

bool Stack::empty()
{
   return list.empty();
}

int Stack::size() {
  return listSize;  
}

using std::cin;

int main()
{
  string s;
  Stack stack;
  
  while(true) {
    cin >> s;
    if (s == "quit")
      break;

    stack.push(s);
  }

  while(!stack.empty())
    {
      cout << stack.peek() << ", ";
      stack.pop();
    }

  return 0;
}
