#include <iostream>
#include <string>


using std::string;
using std::cout;
using std::endl;

using Item = string;

// DListNode represents each 
// node of the list
class DListNode {
public:
   Item item; // data in the list
   DListNode *next;
   DListNode *prev;	

  DListNode(Item a, DListNode *n=nullptr, DListNode*p=nullptr) 
   {
     item = a;
     next=n;
     prev=p;
   }
};

class iterator {
private:
  DListNode *node; // private, implementation details hidden

public: 
  iterator(DListNode *n=nullptr) {
    node = n;
  }
  
  Item& getItem()
  {
    return node->item;
  }
  
  void next() { node = node->next; } // go forward
  void prev() { node = node->prev; } // go reverse
  bool end() { return node==nullptr; }

  // inside List::iterator class
    // check if two iterators are equivalent:
    bool operator==(const iterator &other) {
      return node == other.node;
    }
    
    // check if two iterators are not equal
    bool operator != (const iterator &other) {
      return node != other.node;
    }
    
    iterator& operator++() 
    {
      next();
      return *this;
    }

  iterator& operator--() 
    {
      prev();
      return *this;
    }

  friend class DList;
};


class DList {
private:
   // add head and tail pointer
   DListNode *head;
   DListNode *tail;
  
public:  
  DList()
  {
    head = nullptr;
    tail = nullptr;
  }
   void append(Item a);   
   void insertAfter(iterator i, Item a); 
   void erase(iterator i);
   bool empty();

  iterator begin() {  return iterator(head); }
  iterator end() { return iterator(nullptr); }

};

void DList::append(Item a) // zyBook 4.5
{
  DListNode *node = new DListNode(a,nullptr,tail); // set prev to tail
  if (head==nullptr) { 
    // list is empty, so set head and 
    // tail to be node
    head = node;
    tail = node;
  } else {
    // put new node at end of list
    tail->next = node;
    tail = node;
  }
}

void DList::insertAfter(iterator it, Item item) // zyBook 4.6, with some changes
{
  if(it.node == nullptr) { // nullptr iterator means insert at head
    DListNode *node = new DListNode(item,head); // next=head, prev=NULL
    if (head==nullptr) // same as zyBook
      head = tail = node;
    else { // if inserting before head, it.node==nullptr
      head->prev = node;
      head = node;
    }  
  } else if (it.node == tail) {
    DListNode *node = new DListNode(item,nullptr,tail); // next=nullptr, prev=old tail
    tail->next = node;
    tail = node;
  } else {
    DListNode *node = new DListNode(item,it.node->next,it.node); 
    it.node->next = node;
    node->next->prev = node;
  }
}

void DList::erase(iterator it) // zyBook 4.7 (they call it remove)
{
  DListNode * succ = it.node->next; // successor node
  DListNode * pred = it.node->prev; // predecessor node

  if (succ != nullptr) // it.node is not tail
    succ->prev = pred;
  if (pred != nullptr) // it.node is not head
    pred->next = succ;

  if (it.node == head)
    head = succ; // head is following node
  if (it.node == tail)
     tail = pred;// tail is previous node

  delete it.node; // delete the node; not shown in zyBook, but necessary in C/C++
  // iterator is now invalid, caller should not use it again
}

int main()
{
  DList l;

  l.append("milk");
  l.append("bread");
  l.append("eggs");

  for(iterator it = l.begin(); it != l.end(); ++it)
    {
      cout << it.getItem() << ", " ;
    }
  cout << endl;

  iterator it = l.begin();
  l.insertAfter(iterator(nullptr), "coffee");
  l.insertAfter(it, "ice cream");
  l.insertAfter(it, "butter");

  for(iterator it = l.begin(); it != l.end(); ++it)
    {
      cout << it.getItem() << ", " ;
    }
  cout << endl;

  l.erase(l.begin());

  for(iterator it = l.begin(); it != l.end(); ++it)
    {
      cout << it.getItem() << ", " ;
    }
  cout << endl;
  
  return 0;
}
