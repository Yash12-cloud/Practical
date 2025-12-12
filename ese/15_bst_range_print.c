/* 15_bst_range_print.c */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int val; struct Node *l,*r; } Node;
Node* root = NULL;
Node* newNode(int v){ Node* n=malloc(sizeof(Node)); n->val=v; n->l=n->r=NULL; return n; }

void insert(Node** r, int v){
    if(!*r){ *r=newNode(v); return; }
    if(v < (*r)->val) insert(&(*r)->l, v); else insert(&(*r)->r, v);
}

void printRange(Node* r, int low, int high){
    if(!r) return;
    if(r->val > low) printRange(r->l, low, high);
    if(r->val >= low && r->val <= high) printf("%d ", r->val);
    if(r->val < high) printRange(r->r, low, high);
}

int main(){
    int ch,x,a,b;
    while(1){
        printf("\n1.Insert 2.PrintRange 3.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("Val: "); scanf("%d",&x); insert(&root,x); break;
            case 2: printf("Low High: "); scanf("%d %d",&a,&b); printRange(root,a,b); printf("\n"); break;
            case 3: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
