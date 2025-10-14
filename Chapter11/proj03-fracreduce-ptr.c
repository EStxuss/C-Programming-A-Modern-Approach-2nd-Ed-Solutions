// asks for a fraction and then outputs reduced version to lowest terms

#include <stdio.h>

void reduce(int numerator, int denominator, int *reducedNumerator,
            int *reducedDenominator);

int main(void) {
    int num, den;
    printf("Enter a fraction: ");
    scanf("%d / %d", &num, &den);

    reduce(num, den, &num, &den);

    printf("In lowest terms: %d/%d\n", num, den);

    return 0;
}

void reduce(int numerator, int denominator, int *reducedNumerator,
            int *reducedDenominator) {
    int m = denominator, n = numerator, rem;
    while (n != 0) {
        rem = m % n;
        m = n;
        n = rem;
    }

    *reducedDenominator = denominator / m;
    *reducedNumerator = numerator / m;
}
