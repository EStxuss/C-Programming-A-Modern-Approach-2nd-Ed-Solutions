// uses a stack to tell whether nested braces/parentheses are correct

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char stack[STACK_SIZE];
int top = 0;

char pop(void);
void push(char brace);
bool isEmpty(void);
bool isFull(void);
void makeEmpty(void);
void stack_underflow(void);
void stack_overflow(void);

int main(void) {
    printf("Enter curly braces and/or parentheses: ");

    char c;
    while ((c = getchar()) != '\n') {
        if (c == '(' || c == '{')
            push(c);
        else if (c == ')') {
            char match = pop();
            if (match != '(') {
                printf("\nBraces/Parentheses are NOT properly nested\n");
                return 0;
            }
        } else if (c == '}') {
            char match = pop();
            if (match != '{') {
                printf("\nBraces/Parentheses are NOT properly nested\n");
                return 0;
            }
        }
    }

    if (isEmpty())
        printf("\nBraces/Parentheses ARE properly nested\n");
    else
        printf("\nBraces/Parentheses are NOT properly nested\n");

    return 0;
}

char pop(void) {
    if (isEmpty())
        stack_underflow();
    return stack[--top];
}
void push(char brace) {
    if (isFull())
        stack_overflow();
    stack[top++] = brace;
}

void makeEmpty(void) { top = 0; }

bool isEmpty(void) { return top == 0; }

bool isFull(void) { return top == STACK_SIZE; }

void stack_underflow() {
    printf("\nNot valid nesting. Tried to pop from a empty stack\n");
    exit(EXIT_FAILURE);
}

void stack_overflow() {
    printf("\nStack Overflow\n");
    exit(EXIT_FAILURE);
}
