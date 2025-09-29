// outputs squares of numbers to test limits of type sizes

#include <limits.h>
#include <stdio.h>

int main(void) {
    printf("What type to test 1(short), 2(int), 3(long): ");
    int typeSelect;
    scanf("%d", &typeSelect);

    if (typeSelect == 1) {
        long long shouldBe;
        short square;
        short i;
        for (i = 1, square = 1, shouldBe = 1; shouldBe == square;
             ++i, shouldBe = (long long)i * i, square = i * i)
            printf("%hd%15hd\n", i, square);
        printf("%hd%15hd\nshould have been: %lld\n", i, square, shouldBe);
    } else if (typeSelect == 2) {
        long long shouldBe;
        int square;
        int i;
        for (i = 1, square = 1, shouldBe = 1; shouldBe == square;
             ++i, shouldBe = (long long)i * i, square = i * i)
            printf("%d%15d\n", i, square);
        printf("%d%15d\nshould have been: %lld\n", i, square, shouldBe);
    } else if (typeSelect == 3) {
        long square;
        long i;
        for (i = 3036150177, square = i * i; (LLONG_MAX / i) >= i;
             i += 1, square = i * i)
            printf("%ld%30ld\n", i, square);
        printf("The next square would've overflowed\n");
    }

    return 0;
}
