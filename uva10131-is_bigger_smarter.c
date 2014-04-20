#include <stdio.h>
#define MAX 1002
#define max(a,b) (((a) > (b) ) ? (a) : (b))
typedef struct {
  int p,w,s;
} Elephant;

int N;
Elephant elephants[MAX];
int P[MAX];
int C[MAX][MAX];
int result[MAX];
int lenResult;

int compareW(const void *a, const void *b){
  Elephant *e1=(Elephant *)a;    
  Elephant *e2=(Elephant *)b;
  return e1->w-e2->w;
}
int compareS(const void *a, const void *b){
  Elephant *e1=(Elephant *)a;    
  Elephant *e2=(Elephant *)b;
  return e2->s-e1->s;    
}

void lcs(){
  int c,i,j;  
  for(i=0;i<=N;i++) C[i][0]=C[0][i]=0;
  for(i=1;i<=N;i++){
    for(j=1;j<=N;j++){
      if(elephants[i-1].p==P[j-1]){
        C[i][j]=C[i-1][j-1]+1;
      }else{
        C[i][j]=max(C[i-1][j],C[i][j-1]);
      }                
    }
  }
  i=j=N;
  lenResult=c=C[N][N];
  while((i>0)&&(j>0)){
    if(C[i][j]==C[i-1][j]) i--;
    else if(C[i][j]==C[i][j-1]) j--;
    else {
      result[--c]=P[j-1];
      i--;j--;     
    }
  }
}
int main(){
 int i,W,S;
 N=0;
 while(scanf("%d %d",&W,&S)==2){
   elephants[N].w=W;
   elephants[N].s=S;
   elephants[N].p=(N+1);
   N++;
 }
 qsort(elephants,N,sizeof(Elephant),compareW);
 for(i=0;i<N;i++) P[i]=elephants[i].p;
 qsort(elephants,N,sizeof(Elephant),compareS);
 lcs();
 printf("%d\n",lenResult);
 for(i=0;i<lenResult;i++)
   printf("%d\n",result[i]);
 return 0;   
}
