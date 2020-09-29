#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

#define MAX 30

typedef struct 
{
    int dia, mes, ano;
} data;


int main()
{
    data *dias;
    data *f;
    
    dias = (data *) malloc ( MAX * sizeof(data));

    dias[0].dia = 20; dias[0].mes = 9;  dias[0].ano = 2020;
    dias[1].dia = 10; dias[1].mes = 12; dias[1].ano = 2020;
    dias[2].dia = 12; dias[2].mes = 3;  dias[2].ano = 2020;

    //F aponta para o endereço do D:
    f = &dias[0];
    
    printf("\nData [d]:\t%2i/%2i/%4i", dias[0].dia,dias[0].mes,dias[0].ano);    
    printf("\nData [f]:\t%2i/%2i/%4i", f->dia,f->mes,f->ano);

    f = &dias[1];

    printf("\nData [d]:\t%2i/%2i/%4i", dias[1].dia,dias[1].mes,dias[1].ano);    
    printf("\nData [f]:\t%2i/%2i/%4i", f->dia,f->mes,f->ano);

    f = &dias[2];

    printf("\nData [d]:\t%2i/%2i/%4i", dias[2].dia,dias[2].mes,dias[2].ano);    
    printf("\nData [f]:\t%2i/%2i/%4i\n\n", f->dia,f->mes,f->ano);
    
    //F perde a referência de D, desse modo o D permanece com o seu valor
    free(f);
    system("PAUSE");    

    printf("\nData [d]:\t%2i/%2i/%4i", dias[2].dia,dias[2].mes,dias[2].ano);    
    printf("\nData [f]:\t%2i/%2i/%4i", f->dia,f->mes,f->ano);
}
