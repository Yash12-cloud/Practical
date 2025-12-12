/* 10_queue_linkedlist.c */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int data; struct Node* next; } Node;
Node *front = NULL, *rear = NULL;

void enqueue(int x){
    Node *n = malloc(sizeof(Node)); n->data=x; n->next=NULL;
    if(!rear){ front = rear = n; }
    else { rear->next = n; rear = n; }
}

int dequeue(){
    if(!front){ printf("Empty\n"); return -1; }
    Node *t = front; int v = t->data; front = front->next; if(!front) rear=NULL; free(t); return v;
}

void display(){
    Node *p = front; printf("Queue: ");
    while(p){ printf("%d ", p->data); p=p->next; } printf("\n");
}

int main(){
    int ch,x;
    while(1){
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("Val: "); scanf("%d",&x); enqueue(x); break;
            case 2: x=dequeue(); if(x!=-1) printf("Dequeued %d\n",x); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
