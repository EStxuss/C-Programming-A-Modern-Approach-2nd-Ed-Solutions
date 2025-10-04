// reverses word order of an input sentence

#include <stdio.h>

#define SIZE 150
#define WORD_SIZE 50

int main(void) {
    char c, punc = '.', sentence[SIZE] = {0};

    printf("Enter a sentence: ");
    int i;
    for (i = 0, c = getchar(); i < SIZE && c != '?' && c != '.' && c != '!';
         ++i, c = getchar())
        sentence[i] = c;
    punc = c;

    printf("Reversal of sentence: ");
    char word[50] = {'\0'};
    int wordSize = 0;
    for (int j = i - 1; j >= 0; --j) {
        if (sentence[j] == ' ')
            continue;
        else {
            for (int k = 0; j >= 0 && sentence[j] != ' ' && k < WORD_SIZE;
                 ++k, --j) {
                word[k] = sentence[j];
                ++wordSize;
            }
        }
        for (int k = wordSize - 1; k >= 0; --k)
            putchar(word[k]);
        if (j >= 0)
            putchar(' ');
        wordSize = 0;
    }

    if (punc == '.' || punc == '?' || punc == '!')
        printf("%c\n", punc);
    else
        printf(".\n");

    return 0;
}
