#include <stdio.h>
#define MAX 5

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data){
    stack1[++top1] = data;
}

int pop1(){
    return stack1[top1--];
}

void push2(int data){
    stack2[++top2] = data;
}

int pop2(){
    return stack2[top2--];
}

void enqueue(int x){
    push1(x);
    count++;
    printf("%d inserted into queue.\n", x);
}

void dequeue(){

    if (top1 == -1 && top2 == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        push2(pop1());
    }
    printf("%d dequeued from queue.\n", pop2());
    count--;
    for (int i = 0; i < count; i++)
    {
        push1(pop2());
    }
}

void display(){
    if (top1 == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = 0; i <= top1; i++)
        printf("%d ", stack1[i]);
    printf("\n");
}

int main(){
    int choice, value;
    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");

            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Choice!\n");
        }
    }
}