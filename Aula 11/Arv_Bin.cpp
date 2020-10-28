#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#define MAX 10
#define espaco 5

struct no {
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

// https://pt.stackoverflow.com/questions/207358/como-imprimir-%C3%A1rvores-bin%C3%A1rias-gen%C3%A9ricas-usando-c
void desenha_arvore_horiz(no *arvore, int depth, char *path, int direita);
void draw_arvore_hor(no *arvore);

int main()
{
	int v[MAX] = {6, 5, 8, 9, 7, 10, 2, 3, 4, 1};
	no *tree;
	tree = NULL;
	for(int i=0; i < MAX; i++)
		insert(v[i],&tree);
	printf("\n Vetor Original: ");
	for(int i=0; i < MAX; i++)
		printf("[%i] ",v[i]);
	printf("\n Altura da Arvore: %i",altura(tree));
	printf("\n Qtde Nos Folha: %i",qtd_folhas(tree));
	printf("\n Qtde Nos Total: %i",conta_nos(tree));
	draw_arvore_hor(tree);
	printf("\n Percurso Pre Ordem: ");
	preordem(tree);	
	printf("\n Percurso In Ordem: ");
	inordem(tree);	
	printf("\n Percurso Pos Ordem: ");
	posordem(tree);	
	int num;
	while(true)
	{
		printf("\nQual numero buscar (0=Exit)?: ");
		scanf("%i",&num);
		if(num==0) exit(-1);
		if (find(num, tree)) printf("\nEncontrado!");
		else printf("\nNAO Encontrado!");
	} 
}

no *maketree(int n)
{
	no *p;
	p = (no *) malloc(sizeof(no));
	p->info = n;
	p->left = NULL;
	p->right = NULL;
	return(p);
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
		printf("[%i] ",t->info);
		preordem(t->left);
		preordem(t->right);
	}
}

void inordem(no *t)
{
	if (t != NULL)
	{
		inordem(t->left);
		printf("[%i] ",t->info);
		inordem(t->right);
	}
}

void posordem(no *t)
{
	if (t != NULL)
	{
		posordem(t->left);
		posordem(t->right);
		printf("[%i] ",t->info);
	}
}

bool find(int n, no *t)
{
	if(t==NULL) return(false); // procurando e encontrei NULL
	else if(n == t->info) return(true); // 
	else if(n > t->info) return(find(n,t->right));
	else 				 return(find(n,t->left));
}

int altura(no *t)
{
	if(t == NULL)
		return(-1);
	else
	{
		int alt_e = 1 + altura(t->left);
		int alt_d = 1 + altura(t->right);
		return(alt_e > alt_d ? alt_e : alt_d);
		}	
}

int qtd_folhas(no *t)
{
    if(t == NULL) return(0);
    else if((t->left == NULL) && (t->right == NULL)) return (1);
    return(qtd_folhas(t->left) + qtd_folhas(t->right)); 
} 

int conta_nos(no *t)
{
   if(t == NULL) return(0);
    else return(1 + conta_nos(t->left) + conta_nos(t->right)); 
}

void desenha_arvore_horiz(no *arvore, int depth, char *path, int direita)
{
    if (arvore== NULL)
        return;
    depth++;
    desenha_arvore_horiz(arvore->right, depth, path, 1);
    path[depth-2] = 0;

    if(direita)
        path[depth-2] = 1;

    if(arvore->left)
        path[depth-1] = 1;

    printf("\n");

    for(int i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    printf("%d\n", arvore->info);

    for(int i=0; i<depth; i++)
    {
      if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
          printf(" ");
    }

    desenha_arvore_horiz(arvore->left, depth, path, 0);
}

void draw_arvore_hor(no *arvore)
{
    char path[255] = {};
    desenha_arvore_horiz(arvore, 0, path, 0);
}
