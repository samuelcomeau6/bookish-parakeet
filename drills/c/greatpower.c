#include <stdio.h>
void printResult(int, int, int);
int main(void){
    int cases;
    int x, y, z;
    scanf("%i",&cases);
    for(int i=0;i<cases;++i){
        scanf("%i %i %i",&x,&y,&z);
        printResult(x,y,z);
    }
    return 0;
}
void printResult(int x, int y, int z){
    int result=1;
    for(int i=0;i<y;++i){
        result*=x;
        result=result%z;
    }
    printf("%i",result);
}