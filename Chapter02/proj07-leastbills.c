// outputs how to pay an input dollar amount with least amount of bills

#include <stdio.h>

int main(void) {
    printf("Enter a dollar amount $*.00: ");

    int amt = 0;
    scanf("%d", &amt);

    int rem = amt;
    int twenties = 0;
    while (rem >= 20) {
        ++twenties;
        rem -= 20;
    }

    int tens = 0;
    while (rem >= 10) {
        ++tens;
        rem -= 10;
    }

    int fives = 0;
    while (rem >= 5) {
        ++fives;
        rem -= 5;
    }

    int ones = 0;
    while (rem >= 1) {
        ++ones;
        rem -= 1;
    }

    printf("\nLeast amount of bills to make $%d\n", amt);
    printf("\n$20 bills: %d", twenties);
    printf("\n$10 bills: %d", tens);
    printf("\n$5 bills: %d", fives);
    printf("\n$1 bills: %d\n", ones);

    return 0;
}
