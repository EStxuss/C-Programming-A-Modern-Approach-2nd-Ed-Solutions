// planets.c from section 13.7 but input isn't case sensitive

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9
#define LEN 7

void matchCase(char word[]);

int main(int argc, char *argv[]) {
    char *planets[] = {"Mercury", "Venus",  "Earth",   "Mars", "Jupiter",
                       "Saturn",  "Uranus", "Neptune", "Pluto"};
    char currWord[LEN + 1] = "";
    int i, j;
    for (i = 1; i < argc; i++) {
        if (strlen(argv[i]) > LEN)
            continue;

        strncpy(currWord, argv[i], LEN);
        currWord[LEN] = '\0';
        matchCase(currWord);

        for (j = 0; j < NUM_PLANETS; j++)
            if (strcmp(currWord, planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }
    return 0;
}

void matchCase(char word[]) {
    if (strcmp(word, "") == 0)
        return;

    *word = toupper(*word);

    while (*(++word))
        *word = tolower(*word);
}
