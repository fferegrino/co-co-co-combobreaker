#include <cstdio>
using namespace std;
int main() {
	long long int N, M, DN, q, ans = 0;
	scanf("%lld%lld", &N, &M);
	DN = (2*N) +1;
	while(M--){
		scanf("%lld", &q);
		if(N+2 <= q && q <= N + 2*N){
			if(q == DN){
				ans = N;
			}else{
				if(q < DN){
					ans = N - (DN - q);
				}
				else{
					ans = N - (q - DN);
				}
			}
		}else{ ans = 0; }
		printf("%lld\n", ans);
	}
	return 0;
}