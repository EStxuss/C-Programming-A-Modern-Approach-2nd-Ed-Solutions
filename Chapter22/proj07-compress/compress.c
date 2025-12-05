#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: compress filename");
        exit(EXIT_FAILURE);
    }

    FILE *origFp, *comprFp;
    if ((origFp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Couldn't open file %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char comprFilename[strlen(argv[1]) + 4];
    strcpy(comprFilename, argv[1]);
    strcat(comprFilename, ".rle");

    if ((comprFp = fopen(comprFilename, "wb")) == NULL) {
        fprintf(stderr, "Couldn't open file %s for writing\n", comprFilename);
        exit(EXIT_FAILURE);
    }

    int count = 1, ch = getc(origFp), nextCh;
    while (ch != EOF) {
        while ((nextCh = getc(origFp)) == ch)
            ++count;

        putc(count, comprFp);
        putc(ch, comprFp);

        ch = nextCh;
        count = 1;
    }

    return 0;
}