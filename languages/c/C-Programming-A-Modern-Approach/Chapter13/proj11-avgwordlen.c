// calculates average word length of a sentence

#include <ctype.h>
#include <stdio.h>

#define LEN 150

double computeAvgWordLen(const char *sentence);

int main(void) {
    printf("Enter a sentence: ");

    char sentence[LEN + 1];
    fgets(sentence, LEN + 1, stdin);

    printf("Average word length: %.1f\n", computeAvgWordLen(sentence));

    return 0;
}

double computeAvgWordLen(const char *sentence) {
    int numWords = 0, totalLetters = 0, currWordLetters = 0;
    while (*sentence) {
        if (isspace(*sentence)) {
            if (currWordLetters > 0) {
                ++numWords;
                totalLetters += currWordLetters;
                currWordLetters = 0;
            }
        } else {
            ++currWordLetters;
        }
        ++sentence;
    }

    return (double)totalLetters / numWords;
}
