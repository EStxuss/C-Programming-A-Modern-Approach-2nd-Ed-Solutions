// takes the wind force in knots and outputs a description of the wind

#include <stdio.h>

int main(void){
    printf("Enter the wind speed in knots: ");
    int knots = 0;
    scanf("%d", &knots);

    if(knots < 0)
	; //negative not valid
    else if(knots < 1)
	printf("Calm\n");
    else if(knots <= 3)
	printf("Light air\n");
    else if(knots <= 27)
	printf("Breeze\n");
    else if(knots <= 47)
	printf("Gale\n");
    else if(knots <= 63)
	printf("Storm\n");
    else
	printf("Hurricane\n");

    return 0;
}
