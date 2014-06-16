#include <cstdio>
#include <algorithm>

long long int mcd(long long int x,long long int y){
  return (!y) ? x : mcd(y,x%y);
}
long long int pares(long long int N){
	return N / 2;
}
long long int impares(long long int N){
	int r = (N % 2) == 1 ? 1 : 0;
	return N /2 + r;
}
int main(){
	int T;
	long long int N, M;
	scanf("%d", &T);
	while(T--){
		scanf("%lld %lld", &N, &M);
		long long int total = N * M;
		long long int pN = pares(N), iN = impares(N), pM = pares(M), iM = impares(M);
		long long int r1 =  iM * pN;
		long long int r2 = pM * iN;
		long long int MCD = mcd(total, r1+r2);
		printf("%lld/%lld\n", (r1 + r2) / MCD, total / MCD);
	}
	return 0;
}