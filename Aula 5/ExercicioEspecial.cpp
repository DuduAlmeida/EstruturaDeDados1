#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX 400
#define qtdMaxCaixas 10

typedef struct {
	char items[MAX];
	int inicio, fim;
} fila;

typedef struct
{
    int items[MAX];
    int top;
	int tempoRestante;
	int tempoSolicitado;
} stack;

void pause (float delay1);

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


void inicializarGuiches(int quantidade, stack ** guiches);


int main()
{
	int cont = 1, qtdCaixas, quantidadeCiclos;
	fila pessoas;
    stack *guiches = NULL;
    float clk ;

    
	// inicializar_fila(&pessoas);

	printf("Quantos guiches serao utilizados: ");
	fflush(stdin);
	scanf("%i", &qtdCaixas);

	inicializarGuiches(qtdCaixas, &guiches);
    printf("Qual valor do clock da simulacao em segundos: ");
	fflush(stdin);
    scanf("%f", &clk);
	printf("Quantidade de Ciclos: ");
	fflush(stdin);
    scanf("%i", &quantidadeCiclos);

	while (cont <= quantidadeCiclos)
	{
		// A mágica acontece aqui
	}
}



void pause (float delay1) {
   if (delay1<0.001) return; // pode ser ajustado e/ou evita-se valores negativos.
   float inst1=0, inst2=0;
   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;
   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
   return;
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

void mostrarPilha( stack *s, char nomePilha[MAX] ){

    int aux[MAX],
    i = 0,
    tamanhoPilha = 0,
	tamanhoNomePilha = strlen(nomePilha);
	char auxNomePilha[MAX];

	while (i <  tamanhoNomePilha)
    {
        auxNomePilha[i] = '='; 
        i++;
    }
	auxNomePilha[i] = '\0';
	i = 0;

    while (s->top >= 0)
    {
        aux[i] = pop(s); 
        i++;
    }
    tamanhoPilha = i;
    i=0;

    printf("\n============\t%s\t============\n", nomePilha);
    while(i < tamanhoPilha)
    {
        if(i != 0)
            printf("\t%i", aux[i]);
        else 
            printf("%i", aux[i]);
        push(aux[i], s);
        i++;
    }
    printf("\n================%s==================", auxNomePilha);
}


//Funções Referente aos guichês:
void inicializarGuiches(int quantidade, stack ** guiches){

	int i;

	if( (*guiches = (stack*) realloc(*guiches, quantidade * sizeof(stack))) == NULL){
		printf("\nErro na alocacao dos guiches\n");
		exit(1);
	}

	// printf("\n%i", quantidade);

	for (i = 0; i < quantidade; i++)
	{
		(*guiches + i)->tempoRestante = 0;
		(*guiches + i)->tempoSolicitado = 0;
		(*guiches + i)->top = -1;
		push(0, *guiches + i);
		// mostrarPilha(*guiches + i, "Guiche [ ]");
	}
		
}