#include <cstdio>
#include <algorithm>

int main(){
	int T, x, y, res;
	scanf("%d", &T); T++;
	while(--T){
		res = 0;
		scanf("%d%d", &x, &y);
		x = abs(x); y = abs(y);
		if(x == y) res = x + y;
		else if(x < y){
			res += y % 2 == 0 ? y * 2 : (y - 1) * 2 + 1;
			res += x % 2 == 0 ? 0 : y % 2 == 0 ? -1 : 1;
		} else {
			res += x % 2 == 0 ? x * 2 : (x + 1) * 2 - 1;
			res += y % 2 == 0 ? 0 : x % 2 == 0 ? 1 : -1;
		}
		printf("%d\n", res);
	}
}