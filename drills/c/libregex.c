#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
char * match(char *,char *);

int main(int argc,char *argv[]){
    char *substring =match("tacos are great","(are)");
    if(substring!=NULL) printf("%s\n",substring);
    return 0;
}
char * match(char *string,char *pattern){
    regex_t compPattern;    //Define the compare pattern
    size_t nmatch=1;        //set the number of parenthetical matches
    regcomp(&compPattern,pattern,nmatch);   //Compile the expression

    regmatch_t matchptr;  //Allocate memory for matchptr
    int result = regexec(&compPattern,string,
                         nmatch,&matchptr,0); //Search string for pattern

    int matchdiff=matchptr.rm_eo-matchptr.rm_so;
    char *returnstring=malloc(sizeof(char)*(matchdiff+1));

    if(result) fprintf(stderr,"\x1b[31;1mNo Match Found\n\x1b[0m"); //regexec return 0 if no match
    else if(nmatch) {
        PRINTDB("matchptr.rm_so-eo= %d - %d, nmatch=%li\n",
                 matchptr.rm_so,matchptr.rm_eo,nmatch);
        //Define the distance to travel
        for(int i=0;i<matchdiff;i++)  //Iterate over string to obtain substring
            returnstring[i]=string[i+matchptr.rm_so];
        returnstring[matchdiff]='\0';
    }
    PRINTDB("Program Exited Normally\n");
    if(!result) return returnstring;
    else return NULL;
}