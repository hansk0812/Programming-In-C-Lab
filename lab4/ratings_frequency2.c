#include<stdio.h>
#include<stdlib.h> 

void main() {
  int num_loop = 100, loop_idx = 0, ratings[5] = {0}, rating;
  
  while (loop_idx < num_loop) {
    printf ("Enter rating for student %d (-1 to stop): ", loop_idx);
    scanf ("%d", &rating);

    if (rating > 5 || rating <= -2) 
      exit(0);
    
    if (rating == -1) 
      break;

    ratings[rating-1] += 1;
    loop_idx++;
  }

  for (size_t idx = 1; idx <= 5; idx++) {
    printf ("\n Rating: %d : ", idx);
    for (size_t j = 0; j < ratings[idx-1]; j++)
      printf ("*");
  }
}
