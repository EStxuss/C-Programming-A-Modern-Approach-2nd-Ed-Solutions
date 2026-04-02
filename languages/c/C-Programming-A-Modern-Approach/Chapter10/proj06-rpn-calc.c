// calculates a reverse polish notation math expression with single digit
// integers

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

void push(char operand);
char pop(void);
bool isEmpty(void);
bool isFull(void);
void makeEmpty(void);
void stackOverflow(void);
void stackUnderflow(void);

int top = 0, stack[STACK_SIZE];

int main(void) {
    char c;
    for (;;) {
        printf("Enter an RPN expression: ");
        do {
            scanf(" %c", &c);
            if (isdigit(c))
                push(c - '0');
            else if (c == '+')
                push(pop() + pop());
            else if (c == '-') {
                int secOperand = pop();
                int firOperand = pop();
                push(firOperand - secOperand);
            } else if (c == '*')
                push(pop() * pop());
            else if (c == '/') {
                int secOperand = pop();
                int firOperand = pop();
                push(firOperand / secOperand);
            } else if (c != '=') // not valid character
                return 0;
        } while (c != '=');

        printf("Value of expresion: %d\n", pop());

        makeEmpty();
    }

    return 0;
}

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
