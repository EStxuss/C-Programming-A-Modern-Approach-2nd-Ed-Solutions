// approximates square root of floating point using newtons method

#include <math.h>
#include <stdio.h>

int main(void) {
    printf("Enter a positive number: ");
    double x;
    scanf("%lf", &x);

    double y = 1.0, oldY = 2.0;
    while ((fabs(oldY - y)) >= (0.00001 * y)) {
        oldY = y;

        y = ((y + x / y) / 2);
        printf("%f\n", y);
    }

    printf("Square root: %f\n", y);

    return 0;
}
