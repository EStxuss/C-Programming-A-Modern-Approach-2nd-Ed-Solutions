// prints 1000 rand values 0 if even 1 if odd

/*
the problem tells us to determine if theres some repeating pattern, but
I don't see one probably because the author used a different version of rand
than I did

If the low order bits in a different version were predictable, you could first
divide by some number before using modulus to get the range

The answer given in the book is dividing rand's return by RAND_MAX / (n + 1) for
the range 0 - (n - 1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));

    for (int i = 0; i < 1000; ++i) {
        printf("%d", rand() % 2);
    }
    printf("\n");

    return 0;
}