// takes input firstname lastname and outputs lastname, firstinitial

#include <ctype.h>
#include <stdio.h>

#define SIZE 20

int main(void) {
    char c, firstInit, lastName[SIZE];

    printf("Enter a first and last name: ");

    while ((c = toupper(getchar())) == ' ')
        ;

    firstInit = c;

    while ((c = getchar()) != ' ')
        ;

    while ((c = toupper(getchar())) == ' ')
        ;

    lastName[0] = c;
    int i;
    for (i = 1, c = getchar(); c != '\n' && c != ' ' && i < SIZE;
         c = getchar(), ++i)
        lastName[i] = tolower(c);

    printf("You entered the name: ");
    for (int j = 0; j < i && j < SIZE; ++j)
        putchar(lastName[j]);
    printf(", %c.\n", firstInit);

    return 0;
}
