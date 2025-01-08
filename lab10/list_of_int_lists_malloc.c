#include<stdio.h>
#include<stdlib.h> // for malloc

void main() {
  
  int **two_d_array; // First dimension for number of lists' memory and second pointer for each list's memory
  int *array_of_sizes; // Store the sizes for printing

  int num_arrays;
  printf ("Enter number of arrays:");
  scanf ("%d", &num_arrays);

  two_d_array = malloc(num_arrays * 1); // Size of pointer is 1
  array_of_sizes = malloc(num_arrays * 2); // Size of int is 2

  for (int idx = 0; idx < num_arrays; idx++) {
    int n;
    printf ("\nEnter number of elements for array number %d\n", idx+1);
    scanf ("%d", &n);

    array_of_sizes[idx] = n;

    int *array = malloc(n * 2); // size of integer is 2
    for (int jdx = 0; jdx < n; jdx++) {
      printf ("Enter the %d number:", jdx+1);
      scanf ("%d", (array+jdx));
    }

    two_d_array[idx] = array;
  }
  
  // Print array
  printf ("\n\nEntire 2D array:\n\n");
  for (int idx = 0; idx < num_arrays; idx++)
  {
    for (int jdx = 0; jdx < array_of_sizes[idx]; jdx++)
      printf("%d ", two_d_array[idx][jdx]);
    printf ("\n");
  }
}
