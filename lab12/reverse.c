#include<stdio.h>

void swap(int *a, int *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

void reverse(int *arr, int N) {
  for(int i=0; i<N/2; i++)
    swap(&arr[i], &arr[N-1-i]);
}

void main() {
  int arr[10]={0,1,2,3,4,5,6,7,8,9}, N=10;
  reverse(arr, N);
  
  for(int i=0; i<N; i++) {
    printf(" %d ", arr[i]);
  }
}
