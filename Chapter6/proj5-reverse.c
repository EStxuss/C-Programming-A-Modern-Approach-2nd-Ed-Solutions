// gets a integer from the user and outputs that integer reversed

#include <stdio.h>

int main(void){
    int input;
    printf("Enter an integer: ");
    scanf("%d", &input);

    do{
	printf("%d", input % 10);
	input /= 10;
    }while(input > 0);
    printf("\n");

    return 0;
}
