#include "word.h"
#include <stdio.h>

int read_char(void) {
    int ch = getchar();
    if (ch == '\n' || ch == '\t')
        return ' ';
    return ch;
}

void read_word(char *word, int len) {
    int ch, pos = 0, actualLen = 0;
    while ((ch = read_char()) == ' ')
        ;
    while (ch != ' ' && ch != EOF) {
        if (pos < len)
            word[pos++] = ch;
        ++actualLen;
        ch = read_char();
    }
    if (actualLen > MAX_WORD_LEN) {
        word[MAX_WORD_LEN] = '*';
        word[MAX_WORD_LEN + 1] = '\0';
    } else
        word[pos] = '\0';
}
