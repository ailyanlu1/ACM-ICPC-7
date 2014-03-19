/* UVA 10003 - Cuttings Sticks */
/* link: http://uva.onlinejudge.org/external/100/10003.html */
/* Tags: Dynamic Programming, Memoization, Matrix Chain Multiplication */

#include <stdio.h>
#include <string.h>
#define MAX_CUTS 53
#define INF 10000

/* Input */
int L, N;
int cut[MAX_CUTS];
/* Vars */
int cost[MAX_CUTS][MAX_CUTS];

/* The minimum cost for a stick that begins in "begin" and ends in "end" */
/* is the minimum cost of all inner sticks (the left side plus the right side) */
/* plus the cost of the current stick */
int min_cost(int begin, int end)
{
	int i, min_candidate;	
	/* Base case for recursion */
	if(begin+1==end) {
		cost[begin][end]=0;
	} else if(cost[begin][end]==INF) {
		/* Find the minimum from all candidates/inner_sticks */
		for(i=begin+1; i<end; i++){
			min_candidate = min_cost(begin,i) + min_cost(i,end) + cut[end]-cut[begin];
			if(min_candidate < cost[begin][end])
				cost[begin][end] = min_candidate;
		}
	}
	return cost[begin][end];
}

void clear()
{
	int i,j;
	for(i=0;i<=N+1;i++)
		for(j=0;j<=N+1;j++)
			cost[i][j]=INF;
	cut[0]=0;
	cut[N+1]=L;
}
int main()
{
	int i;
	while(scanf("%d", &L) && L)
	{
		scanf("%d", &N);
		for(i=1;i<=N;i++)
			scanf("%d",&cut[i]);
		clear();
		printf("The minimum cutting is %d.\n", min_cost(0,N+1));
	}
	return 0;
}