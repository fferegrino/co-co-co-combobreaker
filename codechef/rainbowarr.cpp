#include <cstdio>
#define L 7
#define MOD 1000000007
//#define DEBUG
//#define DP
int N, calls;
int T;
int R[] = {1,2,3,4,5,6,7};
int m[10][1000010];
bool par;
int dp(int i, int res){
	int ii = i, ress = res;
	#ifdef DP
	if(i == 7) { if(res) return 0; else return 1; }
	if(m[i][res] != -1) return m[i][res];
	if(res){
		return m[i][res] = (dp(i, res-1) % MOD + dp(i+1, res) % MOD) % MOD;
	}
	return m[i][res] = dp(i+1, res) % MOD;
	#else
	for(int i = 7; i >= 0; i--) {
		for(int res = 0; res <= ress; res++) {
			if(i == 7) { if(res) m[i][res] = 0; else m[i][res] = 1; continue; }
			if(res){
				m[i][res] = (m[i][res-1] % MOD + m[i+1][res] % MOD) % MOD;
			} else {
				m[i][res] = m[i+1][res] % MOD;
			}
		}
	}
	return m[ii][ress];
	#endif
}
int main(){
#ifdef DEBUG
	scanf("%d", &T);
#else 
	T = 1;
#endif
	while(T--){
		scanf("%d", &N);
		#ifdef DP
		for(int i  =0 ; i < 10; i++){
			for(int j = 0; j < 1000010; j++){
				m[i][j] = -1;
			}
		}
		#endif
		N++; N /= 2;
		if(N - L < 0) printf("0\n");
		else {
			#ifdef DEBUG
			printf("%d %d\n", N - L, dp(0,N - L));
			for(int i = 0; i < 7; i++) {
				for(int res = 0; res < 5; res++) {
					printf("%d ", m[i][res]);
				}
				printf("\n");
			}
			#else 
			printf("%d\n", dp(0,N - L) % MOD);
			#endif
		}
	}
	return 0;
}
