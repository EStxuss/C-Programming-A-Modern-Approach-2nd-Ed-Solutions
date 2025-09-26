// asks for a fraction and then outputs reduced version to lowest terms

#include <stdio.h>

int main(void){
    int num, den;
    printf("Enter a fraction: ");
    scanf("%d / %d", &num, &den);

    //compute gcd
    int n = num, m = den, rem;
    while(n != 0){
	rem = m % n;
	m = n;
	n = rem;
    }

    if(m != den){
	num /= m;
	den /= m;
    }

    printf("In lowest terms: %d/%d\n", num, den);

    return 0;
}
