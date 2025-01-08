#include<stdio.h>

void main()
{
  int N, a, max=-1;

  printf("Enter number of elements in the array:");
  scanf("%d", &N);

  for (int i = 0; i < N; i++) 
  {
    printf ("Enter element %d of array:", i+1);
    scanf("%d", &a);

    if (a > max)
      max = a;
  }

  printf("Maximum of the array: %d", max);
}

