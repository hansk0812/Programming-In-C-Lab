#include<stdio.h>
#include<string.h>


void main() {
  
  char firstday[10];  
  char x[7][10]; 
  int order[7];

  strcpy(x[0], "Monday");
  strcpy(x[1], "Tuesday");
  strcpy(x[2], "Wednesday");
  strcpy(x[3], "Thursday"); 
  strcpy(x[4], "Friday");
  strcpy(x[5], "Saturday");
  strcpy(x[6], "Sunday");

  int date;

  printf("Enter the first day of the month:");
  scanf("%s", firstday);
  
  int order_idx = -1;
  for (int idx=0; idx < sizeof(x) / 10; idx++) {
    if (strcmp(x[idx], firstday) == 0)
      order_idx = idx;
  }

  if (order_idx == -1) {
    printf("Invalid input! Exiting!");
    return;
  }

  printf("Enter date:");
  scanf("%d", &date);
  
   printf("The date %d is a %s", date, x[(order_idx+date-1) % 7]);

}
