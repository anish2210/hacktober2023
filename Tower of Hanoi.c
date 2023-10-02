#include<stdio.h>

void Tower_of_Hanoi(int n, char BEG, char END, char AUX)
{
    if(n == 1)
    {
        printf("\n DISC 1 FROM %c TO %c",BEG,END);
        return;
    }
    else {
        Tower_of_Hanoi(n-1,BEG,AUX,END);
        printf("\n DISC %d FROM %c TO %c",n,BEG,END);
        Tower_of_Hanoi(n-1,AUX,END,BEG);
    }
}

int main()
{
    int n;
    printf("ENTER NUMBER OF DISCS: ");
    scanf("%d",&n);
    Tower_of_Hanoi(n,'A','C','B');
}
