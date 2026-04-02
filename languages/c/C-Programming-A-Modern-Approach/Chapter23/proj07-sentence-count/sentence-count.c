// counts the number of sentences assuming a sentence ends with '.', '!', or '?'
// followed by a whitespace character

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define PUNCT_STR ".!?"

int main(void) {
    int ch, count = 0;
    bool foundPunct = false;
    while ((ch = getc(stdin)) != EOF) {
        if (foundPunct && isspace(ch)) {
            ++count;
            foundPunct = false;
        } else if (strchr(PUNCT_STR, ch) != NULL)
            foundPunct = true;
        else
            foundPunct = false;
    }

    printf("There are %d sentences\n", count);

    return 0;
}