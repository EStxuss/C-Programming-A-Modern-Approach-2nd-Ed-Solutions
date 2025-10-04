// counts the vowels in the input sentence

#include <ctype.h>
#include <stdio.h>

int main(void) {
    printf("Enter a sentence: ");
    char c;
    int vowels = 0;
    while ((c = toupper(getchar())) != '\n')
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            ++vowels;

    printf("Your sentence contains %d vowels\n", vowels);

    return 0;
}
