// thanks to geeksforgeeks for the code

#include<stdio.h>
#include<string.h>

char* replace(char* arr, int idx1, int idx2)
{
  char temp = arr[idx1];
  arr[idx1] = arr[idx2];
  arr[idx2] = temp;

  return arr;
}

// string s, first idx characters are constant
void permute_recursive(char* s, int idx)
{
    // Base case
    if (idx == strlen(s) - 1) {
      printf("%s\n", s);
      return;
    }

    // recursive case
    for (int i = idx; i < strlen(s); i++) {
      
        // Swapping 
        s = replace(s, idx, i);

        // First idx+1 characters fixed
        permute_recursive(s, idx + 1);

        // Backtrack
        s = replace(s, idx, i);
    }
}

// Wrapper function
void permute(char* s) {
    permute_recursive(s, 0);
}

void main()
{
    char s[50];

    printf("Enter string such that every character is unique: ");
    scanf("%s", s);
    permute(s);
}

