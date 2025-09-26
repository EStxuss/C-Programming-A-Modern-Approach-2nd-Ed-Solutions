// takes two integers and outputs the greatest common divisor

#include <stdio.h>

int main(void) {
    int n, m;
    printf("Enter two integers: ");
    scanf("%d%d", &n, &m);

    if (m == 0)
        printf("Greatest common divisor: %d\n", n);
    else {
        while (n != 0) {
            int rem = m % n;
            m = n;
            n = rem;
        }
        printf("Greatest common divisor: %d\n", m);
    }

    return 0;
}
