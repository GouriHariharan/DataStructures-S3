#include<stdio.h>
int visited[100], a[100][100] = {0}; //initializing with 0
int V;
void dfs(int v)
{
    visited[v]=1;
    printf("v%d\t", v+1);
    for(int i=0;i<V;i++)
    {
        if(a[v][i]==1 && visited[i]==0)
            dfs(i);
    }
}
int main()
{
    int e,i,j,v1,v2;
    printf("\nEnter the number of vertices (<100):");
    scanf("%d",&V);
    printf("\nEnter the number of edges:");
    scanf("%d",&e);
    printf("\nEnter the edges (ie. v1 v2)\n");
    for(i=0;i<e;i++)
    {
        scanf("%d %d",&v1,&v2);
        a[v1-1][v2-1] = 1;  //adjacency matrix starts as a[1][1]
    }
    printf("\nThe Adjacency Matrix :\n");
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            printf("%d",a[i][j]);
        printf("\n");
    }
    printf("\nDFS :\n");
    dfs(0); //starting from v1
}