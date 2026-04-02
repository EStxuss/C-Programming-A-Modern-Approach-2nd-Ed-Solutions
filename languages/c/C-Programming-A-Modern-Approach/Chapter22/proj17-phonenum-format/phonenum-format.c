// takes a file as a cli arg that contains phones numbers in no single format
// and outputs them formatted the same way.
// assumes 10 digits per line of file

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define PHONENUM_DIGS 10

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: phonenum-format inputfile\n");
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    FILE *fpIn = fopen(filename, "r");
    if (fpIn == NULL) {
        fprintf(stderr, "Couldn't open read file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int ch, size, digits[PHONENUM_DIGS];
    while ((ch = getc(fpIn)) != EOF) {
        size = 0;
        do {
            if (isdigit(ch))
                digits[size++] = ch;
            ch = getc(fpIn);
        } while (ch != EOF && ch != '\n' && size < 10);

        if (size != PHONENUM_DIGS) {
            fprintf(stderr,
                    "Line of file %s contained more or less than %d digits\n",
                    filename, PHONENUM_DIGS);
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < PHONENUM_DIGS; ++i) {
            if (i == 0)
                putchar('(');
            putchar(digits[i]);

            if (i == 2)
                fprintf(stdout, ") ");
            if (i == 5)
                putchar('-');
        }
        putchar('\n');
    }

    fclose(fpIn);

    return EXIT_SUCCESS;
}