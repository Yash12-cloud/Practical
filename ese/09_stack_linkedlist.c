/* 09_stack_linkedlist.c */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int x){
    Node *n = malloc(sizeof(Node));
    n->data = x; n->next = top; top = n;
}

int pop(){
    if(!top){ printf("Empty\n"); return -1; }
    Node *t = top; int v = t->data; top = top->next; free(t); return v;
}

void display(){
    Node *p = top;
    printf("Stack: ");
    while(p){ printf("%d ", p->data); p=p->next; }
    printf("\n");
}

int main(){
    int ch,x;
    while(1){
        printf("\n1.Push 2.Pop 3.Display 4.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("Val: "); scanf("%d",&x); push(x); break;
            case 2: x=pop(); if(x!=-1) printf("Popped %d\n",x); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
