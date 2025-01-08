#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h> // for swap function from question

// 1a
struct Card
{
  int number;
  char suit;
  int frequency;
};

static void shuffle(void *array, int n, int size) {
    char tmp[size];
    char *arr = array;
    size_t stride = size * sizeof(char);

    if (n > 1) {
        for (int i = 0; i < n - 1; ++i) {
            int rnd = (size_t) rand();
            int j = i + rnd / (RAND_MAX / (n - i) + 1);

            memcpy(tmp, arr + j * stride, size);
            memcpy(arr + j * stride, arr + i * stride, size);
            memcpy(arr + i * stride, tmp, size);
        }
    }
}

// 1c
bool is_same(struct Card card1, struct Card card2) {
  return (card1.number == card2.number && card1.suit == card2.suit);
}

// 1c
// Returns -1 if card is not in deck
int get_index(struct Card *deck, struct Card card, int len_of_deck) {
  for (int idx = 0; idx < len_of_deck; idx++)
    if (is_same(deck[idx], card))
      return idx;
  return -1;
}

char *card_number(int index, char *str) {

  if (index < 1 || index > 13)
      return "Invalid Card Number";
  switch (index) {
    case 1:
      return "Ace";
    case 11:
      return "Jack";
    case 12:
      return "Queen";
    case 13:
      return "King";
    default: {
      sprintf(str, "%d", index);
      return str;
    }
  }
}

// 1f
void print_card(struct Card *c)
{
  char *str[4] = {"Spade", "Claver", "Hearts", "Diamond"};
  char num[3];

  switch (c->suit) {
    case 'S':
      printf("\nCard: Number = %s ; Suit = %s ; Frequency = %d\n", card_number(c->number, num), "Spade", c->frequency);
      break;
    case 'C':
      printf("\nCard: Number = %s ; Suit = %s ; Frequency = %d\n", card_number(c->number, num), "Claver", c->frequency);
      break;
    case 'H':
      printf("\nCard: Number = %s ; Suit = %s ; Frequency = %d\n", card_number(c->number, num), "Hearts", c->frequency);
      break;
    case 'D':
      printf("\nCard: Number = %s ; Suit = %s ; Frequency = %d\n", card_number(c->number, num), "Diamond", c->frequency);
      break;
  }
}

void change_freq(struct Card *card, char inc_or_dec) {
  if (inc_or_dec == '+')
    card->frequency += 1;
  else if (inc_or_dec == '-')
    if (card->frequency > 0)
      card->frequency -= 1;
  else
    printf ("Unknown frequency change operation. Use + for increment by 1 and - for decrement by 1 only!");
}

void swap_cards(struct Card *card1, struct Card *card2) {
  int temp_num, temp_freq;
  char temp_char;

  temp_num = card2->number;
  temp_freq = card2->frequency;
  temp_char = card2->suit;

  card2->number = card1->number;
  card2->frequency = card1->frequency;
  card2->suit = card1->suit;

  card1->number = temp_num;
  card2->frequency = temp_freq;
  card2->suit = temp_char;
}

void main()
{
  // 1b
  struct Card deck[52];
  int NUM_SUITS = 4;
  char suits[4] = {'S', 'C', 'H', 'D'};
  
  for (int idx = 1; idx <= 13; idx++)
  {
    for (int jdx = 0; jdx < NUM_SUITS; jdx++)
    {
      deck[jdx*13 + idx - 1].number = idx;
      deck[jdx*13 + idx - 1].suit = suits[jdx];
      deck[jdx*13 + idx - 1].frequency = 0;
    }
  }
  
  // 1c
  struct Card card = deck[12];
  print_card(&card);
  printf ("\nUsing 12 card from deck; Searched index = %d\n", get_index(deck, card, 52));
  
  // 1d
  change_freq(&card, '+');
  change_freq(&card, '+');
  change_freq(&card, '+');
  print_card(&card);
  
  // 1e
  printf ("\nSwapping card 0 and card 1 from deck!\n");
  swap_cards(&deck[0], &deck[1]);
  printf("Card 0");
  print_card(&deck[0]);
  printf("Card 1");
  print_card(&deck[1]);
  printf ("\nSwapping back card 0 and card 1 from deck!\n");
  swap_cards(&deck[0], &deck[1]);
  printf("Card 0");
  print_card(&deck[0]);
  printf("Card 1");
  print_card(&deck[1]);


  // 1g
//  for (int idx = 0; idx < 52; idx++)
//    print_card(deck + idx);

  shuffle(deck, 52, sizeof(deck[0]));

//  for (int idx = 0; idx < 52; idx++)
//    print_card(deck + idx);

}
