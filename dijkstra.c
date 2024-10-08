#include <stdio.h>
#include <stdlib.h>

#define INFINITY 999

void dijk(int cost[10][10], int n, int source, int v[10], int d[10]);

int main()
{
    int n;
    int cost[10][10];
    int source;
    int v[10];
    int d[10];
    int i, j;

    printf("Enter number of nodes:\n");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 1; i <= n; i++)     // Keep original indexing
        for (j = 1; j <= n; j++) // Keep original indexing
            scanf("%d", &cost[i][j]);

    printf("Enter the source node:\n");
    scanf("%d", &source); // Added input for the source node

    for (i = 1; i <= n; i++)
    {
        d[i] = cost[source][i];
        v[i] = 0;
    }

    dijk(cost, n, source, v, d);
    printf("Shortest distance from source %d to all other nodes:\n", source);
    for (i = 1; i <= n; i++)
    {
        printf("%d --> %d = %d\n", source, i, d[i]); // Fixed the print statement
    }

    return 0;
}

void dijk(int cost[10][10], int n, int source, int v[10], int d[10])
{
    int least, i, j, u;
    v[source] = 1;

    for (i = 1; i <= n; i++)
    {
        least = INFINITY;
        for (j = 1; j <= n; j++)
        {
            if (v[j] == 0 && d[j] < least)
            {
                least = d[j];
                u = j;
            }
        }

        v[u] = 1;

        for (j = 1; j <= n; j++)
        {
            if (v[j] == 0 && (d[j] > (d[u] + cost[u][j])))
                d[j] = d[u] + cost[u][j];
        }
    }
}
