/*
* UVA-118: Mutant Flatworld Explorers
* ================================
* Author: Felipe Blassioli
* Date: 18/04/2014
* Description: Simulation
*/

#include <stdio.h>
#include <string.h>
#define MAX 55
#define MAX_INSTRUCTION 102

int X,Y; /* top grid coordinates */
int g[MAX][MAX];

char dirs[5] = "NESW";
int x,y; /* current robot position */
char d; /* current robot direction */
/* output */
int fd;
int lost;

void update(char c){
	int p,q;
	/*printf(" %c (%d,%d,%c) -> ",c,x,y,dirs[fd]);*/
	if(c=='R'){
		fd = (fd==3)? 0: fd+1;
	}else if(c=='L'){
		fd = (fd==0)? 3: fd-1;
	}else if(c=='F'){
		p=x; q=y;
		switch(dirs[fd]){
			case 'N': y++ ;break;
			case 'S': y--; break;
			case 'W': x--; break;
			case 'E': x++; break;
		}
		if(g[x][y]==0){
			if(g[p][q]!=2){
				lost=1;
				g[p][q]=2;
				/*printf("FELL from %d,%d at %d, %d\n",p,q,x,y);*/
			}
			x=p;y=q;
		}
	}
	/*printf("(%d,%d,%c)\n",x,y,dirs[fd]);*/
}

int main(){
	int i,j,len;
	char instr[MAX_INSTRUCTION];

	scanf("%d %d", &X, &Y);
	/* Prepare grid */
	/* 0 is ok. 1 is robot lost */
	X++; Y++;
	for(i=0; i<=X+1; i++){
		for(j=0;j<=Y+1;j++){
			g[i][j] = ((i>0 && i<=X) && (j>0 && j<=Y));
			/*printf("%d ",g[i][j]);*/
		}
		/*printf("\n");*/
	}
	while(1){
		scanf("%d %d %c", &x, &y, &d);
		getchar(); /* new line */
		if(fgets(instr, MAX_INSTRUCTION, stdin) == NULL) break;

		/*printf("%d %d %c\n", x,y,d);*/
		for(i=0;i<4;i++) 
			if(dirs[i]==d)
				fd = i;
		len = strlen(instr);
		lost = 0;
		x++; y++; /* we put borders in the grid */
		for(i=0; i<len-1;i++)
			if(lost) break; else update(instr[i]);
		x--; y--;
		if(lost)
			printf("%d %d %c LOST\n",x,y,dirs[fd]);
		else
			printf("%d %d %c\n",x,y,dirs[fd]);
		

		/*for(i=0; i<=X+1; i++){
			for(j=0;j<=Y+1;j++){
				printf("%d ",g[i][j]);
			}
			printf("\n");
		}*/
	}
	return 0;
}