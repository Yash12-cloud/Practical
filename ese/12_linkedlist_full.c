/* 12_linkedlist_full.c
   Single linked list with many operations (menu-driven)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node* next; } Node;
Node* head = NULL;

void insertEnd(int x){
    Node *n = malloc(sizeof(Node)); n->data=x; n->next=NULL;
    if(!head) head=n; else { Node *p=head; while(p->next) p=p->next; p->next=n; }
}

void insertPos(int x, int pos){
    Node *n = malloc(sizeof(Node)); n->data=x;
    if(pos<=1 || !head){ n->next=head; head=n; return; }
    Node *p=head;
    for(int i=1;i<pos-1 && p->next;i++) p=p->next;
    n->next = p->next; p->next = n;
}

void deletePos(int pos){
    if(!head){ printf("Empty\n"); return; }
    if(pos<=1){ Node *t=head; head=head->next; free(t); return; }
    Node *p=head;
    for(int i=1;i<pos-1 && p;i++) p=p->next;
    if(!p || !p->next){ printf("Position invalid\n"); return; }
    Node *t=p->next; p->next = t->next; free(t);
}

void reverseList(){
    Node *prev=NULL, *curr=head, *next;
    while(curr){ next=curr->next; curr->next=prev; prev=curr; curr=next; }
    head = prev;
}

Node* mergeSorted(Node* a, Node* b){
    if(!a) return b; if(!b) return a;
    if(a->data < b->data){ a->next = mergeSorted(a->next,b); return a; }
    else { b->next = mergeSorted(a,b->next); return b; }
}

Node* splitCopy(){
    // return new list with sorted order? For simplicity, return copy
    Node *p=head, *newh=NULL, *tail=NULL;
    while(p){
        Node *n=malloc(sizeof(Node)); n->data=p->data; n->next=NULL;
        if(!newh) newh=tail=n; else { tail->next=n; tail=n; }
        p=p->next;
    }
    return newh;
}

void findMiddle(){
    if(!head){ printf("Empty\n"); return; }
    Node *slow=head,*fast=head;
    while(fast && fast->next){ slow=slow->next; fast=fast->next->next; }
    printf("Middle: %d\n", slow->data);
}

int detectLoop(){
    Node *slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next; fast=fast->next->next;
        if(slow==fast) return 1;
    }
    return 0;
}

int sumList(){
    int s=0; Node *p=head; while(p){ s+=p->data; p=p->next; } return s;
}

void printOddEven(){
    Node *p=head;
    printf("Odd nodes: ");
    while(p){ if(p->data%2) printf("%d ",p->data); p=p->next; }
    p=head;
    printf("\nEven nodes: ");
    while(p){ if(p->data%2==0) printf("%d ",p->data); p=p->next; }
    printf("\n");
}

void display(){
    Node *p=head; printf("List: ");
    while(p){ printf("%d ", p->data); p=p->next; } printf("\n");
}

int main(){
    int ch,x,pos;
    while(1){
        printf("\n1.InsertEnd 2.InsertPos 3.DeletePos 4.Reverse 5.Merge(copy demo) 6.FindMiddle\n7.DetectLoop 8.Sum 9.PrintOddEven 10.Display 11.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("Val: "); scanf("%d",&x); insertEnd(x); break;
            case 2: printf("Val Pos: "); scanf("%d %d",&x,&pos); insertPos(x,pos); break;
            case 3: printf("Pos: "); scanf("%d",&pos); deletePos(pos); break;
            case 4: reverseList(); break;
            case 5: {
                Node *copy = splitCopy();
                printf("Merged (original+copy) using mergeSorted demo - both lists appended and merged if sorted\n");
                Node *merged = mergeSorted(head, copy);
                // display merged
                Node *p=merged; printf("Merged: "); while(p){ printf("%d ",p->data); p=p->next;} printf("\n");
                // free merged (not freeing nodes for simplicity)
                break;
            }
            case 6: findMiddle(); break;
            case 7: printf("%s\n", detectLoop() ? "Loop exists" : "No loop"); break;
            case 8: printf("Sum = %d\n", sumList()); break;
            case 9: printOddEven(); break;
            case 10: display(); break;
            case 11: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
