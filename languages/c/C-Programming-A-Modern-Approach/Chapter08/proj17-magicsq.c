// constructs a magic square of input size

#include <stdio.h>

#define EMPTY_CELL -1

int main(void) {

    int size;
    do {
        printf("Enter size of magic square (odd, 1-99): ");
        scanf("%d", &size);
    } while (size % 2 == 0 || size < 1 || size > 99);

    int magic[size][size];
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            magic[i][j] = EMPTY_CELL;

    for (int row = 0, col = size / 2, i = 1; i <= size * size; ++i) {
        int prevRow = row, prevCol = col;
        magic[row][col] = i;
        if (i == size * size)
            break;
        row = (row - 1 < 0) ? size - 1 : row - 1;
        col = (col + 1 >= size) ? 0 : col + 1;
        while (magic[row][col] != EMPTY_CELL) {
            col = prevCol;
            int tmp = row;
            row = (prevRow + 1 < size) ? prevRow + 1 : 0;
            prevRow = tmp;
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            printf("%-5d", magic[i][j]);
        printf("\n");
    }

    return 0;
}
