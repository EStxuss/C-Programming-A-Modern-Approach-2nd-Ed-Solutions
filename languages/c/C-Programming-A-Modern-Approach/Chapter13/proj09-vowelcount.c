// counts the vowels in the input sentence

#include <ctype.h>
#include <stdio.h>

#define LEN 150

void readSentence(int n, char sentence[]);
int computeVowelCount(const char *sentence);

int main(void) {
    printf("Enter a sentence: ");

    char sentence[LEN + 1];
    readSentence(LEN, sentence);

    printf("Your sentence contains %d vowels\n", computeVowelCount(sentence));

    return 0;
}

void readSentence(int n, char sentence[]) {
    int charRead = 0;
    char c;
    while (charRead <= n && (c = getchar()) != '\n') {
        *sentence++ = c;
        ++charRead;
    }
    *sentence = '\0';
}

int computeVowelCount(const char *sentence) {
    int count = 0;
    while (*sentence) {
        char c = toupper(*sentence++);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            ++count;
    }
    return count;
}
