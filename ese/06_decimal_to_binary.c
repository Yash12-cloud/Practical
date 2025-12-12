/* 06_decimal_to_binary.c */
#include <stdio.h>
#include <stdlib.h>

void decToBin(int n){
    if(n==0){ printf("0\n"); return; }
    int st[64], top=-1;
    while(n>0){ st[++top] = n%2; n/=2; }
    while(top!=-1) printf("%d", st[top--]);
    printf("\n");
}

int main(){
    int n;
    while(1){
        printf("\nEnter decimal (-1 to exit): ");
        if(scanf("%d",&n)!=1) break;
        if(n==-1) break;
        decToBin(n);
    }
    return 0;
}
