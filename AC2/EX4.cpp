#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

int sla = 0;

int fib(int i)
{
    ++sla;
    printf("1 ");
    switch (i)
    {
    case 0:
        return (1);
        break;
    case 1:
        return (1);
        break;
    default:
        return (fib(i - 2) + fib(i - 1));
        break;
    }
}

int main()
{
    int e = 5;
    // for (int i = 1; i <= e; i++)
    printf("\nResposta: %i \n", fib(5));
    printf("\ncont: %i", sla);
}