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
    data d;
    data *f;
    
    d.dia = 22;
    d.mes = 9;
    d.ano = 2020;

    //F aponta para o endereço do D:
    f = &d;
    
    printf("\nData [d]:\t%2i/%2i/%4i", d.dia,d.mes,d.ano);    
    printf("\nData [f]:\t%2i/%2i/%4i", f->dia,f->mes,f->ano);

    f->dia = 25;

    printf("\nData [d]:\t%2i/%2i/%4i", d.dia,d.mes,d.ano);    
    printf("\nData [f]:\t%2i/%2i/%4i", f->dia,f->mes,f->ano);

    d.dia = 29;

    printf("\nData [d]:\t%2i/%2i/%4i", d.dia,d.mes,d.ano);    
    printf("\nData [f]:\t%2i/%2i/%4i\n\n", f->dia,f->mes,f->ano);
    
    //F perde a referência de D, desse modo o D permanece com o seu valor
    free(f);
    system("PAUSE");    

    printf("\nData [d]:\t%2i/%2i/%4i", d.dia,d.mes,d.ano);    
    printf("\nData [f]:\t%2i/%2i/%4i", f->dia,f->mes,f->ano);
}
