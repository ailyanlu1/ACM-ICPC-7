/*
* UVA11957 - Checkers
* ===================
* Author: Felipe Blassioli
* Date: 21/04/2013
* Description: Dynamic programming solution.
*/
#include <stdio.h>
#define MAX 105
#define BORDA '@'
int N,T;
char board[MAX][MAX];
unsigned int mem[MAX][MAX];
unsigned int count=0;
int wx,wy;
void printBoard()
{
  int i;
  for(i=0;i<=N+1;i++)
    printf("|%s|\n",board[i]);
}
int mover(int x, int y)
{     
  int r=0;
  if(board[x][y]==BORDA||board[x][y]=='B')
    return 0;
  else if(x==1 && board[x][y] != 'B')
  {
    board[x][y]='1'; return 1; 
  }
  else if(mem[x][y]!=-1)
    return mem[x][y];
  else{
    if(board[x-1][y+1]=='B')
      r+=mover(x-2,y+2)%1000007;
    else
      r+=mover(x-1,y+1)%1000007;
    if(board[x-1][y-1]=='B')
      r+=mover(x-2,y-2)%1000007;
    else
      r+=mover(x-1,y-1)%1000007;
    board[x][y] = r+'0';
    return mem[x][y]=r%1000007;
  }
}
int main()
{
  int i,r,c;
  /* Leitura de entrada */
  scanf("%d",&T);
  for(i=1;i<=T;i++)
  {
    scanf("%d",&N);
    /* Leitura do \n apos N */
    scanf("%c",&board[0][0]);
    /* Leitura de N linhas e N+1 chars (inclui \n) */
    for(r=0;r<=N+1;r++)
    {
      for(c=0;c<=N+1;c++)
      {
         board[r][c]=BORDA;
         mem[r][c]=-1;
      }
      board[r][c]='\0';
    }
    for(r=1;r<=N;r++)
    {
      for(c=1;c<=N+1;c++)
      {
        scanf("%c",&board[r][c]);
        if(board[r][c]=='\n'){
          board[r][c]=BORDA;
          board[r][c+1]='\0';
        }
        if(board[r][c]=='W')
        {
          wx=r;
          wy=c;
        }
      }
    }
    printBoard();
    count=mover(wx,wy)%1000007;
    printBoard();
    printf("Case %d: %d\n",i,count);
  }
  return 0;
}
