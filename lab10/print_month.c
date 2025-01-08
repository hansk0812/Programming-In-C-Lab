#include<stdio.h>

void main() {
  
  char *two_d_array[13] = {"Invalid Month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  
  int num;
  printf ("Enter month index:");
  scanf ("%d", &num);
  
  if (num < 1 || num > 12)
    printf ("%s", two_d_array[0]);
  else
    printf ("%s", two_d_array[num]);

}
