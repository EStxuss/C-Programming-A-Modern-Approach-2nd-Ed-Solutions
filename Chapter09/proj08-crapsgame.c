// plays games of craps until player quits

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void);
bool playGame(void);

int main(void) {
    srand((unsigned)(time(NULL)));

    bool playAgain = true;
    int win = 0, lose = 0;
    while (playAgain) {
        if (playGame()) {
            printf("\nYou Win!\n");
            ++win;
        } else {
            printf("\nYou Lose!\n");
            ++lose;
        }
        printf("Wins: %d   Losses: %d\n", win, lose);

        printf("\nPlay again? (y/n): ");
        playAgain = tolower(getchar()) == 'y';
        getchar();
    }

    return 0;
}

int rollDice(void) { return (rand() % 6 + 1) + (rand() % 6 + 1); }

bool playGame(void) {
    int roll = rollDice();

    printf("\nYou rolled: %d\n", roll);

    int point;
    switch (roll) {
    case 2:
    case 3:
    case 12:
        return false;
    case 7:
    case 11:
        return true;
    default:
        point = roll;
        printf("Your point is %d\n", point);
        break;
    }

    roll = -1;
    while (roll != point && roll != 7) {
        roll = rollDice();
        printf("You rolled: %d\n", roll);
    }

    return roll == point;
}
