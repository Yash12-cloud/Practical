#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Visited array
int n;             // Number of nodes
void dfs(int v, int skip)
{
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (i != skip && adj[v][i] && !visited[i])
            dfs(i, skip);
    }
}
int isConnected(int skip)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    int start = (skip == 0) ? 1 : 0; // Start from a node other than the skipped one
    dfs(start, skip);
    for (int i = 0; i < n; i++)
    {
        if (i != skip && !visited[i])
            return 0; // Not connected
    }
    return 1; // Connected
}
int main()
{
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    for (int i = 0; i < n; i++)
    {
        if (!isConnected(i))
            printf("Node %d is critical. Its failure disconnects the network.\\n", i);
        else
            printf("Node %d is not critical.\\n", i);
    }
    return 0;
}