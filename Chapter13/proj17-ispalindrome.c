#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100

bool isPalindrome(const char *msg);

int main(void) {
    printf("Enter a message: ");
    char msg[MAX_SIZE + 1];
    fgets(msg, sizeof(msg), stdin);

    printf("%sPalindrome\n", (isPalindrome(msg)) ? "" : "Not a ");
    return 0;
}

bool isPalindrome(const char *msg) {
    const char *l = msg, *r = msg;
    while (*r)
        ++r;
    --r;

    while (l < r) {
        if (isspace(*l) || !isalpha(*l)) {
            ++l;
            continue;
        }
        if (isspace(*r) || !isalpha(*r)) {
            --r;
            continue;
        }
        if (tolower(*l++) != tolower(*r--))
            return false;
    }
    return true;
}
