// takes a first and last name and outputs a lastname, first initial

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

void reverseName(char *name);

int main(void) {
    printf("Enter first and last name: ");
    char name[MAX_LEN + 1];
    fgets(name, MAX_LEN + 1, stdin);

    reverseName(name);

    puts(name);

    return 0;
}

void reverseName(char *name) {
    char *p = name, *l, firstInit[2], lastName[MAX_LEN + 1];

    while (*p && isspace(*p))
        ++p;
    firstInit[0] = toupper(*p);
    firstInit[1] = '\0';

    while (*p && !isspace(*p))
        ++p;
    while (*p && isspace(*p))
        ++p;

    int i = 0;
    while (i < MAX_LEN && *p && !isspace(*p))
        lastName[i++] = *p++;
    lastName[i] = '\0';
    *lastName = toupper(*lastName);

    strcpy(name, lastName);
    strcat(name, ", ");
    strcat(name, firstInit);
    strcat(name, ".");
}
