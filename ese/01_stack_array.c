/* 01_stack_array.c
   Menu-driven stack using array
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x){
    if(top == MAX-1){ printf("Stack overflow\n"); return; }
    stack[++top] = x;
}

int pop(){
    if(top == -1){ printf("Stack underflow\n"); return -1; }
    return stack[top--];
}

void peekTop(){
    if(top==-1) printf("Empty\n");
    else printf("Top = %d\n", stack[top]);
}

void display(){
    if(top==-1){ printf("Empty stack\n"); return; }
    printf("Stack: ");
    for(int i=top;i>=0;i--) printf("%d ", stack[i]);
    printf("\n");
}

int main(){
    int choice, x;
    while(1){
        printf("\n--- Stack (Array) Menu ---\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\nChoice: ");
        if(scanf("%d",&choice)!=1) break;
        switch(choice){
            case 1: printf("Enter value: "); scanf("%d",&x); push(x); break;
            case 2: x = pop(); if(x!=-1) printf("Popped %d\n",x); break;
            case 3: peekTop(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
