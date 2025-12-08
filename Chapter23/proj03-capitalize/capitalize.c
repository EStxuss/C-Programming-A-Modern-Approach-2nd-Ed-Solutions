// capitalizes each word of a text file gotten from input redirection

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int ch;
    bool inWhitespace = true;
    while ((ch = getc(stdin)) != EOF) {
        if (isspace(ch)) {
            inWhitespace = true;
        } else if (inWhitespace && !isspace(ch)) {
            inWhitespace = false;
            ch = toupper(ch);
        }
        putc(ch, stdout);
    }
    return 0;
}