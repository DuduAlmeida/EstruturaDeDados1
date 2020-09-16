#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int alentre(int a,int b)
{
	return(a+(rand()%(b-a+1)));
}

int main(void)
{
  int i;
  
  printf("Gerando 10 valores aleatorios:\n\n");
  
  for (i = 0; i < 20; i++)
  {
    /* gerando valores aleatórios entre zero e 100 */
    printf("%d ", alentre(3,8));
  }
  
  return 0;
}

