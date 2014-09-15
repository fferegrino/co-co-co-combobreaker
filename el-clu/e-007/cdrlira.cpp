#include <cstdio>
#include <algorithm>
using namespace std;
int M, B, N;
int vc[55];
int m[55][1010];
int dp(int i, int v) {
	if(i == N){ if(v < 0 || v > M) return -1; else return v; }
	if(v < 0 || v > M) return -1;
	if(m[i][v] != -10) return m[i][v];
	return m[i][v] = max(dp(i+1, v - vc[i]), dp(i+1, v + vc[i]));
}
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", &vc[i]);
	scanf("%d%d", &B, &M);
	for(int i = 0; i < 55; i++)
		for(int j = 0; j < 1010; j++)
			m[i][j] = -10;
	printf("%d", dp(0, B));
	return 0;
}