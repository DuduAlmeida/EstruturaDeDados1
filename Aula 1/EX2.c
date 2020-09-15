#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void alocaInt(int *p, int tam);

int main(int argc, char *argv[]) {
	
	int copy[100], vetor[100], pos = 0, j=0;
	char op;
	
	do{

		printf("Digite um numero:");		
		fflush(stdin);
		scanf("%i", &vetor[pos]);						        

		printf("Deseja continuar <S/N>: ");
		fflush(stdin);
		scanf("%c", &op);		
		
		pos++;
	}while((op == 's' || op == 'S') && pos < 100);
	
    for(int i=pos -1; i >= 0; i--, j++){
		copy[j] = vetor[i];
        printf("\nPosicao %i: %i  -> %i", j, vetor[j], copy[j]);
	}

	return 0;
}

