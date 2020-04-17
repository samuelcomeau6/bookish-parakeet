#include  <stdio.h>
#include <math.h>
#include <stdlib.h>
//Compiler version gcc  6.3.0

int main()
{
    int a,b,c;
    scanf("%1d%1d%1d",&a,&b,&c);
    int d = a*100+b*10+c;
    if(pow(a,3)+pow(b,3)+pow(c,3)==d) printf("YES");
    else printf("NO");
    return 0;
}