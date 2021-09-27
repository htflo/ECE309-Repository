#include <iostream>

using std::endl;
using std::cout;

template <typename Item>
class List {
private:
  // ListNode represents each node of the list
  class ListNode {
  public:
    Item item; // data in the list
    ListNode *next;	
    ListNode(Item a, ListNode *n=nullptr) 
    {
      item = a;
      next = n;
    }
  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;

  
public:
  class iterator {
  private:
    ListNode *node; // private, implementation details hidden
    
  public: 
    iterator(ListNode *n=nullptr) { node = n; }
    Item& getItem() { return node->item; }
    void next() { node = node->next; }
    
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
    
    friend class List;
  };
  
  List() {
    head = nullptr;
    tail = nullptr;
  }
  ~List() {
    while(!empty())
      {
	Item i;
	remove(i);
      }
  }
  
  void append(Item a)
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
  bool remove(Item &copy) { if (!empty()) // if list is not empty
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
  bool empty() { return head == nullptr; }
  
  iterator begin() { return iterator(head); }
  iterator end() { return iterator(); }
  
  void removeAfter(iterator it)
  {
    if (empty() || it.node==tail) return;   // defensive action, nothing to do
    else if (it.node==nullptr)         // special case to remove head, it’s not after any node
      {
	ListNode *remove = head;           // will remove the head      
	head = head->next;                 // advance head 
	if (head==nullptr) tail = nullptr; // if head is NULL now, list is empty
	delete remove;                     // delete removed node
      }
    else // normal case, if not the head, then simply disconnect the node
      {
	ListNode *tmp = it.node;
	ListNode *remove = tmp->next;      // next node to be removed
	if (tail == remove) 
	  tail = tmp;                     // if removing tail, update tail	
	tmp->next = remove->next;          // point around node to be removed   
	delete remove; // delete node      // delete the removed node
      }    
  }
  void insertAfter(iterator it, Item item) // pseudocode in zyBook 11.
  {
    if (it.node==NULL) { // special case to insert at the head
      // point new node at current head of list
      ListNode *node = new ListNode(item,head);
      if (head==NULL) { // if head was NULL, tail was also NULL
	tail = node;   // new node is now the tail
	head = node;   // new node is now the head
      } else {
	head = node;   // update head to new node
      }
    }
    else // insert in the middle or at the tail
      {
	ListNode *node = new ListNode(item,it.node->next);
	it.node->next = node;
	if (tail==it.node) tail = node;     
      }
  }

  size_t size() {
    int s = 0;
    for(iterator it=begin(); it!=end(); ++it,s++);
    return s;      
  }
};
// List encapsulates and abstracts // away list implementation.

template <typename T>
void print(List<T> &l)
{
  for(auto it = l.begin(); it != l.end(); ++it)
    {
      cout << it.getItem() << ", ";
    }
  cout << endl;
}
