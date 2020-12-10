#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>


int func(int i)
{
    if(i==0) return(0);
    else if(i==1) return(1);
    else return(pow(func(i-2),2)+func(i-1));
}

int main()
{
    // int num = func(7);
    // printf("\n%i", func(10));

    for(int i =0; i< 10; i++){
        printf("\n%i", func(i));
    }
}