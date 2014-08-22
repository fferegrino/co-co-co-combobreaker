#include <cstdio>
#include <map>
#define ull unsigned long long int
using namespace std;
map<ull, int> m;
ull q(int x, int y){
	return (((ull) x) << 32ll) + (ull)y;
}

int main() {
	int N, K, x, y;
	scanf("%d %d", &N, &K); N++; K++;
	while(--N){
		scanf("%d %d", &x, &y);
		m[q(x,y)] = 1;
	}
	while(--K){
		scanf("%d %d", &x, &y);
		if(!m[q(x,y)]) printf("1\n");
		else printf("0\n");
	}
	return 0;
}