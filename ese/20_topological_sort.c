/* 20_topological_sort.c
   Topological sort using Kahn's algorithm (works for DAG)
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXV 100

typedef struct Node{ int v; struct Node* next; } Node;
Node* adj[MAXV];
int indeg[MAXV];
int n;

void addEdge(int u,int v){
    Node* t=malloc(sizeof(Node)); t->v=v; t->next=adj[u]; adj[u]=t;
    indeg[v]++;
}

void topo(){
    int q[MAXV], f=0,r=0, cnt=0;
    for(int i=0;i<n;i++) if(indeg[i]==0) q[r++]=i;
    while(f<r){
        int u=q[f++]; printf("%d ", u); cnt++;
        for(Node* p=adj[u]; p; p=p->next){
            indeg[p->v]--;
            if(indeg[p->v]==0) q[r++]=p->v;
        }
    }
    if(cnt!=n) printf("\nGraph has cycle. Topo not possible.\n"); else printf("\n");
}

int main(){
    for(int i=0;i<MAXV;i++){ adj[i]=NULL; indeg[i]=0; }
    printf("Vertices (n): "); scanf("%d",&n);
    int ch,u,v;
    while(1){
        printf("\n1.AddEdge 2.TopologicalSort 3.Exit\nChoice: ");
        if(scanf("%d",&ch)!=1) break;
        switch(ch){
            case 1: printf("u v: "); scanf("%d %d",&u,&v); addEdge(u,v); break;
            case 2: topo(); break;
            case 3: exit(0);
            default: printf("Invalid\n");
        }
    }
    return 0;
}
