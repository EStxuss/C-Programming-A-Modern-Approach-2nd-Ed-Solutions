// converts alphabetical phone number to numerical

#include <ctype.h>
#include <stdio.h>

#define SIZE 15

int main(void) {
    char phoneNum[SIZE];

    printf("Enter phone number: ");

    char c;
    int i = 0;
    while ((c = toupper(getchar())) != '\n' && i < 15) {
        if (c != ' ') {
            if (c >= 'A' && c <= 'Y') {
                if (c >= 'A' && c <= 'C')
                    c = '2';
                else if (c >= 'D' && c <= 'F')
                    c = '3';
                else if (c >= 'G' && c <= 'I')
                    c = '4';
                else if (c >= 'J' && c <= 'L')
                    c = '5';
                else if (c >= 'M' && c <= 'O')
                    c = '6';
                else if (c >= 'P' && c <= 'S')
                    c = '7';
                else if (c >= 'T' && c <= 'V')
                    c = '8';
                else if (c >= 'W' && c <= 'Y')
                    c = '9';
            }
            phoneNum[i++] = c;
        }
    }

    printf("In numeric form: ");
    for (int j = 0; j < i && j < SIZE; ++j)
        putchar(phoneNum[j]);
    putchar('\n');

    return 0;
}
