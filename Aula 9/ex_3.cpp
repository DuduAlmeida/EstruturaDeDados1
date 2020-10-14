/*
Crie um programa em C, que contenha uma função recursiva que 
receba dois inteiros positivos k e n e calcule kn. Utilize apenas 
multiplicações. O programa principal deve solicitar ao usuário 
os valores de k e n e imprimir o resultado da chamada da função.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int pot(int k, int n)
{
	if (n ==0) return(1); 
	else
	if (n ==1) return(k);
	else return(k*pot(k,n-1));
}

int main()
{
	int k,n;
	printf("Base: ");
	scanf("%i",&k);	
	printf("Expoente: ");
	scanf("%i",&n);
	printf("\n\nPotenciacao: %i",pot(k,n));
}
