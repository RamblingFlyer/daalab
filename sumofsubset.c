#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int s[MAX], x[MAX];
int d;

void sumofsubset(int p, int k, int r)
{
    int i;
    x[k] = 1;
    if (p + s[k] == d)
    {
        printf("Subset: ");
        for (i = 1; i <= k; i++)
        {
            if (x[i] == 1)
            {
                printf("%d ", s[i]);
            }
        }
        printf("\n");
    }
    else if (p + s[k] + s[k + 1] <= d)
    {
        sumofsubset(p + s[k], k + 1, r - s[k]);
    }

    if ((p + r - s[k] >= d) && (p + s[k + 1] <= d))
    {
        x[k] = 0;
        sumofsubset(p, k + 1, r - s[k]);
    }
}

int main()
{
    int i, n, sum = 0;

    printf("Enter maximum number : ");
    scanf("%d", &n);

    printf("Enter the set in increasing order:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &s[i]);

    printf("Enter the maximum subset value : ");
    scanf("%d", &d);

    for (i = 1; i <= n; i++)
        sum += s[i];

    if (sum < d || s[1] > d)
        printf("No subset possible\n");
    else
        sumofsubset(0, 1, sum);

    return 0;
}