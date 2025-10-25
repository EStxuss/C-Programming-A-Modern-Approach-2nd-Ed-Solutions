#include "line.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line(void) {
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word) {
    if (num_words > 0) {
        line[line_len] = ' ';
        line[line_len + 1] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void) { return MAX_LINE_LEN - line_len; }

void write_line(void) {
    int extra_spaces = MAX_LINE_LEN - line_len;

    // determine between which words get extra spaces
    int betweenWordsSlots = num_words - 1;

    int spacesAmt[betweenWordsSlots];
    for (int i = 0; i < betweenWordsSlots; ++i)
        spacesAmt[i] = 1;

    int l, r;
    bool placedR;
    while (extra_spaces > 0) {
        for (l = 0, r = betweenWordsSlots - 1, placedR = false;
             extra_spaces > 0 && l < r; --extra_spaces) {
            if (!placedR) {
                ++spacesAmt[r--];
                placedR = true;
            } else {
                ++spacesAmt[l++];
                placedR = false;
            }
        }
    }

    int currSpaceIdx = 0;
    for (int i = 0; i < line_len; i++) {
        if (line[i] != ' ')
            putchar(line[i]);
        else {
            for (int j = 0; j < spacesAmt[currSpaceIdx]; j++)
                putchar(' ');
            ++currSpaceIdx;
        }
    }
    putchar('\n');
}

void flush_line(void) {
    if (line_len > 0)
        puts(line);
}
