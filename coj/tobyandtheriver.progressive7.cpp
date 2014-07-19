#include <cstdio>
#define M 6
int dogz[M];
int mid;
int dp(int peso, int i){
	if(peso == mid)
		return 1;
	if(i == M)
		return 0;
	if(dogz[i] + peso <= mid)
		return dp(peso+dogz[i],i+1) + dp(peso, i+1); 
	return dp(peso, i+1);
}

int main(){
	int T, sum;
	scanf("%d", &T);
	while(T--){
		sum = 0;
		for(int i = 0; i < M; i++){
			scanf("%d", &dogz[i]);
			sum += dogz[i];
		}
		mid = sum / 2;
		mid * 2 == sum && dp(0,0) > 0 ? printf("Tobby puede cruzar\n") : printf("Tobby no puede cruzar\n");
	}
	return 0;
}
