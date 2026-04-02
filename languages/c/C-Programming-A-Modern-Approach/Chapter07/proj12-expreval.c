// solves a math expression with no operator precedence

#include <stdio.h>

int main(void) {
    printf("Enter an expression: ");

    char op = ' ';
    float num, total;
    scanf(" %f", &total);
    do {
        while ((op = getchar()) != '+' && op != '-' && op != '*' && op != '/' &&
               op != '\n')
            ;
        if (op != '\n') {
            scanf(" %f", &num);
            if (op == '+')
                total += num;
            else if (op == '-')
                total -= num;
            else if (op == '*')
                total *= num;
            else if (op == '/')
                total /= num;
        }
    } while (op != '\n');

    printf("Value of expression: %.2f\n", total);

    return 0;
}
