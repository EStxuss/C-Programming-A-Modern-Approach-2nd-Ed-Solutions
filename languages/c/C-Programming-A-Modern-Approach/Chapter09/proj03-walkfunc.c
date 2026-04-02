// tries generates a random path in a 10x10 matrix going from A - Z as it
// travels

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define EMPTY_CELL '.'

void generateRandomWalk(char board[SIZE][SIZE]);
void printWalk(char board[SIZE][SIZE]);

int main(void) {
    srand((unsigned)time(NULL));

    char board[SIZE][SIZE];

    generateRandomWalk(board);

    printWalk(board);

    return 0;
}

void generateRandomWalk(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            board[i][j] = EMPTY_CELL;

    board[0][0] = 'A';

    char nextChar = 'B';
    bool placed = false;
    bool checked[4] = {false};
    int nextMove, currRow = 0, currCol = 0;
    while (nextChar <= 'Z') {
        placed = false;
        while (!placed) {
            if (checked[UP] && checked[RIGHT] && checked[DOWN] && checked[LEFT])
                return;

            nextMove = rand() % 4;
            while (checked[nextMove])
                nextMove = rand() % 4;

            switch (nextMove) {
            case UP:
                checked[UP] = true;
                if (currRow - 1 >= 0 &&
                    board[currRow - 1][currCol] == EMPTY_CELL) {
                    currRow -= 1;
                    board[currRow][currCol] = nextChar++;
                    placed = true;
                }
                break;
            case RIGHT:
                checked[RIGHT] = true;
                if (currCol + 1 < SIZE &&
                    board[currRow][currCol + 1] == EMPTY_CELL) {
                    currCol += 1;
                    board[currRow][currCol] = nextChar++;
                    placed = true;
                }
                break;
            case DOWN:
                checked[DOWN] = true;
                if (currRow + 1 < SIZE &&
                    board[currRow + 1][currCol] == EMPTY_CELL) {
                    currRow += 1;
                    board[currRow][currCol] = nextChar++;
                    placed = true;
                }
                break;
            case LEFT:
                checked[LEFT] = true;
                if (currCol - 1 >= 0 &&
                    board[currRow][currCol - 1] == EMPTY_CELL) {
                    currCol -= 1;
                    board[currRow][currCol] = nextChar++;
                    placed = true;
                }
                break;
            }

            if (placed)
                for (int i = 0; i < 4; ++i)
                    checked[i] = false;
        }
    }
}

void printWalk(char board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col)
            printf("%2c", board[row][col]);
        printf("\n");
    }
}
