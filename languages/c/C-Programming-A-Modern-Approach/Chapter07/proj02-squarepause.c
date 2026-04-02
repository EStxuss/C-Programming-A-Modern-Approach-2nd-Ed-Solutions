// prints table of squares with pauses every 24 squares

#include <stdio.h>

int main(void) {
    int entries;
    printf("How many entires in the squares table ( > 25 ): ");
    scanf("%d", &entries);
    getchar();

    for (int i = 1, sq = i; i <= entries; ++i, sq = i * i) {
        printf("%d%15d\n", i, sq);

        if (i % 24 == 0) {
            printf("Press ENTER to continue...\n");
            while (getchar() != '\n')
                ;
        }
    }
    return 0;
}
