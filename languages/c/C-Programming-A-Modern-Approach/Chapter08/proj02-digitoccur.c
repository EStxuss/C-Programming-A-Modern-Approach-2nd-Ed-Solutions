// displays how many times each digit appeared in the input integer

#include <stdio.h>

int main(void) {
    int seen[10] = {0};

    printf("Enter an integer: ");
    long long input;
    scanf("%lld", &input);

    while (input > 0) {
        ++seen[input % 10];
        input /= 10;
    }

    printf("Digit:");
    for (int i = 0; i < 10; ++i)
        if (i == 0)
            printf("%8d", i);
        else
            printf("%3d", i);

    printf("\nOccurences:");
    for (int i = 0; i < 10; ++i)
        printf("%3d", seen[i]);
    putchar('\n');

    return 0;
}
