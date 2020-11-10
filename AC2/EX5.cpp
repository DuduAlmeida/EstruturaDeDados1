#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>

int cd(int n)
{
    if (n < 10)
        return (1);
    else
    {
        return (1 + cd(n / 10));
    }
}

int func(int n)
{
    if (n < 10)
        return (n); // caso trivial
    else
    {
        int siz = cd(n);
        return ((n % 10) * pow(10, siz - 1) + func(n / 10)); // caso simples + caso complex
    }
}

int main()
{
    int num = 132;
    int res = 2;
    res = func(num);

    printf("\n%i e %i", num, res);
}