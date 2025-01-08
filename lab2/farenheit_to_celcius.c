#include<stdio.h>

void main(){
  int far = 300;
  float c;

  for (int far = 300; far > 0; far--){
    c = (5./9) * (far-32);
    printf ("\n%d F = %f C", far, c);
  }
}
