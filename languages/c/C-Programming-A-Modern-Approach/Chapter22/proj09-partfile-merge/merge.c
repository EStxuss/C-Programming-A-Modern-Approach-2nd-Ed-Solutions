// takes two sorted part list files given from proj08-inventory-dumprestore and
// merges them keeping sorted order

#include "inventory.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writePart(struct part *part, FILE *fpOut);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: merge partfile1 partfile2 mergedfile\n");
        exit(EXIT_FAILURE);
    }

    FILE *partFpOne, *partFpTwo, *mergeFp;
    if ((partFpOne = fopen(argv[1], "rb")) == NULL ||
        ((partFpTwo = fopen(argv[2], "rb")) == NULL) ||
        ((mergeFp = fopen(argv[3], "wb")) == NULL)) {
        fprintf(stderr, "Unable to open files\n");
        exit(EXIT_FAILURE);
    }

    struct part *partOne, *partTwo;
    if ((partOne = malloc(sizeof(struct part))) == NULL ||
        (partTwo = malloc(sizeof(struct part))) == NULL) {
        fprintf(stderr, "Couldn't allocate memory for parts\n");
        exit(EXIT_FAILURE);
    }

    bool partOneIsValid = fread(partOne, sizeof(struct part), 1, partFpOne);
    bool partTwoIsValid = fread(partTwo, sizeof(struct part), 1, partFpTwo);

    while (partOneIsValid || partTwoIsValid) {
        if (partOneIsValid && partTwoIsValid) {
            if (partOne->number == partTwo->number) {
                if (strcmp(partOne->name, partTwo->name) == 0) {
                    partOne->on_hand += partTwo->on_hand;
                    writePart(partOne, mergeFp);
                } else {
                    printf("WARNING: Parts with same part number had different "
                           "names\nPart number: %d\nParts names: %s, %s\n",
                           partOne->number, partOne->name, partTwo->name);
                    writePart(partOne, mergeFp);
                    writePart(partTwo, mergeFp);
                }

                partOneIsValid = partTwoIsValid = false;
            } else {
                if (partOne->number < partTwo->number) {
                    writePart(partOne, mergeFp);
                    partOneIsValid = false;
                } else {
                    writePart(partTwo, mergeFp);
                    partTwoIsValid = false;
                }
            }
        } else if (partOneIsValid) {
            writePart(partOne, mergeFp);
            partOneIsValid = false;
        } else if (partTwoIsValid) {
            writePart(partTwo, mergeFp);
            partTwoIsValid = false;
        }

        if (!partOneIsValid && !feof(partFpOne)) {
            if (fread(partOne, sizeof(*partOne), 1, partFpOne) == 1)
                partOneIsValid = true;
        }
        if (!partTwoIsValid && !feof(partFpTwo)) {
            if (fread(partTwo, sizeof(*partTwo), 1, partFpTwo) == 1)
                partTwoIsValid = true;
        }
    }

    fclose(partFpOne);
    fclose(partFpTwo);
    fclose(mergeFp);

    free(partOne);
    free(partTwo);

    return 0;
}

void writePart(struct part *part, FILE *fpOut) {
    if (fwrite(part, sizeof(struct part), 1, fpOut) != 1) {
        fprintf(stderr, "Error writing a part to merge file\n");
        exit(EXIT_FAILURE);
    }
}