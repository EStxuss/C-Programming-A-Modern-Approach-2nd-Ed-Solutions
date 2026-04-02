// computes a x^n using recursion and techniques

#include <stdio.h>

long power(long base, long exp);

int main(void) {
    printf("Enter the base integer: ");
    long base;
    scanf("%ld", &base);

    printf("Enter the exponent integer: ");
    long exp;
    scanf("%ld", &exp);

    printf("Answer: %ld\n", power(base, exp));

    return 0;
}

long power(long base, long exp) {
    if (exp == 0)
        return 1;

    if (exp % 2 == 0) {
        long part = power(base, exp / 2);
        return part * part;
    } else
        return base * power(base, exp - 1);
}
