#include <cstdio>
#define NMAX 1005
#define MMAX 20
using namespace std;
int N;
int m[MMAX][NMAX];
int dp(int bit, int n){
	if((bit == 0) && n == N){
		return 1;
	}else if(n == N){
		return 0;
	}
	if(m[bit][n] != -1) return m[bit][n];
	if(bit == 0)
		return m[bit][n] = (dp(0,n+1) + dp(12,n+1) + dp(15,n+1) + dp(3,n+1) + dp(9,n+1));
	if(bit == 9)
		return m[bit][n] = dp(0,n+1) + dp(6,n+1);
	if(bit == 6)
		return m[bit][n] = dp(9,n+1);
	if(bit == 3)
		return m[bit][n] = dp(12,n+1) + dp(0,n+1);
	if(bit == 12)
		return m[bit][n] = dp(0,n+1) + dp(3,n+1);
	if(bit == 15)
		return dp(0,n+1);
	return 0;
}

int main(){
	int x;
	scanf("%d",&x);
	for(int ix = 1; ix <= x; ix++){
		scanf("%d",&N);
		for(int i = 0; i < MMAX; i++){
			for(int j = 0; j < NMAX; j++){
				m[i][j] = -1;
			}
		}
		printf("%d %d\n", ix, dp(0,0));
	}
}