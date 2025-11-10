#include "stackADT.h"
#include <stdio.h>

#define IDENT_STR(x) #x

void printLen(Stack s, const char *stackName);
void printOp(const char *op, const char *stackName);

int main(void) {
    Stack s1, s2;
    int n;

    s1 = create();
    printOp("Created", IDENT_STR(s1));
    printLen(s1, IDENT_STR(s1));

    s2 = create();
    printOp("Created", IDENT_STR(s2));
    printLen(s2, IDENT_STR(s2));

    push(s1, 1);
    printOp("Pushed", IDENT_STR(s1));
    printLen(s1, IDENT_STR(s1));

    push(s1, 2);
    printOp("Pushed", IDENT_STR(s1));
    printLen(s1, IDENT_STR(s1));

    n = pop(s1);
    printOp("Popped", IDENT_STR(s1));
    printLen(s1, IDENT_STR(s1));

    push(s2, n);
    printOp("Pushed", IDENT_STR(s2));
    printLen(s2, IDENT_STR(s2));

    n = pop(s1);
    printOp("Popped", IDENT_STR(s1));
    printLen(s1, IDENT_STR(s1));

    push(s2, n);
    printOp("Pushed", IDENT_STR(s2));
    printLen(s2, IDENT_STR(s2));

    destroy(s1);

    while (!is_empty(s2)) {
        pop(s2);
        printOp("Popped", IDENT_STR(s2));
        printLen(s2, IDENT_STR(s2));
    }

    push(s2, 3);
    printOp("Pushed", IDENT_STR(s2));
    printLen(s2, IDENT_STR(s2));

    make_empty(s2);
    printOp("Make Empty", IDENT_STR(s2));
    printLen(s2, IDENT_STR(s2));

    if (is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty\n");

    destroy(s2);

    return 0;
}

void printLen(Stack s, const char *stackName) {
    printf("Stack %s has length %d\n\n", stackName, length(s));
}

void printOp(const char *op, const char *stackName) {
    printf("stack: %s   operation: %s\n", stackName, op);
}