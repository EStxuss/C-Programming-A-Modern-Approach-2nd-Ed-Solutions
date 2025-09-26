// asks for number n and prints even squares between [1, n]

#include <stdio.h>

int main(void){
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);


    for(int i = 1, sq = 1; sq <= n; ++i, sq = i * i)
	if(sq % 2 == 0)
	    printf("%d\n", sq);
    
    return 0;
}
