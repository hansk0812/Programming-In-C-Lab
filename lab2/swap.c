#include<stdio.h>

void main() {
  int a = 5, b = 10;
  printf("\nBefore swap: \na=%d, b=%d", a, b);

  a = a + b;
  b = a - b;
  a = a - b;
  printf("\nAfter swap: \na=%d, b=%d", a, b);

}
