#include<stdio.h>

float area_triangle(float base, float ht) {
  return 0.5*base*ht;
}

void main() {
  
  float b, h;

  printf ("Enter the base and height of triangle separated by comma and space:");
  scanf ("%f, %f", &b, &h);

  printf ("\nArea of the triangle = %f\n", area_triangle(b, h));

  float l;
  printf ("Enter the length and breadth of a rectangle separated by comma and space:");
  scanf ("%f, %f", &l, &b);

  printf ("\nArea of the rectangle/square = %f\n", 2*area_triangle(l, b));
}
