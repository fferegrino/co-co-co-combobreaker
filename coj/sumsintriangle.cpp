#include <cstdio>
#include <algorithm>
#define MN 102
int tri[MN][MN];
int mem[MN][MN];
int N;
int dp(int nivel, int i){
	if(nivel == N)
		return 0;
	if(mem[nivel][i] != -1)
		return mem[nivel][i];
	if(i + 1 <= nivel)
		return mem[nivel][i] = std::max( 
				dp(nivel+1, i) + tri[nivel][i], 
				dp(nivel+1, i + 1) + tri[nivel][i+1] );
	else
		return mem[nivel][i] = dp(nivel+1, i) + tri[nivel][i];
}

int main(){
	int T;
	scanf("%d", &T); T++; 
	while(--T){
		scanf("%d", &N);
		for(int i = 0; i <= N; i++)
			for(int j = 0; j <= N; j++)
				mem[i][j] =  -1;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < i + 1; j++)
				scanf("%d", &tri[i][j]);
		printf("%d\n", dp(0,0));
	
	}
}