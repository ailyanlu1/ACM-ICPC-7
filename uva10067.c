#include <stdio.h>
#define MAXN 10005
int T;
int F; /* Number of forbidden configurations */

int forbidden[MAXN];
int ten[]={1000,100,10,1};

int readNumber()
{
  int num = 0;
  int d; /* digit */
  int i;
  for(i=0;i<4;i++)
  {
    scanf("%d",&d);
    num+=d*ten[i];
  }
  return num;
}
void extractDigits(int n, int digits[])
{
  digits[0]=n/1000;
  digits[1]=(n%1000)/100;
  digits[2]=(n%100)/10;
  digits[3]=n%10;
}
int is_valid(int n)
{
  int i;
  for(i=0;i<F;i++)
    if(n==forbidden[i])
      return 0;
  return 1;
}
/* Do BFS in a implicit graph */
int bfs(int start, int end)
{
  int q[MAXN]; /* Vertices queue */
  int m,n;     /* Queue indexes */
  int d[MAXN]; /* Discovered vertices. */
  int v;       /* Current vertex */
  int i;       /* Generic count */
  int digits[4];
  int newDigit;
  int newNumber;

  /* All vertices are undiscovered */
  /* Which means their distance from start is -1 */
  for(i=0;i<MAXN;i++)
    d[i]=-1;
  m=n=0;
  q[n++]=start; /* Enqueue */
  d[start]=0;
  while(m<n) /* Queue empty? */
  {
    v=q[m++]; /* Dequeue */
    /* Extract digits into digits[] */
    extractDigits(v, digits);
    /* There are 8 possible children  */   
    /* We add +1 and -1 to each digit */
    for(i=0;i<4;i++)
    {
      newDigit=digits[i]+1;
      newDigit=(newDigit==10)? 0 : newDigit;
      newNumber=v+(newDigit-digits[i])*ten[i];
      /* printf("\t%04d\n",newNumber); */
      if(is_valid(newNumber)&&d[newNumber]==-1)
      {
        q[n++]=newNumber; /* Enqueue */
        d[newNumber]=d[v]+1;
      }
      newDigit=digits[i]-1;
      newDigit=(newDigit==-1)? 9 : newDigit;
      newNumber=v+(newDigit-digits[i])*ten[i];
      /* printf("\t%04d\n",newNumber); */
      if(is_valid(newNumber)&&d[newNumber]==-1)
      {
        q[n++]=newNumber; /* Enqueue */
        d[newNumber]=d[v]+1;
      }
      if(newNumber==end)
        return d[end];
    }
  }
  return -1; 
}

int main()
{
  int i;
  int start, end;
  scanf("%d",&T);
  while(T--)
  {
    /* Read Numbers */
    start=readNumber();
    end=readNumber();
    /* Forbidden Configurations */
    scanf("%d",&F);
    for(i=0;i<F;i++)
    {
      forbidden[i]=readNumber();
    }
    i = bfs(start,end);
    printf("%d\n",i);
  }
  return 0;
}
