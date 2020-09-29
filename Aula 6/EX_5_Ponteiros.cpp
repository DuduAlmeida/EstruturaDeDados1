#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

int main()
{
    int *v;
    int n;
    printf("\nQuantos elementos no vetor: ");
    scanf("%i", &n);
    
    v = (int *) malloc( n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("\nEntre com o elemento [%i]: ", i);
        scanf("%i", &v[i]);
    }

    printf("\nConteudo do vetor: ");
    for (int i = 0; i < n; i++)
    {
        printf("\nElemento [%i]: %i", i, v[i]);        
    }

    free(v);

    printf("\nConteudo do vetor depois de liberar a memoria: ");
    for (int i = 0; i < n; i++)
    {
        printf("[%i]  ", v[i]);        
    }
}
