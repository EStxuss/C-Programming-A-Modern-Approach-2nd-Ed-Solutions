// displays which digits were repeated in the number input

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

    printf("Repeated digits: ");
    for (int i = 0; i < 10; ++i)
        if (seen[i] >= 2)
            printf("%d ", i);
    printf("\n");

    return 0;
}
