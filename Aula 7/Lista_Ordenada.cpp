#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>


struct no {
   int info;
   struct no *prox;   
};

no *novo_no(int i);
no *insere_no(no *p,int i,char param);
void remove_no(no **l, no *p,char param);
no *busca_antecessor(no *l,no *p);

int main()
{
	no *lista, *p, *q;
	int op;
	int num;
	lista = NULL;
	while (true)
	{
		system("CLS");
		printf("Lista de Numeros Ordenados\n");
		printf("==========================\n\n");
		printf("Digite uma das opcoes\n");
		printf("[1] Inserir\n");
		printf("[2] Remover\n");
		printf("[3] Listar\n");
		printf("[0] Sair\n");
		scanf("%i",&op);
		switch (op)
		{
			case 0:
				exit(1);
				break;
			case 1:
				printf("Numero a inserir: ");
				scanf("%i",&num);
				if (lista == NULL || num < lista->info ) 
					    lista = insere_no(lista, num,'i');
				else 
					{
						p=lista;
						q=p;
						while (p != NULL && p->info < num)
						{
							q = p;
							p = p->prox;
						}
						if (p == NULL)
							p = insere_no(q,num,'f');
						else
							p = insere_no(q,num,'m');
						}	    
			
				break;
			case 2:
				printf("Numero a remover: ");
				scanf("%i",&num);
				if (lista->info == num) 
					    	remove_no(&lista, lista,'i');
				else 
					{
						p=lista;
						while (p != NULL && p->info != num)
						{
							p = p->prox;
						}
						if (p == NULL){
							remove_no(&lista, p,'f');
						else
							remove_no(&lista, p,'m');
						}	    
				break;
			case 3:
				p = lista;
				printf("\n\n");
				while (p != NULL)
					{
					printf("[%i] ",p->info);
					p = p->prox;
					}
				printf("\n\n");
				system("PAUSE");	    
				break;
		}
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
