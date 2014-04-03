#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXF 502
#define I 1<<30
using namespace std;
struct Campo{
	int id, t;
	vector<int> vacas;
	vector<Campo> vecinos;
	
	bool operator<(const Campo &n) const
	{
		return t > n.t;
	}
};

void dj();
Campo g[MAXF];
int d[MAXF];
bool visita[MAXF];
priority_queue<Campo> Q;
int F, P, C, M;

int main(){
	scanf("%d%d%d%d",&F,&P,&C,&M);
	vector<int> culpables;
	int id;
	for(int i = 1; i <= F; i++)
		g[i].id = i;
	for(int i = 0; i < P; i++){
		scanf("%d",&id);
		Campo c, c2;
		scanf("%d%d",&c.id,&c.t);
		g[id].vecinos.push_back(c);
		c2.id = id;
		c2.t = c.t;
		g[c.id].vecinos.push_back(c2);
	}
	for(int i = 1; i <= C; i++){
		scanf("%d",&id);
		g[id].vacas.push_back(i);
	}
	dj();
	for(int i = 1; i <= F; i++){
		if(d[i] <= M && d[i] >= 0){
			for(int j = 0; j < g[i].vacas.size(); j++)
				culpables.push_back(g[i].vacas[j]);
		}
	}
	sort(culpables.begin(), culpables.end());
	printf("%d\n",culpables.size());
	for(int i = 0; i < culpables.size(); i++){
		printf("%d\n",culpables[i]);
	}
	return 0;
}

void dj(){
	for(int i = 0; i <= F; i++){
		visita[i] = false;
		d[i] = I;
	}
	g[1].t = 0;
	Q.push(g[1]);
	d[1] = 0;
	while(!Q.empty()){
		Campo ac = Q.top();
		Q.pop();
		if(visita[ac.id]) continue;
		visita[ac.id] = true;
		ac = g[ac.id];
		for(int i = 0; i < ac.vecinos.size(); i++){
			if(!visita[ac.vecinos[i].id]){
				if(d[ac.id] + ac.vecinos[i].t < d[ac.vecinos[i].id]){
					d[ac.vecinos[i].id] = d[ac.id] + ac.vecinos[i].t;
					Q.push(ac.vecinos[i]);
				}
			}
		}
	}
}