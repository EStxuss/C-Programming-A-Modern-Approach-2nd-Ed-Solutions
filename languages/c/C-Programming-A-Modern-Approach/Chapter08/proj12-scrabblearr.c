// calculates scrabble value of an input word

#include <ctype.h>
#include <stdio.h>

int main(void) {
    int total = 0, values[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                                 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char c;

    printf("Enter a word: ");
    while ((c = toupper(getchar())) != '\n')
        if (c >= 'A' && c <= 'Z')
            total += values[c - 'A'];

    printf("Scrabble value: %d\n", total);

    return 0;
}
