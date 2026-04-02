// converts a unix text file to a windows text file

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define WIN_EOF '\x1a'
#define WIN_EOL1 '\r'
#define WIN_EOL2 '\n'
#define UNIX_EOL '\n'

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: win-to-unix unix-txt windows-txt\n");
        exit(EXIT_FAILURE);
    }

    const char *uFilename = argv[1];
    const char *wFilename = argv[2];

    FILE *uFp = fopen(uFilename, "rb");
    if (uFp == NULL) {
        fprintf(stderr, "Error opening unix text file %s\n", uFilename);
        exit(EXIT_FAILURE);
    }

    FILE *wFp = fopen(wFilename, "wb");
    if (wFp == NULL) {
        fprintf(stderr, "Error opening windows text file %s\n", wFilename);
        exit(EXIT_FAILURE);
    }

    int ch;
    int eols = 0, eofs = 0;
    while (true) {
        ch = getc(uFp);
        if (ch == EOF) {
            ++eofs;
            putc(WIN_EOF, wFp);
            break;
        } else if (ch == UNIX_EOL) {
            ++eols;
            putc(WIN_EOL1, wFp);
            putc(WIN_EOL2, wFp);
        } else {
            putc(ch, wFp);
        }
    }

    fprintf(stderr, "EOLs: %d\tEOFs: %d\n", eols, eofs);

    fclose(uFp);
    if (fclose(wFp) == EOF) {
        fprintf(stderr, "Error while closing write file %s\n", uFilename);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}