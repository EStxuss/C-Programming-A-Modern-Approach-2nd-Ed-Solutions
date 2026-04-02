// finds the roots of the equation ax2 + bx + c = 0 given an a, b, and c from
// the user

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Enter values:\na = ");
    double a, b, c;
    int n = scanf("%lf", &a);

    printf("b = ");
    n += scanf("%lf", &b);

    printf("c = ");
    n += scanf("%lf", &c);

    if (n != 3) {
        fprintf(stderr, "Didn't recieve values for a, b, or c\n");
        exit(EXIT_FAILURE);
    }

    double rad = pow(b, 2.0) - 4 * a * c;
    if (rad < 0.0) {
        printf("Roots are complex\n");
    } else {
        double root = sqrt(rad);
        double addRes = (-b + root) / (2 * a);
        double minusRes = (-b - root) / (2 * a);

        printf("\nx = %f and %f\n", addRes, minusRes);
    }

    return EXIT_SUCCESS;
}