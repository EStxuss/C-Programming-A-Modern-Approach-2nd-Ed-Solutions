// reads two words and outputs whether they are anagrams

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void readWord(int counts[26]);
bool isEqualArr(int counts1[26], int counts2[26]);

int main(void) {
    int counts1[26] = {0}, counts2[26] = {0};

    printf("Enter first word: ");
    readWord(counts1);

    printf("Enter second word: ");
    readWord(counts2);

    if (isEqualArr(counts1, counts2))
        printf("They are anagrams\n");
    else
        printf("They aren't anagrams\n");

    return 0;
}

void readWord(int counts[26]) {
    char c;
    while ((c = tolower(getchar())) == ' ')
        ;
    do {
        if (isalpha(c))
            ++counts[c - 'a'];
        c = tolower(getchar());
    } while (c != ' ' && c != '\n');
}

bool isEqualArr(int counts1[26], int counts2[26]) {
    for (int i = 0; i < 26; ++i)
        if (counts1[i] != counts2[i])
            return false;
    return true;
}
