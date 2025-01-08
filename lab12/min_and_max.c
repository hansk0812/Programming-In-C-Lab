#include<stdio.h>
#include<stdlib.h>

void main() {
  int a = 15, b = -5;
  
  printf("Min: %d ; Max: %d\n", (a + b - abs(a-b))/2, (a + b + abs(a-b))/2);
}
