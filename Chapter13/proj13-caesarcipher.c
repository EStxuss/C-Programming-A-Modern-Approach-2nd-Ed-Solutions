// does the ceasar cipher on an input message with input shift amount

#include <ctype.h>
#include <stdio.h>

#define LEN 80

void encrypt(char *message, int shiftAmt);

int main(void) {
    printf("Enter a message to encrypt: ");

    char message[LEN + 1];
    fgets(message, sizeof(message), stdin);

    printf("Enter a shift amount (1-25): ");
    int shiftAmt;
    scanf("%d", &shiftAmt);

    encrypt(message, shiftAmt);

    printf("The encrypted message:\n%s\n", message);

    return 0;
}

void encrypt(char *message, int shiftAmt) {
    while (*message) {
        if (isalpha(*message)) {
            *message = (islower(*message))
                           ? 'a' + ((*message - 'a' + shiftAmt) % 26)
                           : 'A' + ((*message - 'A' + shiftAmt) % 26);
        }
        ++message;
    }
}
