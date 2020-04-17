#include  <stdio.h>

//Compiler version gcc  6.3.0

int main()
{
    int maxW, val1, weight1, val2, weight2;
    scanf("%i\n",&maxW);
    scanf("%i %i\n",&val1,&weight1);
    scanf("%i %i",&val2, &weight2);
    int total=0;
    if(weight1+weight2<=maxW) total=val1+val2;
    else if(val1>=val2&&weight1<=maxW) total=val1;
    else if(weight2<=maxW) total=val2;
    else if(weight1<=maxW) total=val1;
    else total=0;
    printf("%i\n",total);
    
    return 0;
}