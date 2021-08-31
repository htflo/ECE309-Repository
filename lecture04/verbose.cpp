#include <iostream>
#include <string>

class Verbose
{
public:
   std::string msg;
   Verbose(std::string m) { msg = m; std::cout << m << ": I’m born!\n";
     //     new int [100]; // on the heap
   }
   ~Verbose(){ std::cout << msg << ": I’m gone!\n"; }
};

Verbose global("global");

int main()
{ 
   Verbose local("local"); // local variable on the stack
   Verbose local2("local2"); // another local

   //Verbose *heap = new Verbose("heap");

   delete heap;
   
   return 0; 
}
