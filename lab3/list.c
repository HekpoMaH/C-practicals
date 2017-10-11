#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *cons(int head, List *tail) { 
  /* malloc() will be explained in the next lecture! */
  List *cell = malloc(sizeof(List));
  cell->head = head;
  cell->tail = tail;
  return cell;
}

/* Functions for you to implement */

int sum(List *list) {
    int ans=0;
    while(list!=NULL){
        ans+=list->head;
        list=list->tail;
    }
    return ans;
}

void iterate(int (*f)(int), List *list) {
    while(list!=NULL){
        list->head=f(list->head);
        list=list->tail;
    }
}

void print_list(List *list) { 
    printf("[");
    while(list!=NULL){
        printf("%d",list->head);
        if(list->tail!=NULL)
            printf(",");
        list=list->tail;
    }
    printf("]\n");
}

/**** CHALLENGE PROBLEMS ****/

List *merge(List *list1, List *list2) { 
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    List *result=NULL;
    if(list1->head <= list2->head){
        result=list1;
        result->tail=merge(list1->tail,list2);
    }
    else{
        result=list2;
        result->tail=merge(list1,list2->tail);
    }
    return result;  
}

void split(List *list, List **list1, List **list2) { 
    if(list==NULL)
        return;
    if(list->tail==NULL){
        (*list1)=list;
        return;
    }
    List *start;
    List *start2;
    List *prev;
    start=list;
    start2=list;
    while(start2!=NULL&&start2->tail!=NULL){
        prev=start;
        start=start->tail;

        start2=start2->tail;
        if(start2!=NULL)
            start2=start2->tail;
    }
    (*list1)=list;
    (*list2)=start;
    prev->tail=NULL;
}

/* You get the mergesort implementation for free. But it won't
   work unless you implement merge() and split() first! */

List *mergesort(List *list) { 
  if (list == NULL || list->tail == NULL) { 
    return list;
  } else { 
    List *list1;
    List *list2;
    split(list, &list1, &list2);
    list1 = mergesort(list1);
    list2 = mergesort(list2);
    return merge(list1, list2);
  }
}
