// converts a windows text file to a unix text file

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define WIN_EOF '\x1a'
#define WIN_EOL1 '\r'
#define WIN_EOL2 '\n'
#define UNIX_EOL '\n'

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: win-to-unix windows-txt unix-txt\n");
        exit(EXIT_FAILURE);
    }

    const char *wFilename = argv[1];
    const char *uFilename = argv[2];

    FILE *wFp = fopen(wFilename, "rb");
    if (wFp == NULL) {
        fprintf(stderr, "Error opening windows text file %s\n", wFilename);
        exit(EXIT_FAILURE);
    }

    FILE *uFp = fopen(uFilename, "wb");
    if (uFp == NULL) {
        fprintf(stderr, "Error opening unix text file %s\n", uFilename);
        exit(EXIT_FAILURE);
    }

    int ch;
    bool EOL1Found = false;
    int eols = 0, eofs = 0;
    do {
        ch = getc(wFp);
        if (ch == WIN_EOF) {
            ++eofs;
            break;
        } else if (ch == WIN_EOL1)
            EOL1Found = true;
        else if (EOL1Found && ch == WIN_EOL2) {
            putc(UNIX_EOL, uFp);
            ++eols;
            EOL1Found = false;
        } else if (EOL1Found && ch != WIN_EOL2) {
            putc(WIN_EOL1, uFp);
            putc(ch, uFp);
            EOL1Found = false;
        } else {
            EOL1Found = false;
            if (ch != EOF)
                putc(ch, uFp);
        }

    } while (ch != EOF);

    fprintf(stderr, "EOLs: %d\tEOFs: %d\n", eols, eofs);

    fclose(wFp);
    if (fclose(uFp) == EOF) {
        fprintf(stderr, "Error while closing write file %s\n", uFilename);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}