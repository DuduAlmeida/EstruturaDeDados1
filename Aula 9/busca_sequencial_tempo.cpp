/* Busca Sequencial
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>

#define MAX 100000
#define CONT 1000000

int alentre(int a,int b);
bool bb (int x, int e, int d, int v[]); 
bool busca (int x, int v[]); 

int main()
{
	srand(time(NULL));
	int v[MAX];
	int found=0, notfound = 0;
	v[0] = 1;
	printf("BUSCA SEQUENCIAL");
	printf("\nConstruindo vetor de chaves com %i posicoes...", MAX);
	for(int i=1;i<MAX;i++)
		v[i] = v[i-1]+alentre(1,5);
	printf("\nExecutando %i buscas no vetor de %i posicoes...", CONT, MAX);
	for(int i=0;i<CONT;i++)
		{
			if (busca(alentre(v[0],v[MAX-1]),v))
				found++;
			else
				notfound++;    	
		}		
	printf("\nBuscas Realizadas: %i", found+notfound);
	printf("\nEncontradas: %i (%.2f%%)", found, (float)found/(found+notfound)*100);
	printf("\nNao Encontradas: %i (%.2f%%)", notfound, (float)notfound/(found+notfound)*100);
}

int alentre(int a,int b)
{
	return(a+(rand()%(b-a+1)));     
}

bool bb (int x, int e, int d, int v[]) 
{
   if (x < v[e]) return(false);
   else
   if (v[e] == x) return(true);
   else return bb (x, e+1, d, v); 
} 

bool busca (int x, int v[]) 
{
   return (bb(x, 0, MAX, v));
}

