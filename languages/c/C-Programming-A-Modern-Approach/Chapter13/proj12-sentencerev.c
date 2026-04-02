// reverses word order of an input sentence

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define WORD_AMT 30
#define WORD_LEN 20

int readWords(char words[WORD_AMT][WORD_LEN + 1]);
void printWordsReverse(int numWords, char words[WORD_AMT][WORD_LEN + 1]);

int main(void) {
    printf("Enter sentence: ");

    char words[WORD_AMT][WORD_LEN + 1];
    int numWords = readWords(words);

    printWordsReverse(numWords, words);

    return 0;
}

int readWords(char words[WORD_AMT][WORD_LEN + 1]) {
    char c = getchar();
    int currWord = 0, j;
    while (c != '\n' && currWord < WORD_AMT) {
        while (c == ' ')
            c = getchar();
        if (c == '\n')
            continue;
        for (j = 0; j < WORD_LEN && !isspace(c); c = getchar(), ++j)
            words[currWord][j] = c;
        words[currWord][j] = '\0';
        ++currWord;
    }
    return currWord;
}

void printWordsReverse(int numWords, char words[WORD_AMT][WORD_LEN + 1]) {
    // get puncuation mark
    char *p = words[numWords - 1], punc;
    while (*p)
        ++p;
    if ((strcmp(--p, ".") == 0 || strcmp(p, "?") == 0 || strcmp(p, "!") == 0) &&
        strlen(words[0]) < WORD_LEN) {
        strcat(words[0], p);
        *p = '\0';
    } else if (strlen(words[0]) < WORD_LEN)
        // period by default if no punctuation was present
        strcat(words[0], ".");

    for (int i = numWords - 1; i >= 0; --i)
        printf("%s ", words[i]);
}
