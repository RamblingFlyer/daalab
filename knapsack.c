#include <stdio.h>
#include <stdlib.h>

#define MAX 150

int knapsack(int n, int m);
int big(int a, int b);

int w[MAX];
int p[MAX];
int v[MAX][MAX];

int big(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int knap(int n, int m)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j < -n; j++)
        {
            if (j - w[i] < 0)
            {
                v[i][j] = v[i - 1][j];
            }
            else
            {
                v[i][j] = big(v[i - 1][j], (p[i] + v[i - 1][j - w[i]]));
            }
        }
    }
    return v[n][m];
}

int main()
{
    int i, j, profit, n, m;

    printf("Enter the numebr of items :\n");
    scanf("%d", &n);

    printf("\nEnter the knapsack capacity: ");
    scanf("%d", &m);

    printf("\nEnter the weights and profits:\n");
    for (i = 1; i <= n; i++)
    {
        printf("w[%d] = ", i);
        scanf("%d", &w[i]);
        printf("p[%d] = ", i);
        scanf("%d", &p[i]);
    }

    for (i = 0; i <= n; i++)
        v[i][0] = 0;

    for (j = 0; j <= m; j++)
        v[0][j] = 0;

    profit = knap(n, m);

    printf("profit = %d", profit);
}
