#include <stdio.h>
#define MAXV 205
#define MAXDEGREE 205
#define NOT_COLORED -1
#define BLACK 0
#define WHITE 1
int N,L;
/* Graph */
int degree[MAXV];
int edges[MAXV][MAXDEGREE];

int bfs (int start)
{
  int color[MAXV]; /* Colored vertices are discovered */
  int q[MAXV]; /* Vertices queue */
  int m,n;   /* Queue indexes */
  int i;
  int v; /* Current vertex */
  int c; /* Color to paint next vertex */ 
  for(i=0;i<N;i++)
    color[i]=NOT_COLORED;
  m=n=0;
  /* Enqueue */
  q[n++]=start;
  color[start]=BLACK;
  /* Queue empty? */
  while(m<n)
  {
    v=q[m++]; /* Dequeue */
    c=(color[v]==BLACK)? WHITE : BLACK;
    for(i=0;i<degree[v];i++)
    {
      if(color[edges[v][i]]==NOT_COLORED)
      {
        color[edges[v][i]]=c;
        q[n++]=edges[v][i]; /* Enqueue */
      } 
      else if(color[edges[v][i]]!=c)
        return 0; /* NOT BICOLORABLE */
    }
  }
  return 1; /* BICOLORABLE */
}
int main()
{
  int i,u,v;
  while(scanf("%d",&N)==1)
  {
    if(N==0) break;
    scanf("%d",&L);
    for(i=0;i<N;i++)
      degree[i]=0;
    for(i=0;i<L;i++)
    {
      scanf("%d %d",&u,&v);
      /* Undirected Graph */
      edges[u][degree[u]++]=v;
      edges[v][degree[v]++]=u;
    }
    if(bfs(0))
      printf("BICOLORABLE.\n");
    else
      printf("NOT BICOLORABLE.\n");
  }
  return 0;
}
