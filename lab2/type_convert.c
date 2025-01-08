//char --> int, int --> char, int --> float, float --> int and short, signed, unsigned variants of the numerical types.

#include <stdio.h>

void main() {
  char x = 'a';
  printf ("\n%d", x);
  int y = (int) x;
  printf ("\n%d", y);

  int a = 65; // capital A in ASCII
  char b = a;
  printf ("\n%c", b);
  b = (char)a;
  printf ("\n%c", b);

  int f = 100;
  printf ("\nWrong answer: %f", f);
  printf ("\nRight answer: %f", (float)f);

  float g = 9.8;
  printf ("\nWrong answer: %d", g);
  printf("\nRight answer: %d", (int)g);

  // the max value for these types can vary based on the underlying hardware
  short int v=10;
  unsigned int w = 1000005537;
  signed int z = 1000005537;

  printf ("\n%d, %d, %d\n", v, w, z);
}

