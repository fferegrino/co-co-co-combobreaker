#include <cstdio>
#include <algorithm>
using namespace std;
int p;//[20];
int w;//[20][15];
int main() {
	int N, B, H, W, ans = 1 << 30;
	while(scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){
		ans = 1 << 30;
		for(int i = 0; i < H; i++){
			scanf("%d", &(p/*[i]*/));
			for(int j = 0; j < W; j++){
				scanf("%d", &w/*[i][j]*/);
				if(w >= N && p * N <= B) {
					ans = min(ans, p * N);
				}
			}
		}
		ans == 1 << 30 ? printf("stay home\n") : printf("%d\n", ans);
		if(feof(stdin))
			break;
	}
	return 0;
}
