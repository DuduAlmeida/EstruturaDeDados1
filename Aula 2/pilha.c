#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LIMITE 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct
{
    int items[LIMITE];
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
	
	int aux;
    stack s1;
    s1.top=-1;

    push(3,&s1);
    push(8,&s1);

    if(empty(&s1))
        printf("\nPilha Vazia");
    else
        printf("\nPilha com elementos");

    aux = pop(&s1);
    printf("\nElemento retirado da pilha: %i", aux);
    
	
	return 0;
}

