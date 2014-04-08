#include <cstdio>
#include <vector>
#include <queue>
#define MAXC 10005
using namespace std;
struct Ciudad{
	int id, int d;
};
vector<int> g[MAXC];
queue<Ciudad> q;
int W[MAXC];
bool visita[MAXC];
int damage(int c, int d);
int N, w, Q, q, A, X, u, v, c = 0;
int main(){
	scanf("%d",&N);
	for(int x = 1; x <= N; x++)
		scanf("%d",&W[x]);
	for(int x = 1; x < N; x++){
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&q);
		if(q == 1){ // BOMB
			scanf("%d%d", &A, &X);
			damage(A, X);
		}
		else{
			scanf("A");
		}
	}
}
int damage(int c, int dam){
	Ciudad ciudad;
	ciudad.id = c;
	ciudad.d = 0;
	q.push(ciudad);
	while(!q.empty()){
		Ciudad at = q.front(); q.pop();
		if(W[at.id] > 0){
			W[at.id] -= d / (1 << at.d);
			if(W[at.id] <= 0) c++;
		}
		for(int i = 0; i < g[at.id].size(); i++){
			Ciudad city;
			city.d = at.d +1;
			city.id g[at.id][i].id;
			q.push(city);
		}
	}
}