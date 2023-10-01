#include<stdio.h>
void main()
{
    int i,j,a[4][4];
    printf("Enter the numbers for the 4X4 matrix below:-\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            scanf("%d",&a[i][j]);
    }
    printf("The matrix you entered:-\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("The required transpose of the above matrix is:-\n");
    for(j=0;j<4;j++)
    {
        for(i=0;i<4;i++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}