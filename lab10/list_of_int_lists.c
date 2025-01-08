#include<stdio.h>

void main() {
  
  int *two_d_array[5];

  int num_arrays = 4;
  int list_of_sizes[5] = {5,3,4,6};

  int a[5] = {1,2,3,4,5};
  int b[3] = {6,7,8};
  int c[4] = {1,6,70,2};
  int d[6] = {1,2,3,4,5,6};

  two_d_array[0] = &a[0]; // same as a
  two_d_array[1] = &b[0];
  two_d_array[2] = &c[0];
  two_d_array[3] = &d[0];
  
  for (int idx = 0; idx < num_arrays; idx++)
  {
    for (int jdx = 0; jdx < list_of_sizes[idx]; jdx++)
      printf("%d ", two_d_array[idx][jdx]);
    printf ("\n");
  }
}
