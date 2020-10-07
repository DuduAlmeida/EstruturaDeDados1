/* Escreva uma função recursiva em linguagem C que calcule  a multiplicação 
dos N primeiros termos inteiros ímpares. Por exemplo, mult(5)=1*3*5*7*9=945.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char *rev(char *i)
{
	char aux[] = " ";
	char c[] = " ";
	char res[] = " ";
	if(strlen(i) == 1)
		return(i);
	else
	{
		strncpy(c,i,1);
		strncpy(aux, i+1,strlen(i)-1);
		strcat(res,rev(aux));
		strcat(res,c);
		printf("%s",aux);exit(1);
		return(res);	
	}
}


int main()
{
	char i[] = "ROMA";
	printf("\nReverso de %s e' %s",i,rev(i));
}

