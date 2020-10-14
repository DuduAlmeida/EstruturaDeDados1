#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

int soma( int v[], int n){
    if(n==1) return v[0]; //Caso trivial
    else return v[n-1]+soma(v,n-1);
}

int potencia( int base, int expoente){
    if ( expoente== 0 ) return 1;
    else if (expoente == 1) return base;
    else return base*potencia(base, expoente-1);
}

int main()
{
    int v[9] = {1,2,4,5,6,8,45,23,54},
    base = 2,
    expoente = 5;
	printf("\n Somatorio : %i", soma(v, 9));
	printf("\n Expoente %i^%i : %i",base,expoente, potencia(base, expoente));
}
