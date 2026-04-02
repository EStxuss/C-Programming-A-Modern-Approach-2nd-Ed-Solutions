// opens a file whose name is passed as a command line argument and outputs it's
// contents capitalized to the console

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: capitalize textfile\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("unable to open file %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = getc(fp)) != EOF) {
        if (isalpha(ch))
            putchar(toupper(ch));
        else
            putchar(ch);
    }

    fclose(fp);

    return 0;
}