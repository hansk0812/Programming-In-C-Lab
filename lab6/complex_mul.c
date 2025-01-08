#include<stdio.h>

void multiply(int a_real, int a_complex, int b_real, int b_complex) {
  int res_real = a_real*b_real - a_complex*b_complex;
  int res_complex = a_complex*b_real + a_real*b_complex;

  printf (" (%d + %di) * (%d + %di) = (%d + %di) ", a_real, a_complex,
                                                    b_real, b_complex,
                                                    res_real, res_complex);
}

void main() {
  int a_real, a_complex, b_real, b_complex;

  printf ("Enter a and b from (a+bi) separated by comma: ");
  scanf("%d,%d", &a_real, &a_complex);

  printf ("Enter c and d from (c+di) separated by comma: ");
  scanf("%d,%d", &b_real, &b_complex);

  multiply(a_real, a_complex, b_real, b_complex);

}
