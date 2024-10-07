#include <stdio.h>
#include <stdlib.h>
int j = 0, pop[10], v[10];

void dfs(int source, int n, int a[10][10])
{
    int i, k, top = -1, stack[10];
    v[source] = 1;
    stack[++top] = source + 1;
    while (top != -1) // check if stack is not empty
    {
        for (k = 0; k < n; k++)
        {
            if (a[source][k] == 1 && v[k] == 1)
            {
                for (i = top; i >= 0; i--)
                    if (stack[i] == k + 1)
                    {
                        printf("\nTopological order not possible");
                        exit(0);
                    }
            }
            else
            {
                if (a[source][k] == 1 && v[k] == 0)
                {
                    v[k] = 1;
                    stack[++top] = k + 1;
                    source = k;
                    k = 0;
                }
            }
        }
        pop[j++] = source + 1;
        top--;
        source = stack[top] - 1;
    }
}

void topo(int n, int a[10][10])
{
    int i, k;
    for (i = 0; i < n; i++)
        v[i] = 0;
    for (k = 0; k < n; k++)
        if (v[k] == 0)
            dfs(k, n, a); // dfs function call
}

int main()
{
    int n, i, j, a[10][10];
    printf("\nEnter the no of Vertices : ");
    scanf("%d", &n);
    printf("\nEnter the Adjacency matrix\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    topo(n, a);
    printf("\nThe topological ordering is\n");
    for (i = n - 1; i >= 0; i--)
        printf("%d\t", pop[i]);
}
