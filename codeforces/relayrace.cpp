#include <cstdio>
#include <algorithm>
#define MAX 303
#define INF 1<<30
using namespace std;
int tab[MAX][MAX];
int mem[MAX][MAX][MAX];
int n;
int rr(int d, int i, int x){
	int j = d - i;
	int y = d - x;
	if(j == n-1 && i == n-1){
		return tab[i][j];
	}
	if(j == n || i == n || x == n || y == n)
		return -1 * INF;
	
	if(mem[d][i][x] != INF)
		return mem[d][i][x];
		
	if(i == x && j == y){
		return mem[d][i][x] = max(
					max(rr(d+1,i+1,x+1),
						rr(d+1,i,x+1)),
					max(rr(d+1,i+1,x), 
						rr(d+1,i,x))) + tab[i][j];
	}
	else{
		return 	mem[d][i][x] = max(
					max(rr(d+1,i+1,x+1),
						rr(d+1,i,x+1)),
					max(rr(d+1,i+1,x), 
						rr(d+1,i,x))) + tab[i][j] + tab[x][y];
	}
}
int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d",&tab[i][j]);
			
	for(int i = 0; i < MAX; i++)
		for(int j = 0; j < MAX; j++)
			for(int k = 0; k < MAX; k++)
				mem[i][j][k] = INF;
				
	printf("%d\n",rr(0,0,0));
	return 0;
}