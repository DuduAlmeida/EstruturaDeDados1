#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define LIMITE 100

typedef struct
{
    float items[LIMITE];
    int top;
} stack;

void push(float e, stack *s){
    s->top += 1;
    s->items[s->top] = e;
}

float pop(stack *s){
    float aux = s->items[s->top];
    s->top-=1;
    
    return aux;
}

bool empty(stack *s){
    bool aux;
    aux = (s->top == -1) ? true : false;
    return aux;
}


// void alocaInt(int* p, int tam){
// 	if( (p = (int*) realloc(p, tam*sizeof(int))) == NULL){
// 		printf("\n\nDeu erro na alocacao do tipo int\n\n");
// 		exit(1);
// 	}
// }

bool verificarOperador(char item){
    return(item == '/' || item == '+' || item == '-' || item == '*' || item == '^');
}

void showStack(stack s){
    printf("\nPilha:");
    for(int i=0;i< s.top; i++){
        printf("\t[%i]:%i",i,s.items[i]);
    }
}

float calculaNotacaoPolonesa(char posfix[]){
    stack pilha;
        pilha.top = -1;
    int tam = strlen(posfix),
        i=0, j=0;
    float valor = 0.0, 
        a, b;
    bool sn_operador = false;

    //"72^28^-9+3-"

    printf("\ntam -> %i", tam);
    while (i< tam )
    {
        sn_operador = verificarOperador(posfix[i]);
        
        if(sn_operador == true){

            b = pop(&pilha);
            a = pop(&pilha);            
            if(posfix[i] == '+'){

                valor =  a + b;
            }else if(posfix[i] == '-'){
                
                valor = a - b;
            }else if(posfix[i] == '*'){
                
                valor = a * b;
            }else if(posfix[i] == '/'){
                
                valor = a / b;
            }else if(posfix[i] == '^'){
                
                valor = pow(a,b);
            }            
        }else{
            // converter char para float:
            valor = (float) posfix[i] - '0';
        }

        // printf("\n\nsnOperador -> %d\t i %i", sn_operador, i);
        printf("\nNumero Colocado -> %.2f\t\t\ttop %i", valor, pilha.top);
        
        push(valor,&pilha);        
        
        i++;        
    }
    

    return valor;
}

int main(int argc, char *argv[]) {
	
	float valor;
    char posfix[] = "72^28^-9+3-";

    // int *i = NULL;
    // alocaInt(&i, 2);
    // i[0] =2;
    // i[1] = 3;    
    // printf("\n %i %i", i[0], i[1]);

    valor = calculaNotacaoPolonesa(posfix);
    
    printf("\nExpressao notacao polonesa reversa: %s", posfix);
    printf("\nValor resultado: %.2f", valor);
	
	return 0;
}

