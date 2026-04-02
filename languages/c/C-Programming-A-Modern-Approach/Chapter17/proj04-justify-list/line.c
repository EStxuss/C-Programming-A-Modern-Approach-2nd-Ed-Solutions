#include "line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20

struct WordNode {
    char word[MAX_WORD_LEN + 2]; // enough space for 20 letters + '*' + '\0'
    struct WordNode *next;
};

struct WordNode *line = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void) {
    if (line != NULL) {
        for (struct WordNode *p = line; p != NULL;) {
            struct WordNode *toFree = p;
            p = p->next;
            free(toFree);
        }
        line = NULL;
    }
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word) {
    struct WordNode *newWord = malloc(sizeof(struct WordNode));
    if (newWord == NULL) {
        printf("Failed to allocate memory in add_word()\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (line == NULL)
        line = newWord;
    else {
        struct WordNode *p;
        for (p = line; p->next != NULL; p = p->next)
            ;
        p->next = newWord;
        line_len += 1; // for ' '
    }

    line_len += strlen(newWord->word);
    num_words++;
}

int space_remaining(void) { return MAX_LINE_LEN - line_len; }

void write_line(void) {
    int extra_spaces, spaces_to_insert;
    extra_spaces = MAX_LINE_LEN - line_len;
    struct WordNode *p = line;
    for (struct WordNode *p = line; p != NULL; p = p->next) {
        printf("%s", p->word);

        if (num_words > 1) {
            spaces_to_insert = extra_spaces / (num_words - 1);
            extra_spaces -= spaces_to_insert;
            spaces_to_insert += 1; // for required space between words
        } else
            spaces_to_insert = 0;

        for (int i = 0; i < spaces_to_insert; ++i)
            putchar(' ');

        num_words--;
    }
    putchar('\n');
}

void flush_line(void) {
    if (line_len > 0) {
        for (struct WordNode *p = line; p != NULL; p = p->next) {
            printf("%s", p->word);
            if (p->next != NULL)
                putchar(' ');
        }
    }
    clear_line();
}
