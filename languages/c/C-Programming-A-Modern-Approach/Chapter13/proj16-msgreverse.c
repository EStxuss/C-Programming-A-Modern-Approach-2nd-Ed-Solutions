// reverses a sentence entered by the user

#include <stdio.h>

#define MSG_MAX 150

void reverse(char *msg);

int main(void) {
    printf("Enter a message: ");
    char msg[MSG_MAX + 1];
    fgets(msg, sizeof(msg), stdin);

    reverse(msg);

    printf("\nThe message reversed:\n%s\n", msg);

    return 0;
}

void reverse(char *msg) {
    char *l = msg, *r = msg;

    while (*r)
        ++r;
    --r;
    if (*r == '\n') {
        *r = '\0';
        --r;
    }

    char tmp;
    while (l < r) {
        tmp = *l;
        *l++ = *r;
        *r-- = tmp;
    }
}
