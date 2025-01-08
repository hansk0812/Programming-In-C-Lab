#include<stdio.h>
#include<string.h>
#include<stdbool.h>

struct Movie {
  char title[50];
  char synopsis[200];
  float rating;
  char director[50];
  struct Movie *SimilarTo;
  int length;
};

void q_a(struct Movie *MOVIES, int len) {
  printf ("\n");
  for (int idx = 0; idx < len; idx++)
    printf ("Title: %s, Director: %s, SimilarTo: %s\n", MOVIES[idx].title, MOVIES[idx].director, MOVIES[idx].SimilarTo->title);
  printf ("\n");

  // check for validity
  printf ("\n");
  for (int idx = 0; idx < len; idx++) {
    if ((MOVIES[idx].rating < 0 || MOVIES[idx].rating > 10) || (MOVIES[idx].length < 120 || MOVIES[idx].length > 150))
      printf ("%s: INVALID\n", MOVIES[idx].title);
    else
      printf ("%s: VALID\n", MOVIES[idx].title);
  }
  printf ("\n");
}

void insertion_sort(int *L, int *I, int len) {
  for (int idx = 1; idx < len; idx++) {
    int key = L[idx];
    int key2 = I[idx];
    int jdx = idx - 1;

    while (jdx >= 0 && L[jdx] > key) {
        L[jdx + 1] = L[jdx];
        I[jdx + 1] = I[jdx];
        jdx = jdx - 1;
    }
    L[jdx + 1] = key;
    I[jdx + 1] = key2;
  }
}

void selection_sort(int *L, int *I, int len) {
  for (int idx = 0; idx < len; idx++) {
      int min = L[idx];
      int pos = idx;

      for (int jdx = idx+1; jdx<len; jdx++)
        if (L[jdx] < min) {
          min = L[jdx];
          pos = jdx;
        }
      
      if (pos != idx) {
        L[idx] = L[idx] + L[pos];
        L[pos] = L[idx] - L[pos];
        L[idx] = L[idx] - L[pos];

        I[idx] = I[idx] + I[pos];
        I[pos] = I[idx] - I[pos];
        I[idx] = I[idx] - I[pos];
      }
  }
}

void q_b(struct Movie *MOVIES, int len) {
  
  int I[len], L[len];
  for (int idx = 0; idx < len; idx++) {
    I[idx] = idx;
    L[idx] = MOVIES[idx].length;
  }
  insertion_sort(L, I, len);
  //selection_sort(L, I, len);

  printf ("\n");
  for (int idx = 0; idx < len; idx++)
    printf("Title: %s, Original Index: %d, Length: %d minutes\n", MOVIES[I[idx]].title, I[idx], MOVIES[I[idx]].length);
  printf ("\n");
 
}

int get_words(char *sentence, char words[30][20]) {
  int wc = 0;
  int pos = 0;
  
  for (int idx = 0; sentence[idx] != '\0'; idx++) {
    if (sentence[idx] == ' ') {
      for (int jdx = pos; jdx < idx; jdx++) 
        words[wc][jdx-pos] = sentence[jdx];
      words[wc][idx-pos] = '\0';
      
      pos = idx + 1;
      wc++;
    }
  }
  int jdx;
  for (jdx = pos; sentence[jdx] != '\0'; jdx++) 
    words[wc][jdx-pos] = sentence[jdx];
  words[wc][jdx-pos] = '\0';
  
  return wc+1;
}

void q_c(struct Movie *MOVIES, int len) {

  char words1[30][20], words2[30][20]; 
  int wc1, wc2; 

  for (int idx = 0; idx < len; idx++) {

    wc1 = get_words(MOVIES[idx].synopsis, words1);
    wc2 = get_words(MOVIES[idx].SimilarTo->synopsis, words2);
    
    char *common_words[30];
    int wc_c = 0;
    for (int idx = 0; idx < wc1; idx++)
      for (int jdx = 0; jdx < wc2; jdx++)
        if (strcmp(words1[idx], words2[jdx]) == 0) {
          common_words[wc_c] = &words1[idx][0];
          wc_c++;
        }
    
    printf ("\nCommon Words: ");
    for (int idx = 0; idx < wc_c; idx++)
      printf ("%s, ", common_words[idx]);
  }
}

