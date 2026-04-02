// gets words from the user and outputs the first and last words if they were
// sorted in lexicographic order

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define SIZE 20

int main(void) {
    char c, smallest[SIZE + 1] = {0}, largest[SIZE + 1] = {0},
                            curr[SIZE + 1] = {0};

    do {
        printf("Enter a word: ");
        while (isspace(c = getchar()))
            ;

        char *p = curr;
        do {
            *p = c;
        } while (++p < curr + SIZE && !isspace(c = getchar()));
        *p = '\0';

        if (strcmp(smallest, "") == 0 || strcmp(curr, smallest) < 0)
            strcpy(smallest, curr);
        if (strcmp(largest, "") == 0 || strcmp(curr, largest) > 0)
            strcpy(largest, curr);
    } while (strlen(curr) != 4);

    printf("\nSmallest word: %s\n", smallest);
    printf("Largest word: %s\n", largest);

    return 0;
}
