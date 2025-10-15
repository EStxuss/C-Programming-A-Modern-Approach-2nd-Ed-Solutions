// proj01 b but takes advantage of the fact you can use array names as pointers

#include <stdio.h>

#define MSG_MAX 150

void msgReverseSubscript(int n, char msg[n]);
void msgReversePointer(int n, char msg[n]);
void printMsg(int n, char msg[n]);

int main(void) {
    printf("Enter a message: ");
    char c, msg[MSG_MAX], msgCopy[MSG_MAX];
    int i, size = 0;
    for (c = getchar(), i = 0; i < MSG_MAX && c != '\n'; ++i, c = getchar()) {
        msg[i] = msgCopy[i] = c;
        ++size;
    }

    printf("Subscript reversal method result: ");
    msgReverseSubscript(size, msgCopy);
    printMsg(size, msgCopy);

    printf("Pointer reversal method result: ");
    msgReversePointer(size, msg);
    printMsg(size, msg);

    return 0;
}

void msgReverseSubscript(int n, char msg[n]) {
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        char tmp = msg[i];
        msg[i] = msg[j];
        msg[j] = tmp;
    }
}

void msgReversePointer(int n, char msg[n]) {
    for (char *l = msg, *r = msg + n - 1; l < r; ++l, --r) {
        char tmp = *l;
        *l = *r;
        *r = tmp;
    }
}

void printMsg(int n, char msg[n]) {
    for (char *p = msg; p < msg + n; ++p)
        putchar(*p);
    putchar('\n');
}
