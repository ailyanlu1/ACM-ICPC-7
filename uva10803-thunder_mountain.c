/*
* 10803: Thunder Mountain
* =======================
* Author: Felipe Blassioli
* Date: 25/06/2014
* Description: Graphs, AllPair-Shortest-Path, Floyd-Warshall
*/
#include <stdio.h>
#include <math.h>
#define MAX 105
#define INF 999999.0

double c[MAX][MAX];
int x[MAX], y[MAX];
int N, n;

double dist(int s, int t){
	int dx = x[s]-x[t];
	int dy = y[s]-y[t];
	return sqrt(dx*dx + dy*dy);
}
double floyd_warshall(){
	int k,s,t;
	double d;
	for(s=0; s<n; s++)
		for(t=0;t<n;t++){
			d = dist(s,t);
			if(d<=10)
				c[s][t] = c[t][s] = d;
			else
				c[s][t] = INF;
		}
	for(k=1;k<=n;k++)
		for(s=0;s<n;s++)
			for(t=0;t<n;t++){
				d = c[s][k-1] + c[k-1][t];
				if(c[s][t] > d) 
					c[s][t] = d;
			}
}
int main(){
	double m;
    int t,i,j;
    scanf("%d",&N);
    for(t=1;t<=N;t++){
    	scanf("%d",&n);
    	for(i=0;i<n;i++)
    		scanf("%d %d", &x[i], &y[i]);
    	floyd_warshall();
    	m = -1.0;
    	for(i=0;i<n;i++)
    		for(j=0;j<n;j++)
    			if(m < c[i][j])
    				m = c[i][j];
    	printf("Case #%d:\n",t);
    	if(m==INF) 
    		printf("Send Kurdy\n\n");
    	else
    		printf("%0.4lf\n\n",m);
    }
    return 0;   
}
