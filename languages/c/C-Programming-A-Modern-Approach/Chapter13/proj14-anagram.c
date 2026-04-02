// takes two words input and outputs whether they are anagrams

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define LEN 80

bool areAnagrams(const char *word1, const char *word2);

int main(void) {
    char word1[LEN + 1], word2[LEN + 1];

    printf("Enter first word: ");
    fgets(word1, sizeof(word1), stdin);
    printf("Enter second word: ");
    fgets(word2, sizeof(word2), stdin);

    printf("%sAnagrams\n", (areAnagrams(word1, word2)) ? "" : "Not ");

    return 0;
}

bool areAnagrams(const char *word1, const char *word2) {
    int count[26] = {0};
    while (*word1) {
        if (isalpha(*word1))
            ++count[tolower(*word1) - 'a'];
        ++word1;
    }

    while (*word2) {
        if (isalpha(*word2))
            --count[tolower(*word2) - 'a'];
        ++word2;
    }

    for (int i = 0; i < 26; ++i) {
        if (count[i])
            return false;
    }
    return true;
}
