// does the ceasar cipher on an input message with input shift amount

#include <stdio.h>

#define MAX_SIZE 80

int main(void) {
    printf("Enter a message to encrypt: ");

    char c, msg[MAX_SIZE];
    int size = 0;
    for (int i = 0, c = getchar(); i < MAX_SIZE && c != '\n';
         ++i, c = getchar()) {
        msg[i] = c;
        ++size;
    }

    int shiftAmt;
    do {
        printf("Enter shift amount (1-25): ");
        scanf("%d", &shiftAmt);
    } while (shiftAmt < 1 || shiftAmt > 25);

    printf("Encrypted message: ");
    for (int i = 0; i < size; ++i) {
        if (msg[i] >= 'a' && msg[i] <= 'z')
            msg[i] = 'a' + (((msg[i] - 'a') + shiftAmt) % 26);
        else if (msg[i] >= 'A' && msg[i] <= 'Z')
            msg[i] = 'A' + (((msg[i] - 'A') + shiftAmt) % 26);
        putchar(msg[i]);
    }
    putchar('\n');

    return 0;
}
