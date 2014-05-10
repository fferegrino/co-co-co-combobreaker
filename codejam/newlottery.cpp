#include <cstdio>


int main(){
	int T, A, B, K, ans, b;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++){
		ans = 0;
		b = 0;
		scanf("%d%d%d",&A,&B,&K);
		for(int ix = 0; ix < A && b < K; ix++){
			for(int jx = 0; jx < B && b < K; jx++){
				b = ix & jx;
				if(b < K)
					ans++;
			}
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}