#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>


int main()
{
	int x, y, *p, **q;
	x = 10;
	y = 5;
	p = &x;
	q = &p;
	printf("\n %i",x);
	printf("\n %i",*p);
	*q = &y;  
	printf("\n %i",*p);
}
