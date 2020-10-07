/* Busca Binária
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int bb (int x, int e, int d, int v[]) 
{
   if (e == d-1) return d;  
   else {
      int m = (e + d)/2;
      if (v[m] < x)  
         return bb (x, m, d, v);
      else  
         return bb (x, e, m, v); 
	}
} 

int buscaBinaria (int x, int n, int v[]) 
{
   return (bb(x, -1, n, v));
}

int main()
{
	int num;
	int a;
	int v[30] = {1, 2, 5, 6, 7, 9, 11, 15, 17, 18, 20, 21, 23, 28, 29, 30, 34, 35, 39, 40, 41, 45, 50, 57, 60, 61, 68, 73, 78, 81};
	for(int i=0;i<30;i++)
		printf("[%i] ",v[i]);
	while(true)
	{
		printf("Procurado? (0=Exit): ");
		scanf("%i",&num);
		if(num==0) exit(1);	
		if(v[buscaBinaria(num,30,v)] == num)
			printf("\nENCONTRADO!");
		else
			printf("\nNAO ENCONTRADO!");
	}		
}
