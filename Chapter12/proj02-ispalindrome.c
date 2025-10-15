#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100

bool isPalindromeSubscript(int n, const char msg[n]);
bool isPalindromePointer(int n, const char msg[n]);

int main(void) {
    printf("Enter a message: ");
    char c, msg[MAX_SIZE];
    int size = 0, i = 0;
    while (i < MAX_SIZE && ((c = getchar()) != '\n')) {
        if (isalpha(c)) {
            msg[i++] = tolower(c);
            ++size;
        }
    }

    printf("Subscript method result: ");
    (isPalindromeSubscript(size, msg)) ? printf("Is a palindrome\n")
                                       : printf("Isn't a palindrome\n");

    printf("Pointer method result: ");
    (isPalindromePointer(size, msg)) ? printf("Is a palindrome\n")
                                     : printf("Isn't a palindrome\n");

    return 0;
}

bool isPalindromeSubscript(int n, const char msg[n]) {
    for (int l = 0, r = n - 1; l < r; ++l, --r) {
        if (msg[l] != msg[r])
            return false;
    }
    return true;
}

bool isPalindromePointer(int n, const char msg[n]) {
    for (const char *l = &msg[0], *r = &msg[n - 1]; l < r; ++l, --r) {
        if (*l != *r)
            return false;
    }
    return true;
}
