#include <stdio.h>

int main() {
    int a[] = {1,3,5,7};
   
    int *p = a; // or &a[0]
   
    for (int idx=0; idx < 4; idx++)
    {
        printf ("%d\n", *(p+idx));
    }
    return 0;
}
