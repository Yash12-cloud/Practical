/* 19_biconnected_graph.c
   Check if undirected graph is biconnected (no articulation point)
   Uses DFS low/time arrays
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXV 100

typedef struct Node{ int v; struct Node* next; } Node;
Node* adj[MAXV];
int n;

void addEdge(int u,int v){
    Node* t = malloc(sizeof(Node)); t->v=v; t->next=adj[u]; adj[u]=t;
    t = malloc(sizeof(Node)); t->v=u; t->next=adj[v]; adj[v]=t;
}

int timeD;
int disc[MAXV], low[MAXV], parent[MAXV], ap[MAXV];

void APUtil(int u){
    disc[u]=low[u]=++timeD;
    int children=0;
    for(Node* p=adj[u]; p; p=p->next){
        int v=p->v;
        if(!disc[v]){ children++; parent[v]=u; APUtil(v); low[u]= low[u]<low[v]?low[u]:low[v];
            if(parent[u]==-1 && children>1) ap[u]=1;
            if(parent[u]!=-1 && low[v]>=disc[u]) ap[u]=1;
        } else if(v != parent[u]){
            low[u] = low[u]<disc[v]?low[u]:disc[v];
        }
    }
}

int isBiconnected(){
    for(int i=0;i<n;i++){ disc[i]=0; low[i]=0; parent[i]=-1; ap[i]=0; }
    timeD=0;
    APUtil(0);
    for(int i=0;i<n;i++) if(!disc[i]) return 0; // not connected
    for(int i=0;i<n;i++) if(ap[i]) return 0;
    return 1;
}

int main(){
    for(int i=0;i<MAXV;i++) adj[i]=NULL;
    printf("Number of vertices: "); scanf("%d",&n);
    int ch,u,v;
    while(1){
        printf("\n1.AddEdge 2.CheckBiconnected 3.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("u v: "); scanf("%d %d",&u,&v); addEdge(u,v); break;
            case 2: printf("%s\n", isBiconnected() ? "Graph is biconnected" : "Not biconnected"); break;
            case 3: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
