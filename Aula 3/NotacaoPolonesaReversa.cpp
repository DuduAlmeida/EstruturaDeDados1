#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//gcc NotacaoPolonesaReversa.cpp -o executaNotacao
//./executaNotacao

#define LIMITE 100

typedef struct
{
    float items[LIMITE];
    int top;
} stack;

bool isFull(stack *s){
    bool aux;
    aux = (s->top == (LIMITE - 1) ) ? true : false;
    return aux;
}

bool empty(stack *s){
    bool aux;
    aux = (s->top == -1) ? true : false;
    return aux;
}

void push(int e, stack *s){
    s->top += 1;
    s->items[s->top] = e;
}

int pop(stack *s){
    int aux = s->items[s->top];
    s->top-=1;
    
    return aux;
}

int stacktop(stack *s){

    return s->items[s->top];
}

int main(int argc, char *argv[]) {
	
	float aux, aux2;
    stack s1;
    s1.top=-1;

	//34*2/5+1+ == 12	    
	printf("\n\t34*2/5+1+:");
    push(3,&s1);    
    push(4,&s1);    
    aux = pop(&s1) * pop(&s1);
	push(aux,&s1);
	printf("\nElemento : %f", aux);
	push(2,&s1);	
	aux2 = pop(&s1);
	aux = (1/aux2) * pop(&s1);
	push(aux,&s1);
	printf("\nAux : %f", aux2);
	printf("\nElemento : %f", aux);
	push(5,&s1);
	aux = pop(&s1) + pop(&s1);
	push(aux,&s1);
	printf("\nElemento : %f", aux);
	push(1,&s1);
	aux = pop(&s1) + pop(&s1);
    push(aux,&s1);    
    printf("\nResposta : %f", aux);
    
    stack s2;
    s2.top=-1;
    //2+3^2	    
	printf("\n\n\t2+3^2  == 32^2+:");
    push(3,&s1);    
    push(2,&s1);    
    aux2 = pop(&s1);
    aux = pow(pop(&s1),aux2);
	push(aux,&s1);
	printf("\nAux : %f", aux2);
	printf("\nElemento : %f", aux);
	push(2,&s1);		
	aux = pop(&s1) + pop(&s1);
	push(aux,&s1);	
    printf("\nResposta : %f", aux);

    stack s3;
    s3.top=-1;    
	printf("\n\n\t12+35+*  == (1+2)*(3+5):");
    push(1,&s3);    
    push(2,&s3);  
    aux = pop(&s3) + pop(&s3);
    push(aux,&s3);  
    printf("\nElemento : %f", aux);
    push(3,&s3);    
    push(5,&s3);  
    aux = pop(&s3) + pop(&s3);
    printf("\nElemento : %f", aux);
    push(aux,&s3);  
    aux = pop(&s3) * pop(&s3);
    push(aux,&s3);
    printf("\nResposta : %f", aux);  

	
	return 0;
}

