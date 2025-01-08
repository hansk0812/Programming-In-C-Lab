#include <stdio.h>
int main() {
int a = 5, b = 10, c = 2, d = 8;
int result = a + b * c - d / c % b + (a > b ? a : c);
int result2 = a + (b * c) - (d / c) % b + (a > b ? a: c);
printf("Result: %d\n", result);
printf("Result 2: %d\n", result2);
return 0;
}
