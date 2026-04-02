// takes a message and rewrites it how b1ff would say it

#include <ctype.h>
#include <stdio.h>

#define SIZE ((int)(sizeof(msg) / sizeof(msg[0])))

int main(void) {
    printf("Enter a message: ");

    char msg[150];

    for (int i = 0; i < SIZE; ++i) {
        msg[i] = toupper(getchar());
        if (msg[i] == '\n')
            break;
    }

    for (int i = 0; i < SIZE && msg[i] != '\n'; ++i) {
        if (msg[i] == 'A')
            msg[i] = '4';
        else if (msg[i] == 'B')
            msg[i] = '8';
        else if (msg[i] == 'E')
            msg[i] = '3';
        else if (msg[i] == 'I')
            msg[i] = '1';
        else if (msg[i] == 'O')
            msg[i] = '0';
        else if (msg[i] == 'S')
            msg[i] = '5';
    }

    printf("In B1FF-speak: ");
    for (int i = 0; i < SIZE && msg[i] != '\n'; ++i)
        putchar(msg[i]);
    printf("!!!!!!!!!!\n");

    return 0;
}
