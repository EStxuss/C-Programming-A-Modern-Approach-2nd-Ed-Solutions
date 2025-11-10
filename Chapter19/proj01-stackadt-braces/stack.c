#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static void terminate(const char *errMsg);

struct node {
    Item item;
    struct node *next;
};

struct stack {
    struct node *top;
};

Stack stackCreate(void) {
    Stack newStack = malloc(sizeof(struct stack));
    if (newStack == NULL)
        terminate("Failed to allocate memory to create stack");

    newStack->top = NULL;
    return newStack;
}

void stackDestroy(Stack s) {
    stackMakeEmpty(s);
    free(s);
}

void stackPush(Stack s, Item i) {
    if (stackIsFull(s))
        terminate("Tried pushing onto a full stack");

    struct node *newNode;
    if ((newNode = malloc(sizeof(struct node))) == NULL)
        terminate("Failed to allocate a new node in stackPush()");

    newNode->item = i;
    newNode->next = s->top;
    s->top = newNode;
}

Item stackPop(Stack s) {
    if (stackIsEmpty(s))
        terminate("Tried popping from an empty stack");

    Item popped = s->top->item;
    struct node *toDestroy = s->top;
    s->top = s->top->next;
    free(toDestroy);
    return popped;
}

void stackMakeEmpty(Stack s) {
    while (s->top != NULL)
        stackPop(s);
}

bool stackIsEmpty(Stack s) { return s->top == NULL; }
bool stackIsFull(Stack) { return false; }

static void terminate(const char *errMsg) {
    printf("%s\n", errMsg);
    exit(EXIT_FAILURE);
}