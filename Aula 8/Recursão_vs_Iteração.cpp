#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int fat_i(int i)
{
	int res = 1;
	while (i > 0)
	{
		res = res * i;
		i--;
	}
	return (res);
}

int fat_r(int i)
{
	if (i == 0)
		return (1);
	else
		return (i * fat_r(i - 1));
}

int fib_i(int i)
{
	int fib1 = 0;
	int fib2 = 1;
	int res = 1;
	if (i == 0)
		return (fib1);
	else if (i == 1)
		return (fib2);
	else
	{
		for (int j = 2; j <= i; j++)
		{
			res = fib1 + fib2;
			fib1 = fib2;
			fib2 = res;
		}
	}
	return (res);
}

int fib_r(int i)
{
	if (i == 0)
		return (0);
	else if (i == 1)
		return (1);
	else
		return (fib_r(i - 1) + fib_r(i - 2));
}

int main()
{
	printf("\n Fatorial (funcao iterativa): %i", fat_i(6));
	printf("\n Fatorial (funcao recursiva): %i", fat_r(6));
	printf("\n Fibonacci (funcao iterativa): %i", fib_i(6));
	printf("\n Fibonacci (funcao recursiva): %i", fib_r(6));
}
