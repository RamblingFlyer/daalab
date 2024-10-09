#include <stdio.h>
#include <limits.h>
int V;
int minimum(int key[], int mstSet[])
{
    int minval = INT_MAX;
    int minindex = 0;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == 0 && key[v] < minval)
        {
            minval = key[v];
            minindex = v;
        }
    }
    return minindex;
}
void printmst(int graph[V][V], int parent[])
{
    printf("Edges \t Weights\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d-%d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}
void prims(int graph[V][V])
{
    int key[V];
    int mstSet[V];
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        mstSet[i] = 0;
        key[i] = INT_MAX;
    }
    parent[0] = -1;
    key[0] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int u = minimum(key, mstSet);
        mstSet[u] = 1;
        for (int j = 0; j < V; j++)
        {
            if (graph[u][j] && mstSet[j] == 0 && graph[u][j] < key[j])
            {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    printmst(graph, parent);
}
int main()
{
    printf("Enter no. of vertices\n");
    scanf("%d", &V);
    printf("Enter the graph\n");
    int graph[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    prims(graph);
    return 0;
}