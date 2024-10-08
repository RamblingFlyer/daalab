#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bfs(int adj[MAX][MAX], int s, int v)
{
    int q[MAX], front = 0, rear = 0;

    int visited[MAX] = {0};

    visited[s] = 1; // Mark the source vertex as visited
    q[rear++] = s;  // Enqueue the source vertex

    while (front < rear)
    {
        int curr = q[front++]; // Dequeue a vertex
        printf("%d ", curr);   // Print the current vertex

        // Explore all adjacent vertices
        for (int i = 0; i < v; i++)
        {
            if (adj[curr][i] == 1 && visited[i] == 0) // Check for adjacent and unvisited vertices
            {
                visited[i] = 1; // Mark the vertex as visited
                q[rear++] = i;  // Enqueue the vertex
            }
        }
    }
}

void addedge(int adj[MAX][MAX], int u, int v)
{
    adj[u][v] = 1; // Add an edge from u to v
    adj[v][u] = 1; // Add an edge from v to u (undirected graph)
}

int main()
{
    int n;
    int v = 5; // Number of vertices

    int adj[MAX][MAX] = {0}; // Initialize the adjacency matrix

    // Add edges to the graph
    addedge(adj, 0, 1);
    addedge(adj, 0, 2);
    addedge(adj, 1, 3);
    addedge(adj, 1, 4);
    addedge(adj, 2, 4);

    printf("Enter source vertex (0 to %d):\n", v - 1);
    scanf("%d", &n);

    // Validate the source vertex input
    if (n < 0 || n >= v)
    {
        printf("Invalid vertex. Please enter a vertex between 0 and %d.\n", v - 1);
        return 1; // Exit the program with an error code
    }

    // Perform BFS traversal starting from the source vertex
    printf("BFS starting from vertex %d:\n", n);
    bfs(adj, n, v);

    return 0;
}
