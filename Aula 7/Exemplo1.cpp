#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>


struct no {
   int info;
   struct no *prox;   
};

int main(){
    int x, y, *p, **q;
    x = 10;
    y = 5;
    p = &x;
    q = &p;
    printf("\n %i", x);
    printf("\n %i", *p);
    *q = &y;
    printf("\n %i", *p);
    
    return 0;
}