#include<stdio.h>

int main(){
	int x=0,y=0;
	int a =0;
	char operator[10];
	printf("enter the input1:");
	scanf("%d",&x);
	printf("Enter the input2:");
	scanf("%d",&y);
	printf("Enter the operator:");
	scanf("%s",&operator);
	
	switch (operator[0])
	{
		case '+':
			a = x+y;
			printf("%d",a);
			break ;
		case '-':
			printf("%d",x-y);
			break ;
		case '*':
			printf("%d",x*y);
			break ;
		case '/':
			printf("%d",x/y);
			break ;
	}
}
			
