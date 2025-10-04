// translates an alphabetic phone number to the buttons pressed on a flip phone
// number pad

#include <stdio.h>

int main(void) {
    printf("Enter phone number: ");
    char c;
    while ((c = getchar()) != '\n') {
        if (c >= 65 && c <= 90) {
            if (c >= 'A' && c <= 'C')
                putchar('2');
            else if (c >= 'D' && c <= 'F')
                putchar('3');
            else if (c >= 'G' && c <= 'I')
                putchar('4');
            else if (c >= 'J' && c <= 'L')
                putchar('5');
            else if (c >= 'M' && c <= 'O')
                putchar('6');
            else if (c >= 'P' && c <= 'S')
                putchar('7');
            else if (c >= 'T' && c <= 'V')
                putchar('8');
            else if (c >= 'W' && c <= 'Y')
                putchar('9');
        } else
            putchar(c);
    }
    putchar('\n');

    return 0;
}
