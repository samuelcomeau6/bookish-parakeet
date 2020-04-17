#ifdef DEBUG
    #define PRINTDB(...) printf(__VA_ARGS__)
#else
    #define PRINTDB(...)
#endif
#include <stdio.h>
#include <string.h>

int main(void){
    unsigned char c,d=' ';
    int cases;
    int a,b;
    PRINTDB("Start");
    
    scanf("%i",&cases);
    PRINTDB("%i",cases);
    while((c=getchar())!='\n');
    for(int i=0;i<cases;i++){
        a =getchar();
        while((c=getchar())>0x29&&c<0x3A)
            d=c;
        b=d;
        PRINTDB("a=0x%x b=0x%x\n",a,b);
        a-=0x30;
        b-=0x30;
        printf("%i\n",a+b);
    }
}