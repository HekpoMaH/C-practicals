#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

Node *empty = NULL;

Node *node(int value, Node *left, Node *right) { 
  Node *r = malloc(sizeof(Node));
  r->marked = false;
  r->value = value;
  r->left = left;
  r->right = right;
  return r;
}


/* Basic Problems */

int size(Node *node) { 
    if(node==NULL){
        return 0;
    }
    if(node->marked==true){
        return 0;
    }
    node->marked=true;
    return 1+size(node->left)+size(node->right);
}


void unmark(Node *node) { 
    if(node==NULL){
        return;
    }
    if(node->marked==false){
        return;
    }
    node->marked=false;
    unmark(node->left),unmark(node->right);
}

bool path_from(Node *node1, Node *node2) {
    if(node1==NULL){
        return 0;
    }
    if(node2==NULL){
        return 0;
    }
    unmark(node1);
    size(node1);
    if(node2->marked==true)
        return true;
    return false;
}

bool chck_cycle(Node *node, Node *starting){
    if(node==NULL){
        return false;
    }
    if(node->marked==true)
        return false;
    if(node->left==starting||node->right==starting)
        return true;
    node->marked=true;
    return chck_cycle(node->left,starting)|chck_cycle(node->right,starting);
}
bool cyclic(Node *node) { 
    if(node==NULL)
        return false;
    unmark(node);
    return chck_cycle(node,node);
} 


/* Challenge problems */

void get_nodes(Node *node, Node **dest) { 
    if(node==NULL)
        return;
    if(node->marked)
        return;
    (*dest)=node;
    node->marked=true;
    dest++;
    get_nodes(node->left,dest);
    get_nodes(node->right,dest);

}

void graph_free(Node *node) { 
    unmark(node);
    int sz=size(node);
    unmark(node);
    Node *arr[sz+1];
    get_nodes(node,arr);
    for(int i=0;i<sz;i++){
        free(arr[i]);
    }
}


