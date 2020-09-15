#include <stdio.h>
#include <stdbool.h> // necess�rio p/ fun��o declarar bool
#include <string.h>  // necess�rio para strlen()


typedef struct {
	char items[100];
	int top;
} stack;


bool empty(stack *s)
{
	bool aux;
	aux = (s->top == -1) ? true : false;
	return(aux);
}

void push(char e, stack *s)
{
	s->top += 1;
	s->items[s->top] = e;
}

char pop(stack *s)
{
	char e;
	e = s->items[s->top];
	s->top -= 1;
	return(e);
}

char stacktop(stack *s)
{
	char e;
	e = s->items[s->top];
	return(e);
}

int main(void)
{
 char expressao[20];
 stack s1;

 s1.top = -1;
 
 printf("Digite uma expressao: ");
 fflush(stdin);
 scanf("%[^\n]s",&expressao);
 int i;
 for(i=0;i < strlen(expressao); i++)
 {
 	push(expressao[i], &s1);
 }
 printf("\nExpressao ao inverso: ");
 while (!empty(&s1))
 {
 	printf("%c", pop(&s1));
 }
}

