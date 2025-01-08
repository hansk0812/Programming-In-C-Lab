#include<stdio.h>

int is_prime(int num) {
  int isp = 1;
  for (int idx=2; idx <= num/2; idx++) {
    if (num % idx == 0)
      isp = 0;
  }
  return isp;
}

void main() {
  
  int m, M;
  printf ("Enter a numerical range separated by comma followed by space: ");
  
  scanf ("%d, %d", &m, &M);

  for (int idx = m; idx <= M; idx++) {
    if (is_prime(idx))
      printf (" %d, ", idx);
  }
}
