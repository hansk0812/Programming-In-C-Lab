#include<stdio.h>

void main() {

  int a = 5; // 0101 in binary
  int b = 3; // 0011 in binary
  
  int c = a & b; // 0001 in binary, so c = 1
  printf ("\na & b = %d", c);
  c = a | b; // 0111 in binary, so c = 7
  printf ("\na | b = %d", c);
  c = a ^ b; // 0110 in binary, so c = 6
  printf ("\na ^ b = %d", c);
  c = ~a; // 1010 in binary (for a 4-bit system), so c = -6 in 2's complement form
  printf ("\n~a = %d", c);
  c = a << 1; // 1010 in binary, so c = 10
  printf ("\na << 1 = %d", c); // Left shift is equivalent to number*2^n
  c = a >> 1; // 0010 in binary, so c = 2
  printf ("\na >> 1 = %d", c); // Right shift is equivalent to number/2^n

}

