// calculates the value of savings after the input number of years and the
// interest rate

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double origAmt, rate;
    int years;

    printf("Enter original amount: $");
    int read = scanf("%lf", &origAmt);

    printf("Enter annual rate: ");
    read += scanf("%lf", &rate);

    printf("Enter number of years: ");
    read += scanf("%d", &years);

    if (read != 3) {
        fprintf(stderr, "Couldn't get all values from user\n");
        exit(EXIT_FAILURE);
    }

    double finalAmt = origAmt * exp(rate * years);

    printf("\nFinal value: $%.2f\n", finalAmt);

    return EXIT_SUCCESS;
}