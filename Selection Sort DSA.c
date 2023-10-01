#include<stdio.h>
#include<stdlib.h>
void main() //selection sort
{
    int i,j,m,x,temp,*a = NULL;
    printf("Enter the size of the array: ");
    scanf("%d",&x);
    a=(int *)malloc(x * sizeof(int)); //Dynamically allocated the array

    printf("Enter the numbers to be sorted in the array below:-\n");
    for(i=0;i<x;i++)
        scanf("%d",&a[i]);

    for (i = 0; i < x - 1; i++) 
    {
      m = i;
      for (j = i + 1; j < x; j++)
       {
         if (a[j] < a[m])
            m = j;
        }
        temp = a[m];
        a[m] = a[i];
        a[i] = temp;
   }

    printf("The sorted array: ");
     for(i=0;i<x;i++)
        printf("%d ",a[i]);
}
