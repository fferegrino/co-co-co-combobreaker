#include <cstdio>
#define M 2000010
using namespace std;
int cr[M];
int main() {
	int l, h, count = 0;
	for(int i = 1; i < M; i++){
		for(int j = 1; j * i < M; j++){
			cr[j * i]++;
		}
	}
	scanf("%d %d", &l, &h);
	while(l <= h){
		if(l % cr[l++] == 0)
			count++;
	}
	printf("%d\n", count);
	return 0;
}
