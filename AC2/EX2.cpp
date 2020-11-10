#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

struct no
{
    int info;
    struct no *prox;
};

int main()
{
    no *lista, *p, *q;
    p = (no *)malloc(sizeof(no));
    p->info = 8;
    p->prox = NULL;
    lista = p;
    q = p;

    p = (no *)malloc(sizeof(no));
    p->info = 10;
    p->prox = NULL;
    q->prox = p;
    q = q->prox;

    p = (no *)malloc(sizeof(no));
    p->info = 12;
    p->prox = NULL;

    q->prox = p;
    q = q->prox;

    p = (no *)malloc(sizeof(no));
    p->info = 14;
    p->prox = NULL;
    q->prox = p;
    q = q->prox;

    p = (no *)malloc(sizeof(no));
    p->info = 27;
    p->prox = NULL;
    q->prox = p;

    printf("\n%i, %i e %i", lista->info, p->info, q->info);

    q = q->prox;
    printf("\n%i, %i e %i", lista->info, p->info, q->info);
}