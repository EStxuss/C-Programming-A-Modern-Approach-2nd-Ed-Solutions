#include "stackADT.h"
#include <stdio.h>

#define IDENT_STR(x) #x

void printLen(Stack s, const char *stackName);
void printOp(const char *op, const char *stackName);

int main(void) {
    Stack s1, s2;
    int n;

    s1 = create();
    s2 = create();

    push(s1, "test1");
    printf("Pushed string test1 onto s1\n\n");

    push(s1, "test2");
    printf("Pushed string test2 onto s1\n\n");

    const char *str = pop(s1);
    printf("Popped string %s from s1\n", str);

    push(s2, "test3");
    printf("Pushed string test3 onto s2\n\n");

    str = pop(s1);
    printf("Popped string %s from s1\n", str);

    push(s2, "test4");
    printf("Pushed string test4 onto s2\n\n");
    destroy(s1);

    while (!is_empty(s2)) {
        str = pop(s2);
        printf("Popped string %s from s2\n", str);
    }

    push(s2, "test5");
    printf("Pushed string test5 onto s2\n\n");

    make_empty(s2);

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