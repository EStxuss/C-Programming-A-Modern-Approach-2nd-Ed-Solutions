// copies contents of source file into destination 512 bytes at a time

#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 512

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: copy-block source destination\n");
        exit(EXIT_FAILURE);
    }

    FILE *fpIn = fopen(argv[1], "rb");
    if (fpIn == NULL) {
        fprintf(stderr, "Couldn't open source file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *fpOut = fopen(argv[2], "wb");
    if (fpOut == NULL) {
        fprintf(stderr, "Couldn't open destination file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    typedef unsigned char Byte;

    Byte buffer[BUF_SIZE];
    int bufSize = 0, bytesCopied = 0, n;
    while (!feof(fpIn)) {
        bufSize = fread(buffer, 1, BUF_SIZE, fpIn);
        if (bufSize == 0)
            break;

        if (fwrite(buffer, bufSize, 1, fpOut) != 1) {
            fprintf(stderr, "Failed to write buffer to destination file\n");
            exit(EXIT_FAILURE);
        }
        bytesCopied += bufSize;
    }

    printf("Copied %d bytes from %s to %s\n", bytesCopied, argv[1], argv[2]);

    fclose(fpIn);

    if (fclose(fpOut) == EOF) {
        fprintf(stderr, "Error while closing destination file\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}