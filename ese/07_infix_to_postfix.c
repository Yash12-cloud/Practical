/* 07_infix_to_postfix.c */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 500

int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/'||c=='%') return 2;
    if(c=='^') return 3;
    return 0;
}

void infixToPostfix(char *in, char *out){
    char st[MAX]; int top=-1; int k=0;
    for(int i=0; in[i]; i++){
        char c=in[i];
        if(isspace(c)) continue;
        if(isalnum(c)) out[k++]=c;
        else if(c=='(') st[++top]=c;
        else if(c==')'){
            while(top!=-1 && st[top]!='(') out[k++]=st[top--];
            if(top!=-1) top--; // pop '('
        } else {
            while(top!=-1 && ((prec(st[top])>prec(c)) || (prec(st[top])==prec(c) && c!='^')) && st[top]!='(')
                out[k++]=st[top--];
            st[++top]=c;
        }
    }
    while(top!=-1) out[k++]=st[top--];
    out[k]='\0';
}

int main(){
    char inf[500], out[500];
    getchar();
    while(1){
        printf("\nEnter infix (or type exit): ");
        if(!fgets(inf,sizeof(inf),stdin)) break;
        inf[strcspn(inf,"\n")]=0;
        if(strcmp(inf,"exit")==0) break;
        infixToPostfix(inf,out);
        printf("Postfix: %s\n", out);
    }
    return 0;
}
