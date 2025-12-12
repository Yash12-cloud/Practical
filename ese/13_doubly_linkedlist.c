/* 13_doubly_linkedlist.c
   Doubly linked list minimal operations
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node *prev, *next; } Node;
Node *head = NULL;

void insertEnd(int x){
    Node *n = malloc(sizeof(Node)); n->data=x; n->next=NULL; n->prev=NULL;
    if(!head) head=n;
    else{
        Node *p=head;
        while(p->next) p=p->next;
        p->next=n; n->prev=p;
    }
}

void deletePos(int pos){
    if(!head) { printf("Empty\n"); return; }
    Node *p=head; int i=1;
    if(pos==1){
        head = head->next; if(head) head->prev=NULL; free(p); return;
    }
    while(p && i<pos){ p=p->next; i++; }
    if(!p){ printf("Invalid\n"); return; }
    if(p->next) p->next->prev = p->prev;
    if(p->prev) p->prev->next = p->next;
    free(p);
}

void display(){
    printf("Forward: ");
    for(Node *p=head;p;p=p->next) printf("%d ", p->data);
    printf("\nBackward: ");
    if(!head){ printf("Empty\n"); return; }
    Node *p=head; while(p->next) p=p->next;
    while(p){ printf("%d ", p->data); p=p->prev; }
    printf("\n");
}

int main(){
    int ch,x,pos;
    while(1){
        printf("\n1.InsertEnd 2.DeletePos 3.Display 4.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("Val: "); scanf("%d",&x); insertEnd(x); break;
            case 2: printf("Pos: "); scanf("%d",&pos); deletePos(pos); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
