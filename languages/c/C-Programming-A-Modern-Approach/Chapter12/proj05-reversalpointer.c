// reverses word order of an input sentence.
// uses a pointer to keep track of position in array

#include <stdio.h>

#define SIZE 150
#define WORD_SIZE 50

int main(void) {
    char c, *p, punc = '.', sentence[SIZE] = {0};

    printf("Enter a sentence: ");
    int len = 0;
    for (p = sentence, c = getchar();
         p < sentence + SIZE && c != '?' && c != '.' && c != '!';
         ++p, c = getchar(), ++len)
        *p = c;
    punc = c;

    printf("Reversal of sentence: ");
    char word[WORD_SIZE] = {'\0'};
    int wordSize = 0;
    for (char *p = sentence + len - 1; p >= sentence; --p) {
        if (*p == ' ')
            continue;
        else {
            for (char *wp = word;
                 p >= sentence && *p != ' ' && wp < word + WORD_SIZE;
                 ++wp, --p) {
                *wp = *p;
                ++wordSize;
            }
        }
        for (char *wp = word + wordSize - 1; wp >= word; --wp)
            putchar(*wp);
        if (p >= sentence)
            putchar(' ');
        wordSize = 0;
    }

    if (punc == '.' || punc == '?' || punc == '!')
        printf("%c\n", punc);
    else
        printf(".\n");

    return 0;
}
