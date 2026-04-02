#ifndef QSORT_H
#define QSORT_H

#include "inventory.h"

void quicksort(struct part *parts, int num_parts); // qsort wrapper
int compareParts(const void *part1, const void *part2);

#endif
