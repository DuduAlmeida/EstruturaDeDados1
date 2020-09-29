#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>


struct no {
   int info;
   struct no *prox;   
};

no *novo_no(int i);
void inicializar_lista(no *l);
no *insere_no(no *p,int i,char param);
void remove_no(no **l, no *p,char param);
no *busca_antecessor(no *l,no *p);


int main()
{
	no *lista, *p;
	inicializar_lista(lista);
    
    lista = insere_no(lista, 2,'i');
	p = insere_no(lista,4,'f');
	p = insere_no(p,6,'f');
	p = insere_no(p,8,'f');
	lista = insere_no(lista,10,'i');
	p=lista->prox->prox;
	p = insere_no(p,5,'m');

	p=lista;
	remove_no(&lista, lista,'i');

	p=lista->prox->prox;
	
	remove_no(&lista, p,'m');
	p=lista->prox->prox;
	remove_no(&lista, p,'m');
	p=lista->prox->prox;
	remove_no(&lista, p,'m');
	p=lista;
	remove_no(&lista, lista,'i');

	printf("\n\nPERCORRENDO A LISTA\n\n");
	p = lista;
	while (p != NULL)
		{
		printf("[%i] ",p->info);
		p = p->prox;
		}
}

no *novo_no(int i)
{
	no *p;
	p = (no *) malloc(sizeof(no));
	p->info = i;
	p->prox = NULL;
    return(p);
}

void inicializar_lista(no *l)
{
	l = NULL;
}

no *insere_no(no *p,int i,char param)
{
	no *q;
	q = novo_no(i);
	switch (param)
	{
		case 'i' :
			q->prox = p;
			p = q;
			break;
		case 'm' :
			q->prox = p->prox;
			p->prox = q;
			break;
		case 'f' :
			p->prox = q;
			break;
	}
	return(q);
}

no *busca_antecessor(no *l, no *p)
{
	no *q;
	q = l;
	while (q->prox != p)
		{
		q = q->prox;
		}
	return(q);	
}

void remove_no(no **l, no *p, char param)
{
	no **q, *r;
	switch (param)
	{
		case 'i':
			*l = (*l)->prox;
			break;
		case 'm':
			r = busca_antecessor(*l, p);
			r->prox = p->prox;
			break;
		case 'f':
			r = busca_antecessor(*l, p);
			r->prox = NULL;
			break;
	}
}
