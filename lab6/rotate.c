#include<stdio.h>

void rotate_left(int arr[5]) {

  int swap1 = arr[0];
  for (int idx=1; idx<5; idx++)
    arr[idx-1] = arr[idx];
  arr[4] = swap1;
  
  printf ("\nRotated array: ");
  for (int idx=0; idx<5; idx++)
    printf("%d,", arr[idx]);
  printf ("\n");
}

void main() {
  int arr[5];

  printf ("Enter 5 numbers of the array separated by , and ending with ,:");
  for (int idx = 0; idx < 5; idx++) {
    scanf("%d,", &arr[idx]);
  }
  
  for (int idx=0; idx<5; idx++)
    rotate_left(arr);
}
