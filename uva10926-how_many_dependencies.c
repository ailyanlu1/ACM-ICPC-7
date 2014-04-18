/*
* UVA10926: How many dependencies?
* ================================
* Author: Felipe Blassioli
* Date: 18/04/2014
* Description: DFS
*/
#include <stdio.h>
#include <string.h>
#define MAX 102
int N, T;
int a[MAX][MAX];
int v[MAX];

int dfs(int u){
    int i,c;
    c = 0;
    v[u]=1;
    /*printf("  visited %d\n", u);*/
    for(i=1;i<=N;i++)
        if(a[u][i] && !v[i])
        {
            c++;
            c += dfs(i);
        }
    /*printf("vertex %d has %d children\n", u, c);*/
    return c;
}

int main(){
	int i, j, t, max, max_i;
	while(scanf("%d", &N) && N){
		for(i=0;i<=N;i++) for(j=0;j<=N;j++)
            a[i][j] = 0;
		for(i=1;i<=N;i++){
			scanf("%d", &T);
			for(j=0;j<T;j++){
				scanf("%d", &t);
				a[i][t] = 1;
			}
		}
        max = -1;
        for(i=1;i<=N;i++){
            /*printf("Vertex %d\n",i);*/
            for(j=0;j<=N;j++) v[j]=0;
            t = dfs(i);
            if(t > max){
                max = t; max_i = i;
            }
            /*printf("---\n");*/
        }
        printf("%d\n",max_i);
	}
}
