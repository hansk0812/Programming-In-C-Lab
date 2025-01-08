#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main() {
  char name[50];

  printf("Enter first name:");
  scanf("%s", name);
  
  int sum = 0;
  for (int idx = 0; idx < strlen(name); idx++) {
    sum += tolower(name[idx]);
  }
  printf("\nSum of characters in lowercase: %d", sum);
}
