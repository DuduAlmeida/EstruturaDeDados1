#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#define MAX 10
#define espaco 5

struct no
{
    int info;
    struct no *left;
    struct no *right;
};

no *maketree(int n);
void insert(int i, no **t);
bool find(int n, no *t);

int altura(no *t);
int qtd_folhas(no *t);
int conta_nos(no *t);

void preordem(no *t);
void inordem(no *t);
void posordem(no *t);

void sortIntArray(int **list, int length);
void build_tree(int e, int d, int v[], no**t);

// https://pt.stackoverflow.com/questions/207358/como-imprimir-%C3%A1rvores-bin%C3%A1rias-gen%C3%A9ricas-usando-c
void desenha_arvore_horiz(no *arvore, int depth, char *path, int direita);
void draw_arvore_hor(no *arvore);

int main()
{
    no *tree = NULL;
    int aux = 0, *listNumbers = NULL, cont = 0, indexMedium;

    do
    {

        fflush(stdin);
        printf("\nDigite um numero: ");
        scanf("%i", &aux);

        if (aux != -1)
        {
            listNumbers = (int *)realloc(listNumbers, sizeof(int) * (cont + 1));
            listNumbers[cont] = aux;
            cont++;
        }

    } while (aux != -1);

    fflush(stdin);
    system("CLS");

    sortIntArray(&listNumbers, cont);

    for (int i = 0; i < cont; i++)
    {
        printf("[%i]\t", listNumbers[i]);
    }

    indexMedium = cont / 2;
    insert(listNumbers[indexMedium], &tree);
    int m = indexMedium;
    for (int i = 0; i < indexMedium; i++)
    {
        if (i - 1  !=  m)
        {
            m = (i+m)/2;
            insert(listNumbers[m], &tree);
        }
        // else if (indexMedium - 1 >= 0)
        // {
        // }
    }

    draw_arvore_hor(tree);
}

no *maketree(int n)
{
    no *p;
    p = (no *)malloc(sizeof(no));
    p->info = n;
    p->left = NULL;
    p->right = NULL;
    return (p);
}

void insert(int n, no **t)
{
    if (*t == NULL)
        *t = maketree(n);
    else if (n > (*t)->info)
        insert(n, &((*t)->right));
    else
        insert(n, &((*t)->left));
}

void preordem(no *t)
{
    if (t != NULL)
    {
        printf("[%i] ", t->info);
        preordem(t->left);
        preordem(t->right);
    }
}

void inordem(no *t)
{
    if (t != NULL)
    {
        inordem(t->left);
        printf("[%i] ", t->info);
        inordem(t->right);
    }
}

void posordem(no *t)
{
    if (t != NULL)
    {
        posordem(t->left);
        posordem(t->right);
        printf("[%i] ", t->info);
    }
}

bool find(int n, no *t)
{
    if (t == NULL)
        return (false); // procurando e encontrei NULL
    else if (n == t->info)
        return (true); //
    else if (n > t->info)
        return (find(n, t->right));
    else
        return (find(n, t->left));
}

int altura(no *t)
{
    if (t == NULL)
        return (-1);
    else
    {
        int alt_e = 1 + altura(t->left);
        int alt_d = 1 + altura(t->right);
        return (alt_e > alt_d ? alt_e : alt_d);
    }
}

int qtd_folhas(no *t)
{
    if (t == NULL)
        return (0);
    else if ((t->left == NULL) && (t->right == NULL))
        return (1);
    return (qtd_folhas(t->left) + qtd_folhas(t->right));
}

int conta_nos(no *t)
{
    if (t == NULL)
        return (0);
    else
        return (1 + conta_nos(t->left) + conta_nos(t->right));
}

void desenha_arvore_horiz(no *arvore, int depth, char *path, int direita)
{
    if (arvore == NULL)
        return;
    depth++;
    desenha_arvore_horiz(arvore->right, depth, path, 1);
    path[depth - 2] = 0;

    if (direita)
        path[depth - 2] = 1;

    if (arvore->left)
        path[depth - 1] = 1;

    printf("\n");

    for (int i = 0; i < depth - 1; i++)
    {
        if (i == depth - 2)
            printf("+");
        else if (path[i])
            printf("|");
        else
            printf(" ");

        for (int j = 1; j < espaco; j++)
            if (i < depth - 2)
                printf(" ");
            else
                printf("-");
    }

    printf("%d\n", arvore->info);

    for (int i = 0; i < depth; i++)
    {
        if (path[i])
            printf("|");
        else
            printf(" ");

        for (int j = 1; j < espaco; j++)
            printf(" ");
    }

    desenha_arvore_horiz(arvore->left, depth, path, 0);
}

void draw_arvore_hor(no *arvore)
{
    char path[255] = {};
    desenha_arvore_horiz(arvore, 0, path, 0);
}

void sortIntArray(int **list, int length)
{
    int i, j, aux;

    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if ((*list)[i] > (*list)[j])
            {
                aux = (*list)[i];
                (*list)[i] = (*list)[j];
                (*list)[j] = aux;
            }
        }
    }

    printf("\n");

    for (int i = 0; i < length; i++)
    {
        // printf("[%i]\t", (*list)[i]);
    }
}

void build_tree(int e, int d, int v[], no**t){
    if(d-1 != e){
        int m = (e+d)/2;
        insert(v[m],t);
        build_tree(e,m,v,t);
        build_tree(m,d,v,t);
    }
}