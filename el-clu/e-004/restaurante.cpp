#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> answ;
int pl[1005];
int mem[90002][1003];
int maxsize;
int N, M;
int dp(int capac, int ix){
	if(ix == N)	return 0;
	if(capac == 0) return 0;
	if(mem[capac][ix] != -1) return mem[capac][ix];
	if(capac - pl[ix] < 0)
		return mem[capac][ix] = dp(capac, ix+1);
	return mem[capac][ix] = max(dp(capac, ix+1),dp(capac - pl[ix], ix+1)+1);
}
int main() {
	int i = 0, cap = 0, a;
	scanf("%d %d", &N, &M); 
	for(i = 0; i < N; i++){
		scanf("%d", &pl[i]);
	}
	for(i = 0; i < M; i++){
		scanf("%d", &a);
		cap += a;
	}
	/*
	for(i = 0; i <= N; i++)
		for(int j = 0; j <= cap; j++)
			mem[j][i] = -1;
	*/
	for(i = N; i > 0; i--){
		for(int j = 0; j < cap; j++){
			if(i == N){ mem[j][i] =  0; continue; }
			if(j == 0){ mem[j][i] =  0; continue; }
			//if(mem[j][i] != -1) return mem[capac][ix];
			if(j - pl[i] < 0)
				mem[j][i] = mem[j][i+1];
			else mem[j][i] = max(mem[j][i+1],mem[j - pl[i]][i+1]+1);
		}
	}
	int ans = mem[0][0]; //dp(cap, 0);
	printf("%d\n", ans);
	
	return 0;
}
