/*
Faça uma função recursiva que permita somar os elementos de um vetor de inteiros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int soma(int v[],int n)
{
	if (n ==1) return(v[0]); // caso trivial
	else return(v[n-1]+soma(v,n-1));
}

int main()
{
	int v[30] = {1, 2, 5, 6, 7, 9, 11, 15, 17, 18, 20, 21, 23, 28, 29, 30, 34, 35, 39, 40, 41, 45, 50, 57, 60, 61, 68, 73, 78, 81};
	printf("Soma: %i", soma(v,30));
	
}
