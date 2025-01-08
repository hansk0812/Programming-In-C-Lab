#include <stdio.h> 
  
void to_binary(int n) 
{ 
  int binary[1000]; 

  int idx = 0; 
  while (n > 0) { 
    binary[idx] = n % 2; 
    n = n / 2; 
    idx++; 
  } 

  for (int j = idx - 1; j >= 0; j--) 
      printf("%d", binary[j]); 
} 
  
void main() 
{
  int n;
  printf ("Enter integer to convert to binary: ");
  scanf("%d", &n);
  
  to_binary(n); 
}
