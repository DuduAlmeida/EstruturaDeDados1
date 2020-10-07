#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

struct no
{
    int info;
    struct no *prox;
};

no *novo_no(int i);
no *insere_no(no *p, int i, char param);
void remove_no(no **l, no *p, char param);
no *busca_antecessor(no *l, no *p);
int calcularSomaListInfo_i(no *l);
int calcularSomaListInfo_r(no *l);

int main()
{
    no *lista, *p, *q;
    int op;
    int num;
    lista = NULL;

    //Inclusão de dados na lista:
    lista = insere_no(lista, 5, 'i');
    p = lista;
    q = p;
    while (p != NULL)
    {
        q = p;
        p = p->prox;
    }
    p = insere_no(q, 12, 'f');
    q = p;
    p = p->prox;
    p = insere_no(q, 6, 'f');
    q = p;
    p = p->prox;
    p = insere_no(q, 9, 'f');

    //Listagem:
    p = lista;    
    while (p != NULL)
    {
        printf("[%i] ", p->info);
        p = p->prox;
    }
    printf("\n\n");    

    printf("\nSoma [interativa]: %i\n", calcularSomaListInfo_i(lista));
    printf("\nSoma [recursiva]: %i", calcularSomaListInfo_r(lista));
}

no *novo_no(int i)
{
    no *p;
    p = (no *)malloc(sizeof(no));
    p->info = i;
    p->prox = NULL;
    return (p);
}

no *insere_no(no *p, int i, char param)
{
    no *q;
    q = novo_no(i);
    switch (param)
    {
    case 'i':
        q->prox = p;
        p = q;
        break;
    case 'm':
        q->prox = p->prox;
        p->prox = q;
        break;
    case 'f':
        p->prox = q;
        break;
    }
    return (q);
}

no *busca_antecessor(no *l, no *p)
{
    no *q;
    q = l;
    while (q->prox != p)
    {
        q = q->prox;
    }
    return (q);
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

int calcularSomaListInfo_i(no *l){
    no *p = l;
    int sum = 0;

    while(p != NULL){
        sum += (int) p->info;
        // printf("Soma [%i]: %i\n", p->info, sum);
        p = p->prox;
    }

    return sum;
}

int calcularSomaListInfo_r(no *l){
    no *p = l;
    int sum = 0;

    if(p != NULL){
        sum = (int) l->info + calcularSomaListInfo_r(l->prox);
        // printf("\nSoma [%i]: %i", p->info, sum);        
    }

    return sum;
}