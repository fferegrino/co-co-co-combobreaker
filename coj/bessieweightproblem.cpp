#include <cstdio>
#include <algorithm>
#define MAXN 502
#define MAXK 45002
using namespace std;
int p[MAXN];
int m[MAXN][MAXK];
int H, N;
int main(){
	scanf("%d%d",&H,&N);
	for(int k = 0; k <= H; k++)
		m[N][k] = k;
	for(int i = 0; i <= N; i++)
		m[i][H] = H;
	for(int i =0; i < N; i++)
		scanf("%d",&p[i]);
	for(int i = N-1; i >= 0; i--)
		for(int k = 0; k < H; k++)
			if(k + p[i] <= H)
				m[i][k] = max(m[i+1][k+p[i]],m[i+1][k]);
			else 
				m[i][k] = m[i+1][k];
	printf("%d\n",m[0][0]);
	return 0;
}