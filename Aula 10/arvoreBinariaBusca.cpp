#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

/* #region Constants*/

#define espaco 5

/* #Endregion Constants*/

/* #region Structs*/

struct no
{
    int info;
    struct no *left;
    struct no *right;
};
typedef struct no no;

/* #Endregion Structs*/

/* #region Functions*/

void desenha_arvore_horiz(no *arvore, int depth, char *path, int direita);
void draw_arvore_hor(no *arvore);
no *makeNode(int n);
void insert(int n, no **t);
bool search(int n, no **t);
int calculateShallow(no **t, int indice);
int countLeafNode(no **t, int cont);

/* #Endregion Functions*/

/* #region MainAplication*/

int main()
{
    no *tree = NULL;
    int aux = 0;

    do
    {

        fflush(stdin);
        printf("\nDigite um numero: ");
        scanf("%i", &aux);

        if (aux != -1)
            insert(aux, &tree);
    } while (aux != -1);

    fflush(stdin);
    system("CLS");

    draw_arvore_hor(tree);

    // printf("\n\nVerificar existencia do numero: ");
    // scanf("%i", &aux);
    // printf("%s\n\n", search(aux, &tree) ? "Numero existente" : "Numero inexistente");

    printf("\n\nProfundidade: %i", calculateShallow(&tree, 0));
    printf("\nQuantidade de nos folhas: %i", countLeafNode(&tree, 0));
}

/* #Endregion MainAplication*/

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

no *makeNode(int n)
{
    no *p;
    p = (no *)malloc(sizeof(no));
    p->info = n;
    p->left = NULL;
    p->right = NULL;

    return p;
}

void insert(int n, no **t)
{
    if (*t == NULL)
        *t = makeNode(n);
    else if (n > (*t)->info)
        insert(n, &((*t)->right));
    else
        insert(n, &((*t)->left));
}

bool search(int n, no **t)
{

    if (*t == NULL)
        return false;
    else if ((*t)->info == n)
        return true;
    else if (n > (*t)->info)
        search(n, &((*t)->right));
    else
        search(n, &((*t)->left));
}

int calculateShallow(no **t, int indice){
    int left, right;

    if(*t == NULL){
        return indice - 1;
    }

    right = calculateShallow(&((*t)->right), indice + 1);
    left = calculateShallow(&((*t)->left), indice + 1);

    return right > left ? right : left;
}

int countLeafNode(no **t, int cont){
    int left, right;

    if(*t == NULL){
        return cont + 1;
    }

    right = calculateShallow(&((*t)->right), cont);
    left = calculateShallow(&((*t)->left), cont);

    return right > left ? right : left;
}