// deal.c from section 8.2 but modified to output the full card names

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
    srand((unsigned)time(NULL));

    const char *rankStrs[NUM_RANKS] = {"Two",   "Three", "Four", "Five", "Six",
                                       "Seven", "Eight", "Nine", "Ten",  "Jack",
                                       "Queen", "King",  "Ace"};
    const char *suitStrs[NUM_SUITS] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;

    do {
        printf("Enter number of cards in hand: ");
        scanf("%d", &num_cards);
    } while (num_cards > 52);

    printf("Your hand:\n");
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS;
        /* picks a random suit */
        rank = rand() % NUM_RANKS;
        /* picks a random rank */
        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;
            printf("%s of %s\n", rankStrs[rank], suitStrs[suit]);
        }
    }
    printf("\n");
    return 0;
}
