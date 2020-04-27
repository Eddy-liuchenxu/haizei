/*************************************************************************
	> File Name: 1.avl.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月23日 星期四 18时16分20秒
 ************************************************************************/
#include<stdio.h>
#define H(root) (root)->h
#define L(root) (root->lchild)->h
typedef struct Node{
    int key,h;
    struct Node *lchild, *rchild;
}

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL(){
    NIL->key = NIL->h = 0;
    NIL->rchild = NIL->lchild = NIL;
}

Node *getNewNOde(int key){
    NOde *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *maintain(Node *root){
    if(abs())
}

Node *insert(Node *root, int key){
    if(root == NULL) return getNewNOde(key);
    if(root->key == key) return root;
    if(root->key > key) root->lchild = insert(root->lchild,key);
    else root->rchild = insert(root->rchild,key);
    return maintain(root);
}

void clear(Node *root){
    if(root == NULL) return;
}

int main(){

    return 0;
}
