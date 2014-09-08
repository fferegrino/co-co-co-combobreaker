#include <cstdio>
#include <cstring>
#define MM 1000010
#define lli long long int
char M[MM];
lli ans, N, m;
int main(void) {
	scanf("%lld %lld", &N, &m);
	scanf("%s", M);
	ans = 1; N = N % m;
	for(int l = 0; M[l]; l++){
		ans = (ans % m * ans % m) % m;
		if(M[l] == '1')
			ans = (ans % m * N  % m) % m;
	}
	printf("%lld", ans % m);
	return 0;
}
