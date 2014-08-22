#include <cstdio>
#define ll unsigned long long int
#define u 1ll
int main(){
	ll ans, n, uno = u;
	ll i = 0;
	scanf("%lld", &n);
	 for(; i <= 63ll; i++){
		  if(n < (uno << i))
			  break;
 	}
	ans = n - ((uno << (i - 1ll)) - 1ll);
	printf("%lld %lld\n", ans % 10, ans);
}