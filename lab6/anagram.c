#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool anagram(char a[50], char b[50]) {
  if (strlen(a) != strlen(b))
    return false;

  int alphabets[26] = {0};

  for (int idx = 0; idx < strlen(a); idx++) {
    alphabets[a[idx] - 97] += 1;
    alphabets[b[idx] - 97] -= 1;
  }

  for (int idx = 0; idx < 26; idx++)
    if (alphabets[idx] != 0)
      return false;

  return true;

}

void main() {
  char a[50], b[50];

  printf("Enter string 1 in lowercase:");
  scanf("%s", &a);
  printf("Enter string 2 in lowercase:");
  scanf("%s", &b);

  if (anagram(a, b))
    printf ("%s and %s are anagrams!", a, b);
  else
    printf ("%s and %s are not anagrams!", a, b);

}
