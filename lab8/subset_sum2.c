#include <stdio.h>

int main() {
   
    int a[] = {1,3,5,7};
   
    int *p = a; // or &a[0]
    int q[] = {0,0,0,0};
   
    for (int idx=0; idx < 4; idx++)
    {
        if (idx==0)
            q[idx] = (*p);
        else
        {
            q[idx] += (*(q+idx-1)) + (*(a+idx));
        }
       
        printf("%d\n", q[idx]);
    }
    return 0;
}