void q_d(struct Movie *MOVIES, int len) {
  struct Movie *arr1[5], *arr2[5];
  int ptr1=0, ptr2=0; 
  
  for (int idx = 0; idx < len; idx++) {
    if (MOVIES[idx].length < 125) {
      arr1[ptr1] = &MOVIES[idx];
      if (ptr1 > 0)
        arr1[ptr1-1]->SimilarTo = arr1[ptr1];
      ptr1++;
    }
    else {
      arr2[ptr2] = &MOVIES[idx];
      if (ptr2 > 0)
        arr2[ptr2-1]->SimilarTo = arr2[ptr2];
      ptr2++;
    }
  }
  arr1[ptr1-1]->SimilarTo = NULL;
  arr2[ptr2-1]->SimilarTo = NULL;

  printf ("\n\n\nSet 1 (length < 125):\n");
  for (int idx=0; idx<ptr1; idx++)
    printf ("\tTitle: %s, Length: %d\n", arr1[idx]->title, arr1[idx]->length);
  printf ("\nSet 2 (length > 125):\n");
  for (int idx=0; idx<ptr2; idx++)
    printf ("\tTitle: %s, Length: %d\n", arr2[idx]->title, arr2[idx]->length);
}

void q_d2(struct Movie *MOVIES, int len) {
  char *directors[5], *synopses[5][5];
  int ptr = 0, synopses_len[5] = {0};
  for (int idx=0; idx<len; idx++) {
    bool found = false;
    for (int jdx=0; jdx<ptr; jdx++)
      if (strcmp(directors[jdx], MOVIES[idx].director)==0) {
        synopses[jdx][synopses_len[jdx]] = &MOVIES[idx].synopsis[0];
        synopses_len[jdx]++;
        found = true;
      }
      if (!found) {
        directors[ptr] = MOVIES[idx].director;
        synopses[ptr][synopses_len[ptr]] = MOVIES[idx].synopsis;
        synopses_len[ptr]++;
        ptr++;
      }
  }

  for (int idx=0; idx<ptr; idx++) {
    printf ("\nDirector: %s Synopses\n", directors[idx]);
    for (int jdx=0; jdx<synopses_len[idx]; jdx++)
      printf ("\n%s", synopses[idx][jdx]);
  }
  printf("\n");
}

void main() {
  int NUM_MOVIES = 5;
  struct Movie MOVIES[NUM_MOVIES];
  
  strcpy(MOVIES[0].title, "Inception");
  strcpy(MOVIES[0].synopsis, "A skilled thief is given a chance at redemption if he can successfully perform an inception, planting a new idea on his own into the mental space of a target."); 
  MOVIES[0].rating = 9;
  strcpy(MOVIES[0].director, "Christopher Nolan"); 
  MOVIES[0].SimilarTo = NULL;
  MOVIES[0].length = 148;

  strcpy(MOVIES[1].title, "Interstellar");
  strcpy(MOVIES[1].synopsis, "A skilled team of explorers travel through an elaborate wormhole in space in search of a new habitable planet."); 
  MOVIES[1].rating = 8.3;
  strcpy(MOVIES[1].director, "Christopher Nolan"); 
  MOVIES[1].SimilarTo = NULL;
  MOVIES[1].length = 169;

  strcpy(MOVIES[2].title, "The Prestige");
  strcpy(MOVIES[2].synopsis, "Two skilled magicians engage in a bitter rivalry, each trying to outperform the other with ever more new and elaborate tricks."); 
  MOVIES[2].rating = 9.5;
  strcpy(MOVIES[2].director, "Christopher Nolan"); 
  MOVIES[2].SimilarTo = NULL;
  MOVIES[2].length = 130;

  strcpy(MOVIES[3].title, "Memento");
  strcpy(MOVIES[3].synopsis, "A man suffering from short-term memory loss attempts to solve his wife's murder while struggling with his own fractured mind."); 
  MOVIES[3].rating = 8.8;
  strcpy(MOVIES[3].director, "Christopher Nolan"); 
  MOVIES[3].SimilarTo = NULL;
  MOVIES[3].length = 113;

  strcpy(MOVIES[4].title, "Dunkirk");
  strcpy(MOVIES[4].synopsis, "The evacuation of Allied soldiers from the beaches of Dunkirk during World War II."); 
  MOVIES[4].rating = 8;
  strcpy(MOVIES[4].director, "Christopher Nolan"); 
  MOVIES[4].SimilarTo = NULL;
  MOVIES[4].length = 106;
  
  MOVIES[0].SimilarTo = &MOVIES[1];
  MOVIES[1].SimilarTo = &MOVIES[2];
  MOVIES[2].SimilarTo = &MOVIES[4];
  MOVIES[3].SimilarTo = &MOVIES[0];
  MOVIES[4].SimilarTo = &MOVIES[2];
  
  q_a(MOVIES, NUM_MOVIES);
  q_b(MOVIES, NUM_MOVIES);
  q_c(MOVIES, NUM_MOVIES);
  q_d(MOVIES, NUM_MOVIES);
  q_d2(MOVIES, NUM_MOVIES);
}
