#include "word.h"
#include <stdio.h>

int read_char(FILE *fp) {
    int ch = getc(fp);
    if (ch == '\n' || ch == '\t')
        return ' ';
    return ch;
}

void read_word(char *word, int len, FILE *fp) {
    int ch, pos = 0;
    while ((ch = read_char(fp)) == ' ')
        ;
    while (ch != ' ' && ch != EOF) {
        if (pos < len)
            word[pos++] = ch;
        ch = read_char(fp);
    }
    word[pos] = '\0';
}
