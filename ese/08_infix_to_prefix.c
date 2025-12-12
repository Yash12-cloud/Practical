/* 08_infix_to_prefix.c
   Convert infix to prefix using reverse + infix-to-postfix trick
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void reverseStr(char *s){
    int i=0,j=strlen(s)-1;
    while(i<j){ char t=s[i]; s[i]=s[j]; s[j]=t; i++; j--; }
}

int isOperand(char c){ return isalnum(c); }
int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/'||c=='%') return 2;
    if(c=='^') return 3;
    return 0;
}

void infixToPostfix(char *in, char *out){
    char st[500]; int top=-1, k=0;
    for(int i=0; in[i]; i++){
        char c=in[i];
        if(isspace(c)) continue;
        if(isOperand(c)) out[k++]=c;
        else if(c=='(') st[++top]=c;
        else if(c==')'){ while(top!=-1 && st[top]!='(') out[k++]=st[top--]; if(top!=-1) top--; }
        else {
            while(top!=-1 && ((prec(st[top])>prec(c)) || (prec(st[top])==prec(c) && c!='^')) && st[top]!='(')
                out[k++]=st[top--];
            st[++top]=c;
        }
    }
    while(top!=-1) out[k++]=st[top--];
    out[k]='\0';
}

void infixToPrefix(char *in, char *out){
    char rev[500], temp[500];
    strcpy(rev, in);
    reverseStr(rev);
    // swap parentheses
    for(int i=0; rev[i]; i++) if(rev[i]=='(') rev[i]=')'; else if(rev[i]==')') rev[i]='(';
    infixToPostfix(rev, temp);
    reverseStr(temp);
    strcpy(out, temp);
}

int main(){
    char inf[500], out[500];
    while(1){
        printf("\nEnter infix (exit to quit): ");
        if(!fgets(inf,sizeof(inf),stdin)) break;
        inf[strcspn(inf,"\n")]=0;
        if(strcmp(inf,"exit")==0) break;
        infixToPrefix(inf,out);
        printf("Prefix: %s\n", out);
    }
    return 0;
}
