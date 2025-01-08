#include<stdio.h>

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void main() {
  int arr[10]={1,4,7,7,7,7,4,4,1,1}, N=10;
  
  insertionSort(arr, N);
  
  int num=arr[0], count=1;
  for (int i=1; i<N; i++) {
    if (arr[i] == num) {
      count++;
      if (i==N-1)
        printf("\n%d: count=%d", num, count);
    }
    else {
      printf("\n%d: count=%d", num, count);
      num = arr[i];
      count = 1;
    }
  }
  
}
