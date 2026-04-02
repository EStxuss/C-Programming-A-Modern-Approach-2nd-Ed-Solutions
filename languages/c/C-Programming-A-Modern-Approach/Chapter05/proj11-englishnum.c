// takes a 2 digit number input and outputs it in english

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    int inputNum;
    printf("Enter a two digit number: ");
    scanf("%d", &inputNum);

    bool donePrinting = true;
    switch (inputNum) {
    default:
        donePrinting = false;
        break;
    case 10:
        printf("Ten\n");
        break;
    case 11:
        printf("Eleven\n");
        break;
    case 12:
        printf("Twelve\n");
        break;
    case 13:
        printf("Thirteen\n");
        break;
    case 14:
        printf("Fourteen\n");
        break;
    case 15:
        printf("Fifteen\n");
        break;
    case 16:
        printf("Sixteen\n");
        break;
    case 17:
        printf("Seventeen\n");
        break;
    case 18:
        printf("Eighteen\n");
        break;
    case 19:
        printf("Nineteen\n");
        break;
    }

    if (!donePrinting) {
        int firstDig = inputNum / 10;
        int secDig = inputNum % 10;
        switch (firstDig) {
        case 2:
            printf("Twenty");
            break;
        case 3:
            printf("Thirty");
            break;
        case 4:
            printf("Fourty");
            break;
        case 5:
            printf("Fifty");
            break;
        case 6:
            printf("Sixty");
            break;
        case 7:
            printf("Seventy");
            break;
        case 8:
            printf("Eighty");
            break;
        case 9:
            printf("Ninety");
            break;
        }
        switch (secDig) {
        case 0:
            printf("\n");
            break;
        case 1:
            printf("-one\n");
            break;
        case 2:
            printf("-two\n");
            break;
        case 3:
            printf("-three\n");
            break;
        case 4:
            printf("-four\n");
            break;
        case 5:
            printf("-five\n");
            break;
        case 6:
            printf("-six\n");
            break;
        case 7:
            printf("-seven\n");
            break;
        case 8:
            printf("-eight\n");
            break;
        case 9:
            printf("-nine\n");
            break;
        }
    }

    return 0;
}
