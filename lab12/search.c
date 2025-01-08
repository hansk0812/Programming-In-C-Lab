// Binary Search in C

#include <stdio.h>

int binarySearch(int array[], int x, int low, int high, int MID) {
  // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (x == array[mid])
      return mid;

    if ((x > array[mid] && mid < MID) || (x < array[mid] && mid >= MID))
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[] = {3, 4, 5, 9, 8, 7, 6};
  int MID = 3;
  int n = sizeof(array) / sizeof(array[0]);
  int x = 7;
  int result = binarySearch(array, x, 0, n - 1, MID);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}

