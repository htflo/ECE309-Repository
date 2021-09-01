#include <iostream>
#include <string>

using namespace std;

// typedef string Item;
using Item = string;

// ListNode represents each node of the list
class ListNode {
public:
  Item item; // data in the list
  ListNode *next;	
  ListNode(Item a) 
  {
    item = a;
    next = nullptr;
  }
};

// Encapsulates each node of list

class List {
private:
  // add head and tail pointer
  ListNode *head;
  ListNode *tail;
public:
  List();

  ~List() {
    while(!empty())
      {
	remove(i);
      }
  }
  
  void append(Item a);
  bool remove(Item &a); 
  bool empty() { return head == nullptr; }

  void print();
};
// List encapsulates and abstracts // away list implementation.

List::List() {
  head = nullptr;
  tail = nullptr;
}

void List::append(Item a) 
{
  ListNode *node = new ListNode(a);
  if (head==nullptr) { 
    // list is empty, so set head and 
    // tail to be node
    head = node;
    tail = node;
  } else {
    // put new node at end of list
    tail->next = node;   //(1)
    tail = node;         //(2)

    //cout << "adding some " << a << " to my list." << endl;
  }
}

bool List::remove(Item &copy) 
{
  if (!empty()) // if list is not empty
    {
      copy = head->item; // return copy
      ListNode *tmp = head->next;
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==nullptr) // removed last element 
	tail = nullptr;
      return true;
    }
  return false; // nothing in list
}

void List::print()
{
  ListNode *tmp = head;
  while(tmp!=nullptr) // not at end of list
    {
      // do something useful
      cout << tmp->item << ", ";
      
      // get the item out and use it if needed
      // go to next node in the list
      tmp = tmp->next;
    }

  cout << endl;
}


int main()
{
  List l;
  l.append("milk");
  l.append("eggs");
  l.append("bread");
  l.append("coffee");
  l.append("chocolate ice cream");

  l.print();
  
  while(!l.empty())
    {
      Item i;
      l.remove(i);
      //cout << i << endl;
    }

  cout << "after removing everything: " ;
  l.print();
  
  return 0;
}
