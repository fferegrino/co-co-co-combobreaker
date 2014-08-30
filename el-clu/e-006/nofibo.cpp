#include <cstdio>
#include <bitset>
#define M 30023
using namespace std;
int f[M];
bitset<M> c;
int main() {
	int N, i = 0;
	scanf("%d", &N);
	f[0] = f[1] = 1;
	c[0] = 1; c[1] = 1;
	for(i = 2; i < M; i++){
		f[i] = f[i - 1] + f[i - 2];
		if(f[i] >= M) break;
		c[f[i]] = 1;
	}
	i = 0;
	while(i < N){
		if(!c[i]){
			printf("%d ", i);
		}
		i++;
	}
	printf("\n");
	return 0;
}
