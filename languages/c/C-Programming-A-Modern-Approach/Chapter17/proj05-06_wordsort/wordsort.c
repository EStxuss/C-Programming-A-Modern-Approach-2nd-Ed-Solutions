#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_LEN 20

int read_line(char str[], int n);
int strCompare(const void *str1, const void *str2);

int main(void) {
    char *words[MAX_WORDS] = {NULL}, nextWord[MAX_LEN + 1];
    int wordsRead = 0;
    for (;;) {
        printf("Enter a word: ");
        read_line(nextWord, MAX_LEN);

        if (strcmp(nextWord, "") == 0)
            break;

        words[wordsRead] = malloc(strlen(nextWord) + 1);
        if (words[wordsRead] == NULL) {
            printf("Failed to allocate word.\n");
            break;
        }
        strcpy(words[wordsRead], nextWord);
        ++wordsRead;
        if (wordsRead >= 50) {
            printf("Max words read.\n");
            break;
        }
    }

    qsort(words, wordsRead, sizeof(char *), strCompare);

    printf("In sorted order: ");
    for (int i = 0; i < wordsRead; ++i) {
        printf("%s ", words[i]);
    }
    printf("\n");

    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

int strCompare(const void *str1, const void *str2) {
    return strcmp(*(const char **)str1, *(const char **)str2);
}
