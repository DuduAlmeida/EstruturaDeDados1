#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

typedef struct 
{
    int dia, mes, ano;
} data;


int main()
{
    data *d;

    d = (data*) malloc (sizeof(data));
    d->dia = 22;
    d->mes = 9;
    d->ano = 2020;
    
    printf("\nData [malloc]:\t%2i/%2i/%4i", d->dia,d->mes,d->ano);
    free(d);
    printf("\nData [free]:\t%2i/%2i/%4i", d->dia,d->mes,d->ano);
}
