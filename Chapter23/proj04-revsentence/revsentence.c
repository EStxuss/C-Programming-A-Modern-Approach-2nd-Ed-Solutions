// reverses a sentence entered by the user using strtok

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRT_CAP 25
#define CAP_MULT 2
#define SENT_LEN 1000

#define STR2(x) #x
#define STR1(x) STR2(x)

int main(void) {
    int size = 0, capacity = STRT_CAP;
    char **words = malloc(capacity * sizeof(char *));
    if (words == NULL) {
        fprintf(stderr, "Couldn't allocate memory for words array\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter words seperated by a single space:\n");

    char sentence[SENT_LEN + 1];
    if (scanf("%" STR1(SENT_LEN) "[^\n]", sentence) == 0) {
        fprintf(stderr, "Couldn't read sentence\n");
        exit(EXIT_FAILURE);
    }

    char *p = strtok(sentence, " ");
    while (p) {
        if (size == capacity) {
            capacity *= CAP_MULT;
            words = realloc(words, capacity * sizeof(char *));
            if (words == NULL) {
                fprintf(stderr, "Couldn't resize words array\n");
                exit(EXIT_FAILURE);
            }
        }

        words[size++] = p;
        p = strtok(NULL, " ");
    }

    printf("\nThe sentence in reverse order:\n");
    for (int i = size - 1; i >= 0; --i)
        printf((i) ? "%s " : "%s", words[i]);
    printf("\n");

    return EXIT_SUCCESS;
}