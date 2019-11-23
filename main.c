#include <stdio.h>
#include <stdlib.h>
#define min(X,Y)     ((X) < (Y) ? (X) : (Y))

void solve(int n, int **graph);

int main()
{
 int i,j,**graph,N;
 scanf("%d",&N);
 graph=malloc(N * sizeof(int *));
 for(i=0; i<N; i++)
  graph[i]=malloc(N*sizeof(int));

 for(i=0; i<N; i++)
  for(j=0; j<=i; j++)
    {
     if(i==j)
      graph[i][j]=0;
     else
      {
       scanf("%d",&graph[i][j]);
       graph[j][i]=graph[i][j];}
      }

 /*printf("%d\n",N);
 for(i=1; i<N; i++)
  {for(j=0; j<i; j++)
    printf("%3d ",graph[i][j]);  //used to print every edge. I have it as a comment because for large N, it fills up the screen with numbers
  printf("\n");}
 printf("\n\n"); */

 solve(N, graph);
 for(i=0;i<N;i++)
  free(graph[i]);
 free(graph);
}
