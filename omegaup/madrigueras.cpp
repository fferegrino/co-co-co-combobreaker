#include <cstdio>
#include <utility>
#define MAX 100004
#define nodos first
#define aristas second
#define MOD (long long int)1000000007
using namespace std;
int p[MAX];
pair<int,int> rec[MAX];
bool pasada[MAX];
int root(int n){
		if(p[n] != n) 
			p[n] = root(p[n]);
	return p[n];
}
int join(int i, int j){
	int pi = root(i);
	int pj = root(j);
	rec[pi].aristas += 1;
	if(pi != pj){
		p[pj] = p[pi];
		rec[pi].nodos += rec[pj].nodos;
		rec[pi].aristas += rec[pj].aristas;
	}	
	return 0;
}
int N, M;
int a, b;
int main(){
	scanf("%d%d",&N,&M);
	for(int i = 0; i <= N; i++){
		p[i] = i;
		rec[i].nodos = 1;
		rec[i].aristas = 0;
	}
	for(int i = 0; i < M; i++){
		scanf("%d%d",&a,&b);
		join(a,b);
	}
	long long int res = 1;
	int P= 0,  j = 1;
	while(j <= N){
		P = root(p[j]);
		if(rec[P].aristas == rec[P].nodos){
			if(!pasada[P]){
				pasada[P] = true;
				res = ((res % MOD) * 2) % MOD;
			}
		}else if(rec[P].aristas == rec[P].nodos -1 ){
			if(!pasada[P]){
				pasada[P] = true;
				res = ((res % MOD )* (rec[P].nodos % MOD)) % MOD;
			}
		}else{
			res = 0; break;
		}
		while(root(p[j]) == P && j <= N) j++;
	}
	printf("%lld\n", res % MOD);
	return 0;
}