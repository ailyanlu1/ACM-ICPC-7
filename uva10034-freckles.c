#include <stdio.h>
#include <math.h>
#define MAX 105
int N,T;
float x[MAX], y[MAX];

int intree[MAX];
int main()
{
  int c,i,j;
  float dx,dy;
  int minp;
  float len,min,weigth;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d",&N);
    for(i=0;i<N;i++)
      intree[i]=0;
    for(i=0;i<N;i++)
    {
      scanf("%f %f",&x[i],&y[i]);
      /*printf("%d (%f, %f)\n",i+1,x[i],y[i]);*/
    }
    /* Simplest Prim Algorithm */
    c=1;
    intree[0]=1;
    weigth=0;
    while(c<N)
    {
      min = -1.0;
      for(i=0;i<N;i++) if(intree[i])
        for(j=0;j<N;j++) if(!intree[j])
        {
          dx=x[i]-x[j]; dy=y[i]-y[j];
          len=sqrt(dx*dx+dy*dy);
          /*printf("%d -> %d len = %f\n",i+1,j+1,len);*/
          if(min == -1.0 || len < min)
          {
            min=len;
            minp=j;
          }
        }
      /* Adiciona a MST */
      intree[minp]=1;
      weigth+=min;
      c++;
    }
    printf("%.2f\n",weigth);
    if(T>0)
      printf("\n");
  }
  return 0;
}
