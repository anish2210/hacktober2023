#include<stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[],int left,int right)
{
    int i,j;
    int pivot=arr[left];
    i=left+1;
    j=right;
    do
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(&arr[left],&arr[j]);
    }while(i<j);

    swap(&arr[left],&arr[j]);
    return j;
}

void quicksort(int arr[],int left,int right)
{
    if(left < right)
    {
        int p=partition(arr,left,right);
        quicksort(arr,left,p-1);
        quicksort(arr,p+1,right);
    }
}

void main()
{       
    int i,j,n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the numbers to be sorted using Quick Sort in the array below:-\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Unsorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    quicksort(arr,0,n-1);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}