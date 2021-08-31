#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct grocery_item {
  string item;
  double quantity;
  string units;
};


class GroceryList {
private:
  struct grocery_item * list;
  int numItems;
  
public:
  GroceryList(string filename)
  {
    fstream fin;
    fin.open(filename, std::fstream::in);

    fin >> numItems;

    list = new struct grocery_item [numItems];

    fin >> std::ws;
    
    for(int i=0; i<numItems; i++)
      {
	// read in the items
	getline(fin, list[i].item);
	fin >> list[i].quantity;
	fin >> std::ws;		
	getline(fin, list[i].units);
      }

    fin.close();
  }

  ~GroceryList() {
    // we need to delete our list
    delete [] list;
  }

  GroceryList(const GroceryList& copy)
  {
    numItems = copy.numItems;
    list = new struct grocery_item [numItems];
    for(int i=0; i<numItems; i++)
      {
	list[i] = copy.list[i];
      }
  }

  GroceryList& operator =(const GroceryList& copy)
  {
    if ( this == &copy )
      return *this;

    delete [] list;
    
    numItems = copy.numItems;
    list = new struct grocery_item [numItems];
    for(int i=0; i<numItems; i++)
      {
	list[i] = copy.list[i];
      }

    return *this;
  }

  
  struct grocery_item &get(int index) {
    return list[index];
  }

  int getNumItems()
  {
    return numItems;
  }

  
  
};


int main()
{
  GroceryList l("weekly.txt");

  for (int i=0; i < l.getNumItems(); i++)
    cout << l.get(i).quantity << " "
         << l.get(i).units << " "
	 << l.get(i).item << endl;

  GroceryList copy = l;
  
  return 0;
}
