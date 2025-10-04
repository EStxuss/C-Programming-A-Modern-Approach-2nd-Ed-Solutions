// outputs whether a number has a repeated digit
// loops until the input is <= zero

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    bool seen[10] = {false};

    long long input;
    int dig;

    printf("Enter a positive integer (0 to terminate): ");
    scanf("%lld", &input);

    while (input > 0) {
        while (input > 0) {
            dig = input % 10;
            input /= 10;

            if (seen[dig])
                break;
            else
                seen[dig] = true;
        }

        for (int i = 0; i < 10; ++i)
            seen[i] = false;

        if (input > 0)
            printf("Repeated digit\n");
        else
            printf("No repeated digit\n");

        printf("Enter a positive integer (0 to terminate): ");
        scanf("%lld", &input);
    }

    return 0;
}
