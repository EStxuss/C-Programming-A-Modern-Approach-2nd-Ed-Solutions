#include "qsort.h"
#include <stdlib.h>

void quicksort(struct part parts[], int num_parts) {
    qsort(parts, num_parts, sizeof(*parts), compareParts);
}

int compareParts(const void *part1, const void *part2) {
    return (((const struct part *)part1)->number -
            (((const struct part *)part2)->number));
}
