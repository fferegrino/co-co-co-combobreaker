#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 502
#define nodo first
#define cord second
#define x first
#define y second
using namespace std;
pair<int, pair<int, int> > nodos[MAX];
int padres[MAX];
//int nodos[MAX];
struct cable{
	int a, b;
	double d;
	bool ob;
	bool operator<(const cable &n) const
	{
		if(ob == n.ob){
			return d < n.d;
		}
		else{
			return ob;
		}
	}
};


int root(int n){
	if(padres[n] != n)
		padres[n] = root(padres[n]);
	return padres[n];
}

double join(cable c){
	int p1 = root(c.a);
	int p2 = root(c.b);
	if(p1 != p2){
		padres[p1] = padres[p2];
		return c.d;
	}else if (c.ob){
		return c.d;
	}
	return 0;
}

double calcD(int i, int j){
	double pr = (((double)nodos[i].cord.x) - ((double)nodos[j].cord.x));
	double sd = (((double)nodos[i].cord.y) - ((double)nodos[j].cord.y));
	double d = sqrt((pr*pr) + (sd*sd));
	return d;
}

int main(){
	int N, Q, k, x, y;
	vector<cable> cables;
	scanf("%d", &N);
	for(int i = 0; i < MAX; i++){
		padres[i] = i;
	}
	for(int i = 1; i <= N; i++){
		scanf("%d",&k);
		nodos[k].nodo = k;
		scanf("%d%d", &(nodos[k].cord.x),  &(nodos[k].cord.y));
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(j == i) continue;
			cable c;
			c.a = i;
			c.b = j;
			c.d = calcD(i,j);
			c.ob = false;
			cables.push_back(c);
		}
	}
	scanf("%d",&Q);
	while(Q--){
		scanf("%d %d", &x , &y);
		cable c;
		c.a = x;
		c.b = y;
		c.d = calcD(x,y);
		c.ob = true;
		cables.push_back(c);
	}
	sort(cables.begin(), cables.end());
	double ans = 0;
	for(int i = 0; i < cables.size(); i++){
		ans += join(cables[i]);;
	}
	printf("%.2f",ans);
	return 0;
}