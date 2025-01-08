#include<stdio.h>

void main() {

  char sentence[100]; // = "She studies at SNU";

  printf ("Enter string:");
  
  // scanf does not accept strings with spaces
  // So, you can use %NUM to indicate that the sentence variable has NUM characters in the buffer until newline ([^\n])
  // [^\n] means don't read newline (^ means not) 
  // In the exam, you can simply hardcode the string i.e. declare it inside the main function
  scanf ("%99[^\n]", sentence); 

  int prev_space_index = 0;
  for (int idx = 0; *(sentence+idx) != '\0'; idx++) {
    if (sentence[idx] == ' ') {
      printf ("\n");
      for (int jdx = prev_space_index; jdx < idx; jdx++)
        printf ("%c", *(sentence+jdx));
      prev_space_index = idx+1;
    }
  }

  //Print last word
  printf ("\n");
  for (int jdx = prev_space_index; sentence[jdx] != '\0'; jdx++)
    printf ("%c", sentence[jdx]);
  printf ("\n");

}
