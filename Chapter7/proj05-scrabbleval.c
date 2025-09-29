// takes a word and outputs the scrabble value of the word

#include <ctype.h>
#include <stdio.h>

int main(void) {
    char c;
    int total = 0;
    printf("Enter a word: ");
    while ((c = getchar()) != '\n') {
        c = toupper(c);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'L' || c == 'N' ||
            c == 'O' || c == 'R' || c == 'S' || c == 'T' || c == 'U')
            total += 1;
        else if (c == 'D' || c == 'G')
            total += 2;
        else if (c == 'B' || c == 'C' || c == 'M' || c == 'P')
            total += 3;
        else if (c == 'F' || c == 'H' || c == 'V' || c == 'W' || c == 'Y')
            total += 4;
        else if (c == 'K')
            total += 5;
        else if (c == 'J' || c == 'X')
            total += 8;
        else if (c == 'Q' || c == 'Z')
            total += 10;
    }
    printf("Scrabble value: %d\n", total);

    return 0;
}
