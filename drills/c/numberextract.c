#include <stdio.h>

int main(void){
    char c;

    while((c = getchar())!='\n');
    while((c = getchar())!=EOF){
        switch(c){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                printf("%c",c);
                printf("%c",' ');
                break;
            default:
                break;
       }
   }
    return 0;
}