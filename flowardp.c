#include <stdio.h>
#include <stdlib.h>
#include "flowardp.h"

void solve(int n, int **graph)
{
 int i,j,k,dist,a,b,c,d,e,f;
 int **di;
 int **next;
 k=n-1;

 di=malloc(n * sizeof(int *)); //allocating space for the distance graph(di), used for calculating distances between each i,j
 for(a=0; a<n; a++)
  di[a]=malloc(n*sizeof(int));

 next=malloc(n * sizeof(int *)); //allocating space for the array used for reconstructing the shortest path between each i,j
 for(a=0; a<n; a++)
  next[a]=malloc(n*sizeof(int));

 for(a=0; a<n; a++) //initializing array used for the path reconstruction
  for(b=0;b<n;b++)
   next[a][b]=0;

 for(i=0; i<n; i++)  //initializing distance graph
  for(j=0; j<n; j++)
   di[i][j]=0;

 for(i=0; i<n; i++)
   for(j=0; j<n; j++)
     {di[i][j]=graph[i][j];   //copying the weights of the edges to the distance graph
      di[j][i]=di[i][j];
      if(i==j) di[i][j]=0;
      next[i][j]=j;
     }

  for(k=0; k<n; k++)    //executing Floyd-Warshall algorithm
   for(i=0; i<n; i++)
    for(j=0; j<n; j++)
     if(di[i][k] > 0 && di[k][j] > 0)
       if(di[i][j] > di[i][k] + di[k][j] || di[i][j] == -1)
         {di[i][j] = di[i][k] + di[k][j];
          next[i][j] = next[i][k];
         }

 for(i=1; i<n; i++)
  {for(j=0; j<i; j++)
   {
    if(di[i][j]<0)
     printf("From node %d to node %d: There is no path\n",i,j);
    else
     {
      printf("From node %d to node %d: Length of shortest path is %d\n",i,j,di[i][j]);
       #ifdef PATH
      printf("    Shortest path is: %d",i);
      int node=i;
      while(node!=j)
       {
        node = next[node][j];
        printf(" -> %d",node);
       }
      printf("\n");
      #endif
     }
   }
  printf("\n");
 }
 for(a=0; a<n; a++)
  free(di[a]);
 free(di);
 for(a=0; a<n; a++)
  free(next[a]);
 free(next);
}


