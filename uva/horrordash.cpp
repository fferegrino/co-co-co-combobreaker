#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int m = 0, N, n, a;
	scanf("%d", &N); N++;
	for(int i = 1; i < N; i++){
		m = 0;
		scanf("%d", &n); n++;
		while(--n){
			scanf("%d", &a);
			m = max(a, m);
		}
		printf("Case %d: %d\n", i, m);
	}
	return 0;
}