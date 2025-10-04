// takes a 5x5 integer matrix and outputs col and row sums

#include <stdio.h>

int main(void) {
    int num[5][5];
    for (int row = 0; row < 5; ++row) {
        printf("Enter row %d: ", row + 1);
        for (int col = 0; col < 5; ++col)
            scanf("%d", &num[row][col]);
    }

    printf("Row sums:");
    int sum = 0;
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 5; ++col)
            sum += num[row][col];
        printf(" %d", sum);
        sum = 0;
    }

    printf("\nColumn sums: ");
    for (int col = 0; col < 5; ++col) {
        for (int row = 0; row < 5; ++row)
            sum += num[row][col];
        printf(" %d", sum);
        sum = 0;
    }
    printf("\n");

    return 0;
}
