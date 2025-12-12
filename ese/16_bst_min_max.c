/* 16_bst_min_max.c */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int val; struct Node *l,*r; } Node;
Node* root = NULL;
Node* newNode(int v){ Node* n=malloc(sizeof(Node)); n->val=v; n->l=n->r=NULL; return n; }

void insert(Node** r, int v){ if(!*r) {*r=newNode(v); return;} if(v<(*r)->val) insert(&(*r)->l,v); else insert(&(*r)->r,v); }

int findMin(Node* r){ if(!r) return -1; while(r->l) r=r->l; return r->val; }
int findMax(Node* r){ if(!r) return -1; while(r->r) r=r->r; return r->val; }

int main(){
    int ch,x;
    while(1){
        printf("\n1.Insert 2.FindMin 3.FindMax 4.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("Val: "); scanf("%d",&x); insert(&root,x); break;
            case 2: printf("Min: %d\n", findMin(root)); break;
            case 3: printf("Max: %d\n", findMax(root)); break;
            case 4: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
