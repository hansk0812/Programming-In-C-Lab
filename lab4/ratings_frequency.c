#include<stdio.h>
#include<stdlib.h>

#define NUM_STUDENTS 100

void main() {
  int num_students;

  printf("Enter the number of students (<100):");
  scanf("%d", &num_students);

  if (num_students > NUM_STUDENTS)
    exit(0);
  
  int ratings[5] = {0}, rating;

  for (size_t idx = 0; idx < num_students; idx++) {
    printf("Enter the rating given by student %d:", idx+1);
    scanf("%d", &rating);
    
    if (rating > 5 || rating <= 0) 
      exit(0);

    ratings[rating-1] += 1;
  }

  for (size_t idx = 1; idx <= 5; idx++) {
    printf ("\n Rating: %d : ", idx);
    for (size_t j = 0; j < ratings[idx-1]; j++)
      printf ("*");
  }
}
