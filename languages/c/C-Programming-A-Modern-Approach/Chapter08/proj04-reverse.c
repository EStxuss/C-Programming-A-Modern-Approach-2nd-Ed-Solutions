// reverses a series of numbers

#include <stdio.h>

#define SIZE (int)(sizeof(input) / sizeof(input[0]))

int main(void) {
    printf("Enter ten integers: ");

    int input[10] = {0};

    for (int i = 0; i < SIZE; ++i)
        scanf("%d", &input[i]);

    printf("Numbers reversed: ");
    for (int i = SIZE - 1; i >= 0; --i)
        printf("%d ", input[i]);
    printf("\n");

    return 0;
}
