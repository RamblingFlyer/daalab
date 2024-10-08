#include <stdio.h>
#include <stdlib.h>

#define MAX 150

int knap(int n, int m);
int big(int a, int b);

int w[MAX];
int p[MAX];
int v[MAX][MAX];

int big(int a, int b) {
    return (a > b) ? a : b; // Simplified return statement
}

int knap(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) { // Corrected loop condition to <= m
            if (j - w[i] < 0) {
                v[i][j] = v[i - 1][j];
            } else {
                v[i][j] = big(v[i - 1][j], p[i] + v[i - 1][j - w[i]]);
            }
        }
    }
    return v[n][m];
}

int main() {
    int profit, n, m;

    printf("Enter the number of items:\n");
    scanf("%d", &n);

    printf("\nEnter the knapsack capacity: ");
    scanf("%d", &m);

    printf("\nEnter the weights and profits:\n");
    for (int i = 1; i <= n; i++) {
        printf("w[%d] = ", i);
        scanf("%d", &w[i]);
        printf("p[%d] = ", i);
        scanf("%d", &p[i]);
    }

    for (int i = 0; i <= n; i++)
        v[i][0] = 0;

    for (int j = 0; j <= m; j++)
        v[0][j] = 0;

    profit = knap(n, m);

    printf("Profit = %d\n", profit);
    return 0; // Added return statement for main
}
