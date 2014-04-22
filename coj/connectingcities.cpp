#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 2003
using namespace std;
int padres[MAXN];
int T, N, M;
long long int C;
struct road{
	int a,b;
	long long int c;
	bool operator<(const road &n) const
	{
		return c < n.c;
	}
};
int root(int n);
bool join(road r);
int main(){
	scanf("%d",&T);
	while(T--){
		long long int ans = 0;
		long long int roadCost = 0;
		vector<road> car;
		scanf("%d%d%lld", &N, &M, &C);
		while(M--){
			road r;
			scanf("%d%d%lld", &r.a, &r.b, &r.c);
			car.push_back(r);
		}
		sort(car.begin(), car.end());
		ans = ((long long int)N) * C;
		for(int i = 0; i < MAXN; i++){
			padres[i] = i;
		}
		int airports = N;
		for(int i = 0; i < car.size(); i++){
			if(join(car[i])){
				roadCost += car[i].c;
				airports--;
				ans = min(ans, roadCost + airports * C);
			}
		}
		if(airports == 1)
			ans = min(ans, roadCost);
		
		printf("%lld\n",ans);
	}
}


int root(int n){
	if(padres[n] != n)
		padres[n] = root(padres[n]);
	return padres[n];
}

bool join(road r){
	int p1 = root(r.a);
	int p2 = root(r.b);
	if(p1 != p2){
		padres[p1] = padres[p2];
		return true;
	}
	return false;
}