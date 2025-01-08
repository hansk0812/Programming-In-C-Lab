#include<stdio.h>

int twos_complement(int n) 
{
  return (~n) + 1;
}

void main()
{
  int a, b;
  int c, d, sum;

  printf("Enter 2 negative numbers separated by space: \n");
  scanf("%d %d", &a, &b);

  printf ("Sum of the 2 negative numbers = %d", twos_complement(twos_complement(a) + twos_complement(b)));

}
