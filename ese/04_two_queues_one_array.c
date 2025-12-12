/* 04_two_queues_one_array.c
   Two queues in single array: simple partition method
   (Left half queue1, right half queue2). Simpler approach.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int mid = MAX/2;
int q1[MAX], f1=-1,r1=-1, q2[MAX], f2=-1,r2=-1;

void enqueue1(int x){
    if(r1 == mid-1) { printf("Q1 full\n"); return; }
    if(f1==-1) f1=0;
    q1[++r1]=x;
}
int dequeue1(){
    if(f1==-1 || f1>r1){ printf("Q1 empty\n"); return -1; }
    return q1[f1++];
}
void enqueue2(int x){
    if(r2 == MAX-1){ printf("Q2 full\n"); return; }
    if(f2==-1) f2=mid;
    q2[++r2]=x;
}
int dequeue2(){
    if(f2==-1 || f2>r2){ printf("Q2 empty\n"); return -1; }
    return q2[f2++];
}

void disp(){
    printf("Q1: ");
    if(f1==-1) printf("empty");
    else for(int i=f1;i<=r1;i++) printf("%d ",q1[i]);
    printf("\nQ2: ");
    if(f2==-1) printf("empty");
    else for(int i=f2;i<=r2;i++) printf("%d ",q2[i]);
    printf("\n");
}

int main(){
    int ch,x;
    while(1){
        printf("\n1.Enq1 2.Deq1 3.Enq2 4.Deq2 5.Display 6.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("Val: "); scanf("%d",&x); enqueue1(x); break;
            case 2: x=dequeue1(); if(x!=-1) printf("Dequeued %d\n",x); break;
            case 3: printf("Val: "); scanf("%d",&x); enqueue2(x); break;
            case 4: x=dequeue2(); if(x!=-1) printf("Dequeued %d\n",x); break;
            case 5: disp(); break;
            case 6: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
