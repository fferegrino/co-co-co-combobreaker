#include <stdio.h>

int main(void) {
		int T, N, n, x;
		long long int res;
		char scan[100002] ;
		scanf("%d", &T); T++;
		while(--T){
			x = 0; res = 0;
			scanf("%d %s", &N, scan);
			for(int xx = 0; xx < N; xx++) { x += scan[xx] == '1' ? 1 : 0; }
			for(int j = 1; j <= x; j++){
				for(int i = 0; i + j <= x; i++){
					res++;
				}
			}
			printf("%lld\n", res);
		}
	return 0;
}
