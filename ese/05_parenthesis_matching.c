/* 05_parenthesis_matching.c
   Check balanced parentheses/brackets using stack
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isMatching(char a, char b){
    return (a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}');
}

int isBalanced(const char *s){
    int n = strlen(s);
    char *st = malloc(n+1); int top=-1;
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c=='('||c=='['||c=='{') st[++top]=c;
        else if(c==')'||c==']'||c=='}'){
            if(top==-1) { free(st); return 0; }
            if(!isMatching(st[top--], c)) { free(st); return 0; }
        }
    }
    int res = (top==-1);
    free(st);
    return res;
}

int main(){
    char s[500];
    while(1){
        printf("\nEnter expression (or \"exit\"): ");
        if(!fgets(s,sizeof(s),stdin)) break;
        s[strcspn(s,"\n")] = 0;
        if(strcmp(s,"exit")==0) break;
        printf("%s -> %s\n", s, isBalanced(s) ? "Balanced" : "Not Balanced");
    }
    return 0;
}
