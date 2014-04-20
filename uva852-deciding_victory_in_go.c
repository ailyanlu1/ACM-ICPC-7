/*
* UVA-852: Deciding victory in Go
* ===============================
* Author: Felipe Blassioli
* Date: 20/04/2014
* Description: Graphs, connected-components, flood-fill
*/

#include <stdio.h>
#define MAX 15
#define BLACK 'X'
#define WHITE 'O'
#define NONE '.'

int T;
int black, white;
char board[MAX][MAX];
int seen[MAX][MAX];
int b,w; /* border count */
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int floodfill(int x, int y){
	int i,r,nx,ny;
	r=0;
	switch(board[x][y]){
		case BLACK: b++; break;
		case WHITE: w++; break;
		default:
			if(seen[x][y]) return 0;
			seen[x][y]=1;
			r++;
			for(i=0;i<4;i++){
				nx=x+dx[i]; ny=y+dy[i];
				if(nx>=0 && nx<9 && ny>=0 && ny<9)
					r+=floodfill(nx,ny);
			}		
			break;
	}
	return r;
}

int main(){
	int i,j,p;
	scanf("%d",&T);
	getchar();
	while(T--){
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				board[i][j] = getchar();
				seen[i][j]=0;
			}
			getchar();
		}
		black=white=0;
		for(i=0;i<9;i++)
			for(j=0;j<9;j++){
				if(board[i][j]==BLACK) black++;
				else if(board[i][j]==WHITE) white++;
				else if(board[i][j] == NONE && !seen[i][j]){
					b=w=0;
					p=floodfill(i,j);
					if(b==0) white+=p;
					else if(w==0) black+=p;
				}
			}
		printf("Black %d White %d\n",black,white);
	}
	return 0;
}