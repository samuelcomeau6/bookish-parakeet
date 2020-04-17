#include  <stdio.h>

//Compiler version gcc  6.3.0

int main(void)
{
    int cases=0;
    int M,N;
    scanf("%i\n",&cases);
    for(int i=0;i<cases;i++){
        scanf("%i %i",&N,&M);
        if(M%N==0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}