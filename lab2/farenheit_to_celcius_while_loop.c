#include<stdio.h>

void main(){
  int far = 300;
  float c;

  while (far > 0){
    c = (5./9) * (far-32);
    printf ("\n%d F = %f C", far, c);
    far -= 1;
  }
}
