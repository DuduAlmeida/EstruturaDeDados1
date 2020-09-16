#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAX 1000
#define NGUI 50

typedef struct {
	int items[MAX];
	int inicio, fim;
} fila;

typedef struct {
	int items[MAX];
	int top;
	int tempo;
} pilha;


void pause (float);
int alentre(int a,int b);
void mostra_status(fila *q,pilha *guiches);

// PILHA
void inicializar_pilha(fila *s);
bool isfull(pilha *s);
bool empty(pilha *s);
void push(int e, pilha *s);     
int pop(pilha *s);
int stacktop(pilha *s);

// FILA
void inicializar_fila(fila *q);
bool fila_vazia(fila *q);
bool fila_cheia(fila *q);
void inserir_fila(int v,fila *q);
int remover_fila(fila *q);
int prox_indice(int i);


// PRINCIPAL
int main (void) 
{
 fila q;
 pilha guiches[NGUI];	
 int episodios, nguiches, intervalo, tminpc, tmaxpc;	
 float clk,vel;
 srand(time(NULL));
 printf("Parametros da simulacao");
 printf("\n=======================\n");
 printf("Quantos episodios: ");
 scanf("%i",&episodios);
 printf("Velocidade da simulacao: ");
 scanf("%f",&vel);
 printf("Numero de guiches: ");
 scanf("%i",&nguiches);
 printf("Intervalo de chegada dos clientes ao banco: ");
 scanf("%i",&intervalo);
 printf("Tempo MINIMO de atendimento por cliente: ");
 scanf("%i",&tminpc);
 printf("Tempo MAXIMO de atendimento por cliente: ");
 scanf("%i",&tmaxpc);
 
 int contep = 0;
 while (contep < episodios)
 {
	printf("\n-=-=-=-=-=- INICIO DO EPISODIO [%i] -=-=-=-=-=-",contep+1);	
 	if(contep % intervalo == 0)
	 	inserir_fila(alentre(tminpc,tmaxpc),&q);
 	if (!fila_vazia(&q))
 	{
      for(int i=0;i<nguiches;i++)
	  	if(guiches[i].tempo == 0)
	  	{
		  push(remover_fila(&q),&guiches[i]);
		  break; 		 		
		  }
	 }
      for(int i=0;i<nguiches;i++)
	  	if(guiches[i].tempo > 0)
	  	{
		  guiches[i].tempo--;
		  }
	mostra_status(&q,guiches);
	printf("\n-=-=-=-=-=- FIM DO EPISODIO [%i] -=-=-=-=-=-",contep+1);	
 	pause(vel);
//	system("CLS");
//	system("PAUSE");
	contep++;  
 } 
 
float tmp_tot_gui, num_cli_gui, tmp_medio;
float nca, temtot, tmg = 0;
for(int i=0;i<nguiches;i++)
	{
	  tmp_tot_gui = 0;
	  num_cli_gui = -1; 

	  while (!empty(&guiches[i]))
	  {
	  	tmp_tot_gui += pop(&guiches[i]);
	  	num_cli_gui++;
	  }
	  tmp_medio = (num_cli_gui > 0 ? (float) (tmp_tot_gui / num_cli_gui): 0);
	  printf("\n Guiche (%i): Clientes Atendidos (%.0f), Tempo Total (%.0f), Tempo Medio (%.2f)",
	  	i+1,num_cli_gui,tmp_tot_gui,tmp_medio);
	  temtot += tmp_tot_gui;
	  nca += num_cli_gui; 	
	}
 tmg = temtot / nca;
 printf("\n TOTAL CLIENTES ATENDIDOS (%.0f), TEMPO MEDIO ATENDIMENTO (%.2f)",nca,tmg);	
} 

void mostra_status(fila *q,pilha *guiches)
{
	int cf;
	printf("\n-=-=-=-=-=- GUICHES -=-=-=-=-=-\n");	
	for(int i=0;i<NGUI;i++)
		if (guiches[i].tempo>0)
			printf("Gui (%2i)\t",i+1);
	printf("\n");		
	for(int i=0;i<NGUI;i++)
		if (guiches[i].tempo>0)
			printf("TSe (%2i)\t",stacktop(&guiches[i]));
	printf("\n");		
	for(int i=0;i<NGUI;i++)
		if (guiches[i].tempo>0)
			printf("CTS (%2i)\t",guiches[i].tempo);
	printf("\n-=-=-=-=-=- FILA -=-=-=-=-=-\n");	
	if (!fila_vazia(q))
	{
		cf=q->inicio;	
		while (cf != q->fim)
		{
			cf=prox_indice(cf);
			printf("[%i]\t",q->items[cf]);
		}
	}
}


int alentre(int a,int b)
{
	return(a+(rand()%(b-a+1)));
}

void pause (float delay1) {
   if (delay1<0.001) return; // pode ser ajustado e/ou evita-se valores negativos.
   float inst1=0, inst2=0;
   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;
   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
   return;
}

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

//PILHA

void inicializar_fila(pilha *s)
{
	s->top = -1;
	s->tempo = 0;
}

bool isfull(pilha *s)
{
	return(((s->top == (MAX - 1)) ? true : false));
}


bool empty(pilha *s)
{
	return(((s->top == -1) ? true : false));
}

void push(int e, pilha *s)     // void é quando a função retorna NADA (procedimento)
{
	s->top += 1;
	s->items[s->top] = e;
	s->tempo = e;
}

int pop(pilha *s)
{
	int e;
	e = s->items[s->top];
	s->top -= 1;
	return(e);
}

int stacktop(pilha *s)
{
	int e;
	e = s->items[s->top];
	return(e);
}


