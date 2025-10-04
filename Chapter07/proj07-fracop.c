// user enters two fractions with +, -, *, / in the middle and answer is output

#include <stdio.h>

int main(void) {
    int numer1, denom1, numer2, denom2, numerAns, denomAns;
    char op;
    printf("Enter two fractions with +, -, *, or / in between: ");
    scanf(" %d / %d", &numer1, &denom1);
    while ((op = getchar()) != '+' && op != '-' && op != '*' && op != '/')
        ;
    scanf(" %d / %d", &numer2, &denom2);

    if (op == '+' || op == '-') {
        if (denom1 != denom2) {
            int tmp = denom1;
            numer1 *= denom2;
            denom1 *= denom2;
            numer2 *= tmp;
            denom2 *= tmp;
        }
        denomAns = denom1;
        if (op == '+')
            numerAns = numer1 + numer2;
        else
            numerAns = numer1 - numer2;
    } else if (op == '*') {
        numerAns = numer1 * numer2;
        denomAns = denom1 * denom2;
    } else if (op == '/') {
        int tmp = denom2;
        denom2 = numer2;
        numer2 = tmp;

        numerAns = numer1 * numer2;
        denomAns = denom1 * denom2;
    }

    // reduce
    int n = numerAns, m = denomAns, rem;
    while (n != 0) {
        rem = m % n;
        m = n;
        n = rem;
    }
    numerAns /= m;
    denomAns /= m;

    printf("The answer is: %d/%d\n", numerAns, denomAns);

    return 0;
}
