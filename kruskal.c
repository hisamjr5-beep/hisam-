#include<stdio.h>
int i,j,u,v,ru,rv,n,ne=1;
int min,mincost=0,cost[10][10],parent[10];
//find the set reference
int find(int u)
{
 while(parent[u])
  u=parent[u];
 return u;
}
//union of two sets
void uni(int ru,int rv)
{
 parent[rv]=ru;
 return;
}
void main()
{
 printf("\nEnter the no of vertices:");
 scanf("%d",&n);
 printf("\nEnter the cost adjacency matrix:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&cost[i][j]);
   if (cost[i][j]==0)
     cost[i][j]=999;    //if no edge,its weight is infinite
  }
 }
 printf("\nThe edges of minimum cost spanning tree are\n");
 while(ne<n)
 {
  min=999;
  for(i=1;i<=n;i++)      //find the minimum cost edge
    for(j=1;j<=n;j++)
      if(cost[i][j]<min)
       {
        min=cost[i][j];
        u=i;v=j;
       }
       ru=find(u);
       rv=find(v);
       if(ru!=rv)
       { 
        uni(ru,rv);
        printf("\nEdge %d:(%d %d)=%d\n",ne++,u,v,min);
        mincost+=min;
       }
       cost[u][v]=cost[v][u]=999;
 }
  printf("\n\tMinimum Cost=%d\n",mincost);
}
  
 
