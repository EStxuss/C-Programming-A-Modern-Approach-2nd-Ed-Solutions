// takes a first and last name and outputs a lastname, first initial

#include <ctype.h>
#include <stdio.h>

int main(void) {
    char initial;
    printf("Enter a first and last name: ");

    while ((initial = toupper(getchar())) == ' ') // first whitespace
        ;

    char c;
    while ((c = toupper(getchar())) != ' ') // read rest of first name
        ;
    while ((c = toupper(getchar())) == ' ') // middle whitespace
        ;
    putchar(c);
    while ((c = getchar()) != ' ' && c != '\n')
        putchar(c);

    putchar(',');
    putchar(' ');
    putchar(initial);
    putchar('\n');

    return 0;
}
