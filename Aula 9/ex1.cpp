#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

int cd(int n)
{
	if(n < 10) return(1);
	else
	{
		return(1+cd(n/10));
	}
}

float inverteNum_i( float num){    
    int i = 10, cont=0, resto;
    float numAux = 0, j =1;

    cont = cd(num);


    while (fmod(num , i) >= 1)
    {
        j = cont -1;
        resto = fmod(num , i);
        num /= i;
        // printf("\nresto[%f]: %i ", j, resto);
        numAux += resto*pow(10, j);        

        // printf("\t[i:%i j:%f]:%f-%i-[%f]", i, j, num, resto,numAux);
        cont--;
    }

    return numAux;
    
}

int inverteNum(int n){
    if (n < 10) return n;
    else{
        char aux[] = " ";
        sprintf(aux, "%i", n);
        int siz = strlen(aux);
        return ( (n%10) * pow(10,siz-1) + inverteNum(n/10) ); //Caso simples = caso complexo
    }
}

int main()
{
	printf("\n Somatorio (funcao iterativa): %f", inverteNum_i(432198765));
}
