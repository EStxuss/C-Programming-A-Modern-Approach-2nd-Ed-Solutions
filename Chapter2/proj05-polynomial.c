// computes the polynomial 3x^5 + 2x^4 – 5x^3 – x^2 + 7x – 6 for a given x

#include <stdio.h>

int main(void) {
    float x = 0.0f;

    printf("3x^5 + 2x^4 – 5x^3 – x^2 + 7x – 6\nEnter x: ");

    scanf("%f", &x);

    double ans = (3 * x * x * x * x * x) + (2 * x * x * x * x) -
                 (5 * x * x * x) - (x * x) + (7 * x) - 6;

    printf("The answer to the polynomial for x = %.3f is: %.3f\n", x, ans);
}
