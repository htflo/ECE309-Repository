#include <stdio.h>

template <typename T>
T max(T a, T b) {
  if (a > b)
    return a;
  else
    return b;
}

int main() {
  printf("%d\n", max(34, 55));      // max compares ints
  printf("%lf\n", max<double>(3.14, 2));  // max compares doubles
  return 0;
}
