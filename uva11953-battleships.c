/*
* UVA-11953: Battleships
* ======================
* Author: Felipe Blassioli
* Date: 20/04/2014
* Description: Graphs, connected-components, flood-fill
*/

#include <stdio.h>
#define MAX 105
#define CELL_EMPTY '.'
#define CELL_PART 'x'
#define CELL_SHOT '@'

int T,N;
int ans;
char g[MAX][MAX];
int v[MAX][MAX];

int parts, shots;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void floodfill(int x, int y){
	int i,nx,ny;
	if(v[x][y] || g[x][y]==CELL_EMPTY) return;
	v[x][y]=1;
	if(g[x][y]==CELL_SHOT) shots++;
	else if(g[x][y]==CELL_PART) parts++;
	for(i=0;i<4;i++){
		nx=x+dx[i]; ny=y+dy[i];
		if(nx>=0 && ny>=0 && ny < N && nx < N)
			floodfill(x+dx[i],y+dy[i]);
	}
}

int main(){
	int i,j,t;

	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&N);
		getchar();
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				g[i][j]=getchar();
				v[i][j]=0;
			}
			getchar();
		}
		ans=0;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(g[i][j]!=CELL_EMPTY && !v[i][j]){
					parts=shots=0;
					floodfill(i,j);
					/*printf("(%d,%d) parts=%d shots=%d\n",i,j,parts,shots);*/
					if(parts) ans++;
				}
			}
		}
		printf("Case %d: %d\n",t,ans);
	}
	return 0;
}