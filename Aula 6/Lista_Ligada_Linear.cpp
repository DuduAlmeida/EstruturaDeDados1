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
	lista = NULL;

	p = (no *) malloc(sizeof(no));
	p->info = 8;
	p->prox = NULL;
	lista = p;
	q = p;

	p = (no *) malloc(sizeof(no));
	p->info = 10;
	p->prox = NULL;
	q->prox = p;
	q = q->prox;
	
	p = (no *) malloc(sizeof(no));
	p->info = 12;
	p->prox = NULL;

	q->prox = p;
	q = q->prox;

	p = (no *) malloc(sizeof(no));
	p->info = 14;
	p->prox = NULL;

	q->prox = p;
	q = q->prox;
	
	printf("\n\nPERCORRENDO A LISTA");
	p = lista;
	while (p != NULL)
		{
		printf("\nConteudo: %i",p->info);
		p = p->prox;
		}
	free(lista);
}
