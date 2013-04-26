#include<stdio.h>
#include <math.h>
#define MAX_T 1005
int S,T;
int primes[MAX_T];

int bfs(int start, int end)
{
  int q[MAX_T]; /* Vertices queue */
  int m,n;     /* Queue indexes */
  int v;       /* Current vertex */
  int d[MAX_T];
  int i;
  int newNumber;
  int maxPrime = (int)sqrt(S)+1;
  for(i=0;i<MAX_T;i++)
    d[i]=-1;
  m=n=0;
  q[n++]=start;
  d[start]=0;

  while(m<n)
  {
    v=q[m++];
    /* Primes factors */
    for(i=2;i<v;i++)
    {
      if(v%i==0 && primes[i])
      {
        newNumber = v+i;
        /* printf("\ti=%d\n",i); */
        /* If not discovered yet */
        if(d[newNumber]==-1)
        {
          q[n++]=newNumber; /* Enqueue */
          d[newNumber]=d[v]+1;
          if(newNumber==end) return d[end];
          /* printf("\tE %d+%d = %d d=%d\n",v,i,newNumber,d[newNumber]); */
        }
      }
    }
  }
  return d[end];
}

int main()
{
  int i,j;
  int c = 1; /* Test Case */
  /* Sieve of Erastothenes */
  for(i=0;i<=MAX_T;i++) primes[i]=1;
  primes[1]=0;
  for(i=2;i<=MAX_T;i++) if(primes[i])
    for(j=i;j*i<=MAX_T; j++)
      primes[j*i]=0;

  while(scanf("%d %d",&S,&T)==2)
  {
    if(S==0&&T==0) break;
    i = bfs(S,T);
    printf("Case %d: %d\n", c++,i);
  }
  return 0;
}
