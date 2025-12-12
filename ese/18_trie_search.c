/* 18_trie_search.c
   Basic lowercase trie with insert/search
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPH 26

typedef struct TrieNode{
    struct TrieNode* children[ALPH];
    int isEnd;
} TrieNode;

TrieNode* getNode(){
    TrieNode* p = malloc(sizeof(TrieNode));
    p->isEnd=0;
    for(int i=0;i<ALPH;i++) p->children[i]=NULL;
    return p;
}

void insert(TrieNode* root, const char* key){
    TrieNode* p = root;
    for(int i=0; key[i]; i++){
        int idx = key[i]-'a';
        if(idx<0 || idx>=ALPH) continue;
        if(!p->children[idx]) p->children[idx]=getNode();
        p=p->children[idx];
    }
    p->isEnd=1;
}

int searchTrie(TrieNode* root, const char* key){
    TrieNode* p=root;
    for(int i=0; key[i]; i++){
        int idx = key[i]-'a';
        if(idx<0||idx>=ALPH) return 0;
        if(!p->children[idx]) return 0;
        p=p->children[idx];
    }
    return p && p->isEnd;
}

int main(){
    TrieNode* root = getNode();
    char s[200];
    int ch;
    while(1){
        printf("\n1.Insert 2.Search 3.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("word: "); scanf("%s",s); insert(root,s); break;
            case 2: printf("word: "); scanf("%s",s); printf("%s\n", searchTrie(root,s) ? "Found" : "Not Found"); break;
            case 3: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
