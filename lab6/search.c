#include<stdio.h>

int linear_search(int arr[10], int element) {
  for (int idx=0; idx < 10; idx++) {
    if (arr[idx] == element) {
      return idx;
    }
  }

  return -1;
}

void main(){

  int array[10], element;

  printf ("Enter the 10 elements of the array separated by , and end with ,:");
  for (int idx = 0; idx < 10; idx++) {
    scanf("%d,", &array[idx]); //&array[idx]);
  }
  printf("Enter the number to search for:");
  scanf("%d", &element);
  
  int index = linear_search(array, element);
  
  if (index == -1)
    printf ("%d not found in the array!", element);
  else
    printf ("%d is in position %d in the array!", element, index);

}
