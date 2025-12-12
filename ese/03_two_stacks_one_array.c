/* 03_two_stacks_one_array.c
   Two stacks sharing a single array
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int x){ if(top1+1 == top2){ printf("Overflow\n"); return; } arr[++top1] = x; }
void push2(int x){ if(top1+1 == top2){ printf("Overflow\n"); return; } arr[--top2] = x; }
int pop1(){ if(top1==-1){ printf("Underflow\n"); return -1; } return arr[top1--]; }
int pop2(){ if(top2==MAX){ printf("Underflow\n"); return -1; } return arr[top2++]; }

void display(){
    printf("Stack1: "); for(int i=top1;i>=0;i--) printf("%d ",arr[i]); printf("\n");
    printf("Stack2: "); for(int i=top2;i<MAX;i++) printf("%d ",arr[i]); printf("\n");
}

int main(){
    int ch, x;
    while(1){
        printf("\n1.Push1 2.Pop1 3.Push2 4.Pop2 5.Display 6.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("Val: "); scanf("%d",&x); push1(x); break;
            case 2: x=pop1(); if(x!=-1) printf("Popped %d\n",x); break;
            case 3: printf("Val: "); scanf("%d",&x); push2(x); break;
            case 4: x=pop2(); if(x!=-1) printf("Popped %d\n",x); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
