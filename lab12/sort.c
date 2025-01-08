#include<stdio.h>

void swap(int *arr, int i, int j) {
  arr[i] = arr[i] + arr[j];
  arr[j] = arr[i] - arr[j];
  arr[i] = arr[i] - arr[j];
}

void search(int *arr, int mid, int len, int e) {
  int start = 0;
  int end = mid;

  while (start >= mid) {
    if arr[
  }
}

void main() {
  int a[10] = {1,5,11,2,7,4,9,13,15,0};
  
  int mid = 5;

  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++) {
      if (a[i] < a[j] && i<=mid && j<=mid) 
        swap(a, i, j);
      else if (a[i] > a[j] && i>mid && j>mid)
        swap(a,i,j);
    }

  for (int i=0; i < 10; i++)
    printf (" %d ", a[i]);

  search(a, mid, 10, 0);

}
