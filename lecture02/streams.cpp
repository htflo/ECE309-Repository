#include <iostream>
#include <string>

// using declaration so we can avoid typing
// std all the time!
using namespace std;

// example of making a namespace
namespace ece309 {
  int x;
}

int main()
{
  // Example of cout
  std::cout << "This is a string\n";

  std::cout << "Enter a value for x: ";

  std::string x;  

  // Example of cin, get input into x
  cin >> x;

  // Print the value we got.
  std::cout << "The value received for x = "
	    << x
	    << ".\n";
  
  return 0;
}
