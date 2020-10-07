// na busca binaria pode ser assim
// int buscabin(x,e,d,v)
// retorna o índice buscado
// x é o numero procurado
// e é o índice à esquerda
// d è o índice à direita
// e v é o vetor todo
// na busca binaria o vetor é sempre repassado recursivamente para as próximas chamadas
// o que muda são os índices para considerar somente uma faixa para fazer a busca

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX 10

int buscabin(int x, int e, int d, int v[MAX]);

int main()
{
    int vet[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int valor = 11;

    printf("\n\nPos. do valor [%i]: %i\n", valor, buscabin(valor, 0, MAX - 1, vet));
}

int buscabin(int x, int e, int d, int v[MAX])
{
    int posMed = (int)(e + d) / 2;
    int posEsq = 0, posDir = 0;

    printf("\nposMed [%i]: %i", v[posMed], posMed);
    if (v[posMed] == x)
    {
        return posMed;
    }
    else if(posMed == MAX -1 || posMed == 0)
        return 0;
    else if (v[posMed] > x)
    {

        posEsq = buscabin(x, e, posMed, v);
        printf("\nposEsq [%i]: %i", v[posEsq], posEsq);
        if (v[posEsq] == x)
            return posEsq;
    }
    else
    {
        posDir = buscabin(x, posMed, d, v);
        printf("\nposDir [%i]: %i", v[posDir], posDir);
        if (v[posDir] == x)
            return posDir;
    }
        
}
