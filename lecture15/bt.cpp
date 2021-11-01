#include <iostream>

class BTNode { // Binary Tree (BT) Node
public:
   int data;      // data in the tree
   BTNode *left;  // left child
   BTNode *right; // right child

   BTNode(int d, BTNode *l=NULL, BTNode *r=NULL)
   {
     data = d;
     left = l;
     right = r;
   }
};

BTNode * root = nullptr;

/*
bool BSTSearch(tree, data) {
    node = tree->root
    while (node not null) {
       if (node->data == data) return true
       else if (data < node->data) node = node->left;
       else node = node->right;
    }
    return false;
}
*/

bool search(int data)
{
  BTNode *node = root; // start searching at the root
  while (node != nullptr)
    {
      if (node->data == data)
	return true;
      
      else if (data < node->data)	
	node = node->left; // found on left side of the node
      
      else // found on the right side
	node = node->right;       
    }

  return false; // not in the tree at all
}

void insert(int data)
{
  if (root == nullptr)
    {
      root = new BTNode(data);
    }
  else
    {
      BTNode *tmp = root;
      while (tmp != nullptr) {
	if (data < tmp->data) { // go to the left
	  if (tmp->left == nullptr)
	    {
	      tmp->left = new BTNode(data);
	      break;
	    }
	  else
	    {
	      tmp = tmp->left;
	    }
	}
	else
	  {
	    if (tmp->right == nullptr)
	      {
		tmp->right = new BTNode(data);
		break;
	      }
	    else
	      {
		tmp = tmp->right;
	      }	    
	  }
      }
    }
}


int main()
{
  root = new BTNode(100);
  root->left = new BTNode(25);
  root->right = new BTNode(150);

  root = new BTNode(100,new BTNode(25),new BTNode(150));
  
  root = new BTNode(9,
		    new BTNode(5,new BTNode(1),new BTNode(7)),
		    new BTNode(15));


  root = nullptr;
  insert(9);
  insert(5);
  insert(1);
  insert(7);
  insert(15);
  
  if ( search(15) ) {
    std::cout << "Found node 15!" << std::endl;
  } else {
    std::cout << "Did not find node 15." << std::endl;
  }

  if ( search(0) ) {
    std::cout << "Found node 0!" << std::endl;
  } else {
    std::cout << "Did not find node 0." << std::endl;
  }

  root = new BTNode(100, nullptr,
                     new BTNode(150, nullptr,
                           new BTNode(200)));

  root->right->right->right = new BTNode(400);


  
  
  
}
