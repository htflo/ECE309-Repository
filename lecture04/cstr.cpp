#include <iostream>
#include <cstring>

class cstr {
private:
  int size;     // size of the array
  char * array; // points to the string
  char error;
  
public:
  cstr() {
    size = 0;
    array = nullptr; 
  }

  cstr(int n)
  {
    size = n + 1;
    array = new char [size];
    for(int i=0; i<n; i++)
      array[i] = ' ';
    array[n+1] = 0; // null termination character
  }
  
  cstr(const char* str)
  {
    // set the size to match the literal string
    size = std::strlen(str) + 1;
    // allocate an array large enough for the literal
    array = new char [size];
    std::memcpy(array, str, size);
    /*
      for(int i=0; i<size; i++)
         array[i] = str[i];
     */
  }

  cstr(const cstr& other)
  {
    size = other.size;
    array = new char [size];
    std::memcpy(array,other.array,size);
  }
  
  ~cstr()
  {
    delete [] array;
  }

  char& get(int index)
  {
    if ( index < 0 || index >= size )
      // catch other writes to memory that may be out-of-bounds
      return error;
    
    return array[index];
  }

  // char& operator []
  
  void print() {
    std::cout << array;
  }
};

int main()
{
  //  cstr c;
  
  cstr c = "hello!"; // 3rd constructor
  cstr blank(50);

  cstr d = c; 

  c.print();
  std::cout << std::endl;  
  blank.print();
  std::cout << std::endl;

  std::cout << "get first character: " << c.get(0) << std::endl;
  
  c.get(0) = 'H';

  c.print();
  
  c.get(100) = 'X';  // no error
  
  c.print();         // prints Hello!
  

  std::cout << std::endl;

  return 0;
}
