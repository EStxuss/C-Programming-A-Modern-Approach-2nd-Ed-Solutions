// sums a series of doubles entered by the user

#include <stdio.h>

int main(void) {
    printf("Enter doubles, 0 to quit: ");

    double input;
    double sum = 0.0;
    do {
        scanf("%lf", &input);
        sum += input;
    } while (input != 0.0);

    printf("The sum is: %f\n", sum);

    return 0;
}
