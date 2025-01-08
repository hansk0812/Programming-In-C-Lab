#include<stdio.h>

void increment(int *v) 
{
  (*v)++; 
}

int main() 
{
  int a;
  printf("Enter a number to add 1 to:");
  scanf("%d", &a);
  increment(&a);
  printf("%d", a);

  int b[] = {0, 15};
  int *p;
  p = b;

  p++;
  printf("\n%d, %d", *p, p);
  return 0;      
}     
