#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

int main()
{
    int *val;

    //Se não precisar reutilizar o ponteiro, o malloc entra melhor
    val = (int *) malloc(sizeof (int));
    *val = 9;
    printf("\nValor da variavel [malloc]: %i", *val);
    //Valor perde a referência e mostra um lico de memória
    free(val);
    printf("\nValor da variavel [free]: %i", *val);
    //Pro realloc funcionar tem que ser nulo, ou já possuir um lugar armazenado
    val = NULL;
    val = (int *) realloc(val ,1*sizeof (int));
    *val = 9;
    printf("\nValor da variavel [realloc]: %i", *val);

}
