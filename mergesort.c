#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftarr[n1];
    int rightarr[n2];

    for (i = 0; i < n1; i++)
    {
        leftarr[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        rightarr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (leftarr[i] <= rightarr[j])
        {
            arr[k] = leftarr[i];
            i++;
        }
        else
        {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
        }

    while (i < n1)
    {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
