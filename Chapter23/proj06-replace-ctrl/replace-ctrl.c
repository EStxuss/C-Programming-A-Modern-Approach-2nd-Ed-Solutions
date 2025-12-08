// replaces any control character in the input redirected file with '?' and
// outputs it to stdout

#include <ctype.h>
#include <stdio.h>

int main(void) {

    int ch;
    while ((ch = getc(stdin)) != EOF) {
        if (iscntrl(ch) && ch != '\n')
            ch = '?';
        putchar(ch);
    }

    return 0;
}