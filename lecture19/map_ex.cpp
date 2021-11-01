#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {
  std::map<string, int > age;
  
  age["Andrew"] = 9;
  age["Clara"] = 6;
  age["Betty"] = 3;
  age["Noey"] = 2;


  auto it = age.find("Grace"); // Lookup Key==”Grace”

  //age["Grace"];
  
  if ( it == age.end() ) { 
    cout << "Don’t know how old Grace is." << endl;
  } else { // print Grace’s age
    cout << "age[" << (*it).first << "] = " << (*it).second) << endl;
  }

  
  for(auto it=age.begin(); it!=age.end(); it++) 
    cout << "age[" << (*it).first << "] = " << (*it).second << endl;

  return 0;
}
