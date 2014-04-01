#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXM 20000
#define MAXN 1002
using namespace std;
int root(int n);
bool join(int n01, int n02);
int M,N,C;
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
		printf("Juntando %d con %d\n",cables[i].a,cables[i].b);
		if(join(cables[i].a,cables[i].b)){
			printf("%d\n", cables[i].c);
		}
	}
	return 0;
}

int root(int n){
	int padre = 0;
	if(padres[n] != n){
		padres[n] = root(n);
	}
	padre = padres[n];
	return padre;
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

