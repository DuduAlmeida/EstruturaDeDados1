#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 1000

typedef struct {
	int items[MAX];
	int inicio, fim;
} fila;

typedef struct
{
    int items[MAX];
    int top;
    int tempoRestante;
    int tempoRequisitado;
} stack;

void pause (float delay1);
void op_inserir(fila *q);
void op_remover(fila *q);
void op_mostrar(fila *q);

//Fun��es Referente a estrutura das filas:
void inicializar_fila(fila *q);
bool fila_vazia(fila *q);
bool fila_cheia(fila *q);
void inserir_fila(int v,fila *q);
int remover_fila(fila *q);
int prox_indice(int i);

//Fun��es Referente a estrutura das pilhas/stacks:
void inicializarPilhas(stack **stack, int qtdGuiches);
void guicheAtualizarTempo(stack *guiche, int qtdGuiches, int tempo);
int guicheLivre(stack *guiche, int qtdGuiches);
void guicheMostrar(stack *guiche, int qtdGuiches);
bool guicheAindaPossui(stack *guiche, int qtdGuiches);

bool isFull(stack *s);
bool empty(stack *s);
void push(int e, stack *s);
int pop(stack *s);
int stacktop(stack *s);



int main()
{
	int cont = 1, qtdAtendentes, qtde, aux;
	
	fila pessoas;
	
    stack *guiches = NULL;
    
    float tmpChegada, tmpAtendimento, tmpTotal=0;
    
 	srand(time(NULL));
 	inicializar_fila(&pessoas);
	
	printf("Simulador de Caixas\n");
	printf("=====================================================================\n\n");
	inicializar_fila(&pessoas);

    printf("Informe o numero de atendentes (guiches): ");
    scanf("%i",&qtdAtendentes);
    fflush(stdin);
    
    //Inicializa uma pilha para cada guiche
    inicializarPilhas(&guiches, qtdAtendentes);
    guicheMostrar(guiches, qtdAtendentes);
    
    printf("\nInforme o intervalo de tempo de chegada dos clientes ao banco, em segundos: ");
    scanf("%f",&tmpChegada);
    fflush(stdin);
    
    printf("\nInforme o intervalo de tempo necess�rio para cada atendimento, em segundos: ");
    scanf("%f",&tmpAtendimento);
    fflush(stdin);
    
    printf("\nQuantos elementos no trafego? (3 a 10 para melhor visualizacao): ");
 	scanf("%i",&qtde);
    fflush(stdin);

	while(cont<=qtde || !fila_vazia(&pessoas) || guicheAindaPossui(guiches, qtdAtendentes)==true){
		
		
		if(tmpTotal == 0 || (tmpTotal/tmpChegada == cont-1 && cont<=qtde)){
			inserir_fila(3 + (rand() % 14), &pessoas);
			cont++;
		}
		
		//Recebe o primeiro guichê livre, em ordem numérica
		aux = guicheLivre(guiches, qtdAtendentes);
		
		//Se encontrar e a fila não for vazia, a pessoa sairá da fila 
		//e terá o seu tempo total requisitado salvo para empilhar no histórico do guichê
		if(aux != -1 && !fila_vazia(&pessoas)){			
			(guiches+aux)->tempoRequisitado = remover_fila(&pessoas);
			(guiches+aux)->tempoRestante    = (guiches+aux)->tempoRequisitado;
		}
		
		
    	guicheMostrar(guiches, qtdAtendentes);
 		op_mostrar(&pessoas);
 		printf("\n Tempo total: %.0f\n==========================================\n",tmpTotal);
		
		pause(tmpAtendimento);
		tmpTotal += 1;
		guicheAtualizarTempo(guiches, qtdAtendentes, 1);
	}
	
	
 	

    return 0;
}



void pause (float delay1) {
   if (delay1<0.001) return; // pode ser ajustado e/ou evita-se valores negativos.
   float inst1=0, inst2=0;
   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;
   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
   return;
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
	if(!fila_vazia(q)){
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
			printf("%d\t",q->items[i]);
			i = prox_indice(i);
		}
		printf("%d\t",q->items[i]);
		printf("\n");	
	}
	else{
		printf("\n\nFILA");
		printf("\n Inicio = %d \t Fim = %d\n",q->inicio,q->fim);
		printf("Fila vazia\n");
	}

}

//Fun��es Referente a estrutura das filas:
void inicializar_fila(fila *q)
{
	q->inicio = MAX-1;
	q->fim    = MAX-1;
}

int prox_indice(int i)
{
	return((i+1) == MAX ? 0 : ++i);
}

bool fila_vazia(fila *q)
{
	if(q->inicio == q->fim)
		return true;
		
	return false;
}

bool fila_cheia(fila *q)
{
	return(prox_indice(q->fim) == q->inicio);
}

void inserir_fila(int v,fila *q)
{
	q->fim = prox_indice(q->fim);
	q->items[q->fim] = v;
}

int remover_fila(fila *q)
{
	q->inicio = prox_indice(q->inicio);
	return(q->items[q->inicio]);
}

void inicializarPilhas(stack **s, int qtdGuiches){
	int i;
	
	if((*s = (stack*)realloc(*s,qtdGuiches*sizeof(stack)))==NULL){
		fprintf(stderr, "Memoria insufiente para inicializar pilhas\n");
        exit(1);
	}
	
	for(i=0; i<qtdGuiches; i++){
		(*s+i)->top=-1;
		(*s+i)->tempoRestante=0;
	}
}

int guicheLivre(stack *guiche, int qtdGuiches){
	int i;
	
	for(i=0;i<qtdGuiches;i++)
		if((guiche+i)->tempoRestante == 0)
			return i;
	
	return -1;
}

void guicheAtualizarTempo(stack *guiche, int qtdGuiches, int tempo){
	int i;
	
	for(i=0;i<qtdGuiches;i++){
		(guiche+i)->tempoRestante -= tempo;
		
		if( (guiche+i)->tempoRestante <= 0 ){
			(guiche+i)->tempoRestante = 0;
			//Salva na pilha o "id"/ tempo requisitado pelo cliente:
			push((guiche+i)->tempoRequisitado, (guiche+i));
			(guiche+i)->tempoRequisitado = 0;
		}
	}
}

void guicheMostrar(stack *guiche, int qtdGuiches){
	int i;
	
	for(i=0;i<qtdGuiches;i++){
		printf("\n %d#Atendente: %d restantes",i+1, (guiche+i)->tempoRestante);
	}
}

bool guicheAindaPossui(stack *guiche, int qtdGuiches){
	int i;
	
	for(i=0;i<qtdGuiches;i++)
		if((guiche+i)->tempoRestante != 0)
			return true;
	
	return false;
}

//Fun��es Referente a estrutura das pilhas/stacks:
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
