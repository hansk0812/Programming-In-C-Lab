#include<stdio.h>

// void **output represents arr: first dimension = 3 pointers, second dimension = n numbers
void assign(void **output, int *arr, int index) {
  output[index] = arr; // pointer index based assignment happens here
}

void main() {
  
  int a[] = {1,2,3};
  int b[] = {1,2};
  int c[] = {1};
  
  int array_lengths[] = {3,2,1};

  int *arr[3];

  assign(arr, a, 0); 
  assign(arr, b, 1); 
  assign(arr, c, 2); 

  for (int idx = 0; idx < 3; idx++) {
    for (int jdx = 0; jdx < array_lengths[idx]; jdx++)
      printf (" %d ", arr[idx][jdx]); // testing pointer index assignment
    printf ("\n");
  }
}
