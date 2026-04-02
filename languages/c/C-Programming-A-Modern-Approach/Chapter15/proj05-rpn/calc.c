// calculates a reverse polish notation math expression with single digit
// integers

#include "stack.h"
#include <ctype.h>
#include <stdio.h>

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
