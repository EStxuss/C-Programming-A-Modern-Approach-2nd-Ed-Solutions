// takes a word and outputs the scrabble value of the word

#include <ctype.h>
#include <stdio.h>

#define LEN 50

int computeScrabbleVal(const char *word);

int main(void) {
    printf("Enter a word: ");
    char word[LEN + 1];
    scanf("%50s", word);

    printf("Scrabble value: %d\n", computeScrabbleVal(word));

    return 0;
}

int computeScrabbleVal(const char *word) {
    // a - z scrabble vals
    static const int vals[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                               1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int total = 0;
    int num = 0;
    while (*word) {
        if (isalpha(*word))
            total += vals[toupper(*word) - 'A'];
        ++word;
    }

    return total;
}
