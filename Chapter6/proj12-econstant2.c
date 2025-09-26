// approximates the math constant e with input number of terms

#include <stdio.h>

int main(void){
    float smallTerm;
    printf("Stop adding to approximate constant e when added term lower than: ");
    scanf("%f", &smallTerm);
    
    int denom = 1;
    float eVal = 1.0f;
    for(int i = 1; ; ++i){
	denom *= i;
	if(1.0f / denom < smallTerm)
	    break;
	eVal += 1.0f / denom;
    }
    
    printf("Approximation of e: %.10f\n", eVal);

    return 0;
}
