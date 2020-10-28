#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    int aux = 0, *listNumbers=NULL, cont=0;

    do
    {
        listNumbers = (int *) realloc(listNumbers,sizeof(int)*(cont+1));

        fflush(stdin);
        printf("\nDigite um numero: ");
        scanf("%i", &listNumbers[cont]);
        aux = listNumbers[cont];
        printf("%i",aux);

        cont++;
    } while (aux != -1);

    fflush(stdin);
    system("CLS");

    for (int i = 0; i < cont; i++)
    {
        printf("[%i]\t",listNumbers[i]);
    }
    return 0;
}
