#include <cstdio>
#include <algorithm>
#define MAX 2505
int mem[MAX][MAX];
int pre[MAX];
int N, M;

int dp(int pack, int total){
	if(total == N){
		return -pre[0];	
	}
	if(mem[pack][total] !=  1 << 28){
		return mem[pack][total];
	}
	if(pack + total < N){
		return mem[pack][total] = std::min(dp(1,total+pack) + pre[pack] + pre[0], dp(pack+1,total));
	} else {
		return mem[pack][total] = dp(1,total+pack) + pre[pack] + pre[0];
	}
}

int it(){
	for(int i = 0; i <= N; i++){
		mem[i][N] = -pre[0];
	}
	for(int total = N - 1; total >= 0; total--){
		for(int pack = N; pack > 0; pack--){			
			if(pack + total < N){
				mem[pack][total] = std::min(mem[1][total+pack] + pre[pack] + pre[0], mem[pack+1][total]);
			} else {
				mem[pack][total] = mem[1][total+pack] + pre[pack] + pre[0];
			}
		}
	}
}

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
	it();
	printf("%d\n",mem[1][0]);
	return 0;
}
