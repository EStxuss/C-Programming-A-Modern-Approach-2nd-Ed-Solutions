// Takes a dollar amount and inputs the least number of bills to make said
// dollar amount

#include <stdio.h>

void payAmount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void) {
    printf("Enter a whole dollar amount: ");

    int dollars;
    scanf(" %d", &dollars);

    int twenties, tens, fives, ones;
    payAmount(dollars, &twenties, &tens, &fives, &ones);

    printf("\nLeast amount of bills to make $%d\n$20 bills: %d\n$10 bills: "
           "%d\n$5 bills: %d\n$1 bills: %d\n",
           dollars, twenties, tens, fives, ones);

    return 0;
}

void payAmount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    *twenties = dollars / 20;
    dollars %= 20;

    *tens = dollars / 10;
    dollars %= 10;

    *fives = dollars / 5;
    dollars %= 5;

    *ones = dollars;
}
