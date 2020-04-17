#include <stdio.h>
#include <float.h>
#include "../lib/debug.h"
float calcAverage(int[],int,int);
int main(void){
    int cases;
    scanf("%i",&cases);
    for(int i=0;i<cases;++i){
        int len=0;
        scanf("%i",&len);
        --len;
        if(len==0) {
            printf("NO\n");
        }
        else {
            int array[len];
            for(int j=0;j<=len;++j){
                scanf("%i",&array[j]);
            }
            float minResult=FLT_MAX;
            for(int j=0;j<len;++j){
                float firstAvg = calcAverage(array,0,j);
                float secondAvg = calcAverage(array,j+1,len);
                float result = secondAvg-firstAvg;
                if(result<0)
                    result = -result;
                if(result<minResult)
                    minResult=result;
                PRINTDB("1:%.2f 2:%.2f r:%.2f\n"
                       ,firstAvg,secondAvg,result);
            }
            printf("%.2f\n",minResult);

        }
    }
}
float calcAverage(int array[], int start, int stop){
    int range = stop-start+1;
    PRINTDB("range:%i start:%i stop:%i\n",range,start,stop);
    float result=0;
    if(range<0)
        return 0;
    for(int i=start;i<=stop;++i){
        result += array[i];
        PRINTDB("%.2f ",result);
    }
    PRINTDB("\n");
    result = result / range;
    return result;
}