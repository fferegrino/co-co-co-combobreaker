#include <cstdio>
#include <algorithm>
#define MAX 100003

void p(long long int *arr, int n){
	for(int i = 0; i < n; i++){
		printf("%lld ", arr[i]);
	}
	printf("\n");
}

int main(){
	long long int o[MAX];
	/*long long int uno[MAX];*/
	/*long long int par[MAX];*/
	int N, K;
	
	long long int mx = -1 * ((long long int)1 << 33), tmx = -1 * ((long long int)1 << 33);
	
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; i++){
		scanf("%lld", &o[i]);
		mx = std::max(mx,o[i]);
	}
	if(K == 0)
		p(o,N);
	else if(K % 2 == 0){		
		for(int i = 0; i < N; i++){
			o[i] = mx - o[i];
			tmx = std::max(o[i],tmx);
		}
		for(int i = 0; i < N; i++){
			o[i] = tmx - o[i];
		}
		p(o,N);
	}
	else
	{
		for(int i = 0; i < N; i++){
			o[i] = mx - o[i];
		}
		p(o,N);
	}
}