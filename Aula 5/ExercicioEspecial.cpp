#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX 1000
#define qtdMaxCaixas 10

typedef struct {
	int items[MAX];
	int inicio, fim;
} fila;

typedef struct
{
    int items[MAX];
    int top;
	int tempoRestante;
} stack;

void pause (float delay1);
int alentre(int a,int b);

//Funções Referente a estrutura das filas:
void inicializar_fila(fila *q);
bool fila_vazia(fila *q);
bool fila_cheia(fila *q);
void inserir_fila(int v,fila *q);
int remover_fila(fila *q);
void mostrar_fila(fila *q);
int prox_indice(int i);

//Funções Referente a estrutura das pilhas/stacks:
bool isFull(stack *s);
bool empty(stack *s);
void push(int e, stack *s);
int pop(stack *s);
int stacktop(stack *s);


void inicializarGuiches(int quantidade, stack ** guiches);
int verificarGuicheLivre(stack **guiches, int qtdGuiches);
void guicheAtualizarTempo(stack *guiche, int qtdGuiches, int tempo);
void guicheMostrar(stack *guiche, char nomePilha[MAX]);
void mostrarGuichesFila(stack **guiches, int qtdGuiches, fila *pessoas);
void mostrarRelatorioFinal(stack **guiches, int qtdGuiches, fila *pessoas);


int main()
{
	int cont = 0, qtdCaixas, quantidadeCiclos, intervaloInclusaoFila, tempoTotal = 0,
	guicheLivre, tempoSolicitado = 0;
	fila pessoas;
    stack *guiches = NULL;
    float clk ;

    srand(time(NULL));
	inicializar_fila(&pessoas);

	printf("Quantos guiches serao utilizados: ");
	fflush(stdin);
	scanf("%i", &qtdCaixas);

	inicializarGuiches(qtdCaixas, &guiches);
	inicializar_fila(&pessoas);

	printf("Quanto tempo para chegar uma pessoa na fila: ");
	fflush(stdin);
    scanf("%i", &intervaloInclusaoFila);
    printf("Qual valor do clock da simulacao em segundos: ");
	fflush(stdin);
    scanf("%f", &clk);
	printf("Quantidade de Ciclos(Atendimentos): ");
	fflush(stdin);
    scanf("%i", &quantidadeCiclos);

	while (cont < quantidadeCiclos)
	{
		// A mágica acontece aqui

		//Caso o intervalo de inclusão na fila tenha acabado, incluir uma pessoa na fila
		if(tempoTotal == 0 || (tempoTotal)%intervaloInclusaoFila == 0 ){
			inserir_fila(alentre(3,5), &pessoas);
			// inserir_fila(13, &pessoas);
			cont++;
		}

		//Verificar se há um guiche livre, e retornar o indice do mesmo
		guicheLivre = verificarGuicheLivre(&guiches, qtdCaixas);

		//Caso esteja livre e tenha pessoa na fila, retirar uma pessoa da fila e incluir no guichê
		if(guicheLivre != -1 && fila_vazia(&pessoas) == false){
			printf("\nGuiche livre [ %i ]", guicheLivre);
			tempoSolicitado = remover_fila( &pessoas);
			push(tempoSolicitado, (guiches+guicheLivre));
			(guiches+guicheLivre)->tempoRestante = tempoSolicitado;
		}
		
		//Mostrar os Guichês e fila:
		mostrarGuichesFila(&guiches, qtdCaixas,&pessoas);
		printf("\n\nTempo Final[ %i ]\n\n", tempoTotal);

		//Atualizar o tempo percorrido a cada interação
		guicheAtualizarTempo(guiches, qtdCaixas, 1);
		
		pause(clk);
		tempoTotal += 1;
		system("PAUSE");
	}

	mostrarRelatorioFinal(&guiches, qtdCaixas,&pessoas);

	return 0;
}



void pause (float delay1) {
   if (delay1<0.001) return; // pode ser ajustado e/ou evita-se valores negativos.
   float inst1=0, inst2=0;
   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;
   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
   return;
}

int alentre(int a,int b)
{
	return(a+(rand()%(b-a+1)));
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

void mostrar_fila(fila *q)
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
		(*guiches + i)->top = -1;
		// push(0, *guiches + i);
		// mostrarPilha(*guiches + i, "Guiche [ ]");
	}
		
}

int verificarGuicheLivre(stack **guiches, int qtdGuiches){
	int guicheLivre = -1, i;

	for(i=0;i<qtdGuiches;i++){
		
		if( (*guiches+i)->tempoRestante == 0){
			return i;
		}
	}

	return guicheLivre;
}

void guicheAtualizarTempo(stack *guiche, int qtdGuiches, int tempo){
	int i;
	
	for(i=0;i<qtdGuiches;i++){
		(guiche+i)->tempoRestante -= tempo;
		
		if( (guiche+i)->tempoRestante <= 0){			
			
			(guiche+i)->tempoRestante = 0;
		}
	}
}

void guicheMostrar(stack *guiche, char nomePilha[MAX]){
	
	printf("\n%s: %d restantes",nomePilha, (guiche)->tempoRestante);	
}

void mostrarGuichesFila(stack **guiches, int qtdGuiches, fila *pessoas){

	int i;
	char nomeGuiche[] = "Guiche [ ]";

	for (i = 0; i < qtdGuiches; i++)
	{	
		nomeGuiche[8] = i + '0';
		// mostrarPilha(*guiches + i, nomeGuiche);
		guicheMostrar(*guiches + i, nomeGuiche);
	}
	mostrar_fila(pessoas);
}

void mostrarRelatorioFinal(stack **guiches, int qtdGuiches, fila *pessoas){

	int i;
	char nomeGuiche[] = "Guiche [ ]";

	for (i = 0; i < qtdGuiches; i++)
	{	
		nomeGuiche[8] = i + '0';
		mostrarPilha(*guiches + i, nomeGuiche);
	}
	mostrar_fila(pessoas);
}