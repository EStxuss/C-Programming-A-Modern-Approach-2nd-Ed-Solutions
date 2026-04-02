// calculates a reverse polish notation math expression with single digit
// integers

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define LEN 80

// rpn
int evalRpnExpr(const char *expr);
bool isOperation(char);

// stack
void push(char operand);
char pop(void);
bool isEmpty(void);
bool isFull(void);
void makeEmpty(void);
void stackOverflow(void);
void stackUnderflow(void);

int top = 0, stack[STACK_SIZE];

int main(void) {
    char expr[LEN + 1];

    for (;;) {
        printf("Enter an RPN expression with single digit positive numbers:\n");
        fgets(expr, LEN + 1, stdin);
        printf("Value of expresion: %d\n", evalRpnExpr(expr));

        makeEmpty();
    }

    return 0;
}

int evalRpnExpr(const char *expr) {
    while (*expr && *expr != '=') {
        if (isOperation(*expr)) {
            int secOperand;
            int firOperand;
            switch (*expr) {
            case '+':
                push(pop() + pop());
                break;
            case '-':
                secOperand = pop();
                firOperand = pop();
                push(firOperand - secOperand);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                secOperand = pop();
                firOperand = pop();
                push(firOperand / secOperand);
                break;
            }
        } else if (isdigit(*expr))
            push(*expr - '0');

        ++expr;
    }

    return pop();
}

bool isOperation(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
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
