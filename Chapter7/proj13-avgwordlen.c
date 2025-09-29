// calculates average word length of a sentence

#include <stdio.h>

int main(void) {
    printf("Enter a sentence: ");

    char c = ' ';
    int wordLen = 0;
    int wordAmt = 0;
    int letterTotal = 0;
    while (c != '\n') {
        while ((c = getchar()) == ' ')
            ;
        ++wordLen;

        if (c == '\n')
            break;

        while ((c = getchar()) != ' ' && c != '\n')
            ++wordLen;

        // printf("word length was: %d\n", wordLen);
        letterTotal += wordLen;
        ++wordAmt;
        wordLen = 0;
    }

    printf("Average word length: %.1f\n", (float)letterTotal / wordAmt);

    return 0;
}
