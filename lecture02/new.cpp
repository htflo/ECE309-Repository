int main()
{
  // use new to allocate to the heap
  int *x = new int;
  int &y = *(new int);

  *x = 5;
  y = 3;

  delete x;  // free up x
  delete &y; /* must pass a 
		pointer, so take 
		address of y */
  
  return 0;
}
