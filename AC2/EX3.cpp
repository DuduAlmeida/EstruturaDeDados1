#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

struct no
{
    int info;
    struct no *prox;
};

no *novo_no(int i)
{
    no *p;
    p = (no *)malloc(sizeof(no));
    p->info = i;
    p->prox = NULL;
    return (p);
}

void insere(no **q, int i)
{
    no *p, *a;
    if (*q == NULL)
    {

        p = novo_no(i);
        p->prox = *q;
        *q = p;
    }
    else
    {
        a = *q;
        while (a->prox != NULL)
        {
            a = a->prox;
        }
        p = novo_no(i);
        a->prox = p;
    }
}