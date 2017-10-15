#include <stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "tree.h"

Tree *empty = NULL;

/* BASE EXERCISE */

int tree_member(int x, Tree *tree) { 
    if(tree==NULL){
        return 0;
    }
    if(x == tree->value)
        return 1;
    if(x < tree->value){
        return tree_member(x,tree->left);
    }
    return tree_member(x,tree->right);
}

Tree *tree_insert(int x, Tree *tree) { 
    if(tree==NULL){
        tree=(Tree*)malloc(sizeof(Tree));
        tree->value=x;
        assert(tree->left==NULL);
        printf("%d\n", tree->value);
        return tree;
    }
    if(x < tree->value){
        tree->left=tree_insert(x,tree->left);
        return tree;
    }
    tree->right=tree_insert(x,tree->right);
    return tree;
}

void tree_free(Tree *tree) { 
    if(tree==NULL)
        return;
    tree_free(tree->left);
    tree_free(tree->right);
    free(tree);
    tree=NULL;
}

/* CHALLENGE EXERCISE */ 

void pop_minimum(Tree *tree, int *min, Tree **new_tree) { 
    *new_tree=tree;
    if(tree->left!=NULL){
        pop_minimum(tree->left,min,&(*new_tree)->left);
        return;
    }
    printf("Val is %d\n",tree->value);
    *min=(tree->value);
    (*new_tree)=tree_remove(*min,tree);
}

Tree *tree_remove(int x, Tree *tree) { 
    if(tree_member(x,tree)==0)
        return tree;
    if(tree->value==x){
        if(tree->left==NULL&&tree->right==NULL){
            free(tree);
            return NULL;
        }
        if(tree->left==NULL){
            tree->value=tree->right->value;
            tree->right=tree_remove(tree->right->value,tree->right);
            return tree;
        }
        tree->value=tree->left->value;
        tree->left=tree_remove(tree->left->value,tree->left);
        return tree;
    }
    if(tree->value<x){
        tree->right=tree_remove(x,tree->right);
    }
    if(tree->value>x){
        tree->left=tree_remove(x,tree->left);
    }
    return tree;
}
