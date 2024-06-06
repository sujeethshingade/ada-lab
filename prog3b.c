#include<stdio.h>
void warshall(int cost[10][10],int n)
{
int i,j,k;
for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
cost[i][j]=(cost[i][j])||(cost[i][k]&&cost[k][j]);

}
void main()
{
int n,adj[10][10],i,j;
printf("Enter the no of vertices\n");
scanf("%d",&n);
printf("Enter the adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&adj[i][j]);
}
warshall(adj,n);
printf("trasitive clusure Matrix");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d\t",adj[i][j]);
}
printf("\n");
}
}
