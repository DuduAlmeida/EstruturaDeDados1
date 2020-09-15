#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void alocaInt(int *p, int tam);

int main(int argc, char *argv[]) {
	
	int *vet = NULL, vetor[100], pos = 0;
	char op;
	
	do{

		fflush(stdin);
		printf("Digite um numero:");		
		fflush(stdin);
		scanf("%i", &vetor[pos]);				
		
		printf("Deseja continuar: ");
		fflush(stdin);
		scanf("%c", &op);		
		
		pos++;
	}while((op == 's' || op == 'S') && pos < 100);
	
	for(int i=0; i< pos; i++){
		printf("\nPosicao %i: %i", i, vetor[i]);
	}
	
	return 0;
}

