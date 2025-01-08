#include<stdio.h>
#include<stdlib.h>

void calculator() {
  
  int m, n;
  float r;
  char o;
  printf("Enter 2 numbers and the calculator operation separated by comma followed by space:");
  scanf("%d, %d, %c", &m, &n, &o);

  switch(o) {
    case '+':
      r = m + n;
      break;
    case '-':
      r = m - n;
      break;
    case '*':
      r = m * n;
      break;
    case '/':
      r = (float) m/n;
      break;
  }
  printf ("Result: %f", r);
}

void main() {
  
  calculator();
}
