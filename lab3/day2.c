#include<stdio.h>
#include<string.h>

void main() {
  
  char firstday[10];  
  int date;

  printf("Enter the first day of the month:");
  scanf("%s", firstday);
  
  printf("Enter date:");
  scanf("%d", &date);
  
  int firstday_idx = -1;
  
  if (strcmp(firstday, "Monday") == 0) {
    firstday_idx = 1;
  }
  else if (strcmp(firstday, "Tuesday") == 0) {
    firstday_idx = 2;
  }
  else if (strcmp(firstday, "Wednesday") == 0) {
    firstday_idx = 3;
  }
  else if (strcmp(firstday, "Thursday") == 0) {
    firstday_idx = 4;
  }
  else if (strcmp(firstday, "Friday") == 0) {
    firstday_idx = 5;
  }
  else if (strcmp(firstday, "Saturday") == 0) {
    firstday_idx = 6;
  }
  else if (strcmp(firstday, "Sunday") == 0) {
    firstday_idx = 7;
  }

  if (firstday_idx == -1) {
    printf("Invalid day! Exiting!");
    return;
  }
  
  int res = firstday_idx + date % 7 - 1;
  switch (res) {
    case 1:{
      printf("%d of the month is a Monday", date);
      break;
           }
    case 2:{
      printf("%d of the month is a Tuesday", date);
      break;
           }
    case 3:{
      printf("%d of the month is a Wednesday", date);
      break;
           }
    case 4:{
      printf("%d of the month is a Thursday", date);
      break;
           }
    case 5:{
      printf("%d of the month is a Friday", date);
      break;
           }
    case 6:{
      printf("%d of the month is a Saturday", date);
      break;
           }
    case 7:{
      printf("%d of the month is a Sunday", date);
      break;
           }
  }
}
