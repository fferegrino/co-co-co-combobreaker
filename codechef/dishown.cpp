#include <cstdio>
#define MDISH 10001

using namespace std;

int result = -1;
int root(int n);
bool join(int a, int b);

int dishes[MDISH];
int padres[MDISH];

int main() {
	int T, N, x, y, Q, q;
	scanf("%d", &T); T++;
	while(--T){
		scanf("%d", &N);
		for(int i = 1; i <= N; i++){
			scanf("%d", &dishes[i]);
			padres[i] = i;
		}
		scanf("%d", &Q); Q++;
		while(--Q){
			scanf("%d %d", &q, &x);
			if(q){
				printf("%d\n", root(x));
			}else{
				scanf("%d", &y);
				join(x, y) ? 0 : printf("Invalid query!\n");
			}
		}
	}
	
	return 0;
}

int root(int n){
	if(padres[n] != n)
		padres[n] = root(padres[n]);
	return padres[n];
}

bool join(int a, int b){
	int p1 = root(a);
	int p2 = root(b);
	int dv1 = dishes[p1];
	int dv2 = dishes[p2];
	if(p1 != p2){
		if(dv1 > dv2){
			padres[p2] = padres[p1];
		}else if(dv2 > dv1){
			padres[p1] = padres[p2];
		}
		return true;
	}
	return false;
}