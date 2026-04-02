// takes lines of text and removes any blank lines or the beginning whitespace
// of a line of text

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int ch;
    bool nonBlank = false;
    while (!feof(stdin)) {
        while ((ch = getc(stdin)) != EOF && isspace(ch) && ch != '\n')
            ;

        while (ch != EOF && ch != '\n') {
            nonBlank = true;
            putchar(ch);
            ch = getc(stdin);
        }

        if (ch == '\n' && nonBlank)
            putchar(ch);
        nonBlank = false;
    }

    return EXIT_SUCCESS;
}