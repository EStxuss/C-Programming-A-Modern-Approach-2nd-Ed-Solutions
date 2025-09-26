// parses an isbn by category

#include <stdio.h>

int main(void) {
    int gs1Prefix = 0, groupID = 0, pubCode = 0, itemNum = 0, checkDig = 0;
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1Prefix, &groupID, &pubCode, &itemNum,
          &checkDig);
    printf("GS1 Prefix: %d\nGroup Identifier: %.1d\nPublisher Code: %d\nItem "
           "Number: %d\nCheck Digit: %d\n",
           gs1Prefix, groupID, pubCode, itemNum, checkDig);
}
