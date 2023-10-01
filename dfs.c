#include <stdio.h>
#include <stdlib.h>
int visited[7] = {0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};
int dfs(int i)
{
    printf("%d", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (!visited[j] && a[i][j] == 1)
        {
            dfs(j);
        }
    }
}
int main()
{
    dfs(2);
    return 0;
}