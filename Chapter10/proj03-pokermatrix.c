// modified poker.c that trades old arrays for a 5x2 matrix

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

#define CLUB_NUM 0
#define DIAMOND_NUM 1
#define HEART_NUM 2
#define SPADE_NUM 3
#define EMPTY_RANK -1
#define EMPTY_SUIT -1

/* external variables */
bool straight, flush, four, three;
int pairs; /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(int hand[NUM_CARDS][2]);
void analyze_hand(int hand[NUM_CARDS][2]);
void print_result(void);
bool isCardInHand(int rank, int suit, int hand[NUM_CARDS][2]);

// main: Calls read_cards, analyze_hand, and print_result repeatedly
int main(void) {
    int hand[NUM_CARDS][2];
    int num_in_rank[NUM_RANKS];
    int num_in_suit[NUM_SUITS];
    for (;;) {
        read_cards(hand);
        analyze_hand(hand);
        print_result();
    }
}

// read_cards: Reads the cards into  num_in_rank and num_in_suit; checks for bad
// cards and duplicate cards
void read_cards(int hand[NUM_CARDS][2]) {
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    for (int card = 0; card < NUM_CARDS; ++card) {
        hand[card][0] = EMPTY_RANK;
        hand[card][1] = EMPTY_SUIT;
    }

    while (cards_read < NUM_CARDS) {
        bad_card = false;
        printf("Enter a card: ");
        rank_ch = getchar();
        switch (rank_ch) {
        case '0':
            exit(EXIT_SUCCESS);
        case '2':
            rank = 0;
            break;
        case '3':
            rank = 1;
            break;
        case '4':
            rank = 2;
            break;
        case '5':
            rank = 3;
            break;
        case '6':
            rank = 4;
            break;
        case '7':
            rank = 5;
            break;
        case '8':
            rank = 6;
            break;
        case '9':
            rank = 7;
            break;
        case 't':
        case 'T':
            rank = 8;
            break;
        case 'j':
        case 'J':
            rank = 9;
            break;
        case 'q':
        case 'Q':
            rank = 10;
            break;
        case 'k':
        case 'K':
            rank = 11;
            break;
        case 'a':
        case 'A':
            rank = 12;
            break;
        default:
            bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch) {
        case 'c':
        case 'C':
            suit = CLUB_NUM;
            break;
        case 'd':
        case 'D':
            suit = DIAMOND_NUM;
            break;
        case 'h':
        case 'H':
            suit = HEART_NUM;
            break;
        case 's':
        case 'S':
            suit = SPADE_NUM;
            break;
        default:
            bad_card = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ')
                bad_card = true;

        if (bad_card)
            printf("Bad card; ignored.\n");
        else if (isCardInHand(rank, suit, hand))
            printf("Duplicate card; ignored.\n");
        else {
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            ++cards_read;
        }
    }
}

bool isCardInHand(int rank, int suit, int hand[NUM_CARDS][2]) {
    for (int card = 0; card < NUM_CARDS; ++card)
        if (hand[card][0] == rank && hand[card][1] == suit)
            return true;
    return false;
}

// analyze_hand: Determines whether the hand contains a straight, a flush,
// four-of-a-kind, and/or three-of-a-kind; determines the number of pairs;
// stores the result into the external variables straight, flush, four, three,
// and pairs
void analyze_hand(int hand[NUM_CARDS][2]) {
    int num_consec = 0;
    int rank, suit;

    // printf("top of analyze:\n");
    // for (int i = 0; i < NUM_CARDS; ++i) {
    //     printf("%d %d\n", hand[i][0], hand[i][1]);
    // }

    /* check for flush */
    flush = true;
    for (int i = 0, j = 1; j < NUM_CARDS; ++j)
        if (hand[i][1] != hand[j][1]) {
            flush = false;
            break;
        }

    /* check for straight */
    int lowestRank, lowestRankIdx;
    for (int i = 0; i < NUM_CARDS; ++i) {
        lowestRank = hand[i][0];
        lowestRankIdx = i;
        for (int j = i + 1; j < NUM_CARDS; ++j) {
            if (hand[j][0] < lowestRank) {
                lowestRank = hand[j][0];
                lowestRankIdx = j;
            }
        }
        int tmpRank = hand[i][0], tmpSuit = hand[i][1];
        hand[i][0] = hand[lowestRankIdx][0],
        hand[i][1] = hand[lowestRankIdx][1];
        hand[lowestRankIdx][0] = tmpRank, hand[lowestRankIdx][1] = tmpSuit;
    }

    straight = true;
    int prevCardRank = hand[0][0];
    for (int i = 1; i < NUM_CARDS; ++i) {
        if (hand[i][0] != prevCardRank + 1) {
            straight = false;
            break;
        }
        prevCardRank = hand[i][0];
    }

    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    four = false;
    three = false;
    pairs = 0;

    int l = 0, r = 1, sameRank = 0, highestSameRank = 0;
    while (r < NUM_CARDS) {
        sameRank = 0;
        while (r < NUM_CARDS && hand[l][0] == hand[r][0]) {
            ++r;
            ++sameRank;
        }
        if (sameRank > highestSameRank)
            highestSameRank = sameRank;
        if (sameRank == 1) {
            ++pairs;
        }
        l = r, r += 1;
    }
    if (highestSameRank == 3)
        four = true;
    else if (highestSameRank == 2)
        three = true;
}

// print_result: prints the classification of the hand, based on the values of
// the external variables straight, flush, four, three, and pairs
void print_result(void) {
    if (straight && flush)
        printf("Straight flush");
    else if (four)
        printf("Four of a kind");
    else if (three && pairs == 1)
        printf("Full house");
    else if (flush)
        printf("Flush");
    else if (straight)
        printf("Straight");
    else if (three)
        printf("Three of a kind");
    else if (pairs == 2)
        printf("Two pairs");
    else if (pairs == 1)
        printf("Pair");
    else
        printf("High card");
    printf("\n\n");
}
