/* 02_queue_array.c
   Circular queue array menu-driven
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int q[MAX], front = -1, rear = -1;

int isEmpty(){ return front == -1; }
int isFull(){ return (rear+1)%MAX == front; }

void enqueue(int x){
    if(isFull()){ printf("Queue full\n"); return; }
    if(isEmpty()){ front = rear = 0; q[rear]=x; }
    else { rear = (rear+1)%MAX; q[rear]=x; }
}

int dequeue(){
    if(isEmpty()){ printf("Queue empty\n"); return -1; }
    int val = q[front];
    if(front == rear) front = rear = -1;
    else front = (front+1)%MAX;
    return val;
}

void display(){
    if(isEmpty()){ printf("Empty\n"); return; }
    printf("Queue: ");
    int i=front;
    while(1){
        printf("%d ", q[i]);
        if(i==rear) break;
        i=(i+1)%MAX;
    }
    printf("\n");
}

int main(){
    int choice,x;
    while(1){
        printf("\n--- Queue (Array) Menu ---\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        if(scanf("%d",&choice)!=1) break;
        switch(choice){
            case 1: printf("Value: "); scanf("%d",&x); enqueue(x); break;
            case 2: x = dequeue(); if(x!=-1) printf("Dequeued %d\n",x); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
