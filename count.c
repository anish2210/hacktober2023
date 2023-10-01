#include <stdio.h>
#include <stdlib.h>
int printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int maxnum(int *a, int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
void count(int *a, int n)
{
    int max = maxnum(a, n), i, j;
    int *b = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i < max + 1; i++)
    {
        b[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        b[a[i]] = b[a[i]] + 1;
    }
    i = 0;
    j = 0;
    while (i <= max)
    {
        if (b[i] > 0)
        {
            a[j] = i;
            b[i] = b[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
    free(b);
}
int main()
{
    int a[] = {9, 1, 24, 8, 78, 5, 6};
    int n = 7;
    printarr(a, n);
    count(a, n);
    printarr(a, n);
    return 0;
}