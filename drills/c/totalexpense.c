#include <stdio.h>

#include "debug.h"

int main(void){
    int cases=0;
    scanf("%i\n",&cases);
    int cost=0;
    for(int i=0;i<cases;i++){
        scanf("%i",&cost);
        getchar();
        int final = cost*100 - cost*100*10/100;
        if(cost>1000) printf("%.2f\n",(float) final/100);
        else printf("%i.00\n",cost);
    }

    return 0;
}