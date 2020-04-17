/*
 * This apparently comes from a Stanford course on how to ace google interview
 * questions:
 * Given the a list of cards (integers) shuffle the list by interleaving value
 * Ie) 1 2 3 4 5 6 7 8 9 10 >> 6 1 7 2 8 3 9 4 10
 */

#include <stdlib.h>
#include <stdio.h>
#include "debug.h"

struct entry* add();
struct entry* initialize_list();

struct entry{
    int value; //Data
    struct entry *next; //Pointer of type struct entry
};

int main(void){
    //Initialize List
    struct entry *head = initialize_list();
    //Determine list length
    struct entry *n = head;
    int listLength=0;
    for(int i=0;n!=NULL;i++){
        n = n->next;
        listLength = i;
    }
    //Set pointer to halfway along list
    n=head;
    for(int i=0;i<listLength/2;i++)
        n = n->next;
    //Insert first half nodes in between second half nodes
    struct entry *firstHalf,*secondHalf, *temp;
    firstHalf = head;
    secondHalf = n;
    head = secondHalf;
    while(secondHalf->next!=NULL){
        temp=secondHalf->next;
        secondHalf->next = firstHalf;
        firstHalf = firstHalf->next;
        secondHalf->next->next=temp;
        secondHalf=temp;
    }
    //Print list
    n = head;
    while(n->next != NULL){
        printf("%i ",n->value);
        n = n->next;
    }
}

struct entry* add(){
    struct entry *p = malloc(sizeof(struct entry));
    p->next = NULL;
    return p;
};
struct entry* initialize_list(){
    struct entry *list_pointer;
    struct entry *n;
    n = list_pointer = add();
    for(int i=1;i<11;i++){
        n->value = i;
        n->next = add();
        n = n->next;
    }
    n = list_pointer;
    return list_pointer;
}

/*
    //Attempted merge code, more error prone, less elegant
    PRINTDB("n->next(1/2):%i ",n->next->value);
    struct entry *secondHalf = n->next;
    PRINTDB("secondHalf(0):%i ",secondHalf->value);
    struct entry *newList = n;
    PRINTDB("newList(0):%i ",newList->value);
    struct entry *firstHalf = head;
    PRINTDB("firstHalf(0):%i \n",firstHalf->value);
    head = newList;
    for(int i=0;i<listLength/2;i++){
        newList->next = firstHalf;
        PRINTDB("newList->Next:%i ",newList->next->value);
        firstHalf = firstHalf->next;
        PRINTDB("firstHalf:%i ",firstHalf->value);
        newList = newList->next;
        PRINTDB("newList:%i ",newList->value);
        newList->next = secondHalf;
        PRINTDB("newList->next:%i ",newList->next->value);
        secondHalf = secondHalf->next;
        PRINTDB("secondHalf:%i ",secondHalf->value);
        newList = newList->next;
        PRINTDB("newList:%i \n",newList->value);
    }
    newList->next = firstHalf;
    PRINTDB("newList->Next:%i ",newList->next->value);
    firstHalf = firstHalf->next;
    PRINTDB("firstHalf:%i ",firstHalf->value);
    n = head;
    PRINTDB("head:%i \n",n->value);
    for(int i=0;i<listLength+1;i++){
        printf("%i",n->value);
        n = n->next;
    }
    printf("\n");
*/