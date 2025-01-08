#include<stdio.h>

int f1(int a, int b, int c) { 
  return f2(a, b, 10); 
}

int f2(int a, int b, int c) {
  printf ("Arguments a and b are specified during runtime!\n");
  printf ("Argument(s) c is specified during compile time as a default value if f1 calls f2!\n");
  printf ("Argument(s) c is specified during runtime if f2 is called!\n");
  printf ("c = %d\n", c);
}

void main() {
  int a = 5, b = 10;

  f1(a, b, 0);
  f2(a, b, 1);

  printf ("The disadvantage of this approach is the addition of another function call to the call stack!");
}
