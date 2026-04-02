// displays the current time in different ways

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    FILE *fOut = fopen("output.txt", "w");
    if (!fOut) {
        fprintf(stderr, "Couldn't open file for writing\n");
        exit(EXIT_FAILURE);
    }

    time_t sec = time(NULL);
    struct tm *currTime = localtime(&sec);

    // (a) Sunday, June 3, 2007 05:48p
    char formatted[100];
    strftime(formatted, sizeof(formatted) - 1, "%A, %B%e, %Y %R%p", currTime);

    char *p = formatted;
    while (*p)
        ++p;
    while (*p != 'a' && *p != 'p' && *p != 'A' && *p != 'P') {
        *p = 0;
        --p;
    }
    *p = tolower(*p);

    fprintf(fOut, "format a: %s\n", formatted);

    // (b) Sun, 3 Jun 07 17:48
    strftime(formatted, sizeof(formatted) - 1, "%a,%e %b %y %R", currTime);
    fprintf(fOut, "format b: %s\n", formatted);

    // (c) 06/03/07 5:48:34 PM
    strftime(formatted, sizeof(formatted) - 1, "%D %T %p", currTime);
    fprintf(fOut, "format c: %s", formatted);

    return 0;
}