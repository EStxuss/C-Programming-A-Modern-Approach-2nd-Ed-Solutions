// takes two words input and outputs whether they are anagrams

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int letter[26] = {0};
    char c;

    printf("Enter first word: ");
    while ((c = tolower(getchar())) != '\n')
        if (isalpha(c))
            ++letter[c - 'a'];

    printf("Enter second word: ");
    while ((c = tolower(getchar())) != '\n')
        if (isalpha(c))
            --letter[c - 'a'];

    bool isAnagram = true;
    for (int i = 0; i < 26; ++i)
        if (letter[i] != 0) {
            isAnagram = false;
            break;
        }

    if (isAnagram)
        printf("They are anagrams\n");
    else
        printf("They are not anagrams\n");

    return 0;
}
