#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 256
int t[MAX];
int count = 1;

void shifttable(char pat[])
{
    int i, j, m;
    m = strlen(pat);
    for (i = 0; i < MAX; i++)
        t[i] = m;
    for (j = 0; j < m - 1; j++)
        t[pat[j]] = m - 1 - j;
}

int horspool(char src[], char pat[])
{
    int i, j, k, m, n;
    n = strlen(src);
    m = strlen(pat);
    i = m - 1;

    while (i < n)
    {
        k = 0;
        while (k < m && (pat[m - 1 - k] == src[i - k]))
            k++;
        if (k == m)
            return (i - m + 1);
        else
            i += t[src[i]];
        count = count + 1;
    }
    return -1;
}

int main()
{
    char src[100], pat[10];
    int pos;
    printf("\nEnter the main source string\n");
    gets(src);
    printf("\nEnter the pattern to be searched\n");
    gets(pat);
    shifttable(pat);

    pos = horspool(src, pat);
    if (pos >= 0)
    {
        printf("\nFound at %d position ", pos + 1);
        printf("\nNumber of shifts are %d", count);
    }
    else
        printf("\nString match failed");
    return 0;
}
