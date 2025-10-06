// takes x as input and solves 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6

#include <stdio.h>

double polySolve(double x);

int main(void) {
    printf("3x^5 + 2x^4 – 5x^3 – x^2 + 7x – 6\nEnter x: ");

    double x;
    scanf("%lf", &x);

    printf("answer: %.2f\n", polySolve(x));

    return 0;
}

double polySolve(double x) {
    return (3.0 * x * x * x * x * x) + (2.0 * x * x * x * x) - (5 * x * x * x) -
           (x * x) + (7 * x) - 6;
}
