#include <cstdio>
#include <algorithm>
#define MAX 2505
int mem[MAX][MAX];
int pre[MAX];
int N, M;
/*
int dp(int pack, int total){
	//printf("\t%d %d\n", pack, total);
	if(total == N){
		return -pre[0];
	}
	if(total > N){
		return 1 << 28;
	}
	int mx = 1 << 28;
	if(mem[pack][total] != -1){
		return mem[pack][total];
	}
	for(int i = pack+1; i <= N - total; i++){
		int dpp = dp(i, total + i) + pre[i] + pre[0];
		mx = std::min(mx, dpp);
	}
	return mem[pack][total] = mx;
	return mx;
}
*/
int main(){
	scanf("%d%d",&N,&pre[0]);
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			mem[i][j] = 1 << 28;
		}
	}
	for(int i = 1; i <= N; i++){
		scanf("%d",&pre[i]);
		pre[i] += pre[i-1];
	}
	for(int i = 0; i <= N+1; i++){
		mem[i][N] = -pre[0];
	}
	
	for(int total = N-1; total >= 0; total--){
		for(int pack = 0; pack < N ; pack++){
		
			
			for(int i = pack+1; i <= N - total; i++){
				mem[pack][total] = std::min(mem[pack][total], mem[i][total + i] + pre[i] + pre[0]);
			}
			
			/*
			int i = pack +1;
			mem[pack][total] = std::min(mem[pack][total], mem[i][total + i] + pre[i] + pre[0]);
			*/
		}
	}
	for(int i = 0; i < N; i++){
		printf("%d ",pre[i]);
	}
	
	printf("\n");
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%10d " , mem[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", mem[0][0]);
	return 0;
}
