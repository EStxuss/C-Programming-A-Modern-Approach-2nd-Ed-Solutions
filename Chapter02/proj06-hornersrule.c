// computes ((((3x + 2)x – 5)x – 1)x + 7)x – 6 for a given x

#include <stdio.h>

int main(void) {
    float x = 0.0f;

    printf("((((3x + 2)x – 5)x – 1)x + 7)x – 6\nEnter x: ");

    scanf("%f", &x);

    double ans = (((((3 * x + 2) * (x - 5)) * (x - 1)) * (x + 7)) * (x - 6));

    printf("The answer to the polynomial for x = %.3f is: %.3f\n", x, ans);
}
