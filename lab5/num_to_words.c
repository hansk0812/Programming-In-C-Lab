#include<stdio.h>

void num_to_words(int num) {
  int n[5], idx=0;
  
  while (num>0) {
    n[idx] = num % 10;
    idx += 1;
    num = num / 10;
  }
  
  int size = idx;

  for (int idx = size-1; idx >= 0; idx--) {
    switch (n[idx]) {
      case 0:
        printf (" zero ");
        break;
      case 1:
        printf (" one ");
        break;
      case 2:
        printf (" two ");
        break;
      case 3:
        printf (" three ");
        break;
      case 4:
        printf (" four ");
        break;
      case 5:
        printf (" five ");
        break;
      case 6:
        printf (" six ");
        break;
      case 7:
        printf (" seven ");
        break;
      case 8:
        printf (" eight ");
        break;
      case 9:
        printf (" nine ");
        break;
    }
  }
}

void main() {
  
  int num;

  printf ("Enter a number (max=5 digits):");
  scanf ("%d", &num);
  num_to_words(num);
}
