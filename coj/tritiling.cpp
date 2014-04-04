#include <cstdio>
using namespace std;
int N;
int m[10][35];
int dp(int bit, int n){
	if((bit == 0) && n == N){
		return 1;
	}else if(n == N){
		return 0;
	}
	if(m[bit][n] != -1) return m[bit][n];
	if(bit == 0)
		return m[bit][n] = (dp(1,n+1) + dp(4,n+1) + dp(7,n+1));
	if(bit == 1)
		return m[bit][n] = dp(0,n+1) + dp(6,n+1);
	if(bit == 6)
		return m[bit][n] = dp(1,n+1);
	if(bit == 4)
		return m[bit][n] = dp(0, n+1) + dp(3, n+1);
	if(bit == 3)
		return m[bit][n] = dp(4,n+1);
	if(bit == 7)
		return dp(0,n+1);
	return 0;
}

int main(){
	scanf("%d",&N);
	while(N >= 0){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 35; j++){
				m[i][j] = -1;
			}
		}
		printf("%d\n",dp(0,0));
		scanf("%d",&N);
	}
}