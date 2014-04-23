/*
* UVA-11561: Getting Gold
* ========================
* Author: Felipe Blassioli
* Date: 23/04/2014
* Description: graph theory, graph traversal, DFS.
*/

#include <stdio.h>
#include <string.h>
#define MAX 55
#define FLOOR '.'
#define PLAYER 'P'
#define TRAP 'T'
#define WALL '#'
#define GOLD 'G'

int W,H;
char g[MAX][MAX];
int s[MAX][MAX];
int ans;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int dfs(int x, int y){
	int i,j,nx,ny;
	s[x][y] = 1;
	if(g[x][y]==GOLD) ans++;
	/* Is there a trap? If true, go back */
	for(i=0;i<4;i++){
		nx=x+dx[i]; ny=y+dy[i];
		if(g[nx][ny]==TRAP)
			for(j=0;j<4;j++){
				nx=x+dx[j]; ny=y+dy[j];
				if(!s[nx][ny] && g[nx][ny]!=TRAP)
					return ;
			}
	}
	/* Move to GOLD or FLOOR */
	for(i=0;i<4;i++){
		nx=x+dx[i]; ny=y+dy[i];
		if(!s[nx][ny] && (g[nx][ny]==FLOOR || g[nx][ny]==GOLD))
			dfs(nx,ny);
	}
}

int main(){
	int i,j,px,py;
	while(scanf("%d %d",&W,&H)==2){
		getchar();
		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				g[i][j] = getchar();
				s[i][j] = 0;
				if(g[i][j] == PLAYER){
					px=i;
					py=j;
				}
			}
			getchar();
		}
		ans=0;
		dfs(px,py);
		printf("%d\n",ans);
	}
	return 0;
}