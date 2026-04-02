// takes 1 or more file names as command line arguments and outputs whether they
// can be opened in read mode

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: canopen file1 file2 ...\n");
        exit(EXIT_FAILURE);
    }

    char *fileName;
    FILE *fp;
    bool cantOpen = false;
    for (int i = 1; i < argc; ++i) {
        fileName = argv[i];
        fp = fopen(fileName, "r");
        printf((fp) ? "file %s can be opened.\n" : "file %s can't be opened.\n",
               fileName);
        if (fp)
            fclose(fp);
        else
            cantOpen = true;
    }

    if (cantOpen)
        return EXIT_FAILURE;

    return 0;
}