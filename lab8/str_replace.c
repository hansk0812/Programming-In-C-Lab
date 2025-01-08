#include<stdio.h>
#include<string.h>

int get_pos(char *a, char *b)
{
  int y_idx = 0;
  int y_idx_backup = 0;

  for (int idx=0; (*(a + idx)) != '\0'; idx++)
  {
    if ((*(a+idx)) == (*(b + y_idx)))
    {
      y_idx += 1;
      for (int jdx=idx+1; (*(a+jdx)) != '\0'; jdx++)
      {
        if ((*(a+jdx)) != (*(b + y_idx)))
          break;
        else
          y_idx += 1;

        if ((*(b + y_idx+1)) == '\0')
          return idx;
      }
    }
  }
  return -1;
}

void main()
{
  char a[50] = "Hello World!";
  char b[50] = "Hello";
  char c[50] = "GOOCHIPOO";

  int pos = get_pos(a, b); 
  
  if (pos == -1)
    printf("No substring match for replace operation!");
  else
  {
    int idx;

    for (idx = 0; idx < strlen(c); idx++)
    {
      (*(a+pos+idx)) = (*(c+idx));
    }
   }
  printf ("%s", a);
}
