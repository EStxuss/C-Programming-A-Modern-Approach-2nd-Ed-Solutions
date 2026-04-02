// takes a 2 digit number input and outputs it in english

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int inputNum;
    printf("Enter a two digit number: ");
    scanf("%2d", &inputNum);

    char *tens[] = {"",      "",      "Twenty",  "Thirty", "Fourty",
                    "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char *ones[] = {"",        "One",     "Two",       "Three",    "Four",
                    "Five",    "Six",     "Seven",     "Eight",    "Nine",
                    "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                    "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    if (inputNum < 20)
        printf("%s\n", ones[inputNum]);
    else {
        int tensDig = inputNum / 10;
        int onesDig = inputNum % 10;

        printf("%s %s\n", tens[tensDig], ones[onesDig]);
    }

    return 0;
}
