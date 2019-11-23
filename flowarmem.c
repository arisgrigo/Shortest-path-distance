#include <stdio.h>
#include <stdlib.h>
#include "flowarmem.h"

void solve(int n, int **graph)
{
 int i,j,k,dist,a,b,c,d,e,f;
 int ***mem;

 mem=malloc(n * sizeof(int **));   //allocating space for the memory graph, where the values returned by the recursion are stored
 for(a=0; a<n; a++)
  mem[a]=malloc(n*sizeof(int *));
 for(a=0; a<n; a++)
  for(c=0; c<n; c++)
   mem[a][c]=malloc(n*sizeof(int));

 for(d=0; d<n; d++)   //initializing memory graph
  for(e=0; e<n; e++)
   for(f=0; f<n; f++)
     mem[d][e][f]=-10;

 for(i=1; i<n; i++)
  {
   for(j=0; j<i; j++)
    {
     k=n-1;
     dist=path(i,j,k,graph,mem);
     if(dist<0)
      printf("From node %d to node %d: There is no path\n",i,j);
     else
      printf("From node %d to node %d: Length of shortest path is %d\n",i,j,dist);
    }
   printf("\n");
  }
 for(i=0; i<n; i++) //freeing the space from the memory graph
  for(j=0; j<n; j++)
   free(mem[i][j]);
 for(i=0; i<n; i++)
  free(mem[i]);
 free(mem);
 }


int path(int i,int j,int k,int **graph, int ***mem)
{
 if(k>=0){
 int dist1;
 int dist2;
 int dist3;
 if(mem[i][j][k]!=-10) //if the memory graph already has a value from a previous recursion, return that value
  return mem[i][j][k];

 dist1=path(i,j,k-1,graph,mem);

 dist2=path(i,k,k-1,graph,mem);

 dist3=path(k,j,k-1,graph,mem);
 if(i==j)
  return 0;
 if(dist1<0 && dist2>0 && dist3>0)
  {
   mem[i][j][k]=dist2+dist3;   //saving the value to the memory graph
   return mem[i][j][k];
  }
 else
  if(dist1>0 && (dist2<0 || dist3<0))
   {
    mem[i][j][k]=dist1;
    return mem[i][j][k];
   }
 else
  {
   mem[i][j][k]=min(dist1,dist2+dist3);
   return mem[i][j][k];}
  }
 if(k<0)
  return graph[i][j];
}
