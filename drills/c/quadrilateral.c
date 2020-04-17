#include <stdio.h>

//#include "debug.h"

int main(void){
    int cases=0;
    scanf("%i\n",&cases);
    int angles[4]={0,0,0,0};
    for(int i=0;i<cases;i++){
        scanf("%i %i %i %i",&angles[0],&angles[1],&angles[2],&angles[3]);
        getchar();
        if(angles[0]+angles[1]+angles[2]+angles[3]==360) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}