#include<stdio.h>
int main()
{
    int arr[100],i,j,n,temp;
    printf("Enter no of limit you want\n");
    scanf("%d",&n);
    printf("Enter your array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
	printf("Sorted Array will be\n");
    for(i=1;i<n;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }

    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}
