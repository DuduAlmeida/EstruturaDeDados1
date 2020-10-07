#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int somatorioImpar_i(int i){

    int j =1, impar = 1;
    while (j<i){
        printf("\nZimpar#%i [%i]: %i",i,j, impar );
        impar+=2;
        j++;
    }
    return impar;
}

int somatorioImpar_r(int i, int max, int impar){
    printf("\nZimpar#%i [%i]: %i",max,i, impar );    
    if(i < max-1)
        return (somatorioImpar_r(i+1, max,  impar + 2));
    else
        return impar + 2;    
}

int somatorioImpar(int i){
    return 2*i - 1;
}

int produtorioImpar(int i){    
    if(i==1)
        return 1;
    else{             
        // int impar = somatorioImpar_r(1, i,  1);
        int impar = somatorioImpar(i);
        printf("\nImpar [%i]: %i\n",i, impar );
        return ( impar * produtorioImpar(i-1));
    }
}

int main()
{
	printf("\n Produtorio (funcao recursiva): %i", produtorioImpar(5));    
}
