#include <stdio.h>
#include <stdlib.h>

#include "debug.h"

struct entry{
    int value; //Data
    struct entry *next; //Pointer of type struct entry
    struct entry *prev;
};
struct entry* add(struct entry*);
struct entry* add(struct entry* last){
    struct entry *p = malloc(sizeof(struct entry));
    p->next = NULL;
    p->prev = last;
    return p;
};
struct entry *head;
struct entry *tail;
struct entry *n;
int main(void){
    n = head = add(n);
    n->value=0;
    while(n->value!=-1){
        n->next = add(n);
        n = n->next;
        scanf("%i",&(n->value));
        PRINTDB("%i ",n->value);
    };
    tail = n;
    while(n->prev->prev!=NULL){
        n=n->prev;
        printf("%i ",n->value);
    }
}
