// prints a calender according to the input amount of days 
// and on what day the month starts

#include <stdio.h>

int main(void){
    int days, startDay;
    printf("Enter the number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &startDay);

    for(int i = 0; i < startDay - 1; ++i)
	printf("   ");

    for(int dayNum = 1, currDay = startDay; days > 0; --days, currDay = currDay % 7 + 1, ++dayNum){
	printf("%2d ", dayNum);
	if(currDay == 7)
	    printf("\n");
    }
    printf("\n");

    return 0;
}
