#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T, i = 1, a, b, c;
	scanf("%d", &T); T++;
	for(;i < T; i++){
		scanf("%d %d %d", &a, &b, &c);
		printf("Case %d: %d\n", i,(a+b+c) - min(a, min(b,c)) - max(a,max(b,c)));
	}
	return 0;
}