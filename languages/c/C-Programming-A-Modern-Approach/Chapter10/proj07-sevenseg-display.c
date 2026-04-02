// takes a number <= 10 digits and displays it in a simulated seven segment
// display

// I got confused by what the segments array was supposed to be so how I did
// processDigit() is slightly different that the intended solution

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_DIGITS 10
#define DIGIT_HEIGHT 3
#define DIGIT_WIDTH 3
#define SPACES_BETWEEN 3

bool segments[MAX_DIGITS][7] = {false};
char digits[DIGIT_HEIGHT][MAX_DIGITS * (DIGIT_WIDTH + SPACES_BETWEEN)];

void clearDigitsArray(void);
void processDigit(int digit, int position);
void printDigitsArray(void);

int main(void) {
    printf("Enter a number: ");

    char c;
    int digsEntered = 0;

    clearDigitsArray();
    while (digsEntered < 10 && (c = getchar()) != '\n') {
        if (isdigit(c)) {

            processDigit(c - '0', digsEntered);

            ++digsEntered;
        }
    }

    printDigitsArray();

    return 0;
}

void clearDigitsArray(void) {
    for (int row = 0; row < DIGIT_HEIGHT; ++row) {
        for (int col = 0; col < MAX_DIGITS * (DIGIT_WIDTH + SPACES_BETWEEN);
             ++col) {
            digits[row][col] = ' ';
        }
    }
}

void processDigit(int dig, int position) {
    // set the segments that appear for the input digit
    for (int i = position, j = 0; j < 7; ++j) {
        switch (j) {
        case 0:
            segments[i][j] = dig == 0 || dig == 2 || dig == 3 || dig == 5 ||
                             dig == 6 || dig == 7 || dig == 8 || dig == 9;
            break;
        case 1:
            segments[i][j] = dig == 0 || dig == 1 || dig == 2 || dig == 3 ||
                             dig == 4 || dig == 7 || dig == 8 || dig == 9;
            break;
        case 2:
            segments[i][j] = dig == 0 || dig == 1 || dig == 3 || dig == 4 ||
                             dig == 5 || dig == 6 || dig == 7 || dig == 8 ||
                             dig == 9;
            break;
        case 3:
            segments[i][j] = dig == 0 || dig == 2 || dig == 3 || dig == 5 ||
                             dig == 6 || dig == 8 || dig == 9;
            break;
        case 4:
            segments[i][j] = dig == 0 || dig == 2 || dig == 6 || dig == 8;
            break;
        case 5:
            segments[i][j] = dig == 0 || dig == 4 || dig == 5 || dig == 6 ||
                             dig == 8 || dig == 9;
            break;
        case 6:
            segments[i][j] = dig == 2 || dig == 3 || dig == 4 || dig == 5 ||
                             dig == 6 || dig == 8 || dig == 9;
            break;
        }
    }

    int colOffset = (DIGIT_WIDTH + SPACES_BETWEEN) * position;
    for (int i = 0; i < 7; ++i) {
        if (segments[position][i]) {
            int row, col = colOffset;
            bool underscore = false;
            if (i == 0 || i == 6 || i == 3) {
                col += 1;
                underscore = true;
            } else if (i == 1 || i == 2)
                col += 2;

            if (i == 1 || i == 6 || i == 5)
                row = 1;
            else if (i == 2 || i == 3 || i == 4)
                row = 2;
            else
                row = 0;

            digits[row][col] = (underscore) ? '_' : '|';
        }
    }
}

void printDigitsArray(void) {
    for (int i = 0; i < DIGIT_HEIGHT; ++i) {
        for (int j = 0; j < MAX_DIGITS * (DIGIT_WIDTH + SPACES_BETWEEN); ++j) {
            putchar(digits[i][j]);
        }
        putchar('\n');
    }
}
