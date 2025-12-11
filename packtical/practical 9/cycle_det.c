#include <stdio.h>
#include <string.h>
#define MAX 10
int adj[MAX][MAX];
int visited[MAX], recStack[MAX], n = 4;
int dfs(int v)
{
    visited[v] = 1;
    recStack[v] = 1;
    for (int u = 0; u < n; u++)
    {
        if (adj[v][u])
        {
            if (!visited[u] && dfs(u))
                return 1;
            else if (recStack[u])
                return 1;
        }
    }
    recStack[v] = 0;
    return 0;
}
int main()
{
    memset(adj, 0, sizeof(adj));
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][0] = 1;
    adj[2][3] = 1;
    int cycle = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            if (dfs(i))
                cycle = 1;
    printf("Cycle Detection in Graph:\n");
    printf("Nodes: %d\n", n);
    printf("Cycle Present: %s\n", cycle ? "Yes" : "No");
    return 0;
}