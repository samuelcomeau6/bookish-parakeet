#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    char string[81];
    _Bool panagram=1;
    scanf("%80s",string);
    for(unsigned char c=0x41;c<0x5A;c++){
        if(strchr(string,c)==NULL && strchr(string,c+0x20)==NULL)
            panagram=0;
    }
    if(panagram) printf("YES");
    else printf("NO");
    return 0;
}