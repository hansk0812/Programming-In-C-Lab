check if the number is even or odd using bitwise operator
#include <stdio.h>

int main()
{
    int x;

    printf("enter any number:");
    scanf("%d", &x);

    if((x^1)==(x+1))
    {
        printf("%d is even.\n", x);
    }
    else
    {
        printf("%d is odd.\n",x);
    }

    return 0;
}




look up 2s complement to find out about positive and negative representations
#include <stdio.h>
int main()
{
   int n;  
   printf("Enter the number of bits do you want to enter :");
   scanf("%d",&n);
   char binary[n+1];  
   char onescomplement[n=1]; 
   char twoscomplement[n+1];
   int carry=1;
   printf("\nEnter the binary number : ");
   scanf("%s", binary);
   printf("%s", binary);
   printf("\nThe ones complement of the binary number is :");
   
   for(int i=0;i<n;i++)
   {
       if(binary[i]=='0')
       onescomplement[i]='1';
       else if(binary[i]=='1')
       onescomplement[i]='0';
   }
   onescomplement[n]='\0';
   printf("%s",onescomplement);
  

printf("\nThe twos complement of a binary number is : ");

for(int i=n-1; i>=0; i--)
    {
        if(onescomplement[i] == '1' && carry == 1)
        {
            twoscomplement[i] = '0';
        }
        else if(onescomplement[i] == '0' && carry == 1)
        {
            twoscomplement[i] = '1';
            carry = 0;
        }
        else
        {
            twoscomplement[i] = onescomplement[i];
        }
    }
twoscomplement[n]='\0';
printf("%s",twoscomplement);
return 0;
}

