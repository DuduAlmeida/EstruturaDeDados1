/*
Faça uma função recursiva que permita inverter um número inteiro N. Ex: 123 – 321
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int cd(int n)
{
	if(n < 10) return(1);
	else
	{
		return(1+cd(n/10));
	}
}

int inverte(int n)
{
	if (n < 10) return(n); // caso trivial
	else {
		int siz = cd(n);
		return((n % 10)*pow(10,siz-1)+inverte(n/10)); // caso simples + caso complex
	}
}

int main()
{
	int num, inv;
	printf("Numero: ");
	scanf("%i",&num);
	inv = inverte(num);
	printf("\nO inverso de %i e' %i",num,inv);
	
}
