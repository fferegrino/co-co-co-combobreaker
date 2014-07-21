#include <cstdio>
#define NN 10005
using namespace std;

int main() {
	int T, N, a, c;
	bool v[NN];
	scanf("%d", &T); T++;
	while(--T){
		c = 0;
		scanf("%d", &N);
		for(int i = 0; i < NN; i++){
			v[i] = false;
		}
		for(int i = 0; i < N; i++){
			scanf("%d", &a);
			if(!v[a]){
				v[a]= true;
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}