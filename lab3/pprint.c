#include<stdio.h>

void main() {
  int arr[50];
  for (int i=0; i<50; i++) 
    arr[i] = i*20;
  
  for (int i=0; i<5; i++) {
    printf("\n");
    for (int j=0; j<10; j++)
      printf(" %d ", arr[i*10 + j]);
  }
  printf("\n");
}
