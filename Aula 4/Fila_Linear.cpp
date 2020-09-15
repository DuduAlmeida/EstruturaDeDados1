// Fila linear - sem rearranjo
//	Programe conforme o raciocínio lógico da execução

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
	char items[MAX];
	int inicio, fim;
} fila;

void op_inserir(fila *q);
void op_remover(fila *q);
void op_mostrar(fila *q);

void inicializar_fila(fila *q);
bool fila_vazia(fila *q);
bool fila_cheia(fila *q);
void inserir_fila(int v,fila *q);
char remover_fila(fila *q);

int main()
{
	int op;
	fila Q;
	inicializar_fila(&Q);
	while (true)
	{
		system("CLS");
		printf("<< MENU >>");
		printf("\n1 - Inserir");
		printf("\n2 - Remover");
		printf("\n3 - Listar");
		printf("\n0 - Sair");
		printf("\nOpcao: ");
		scanf("%d",&op);
		switch (op)
		{
			case 1:
				op_inserir(&Q);
				break;
			case 2:
				op_remover(&Q);
				break;
			case 3:
				op_mostrar(&Q);
				break;
			case 0:
				exit(1);
				break;	
		}
	}
}

void inicializar_fila(fila *q)
{
	q->inicio = -1;
	q->fim =  -1;
	for(int i=0;i<MAX;i++)
		q->items[i] = ' ';
}

bool fila_vazia(fila *q)
{
	return(q->inicio == q->fim);
}

bool fila_cheia(fila *q)
{
	return(q->fim == (MAX-1));
}

void inserir_fila(char v,fila *q)
{
	q->fim++;
	q->items[q->fim] = v;
}

char remover_fila(fila *q)
{
	q->inicio++;
	return(q->items[q->inicio]);
}



void op_inserir(fila *q)
{
	char v;
	if (!fila_cheia(q))
	{
		printf("\n\t\tQual o elemento a inserir: ");
		fflush(stdin);
		scanf("%c",&v);
		inserir_fila(v,q);
		printf("\n\t\tElemento %c inserido com sucesso!\n\t\t",v);
	}
	else
		printf("\n\t\tFila ja esta cheia!\n\t\t");	
	system("PAUSE");	
}

void op_remover(fila *q)
{
	char v;
	if (!fila_vazia(q))
	{
		v = remover_fila(q);	
		printf("\n\t\tElemento %c foi removido com sucesso!\n\t\t",v);
	}
	else
		printf("\n\t\tFila esta vazia!\n\t\t");	
	system("PAUSE");	
}

void op_mostrar(fila *q)
{
	printf("\nESPACO TODO");
	printf("\n Inicio = %d \t Fim = %d\n",q->inicio,q->fim);
	for(int i=0;i<MAX;i++)
		printf("%i\t",i);
	printf("\n");
	for(int i=0;i<MAX;i++)
		printf("%c\t",q->items[i]);
	
	printf("\n\nFILA");
	printf("\n Inicio = %d \t Fim = %d\n",q->inicio,q->fim);
	for(int i=q->inicio+1;i<=q->fim;i++)
		printf("%i\t",i);
	printf("\n");
	for(int i=q->inicio+1;i<=q->fim;i++)
		printf("%c\t",q->items[i]);
	printf("\n");
	system("PAUSE");

}
