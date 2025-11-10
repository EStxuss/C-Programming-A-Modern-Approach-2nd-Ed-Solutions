// calculates a reverse polish notation math expression with single digit
// integers

#include "stack.h"
#include <ctype.h>
#include <stdio.h>

int main(void) {
    Stack stack = stackCreate();

    char c;
    for (;;) {
        printf("Enter an RPN expression: ");
        do {
            scanf(" %c", &c);
            if (isdigit(c)) {
                if (!stackIsFull(stack))
                    stackPush(stack, c - '0');
            } else if (c == '+')
                stackPush(stack, stackPop(stack) + stackPop(stack));
            else if (c == '-') {
                int secOperand = stackPop(stack);
                int firOperand = stackPop(stack);
                stackPush(stack, firOperand - secOperand);
            } else if (c == '*')
                stackPush(stack, stackPop(stack) * stackPop(stack));
            else if (c == '/') {
                int secOperand = stackPop(stack);
                int firOperand = stackPop(stack);
                stackPush(stack, firOperand / secOperand);
            } else if (c != '=') // not valid character
                return 0;
        } while (c != '=');

        printf("Value of expresion: %d\n", stackPop(stack));

        stackMakeEmpty(stack);
    }

    stackDestroy(stack);

    return 0;
}