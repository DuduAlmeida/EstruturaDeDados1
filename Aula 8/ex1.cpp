#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int somatorio( int i){    
    if(i==0)
        return 0;
    else{
        return ( i + somatorio(i-1));
    }
}

int main()
{
	printf("\n Somatorio (funcao iterativa): %i", somatorio(4));
}
