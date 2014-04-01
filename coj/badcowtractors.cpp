#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 1002
using namespace std;
int root(int n);
bool join(int n01, int n02);
int M,N;
int padres[MAXN];
struct cable{
	int a,b,c;
	bool operator<(const cable &c2) const
	{
		return c > c2.c;
	}
};
vector<cable> cables;

int main(){
	long long int costo = 0;
	int nodos = 0;
	scanf("%d%d",&N,&M);
	for(int i = 0; i <= N; i++){
		padres[i] = i;
	}
	for(int i = 0; i < M; i++){
		cable c;
		scanf("%d%d%d",&c.a,&c.b,&c.c);
		cables.push_back(c);
	}
	sort(cables.begin(),cables.end());
	for(int i = 0; i < M; i++){
		if(join(cables[i].a,cables[i].b)){
			nodos++;
			costo += cables[i].c;
		}
	}
	if(nodos == N-1){
		printf("%lld\n",costo);
	}
	else
		printf("-1\n");
	return 0;
}

int root(int n){
	if(padres[n] != n)
		padres[n] = root(padres[n]);
	return padres[n];
}

bool join(int n01, int n02){
	int p1 = root(n01);
	int p2 = root(n02);
	if(p1 != p2){
		padres[p1] = padres[p2];
		return true;
	}
	return false;
}
