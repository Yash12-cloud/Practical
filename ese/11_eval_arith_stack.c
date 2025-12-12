/* 11_eval_arith_stack.c
   Evaluate postfix expression (space separated) using stack
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double compute(double a, double b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a,b);
    }
    return 0;
}

double evalPostfix(char *expr){
    double st[500]; int top=-1;
    char *token = strtok(expr, " ");
    while(token){
        if(isdigit(token[0]) || (token[0]=='-' && isdigit(token[1]))){
            st[++top] = atof(token);
        } else {
            if(top < 1){ printf("Invalid expr\n"); return 0; }
            double b = st[top--]; double a = st[top--];
            st[++top] = compute(a,b, token[0]);
        }
        token = strtok(NULL, " ");
    }
    return top==0 ? st[top] : 0;
}

int main(){
    char line[1000];
    printf("Enter postfix (space separated) or 'exit':\n");
    while(1){
        if(!fgets(line,sizeof(line),stdin)) break;
        line[strcspn(line,"\n")]=0;
        if(strcmp(line,"exit")==0) break;
        char copy[1000]; strcpy(copy,line);
        double res = evalPostfix(copy);
        printf("Result: %.6g\n", res);
    }
    return 0;
}
