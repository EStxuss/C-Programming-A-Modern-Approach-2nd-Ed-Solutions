#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int top = 0, stack[STACK_SIZE];

bool isEmpty(void);
bool isFull(void);
void stackOverflow(void);
void stackUnderflow(void);

void push(char operand) {
    if (isFull())
        stackOverflow();
    else
        stack[top++] = operand;
}

char pop(void) {
    if (isEmpty())
        stackUnderflow();
    return stack[--top];
}

bool isEmpty(void) { return top == 0; }

bool isFull(void) { return top == STACK_SIZE; }

void makeEmpty(void) { top = 0; }

void stackOverflow(void) {
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}

void stackUnderflow(void) {
    printf("Not enough operands in expression\n");
    exit(EXIT_SUCCESS);
}
