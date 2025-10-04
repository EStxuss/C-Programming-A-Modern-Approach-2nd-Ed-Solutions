// calculates the factorial given an integer in order to check type limits

#include <stdio.h>

int main(void) {

    printf("Enter a positive integer: ");

    // short i, input, factorial;
    // scanf("%hd", &input);

    // int i, input, factorial;
    // scanf("%d", &input);

    // long i, input, factorial;
    // scanf("%ld", &input);

    // long long i, input, factorial;
    // scanf("%lld", &input);

    // float i, input, factorial;
    // scanf("%f", &input);

    // double i, input, factorial;
    // scanf("%lf", &input);

    long double i, input, factorial;
    scanf("%Lf", &input);

    for (i = 1, factorial = 1; i <= input; ++i)
        factorial *= i;

    // printf("%hd\n", factorial);
    // printf("Factorial of %d: %d\n", input, factorial);
    // printf("Factorial of %ld: %ld\n", input, factorial);
    // printf("Factorial of %lld: %lld\n", input, factorial);
    // printf("Factorial of %.0f: %.0f\n", input, factorial);
    // printf("Factorial of %.0f: %.0f\n", input, factorial);
    printf("Factorial of %.0Lf: %.0Lf\n", input, factorial);

    return 0;
}

// largest factorial values that worked for different types
// a) short: 7!
// b) int: 12!
// c) long: 20!
// d) long long: 20!
// e) float: 34!
// f) double: 170!
// g) long double: 1754!
