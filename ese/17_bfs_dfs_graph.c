/* 17_bfs_dfs_graph.c
   Undirected graph BFS and DFS using adjacency list
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXV 100

typedef struct Node{ int v; struct Node* next; } Node;
Node* adj[MAXV];
int n = 0;

void addEdge(int u,int v){
    Node* t = malloc(sizeof(Node)); t->v=v; t->next=adj[u]; adj[u]=t;
    t = malloc(sizeof(Node)); t->v=u; t->next=adj[v]; adj[v]=t;
}

void bfs(int s){
    int vis[MAXV]={0}, q[MAXV], f=0,r=0;
    q[r++]=s; vis[s]=1;
    while(f<r){
        int u=q[f++]; printf("%d ", u);
        for(Node* p=adj[u]; p; p=p->next) if(!vis[p->v]){ vis[p->v]=1; q[r++]=p->v; }
    }
    printf("\n");
}

void dfsUtil(int u, int vis[]){
    vis[u]=1; printf("%d ", u);
    for(Node* p=adj[u]; p; p=p->next) if(!vis[p->v]) dfsUtil(p->v, vis);
}

void dfs(int s){
    int vis[MAXV]={0}; dfsUtil(s, vis); printf("\n");
}

int main(){
    int ch,u,v;
    for(int i=0;i<MAXV;i++) adj[i]=NULL;
    printf("Enter number of vertices (<=%d): ", MAXV); scanf("%d",&n);
    while(1){
        printf("\n1.AddEdge 2.BFS 3.DFS 4.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("u v: "); scanf("%d %d",&u,&v); addEdge(u,v); break;
            case 2: printf("Start: "); scanf("%d",&u); bfs(u); break;
            case 3: printf("Start: "); scanf("%d",&u); dfs(u); break;
            case 4: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
