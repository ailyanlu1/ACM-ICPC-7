
/*
* UVA-12442: Forwarding Emails
* ============================
* Author: Felipe Blassioli
* Date: 18/04/2014
* Description: Graphs,DFS
*/
#include <stdio.h>
#define MAX 50005
int T,N;
int vis[MAX], f[MAX], c[MAX];
int m, mu;

int dfs(u){
	int v = f[u];
	int r = 0;
	vis[u] = 1;
	if(!vis[v])
		r = dfs(v) + 1;
	vis[u] = 0;
	c[u] = r;
	return r;
}

int main(){
	int t,i,u,v;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&N);
		for(i=1;i<=N;i++){
			scanf("%d %d",&u,&v);
			f[u] = v;
			vis[u] = 0;
			c[u] = -1;
		}
		m = -1;
		for(i=1;i<=N;i++){ 
			if(c[i]==-1) dfs(i);
			if(c[i]>m){
				m=c[i];
				mu=i;
			}
			/*printf("vertex %d children %d\n",i,c[i]);*/
		}
		printf("Case %d: %d\n",t,mu);
	}
	return 0;
}