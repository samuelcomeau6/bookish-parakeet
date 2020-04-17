
#include <regex.h>
#include <stdio.h>
#include <math.h>
#include "debug.h"
_Bool isprime(int);
int main(void){
    int size;
    scanf("%i",&size);
    scanf("\n");
    int array[size];
    int primes=0;
    for(int i=0;i<size;i++){
        scanf("%i",&array[i]);
        if(isprime(array[i])) primes++;
        PRINTDB("a[i]=%i ",array[i]);
    }
    printf("%i",primes);

    
    return 0;
}
_Bool isprime(int number){
    if(numer<2) return 0;
    if(number==2) return 1;
    int max = sqrt(number);
    PRINTDB("max=%i",max);
    for(int i=2;i<=max;i++)
        if(number%i==0) return 0;
    return 1;
}