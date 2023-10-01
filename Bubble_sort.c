#include <stdio.h>
int main()
{
    int i, n, sort;
    int arr[100];
    printf("Enter Number of elements\n");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("No elements can be added");
        return 0;
    }
    printf("Enter array elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array elements=\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    for (int j = 0; j < n - 1; j++)
    {
        sort = 1;
        for (i = 0; i < n - 1 - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sort = 0;
            }
        }
        if (sort)
        {
            printf("\nAlready sorted");
            break;
        }
    }
    if (!sort)
    {
        printf("\nSorted array elements=\n");
        for (i = 0; i < n; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
    return 0;
}