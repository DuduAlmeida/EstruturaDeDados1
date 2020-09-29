#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>


struct no {
   int info;
   struct no *prox;   
};

int main()
{
	no *lista, *p, *q;
	lista = NULL;   //lst aponta para NULL

	p = (no *) malloc(sizeof(no));
	p->info = 8;

    printf("\nConteudo (passo 1): %i", p->info);
	
	lista = p;
    printf("\nConteudo (passo 2): %i", p->info);

    lista->info = 10;
    printf("\nConteudo (passo 3): %i", lista->info);
    printf("\nConteudo (passo 4): %i", p->info);

    //Ele muda o apontamento, não o valor que do antigo apontamento
    p = (no *) malloc(sizeof(no));
    printf("\nConteudo (passo 5): %i", lista->info);
    printf("\nConteudo (passo 6): %i", p->info);

    p->info = 12;
    printf("\nConteudo (passo 7): %i", lista->info);
    printf("\nConteudo (passo 8): %i", p->info);

    lista->prox = p;
    printf("\nConteudo (passo 9): %i", lista->info);
    printf("\nConteudo (passo 10): %i", p->info);

    printf("\nConteudo (passo 11): %i", lista->info);
    printf("\nConteudo (passo 12): %i", lista->prox->info);

    //Inserir no final da lista
    q = p;
    p = (no *) malloc(sizeof(no));
    p->info = 105;
    q->prox = p;

    printf("\nConteudo: %i", lista->info);
    printf("\nConteudo: %i", lista->prox->info);
    printf("\nConteudo: %i", lista->prox->prox->info);

    p->prox = NULL;

    printf("\n\nPercorrendo a lista:");
    p = lista;
    while ((p != NULL)){
        printf("\nConteudo: %i", p->info);
        p = p->prox;
    }
    
}
