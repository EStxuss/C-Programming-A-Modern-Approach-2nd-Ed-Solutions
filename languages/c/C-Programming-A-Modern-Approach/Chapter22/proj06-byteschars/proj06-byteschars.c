#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 10

// fills int array with characters from stream and retuns the number of
// characters read
int fillBuf(int buf[BUF_SIZE], FILE *);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: bc filename\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Couldn't open file %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Offset              Bytes              Characters\n");
    printf("------  -----------------------------  ----------\n");

    int buf[10], currOffset = 0, n;
    while (!feof(fp)) {
        n = fillBuf(buf, fp);
        if (n == 0)
            break;

        printf("%6d  ", currOffset);
        currOffset += 10;

        for (int i = 0; i < n; ++i)
            printf((i == BUF_SIZE - 1) ? "%.2X  " : "%.2X ", buf[i]);
        for (int i = n; i < BUF_SIZE; ++i)
            printf((i == BUF_SIZE - 1) ? "    " : "   ");

        for (int i = 0; i < n; ++i)
            printf("%c", (isprint(buf[i])) ? buf[i] : '.');

        if (n == BUF_SIZE)
            printf("\n");
    }

    fclose(fp);

    return 0;
}

int fillBuf(int buf[BUF_SIZE], FILE *fp) {
    int ch, i;
    for (i = 0; i < BUF_SIZE && ((ch = getc(fp)) != EOF); ++i)
        buf[i] = ch;
    return i;
}