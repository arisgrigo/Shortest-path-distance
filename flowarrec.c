#include <stdio.h>
#include <stdlib.h>
#define min(X,Y)     ((X) < (Y) ? (X) : (Y))
#include "flowarrec.h"

void solve(int n, int **graph)
{
 int i,j,k,dist;
 k=n-1;
 for(i=1; i<n; i++)
  {for(j=0; j<i; j++)
   {k=n-1;
   dist=path(i,j,k,graph);    //start of the calculation. Every combination of nodes i,j are calculated.
   if(dist<0)                 //if distance is negative, there's infinite distance between the two nodes
    printf("From node %d to node %d: There is no path\n",i,j);
   else
   printf("From node %d to node %d: Length of shortest path is %d\n",i,j,dist);
   }
  printf("\n");
 }
}

int path(int i,int j,int k,int **graph)
{
 if(k>=0){        //reccursion continues while k is 0 or positive
 int dist1=path(i,j,k-1,graph);   //dist1 is the path from i to j through k-1 nodes (Pi,j,k-1)
 int dist2=path(i,k,k-1,graph);   //dist2 is the path from i to k through k-1 nodes (Pi,k,k-1)
 int dist3=path(k,j,k-1,graph);   //dist3 is the path from k to j through k-1 nodes (Pk,j,k-1)
 if(i==j) return 0;               //if i==j then returns the distance from a node to the same node, so 0
 if(dist1<0 && dist2>0 && dist3>0)  //if dist1 is infinite but dist2 and dist3 arent, return dist2+dist3
  return (dist2+dist3);
 else if(dist1>0 && (dist2<0 || dist3<0))
  return dist1;
 else return min(dist1,dist2+dist3);
 }
 if(k<0)        //reccursion ends when k becomes negative
  return graph[i][j]; //gives value of edge between i and j
}
