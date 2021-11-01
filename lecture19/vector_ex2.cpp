#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v(5, 0); // declare a vector with 5 zeros already inserted
  // print them out, all five zeros
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " "; // O(1) access using array notation
  cout << endl;
  
  v[1] = 1; v[2] = 2; v[3] = 3; v[4] = 4; // modify contents using operator[]
  
  v.resize(10,-1); // O(n), make array of length 10, put -1 in new spots


  for(int j=0; j<10000000; j++)
  for (int i = 0; i < v.size(); i++)
    v[i]; //cout << v[i] << " "; // prints: 0 1 2 3 4 -1 -1 -1 -1 -1
  
  //  vector< vector<int> > twoDvector;

  
  return 0;
}
