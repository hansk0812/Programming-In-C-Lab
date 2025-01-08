#include<stdio.h>
#include<string.h>
#include<stdbool.h>

// 2a
struct Book {
  int isbn;
  char title[50];
  char type[10];
  int num_pages;
  char genre[50];
  char author[50];
  int num_reviews;
  char reviews[10][30];
};

// 2b
bool type_checking(struct Book *book) {
  
  bool passed = true;
  passed = passed && (book->isbn > 10000 && book->isbn < 100000);
  passed = passed && (book->num_pages > 0);
  passed = passed && (strcmp(book->type, "Hardcover") == 0 || strcmp(book->type, "Paperback") == 0 || strcmp(book->type, "Invalid") == 0);
  
  return passed;
}

// 2a
struct Book instantiate(struct Book *book, int isbn, char *title, char *type, int num_pages, char *genre, char *author, char reviews[][30], int num_reviews) {
  strcpy(book->title, title);
  book->isbn = isbn;
  strcpy(book->type, type);
  book->num_pages = num_pages;
  strcpy(book->genre, genre);
  strcpy(book->author, author);
  book->num_reviews = num_reviews;
  for (int idx=0; idx < num_reviews; idx++)
    strcpy(book->reviews[idx], reviews[idx]);
}

// 2d
void pretty_print(struct Book *book) {
   printf ("\nBOOK:\n\tBook Title: %s\n", book->title);
   printf ("\tISBN: %d\n", book->isbn);
   printf ("\tType: %s\n", book->type);
   printf ("\tNo. of Pages: %d\n", book->num_pages);
   printf ("\tGenre: %s\n", book->genre);
   printf ("\tAuthor: %s\n\tReviews:\n", book->author);
   for (int idx = 0; idx < book->num_reviews; idx++)
     printf ("\t\t%s\n", book->reviews[idx]);
   printf ("\n\n");
}

// 2e
void add_3_reviews(struct Book *book, char review1[30], char review2[30], char review3[30]) {
  strcpy(book->reviews[book->num_reviews], review1);
  strcpy(book->reviews[book->num_reviews+1], review2); 
  strcpy(book->reviews[book->num_reviews+2], review3);
  book->num_reviews += 3;
}

void reviews_by_author(struct Book *books[], int num_books) {
  
  int total_authors = 0;
  char authors[num_books][50];
  char author_reviews[num_books][20][100];

  for (int idx = 0; idx < num_books; idx++) {
    printf ("\nAuthor: %s REVIEWS:\n", books[idx]->author);
    for (int jdx = 0; jdx < books[idx]->num_reviews; jdx++)
      printf ("\t%s\n", books[idx]->reviews[jdx]);
  }
}

void books_per_genre(struct Book *books[], int num_books) {
  char genres[num_books][50];
  int total_genres_index = 0;
  int genre_counts[num_books];

  for (int idx=0; idx<num_books; idx++) {
    if (total_genres_index == 0) {
      strcpy(genres[idx], books[idx]->genre);
      genre_counts[idx] = 1;
      total_genres_index += 1;
    }
    else
    {
      bool found = false;
      for (int jdx = 0; jdx < total_genres_index; jdx++) {
        if (strcmp(genres[jdx], books[idx]->genre) == 0) {
          genre_counts[jdx] += 1;
          found = true;
        }
      }
      if (!found) {
        strcpy(genres[total_genres_index], books[idx]->genre);
        genre_counts[total_genres_index] = 1;
        total_genres_index += 1;
      }
    }
  }

  for (int idx = 0; idx<total_genres_index; idx++) 
    printf ("\nGenre %s: %d books", genres[idx], genre_counts[idx]);
}

void main() {
  
  struct Book book1;
  char reviews[3][30] = {"Good", "Well-written", "Clear"};
  instantiate(&book1, 10001, "Introduction to C", "Hardcover", 300, "Programming", "Dennis Ritchie", reviews, 3);
  
  // 2b
  if (type_checking(&book1))
    printf ("\nBook type VALID!");
  else
    printf ("\nBook type INVALID!");

  pretty_print(&book1);
  
  // 2e
  char reviews_added[3][30] = {"Added review 1", "Added review 2", "Added review 3"};
  add_3_reviews(&book1, reviews_added[0], reviews_added[1], reviews_added[2]);
  pretty_print(&book1);

  // 2c
  struct Book book2, book3;
  char reviews2[3][30] = {"Thrilling", "Intense", "Suspense-filled"};
  instantiate(&book2, 10002, "Honour Among Thieves", "Paperback", 400, "Thriller", "Jeffrey Archer", reviews2, 3);

  char reviews3[3][30] = {"Great", "Tense", "Gripping"};
  instantiate(&book3, 10003, "A Prisoner of Birth", "Paperback", 500, "Thriller", "Jeffrey Archer", reviews3, 3);
  
  struct Book *books[3] = {&book1, &book2, &book3};
  reviews_by_author(books, 3);
  
  // 2d
  books_per_genre(books, 3);

}
