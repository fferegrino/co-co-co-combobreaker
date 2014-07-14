#include <cstdio>
#include <algorithm>
#include <utility>
#define lugar second
#define distancia first
#define NN 100002

typedef std::pair<int,int> rana;
rana ranas[NN];
int padres[NN];
int N, K, P;

int root(int n){
	if(padres[n] != n)
		padres[n] = root(padres[n]);
	return padres[n];
}

bool join(int a, int b){
	int p1 = root(a);
	int p2 = root(b);
	if(p1 != p2){
		padres[p1] = padres[p2];
		return true;
	}
	return false;
}

bool operator <(const rana& l,const rana& r){
	return l.distancia < r.distancia;
}

int main(){
	int a, b;
	scanf("%d%d%d", &N, &K, &P);
	for(int i = 1; i <= N; i++){
		padres[i] = i;
		scanf("%d", &ranas[i].distancia);
		ranas[i].lugar = i;
	}
	std::sort(ranas+1, ranas+N+1);
	for(int i = 1; i < N; i++){
		if(ranas[i + 1].distancia - ranas[i].distancia <= K){
			join(ranas[i + 1].lugar, ranas[i].lugar);
		}
	}
	for(int i = 0; i < P; i++){
			scanf("%d%d", &a, &b);
			root(a) == root(b) ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}

