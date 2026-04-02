/* Formats a file of text */

#include "line.h"
#include "word.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: justify input-file output-file");
        exit(EXIT_FAILURE);
    }

    FILE *fpIn = fopen(argv[1], "r");
    if (fpIn == NULL) {
        fprintf(stderr, "Couldn't open read file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *fpOut = fopen(argv[2], "w");
    if (fpOut == NULL) {
        fprintf(stderr, "Couldn't open write file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LEN + 2];
    int word_len;
    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN + 1, fpIn);
        word_len = strlen(word);
        if (word_len == 0) {
            flush_line(fpOut);
            return 0;
        }
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (word_len + 1 > space_remaining()) {
            write_line(fpOut);
            clear_line();
        }
        add_word(word);
    }

    fclose(fpIn);
    fclose(fpOut);

    return 0;
}
