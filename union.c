#include<stdio.h>

union
{
  float f;
  int i;
} u;

void main() {
  // Convert floating-point bits to integer:
  printf("As integer: %08x\n", u.i);
  u.f = 3.14159f;
  printf("As integer: %08x\n", u.i);
}
