// takes phone number input in the form (xxx) xxx-xxxx and outputs as
// xxx.xxx.xxxx

#include <stdio.h>

int main(void) {
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    int areaCode = 0, exchange = 0, lineNum = 0;

    scanf("(%d) %d-%d", &areaCode, &exchange, &lineNum);

    printf("You entered %d.%d.%d\n", areaCode, exchange, lineNum);

    return 0;
}
