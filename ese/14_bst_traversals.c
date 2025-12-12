/* 14_bst_traversals.c
   BST with insert and many traversals/queries
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int val; struct Node* left; struct Node* right; struct Node* parent; } Node;
Node* root = NULL;

Node* newNode(int v, Node* parent){
    Node* n = malloc(sizeof(Node)); n->val=v; n->left=n->right=NULL; n->parent=parent; return n;
}

void insertNode(int v){
    if(!root){ root=newNode(v,NULL); return; }
    Node *p=root;
    while(1){
        if(v < p->val){
            if(p->left) p=p->left; else { p->left = newNode(v,p); break; }
        } else {
            if(p->right) p=p->right; else { p->right = newNode(v,p); break; }
        }
    }
}

void inorder(Node* r){ if(!r) return; inorder(r->left); printf("%d ", r->val); inorder(r->right); }
void preorder(Node* r){ if(!r) return; printf("%d ", r->val); preorder(r->left); preorder(r->right); }
void postorder(Node* r){ if(!r) return; postorder(r->left); postorder(r->right); printf("%d ", r->val); }

void bfs(){
    if(!root){ printf("Empty\n"); return; }
    Node* q[1000]; int f=0,r=0; q[r++]=root;
    while(f<r){ Node *t=q[f++]; printf("%d ", t->val); if(t->left) q[r++]=t->left; if(t->right) q[r++]=t->right; }
    printf("\n");
}

Node* findNode(int v){
    Node* p=root;
    while(p){ if(p->val==v) return p; p = v < p->val ? p->left : p->right; }
    return NULL;
}

void mirror(Node* r){
    if(!r) return;
    Node* tmp = r->left; r->left = r->right; r->right = tmp;
    mirror(r->left); mirror(r->right);
}

void childrenOf(int v){
    Node* p = findNode(v);
    if(!p){ printf("Not found\n"); return; }
    printf("Left: %s, Right: %s\n", p->left ? "Exists" : "NULL", p->right ? "Exists" : "NULL");
}

void parent_gp_uncle(int v){
    Node* p = findNode(v);
    if(!p){ printf("Not found\n"); return; }
    if(p->parent) printf("Parent: %d\n", p->parent->val); else printf("No parent\n");
    if(p->parent && p->parent->parent) printf("Grandparent: %d\n", p->parent->parent->val); else printf("No grandparent\n");
    if(p->parent && p->parent->parent){
        Node* gp = p->parent->parent;
        Node* uncle = (gp->left == p->parent) ? gp->right : gp->left;
        if(uncle) printf("Uncle: %d\n", uncle->val); else printf("No uncle\n");
    } else printf("No uncle\n");
}

void siblingOf(int v){
    Node* p = findNode(v);
    if(!p || !p->parent){ printf("No sibling\n"); return; }
    Node* par = p->parent;
    if(par->left && par->right){
        if(par->left==p) printf("Sibling: %d\n", par->right->val);
        else printf("Sibling: %d\n", par->left->val);
    } else printf("No sibling\n");
}

int main(){
    int ch,x;
    while(1){
        printf("\n1.Insert 2.Inorder 3.Preorder 4.Postorder 5.BFS\n6.Mirror 7.Children 8.Parent/GP/Uncle 9.Sibling 10.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("Val: "); scanf("%d",&x); insertNode(x); break;
            case 2: inorder(root); printf("\n"); break;
            case 3: preorder(root); printf("\n"); break;
            case 4: postorder(root); printf("\n"); break;
            case 5: bfs(); break;
            case 6: mirror(root); break;
            case 7: printf("Node: "); scanf("%d",&x); childrenOf(x); break;
            case 8: printf("Node: "); scanf("%d",&x); parent_gp_uncle(x); break;
            case 9: printf("Node: "); scanf("%d",&x); siblingOf(x); break;
            case 10: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
