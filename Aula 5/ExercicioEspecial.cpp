#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
	char items[MAX];
	int inicio, fim;
} fila;

typedef struct
{
    int items[MAX];
    int top;
} stack;

void op_inserir(fila *q);
void op_remover(fila *q);
void op_mostrar(fila *q);

//Funções Referente a estrutura das filas:
void inicializar_fila(fila *q);
bool fila_vazia(fila *q);
bool fila_cheia(fila *q);
void inserir_fila(int v,fila *q);
char remover_fila(fila *q);
int prox_indice(int i);

//Funções Referente a estrutura das pilhas/stacks:
bool isFull(stack *s);
bool empty(stack *s);
void push(int e, stack *s);
int pop(stack *s);
int stacktop(stack *s);



int main()
{
	int op;
	fila pessoas;
	inicializar_fila(&pessoas);
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
	
	if(!fila_vazia(q))
	{
		printf("\n\nFILA");
		printf("\n Inicio = %d \t Fim = %d\n",q->inicio,q->fim);
		int i;
		i = prox_indice(q->inicio);
		while (i != q->fim)
		{
			printf("%i\t",i);
			i = prox_indice(i);
		}
		printf("%i\t",i);
		printf("\n");
		i = prox_indice(q->inicio);
		while (i != q->fim)
		{
			printf("%c\t",q->items[i]);
			i = prox_indice(i);
		}
		printf("%c\t",q->items[i]);
	}
	printf("\n");
	system("PAUSE");

}



//Funções Referente a estrutura das filas:
void inicializar_fila(fila *q)
{
	q->inicio = MAX-1;
	q->fim =  MAX-1;
}

int prox_indice(int i)
{
	return((i+1) == MAX ? 0 : ++i);
}

bool fila_vazia(fila *q)
{
	return(q->inicio == q->fim);
}

bool fila_cheia(fila *q)
{
	return(prox_indice(q->fim) == q->inicio);
}

void inserir_fila(char v,fila *q)
{
	q->fim = prox_indice(q->fim);
	q->items[q->fim] = v;
}

char remover_fila(fila *q)
{
	q->inicio = prox_indice(q->inicio);
	return(q->items[q->inicio]);
}



//Funções Referente a estrutura das pilhas/stacks:
bool isFull(stack *s){
    bool aux;
    aux = (s->top == (MAX - 1) ) ? true : false;
    return aux;
}

bool empty(stack *s){
    bool aux;
    aux = (s->top == -1) ? true : false;
    return aux;
}

void push(int e, stack *s){
    s->top += 1;
    s->items[s->top] = e;
}

int pop(stack *s){
    int aux = s->items[s->top];
    s->top-=1;
    
    return aux;
}

int stacktop(stack *s){

    return s->items[s->top];
}