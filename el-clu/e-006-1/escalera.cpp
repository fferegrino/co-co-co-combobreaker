#include <cstdio>
#define M_N 10002
#define M_k 102
#define lli long long int
lli m[M_N];
lli N, k;
lli dp(lli r);
int main(){
	scanf("%lld%lld", &N, &k);
	for(int i = 0; i <= N; i++) m[i] = -1;
	printf("%lld\n", dp(N));
}

lli dp(lli r) {
	if(r == 0) return 1;
	lli ans = 0;
	if(m[r] != -1) return m[r];
	for(int i = 1; i <= k; i++)
		if(r - i >= 0)
			ans += dp(r - i);
	return m[r] = ans;
}
