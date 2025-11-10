// uses a stack to tell whether nested braces/parentheses are correct

#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Enter curly braces and/or parentheses: ");

    Stack stack = stackCreate();

    char c;
    while ((c = getchar()) != '\n') {
        if (c == '(' || c == '{')
            stackPush(stack, c);

        else if (c == ')') {
            if (stackIsEmpty(stack)) {
                printf("\nBraces/Parentheses are NOT properly nested\n");
                return 0;
            }
            char match = stackPop(stack);
            if (match != '(') {
                printf("\nBraces/Parentheses are NOT properly nested\n");
                return 0;
            }
        }

        else if (c == '}') {
            if (stackIsEmpty(stack)) {
                printf("\nBraces/Parentheses are NOT properly nested\n");
                return 0;
            }
            char match = stackPop(stack);
            if (match != '{') {
                printf("\nBraces/Parentheses are NOT properly nested\n");
                return 0;
            }
        }
    }

    if (stackIsEmpty(stack))
        printf("\nBraces/Parentheses ARE properly nested\n");
    else
        printf("\nBraces/Parentheses are NOT properly nested\n");

    stackDestroy(stack);

    return 0;
}