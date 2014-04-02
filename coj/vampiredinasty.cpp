#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXN 1002
#define INF 1<<30
using namespace std;
int N, E, S, T;
int A, B, C, D;
void iniciar();
struct Nodo{
	int dest,sol,km;
	bool operator<(const Nodo &n) const
	{
		return (sol == n.sol) ? km < n.km : sol < n.sol;
	}
	Nodo operator+(const Nodo &n) const
	{
		Nodo temporal;
		temporal.dest = n.dest;
		temporal.sol = sol + n.sol;
		temporal.km = km + n.km;
		return temporal;
	}
};

Nodo crea(int n, int k, int s){
	Nodo ene;
	ene.dest = n;
	ene.km = k;
	ene.sol = s;
	return ene;
}

struct Compara
{
	bool operator()(const Nodo& a, const Nodo& b) const
	{
		return (a.sol == b.sol) ? a.km > b.km : a.sol > b.sol;
	}
};

Nodo rutas[MAXN];
bool visita[MAXN];
vector<Nodo> g[MAXN];
priority_queue<Nodo, vector<Nodo>, Compara> cola;

int main(){
	scanf("%d%d%d%d",&N,&E,&S,&T);
	for(int i = 0; i < E; i++){
        scanf("%d%d%d%d",&A,&B,&C,&D);        	    
        Nodo r1, r2;
        r1.dest = A; r1.km = C; r1.sol = C - D;
        r2.dest = B; r2.km = C; r2.sol = C - D;
        g[A].push_back(r2); 
		g[B].push_back(r1);
	}
    iniciar();
	Nodo r =crea(S,0,0);
	cola.push(r);
	rutas[S] = r;
	while(!cola.empty()){
		Nodo o = cola.top();
		cola.pop();
		if(o.dest == T) break;
		if(visita[o.dest]) continue;
		visita[o.dest] = true;
		for(int j = 0; j < g[o.dest].size(); j++){
			Nodo temp =  rutas[o.dest] + g[o.dest][j];
			if(!visita[temp.dest])
			{
				if(temp < rutas[g[o.dest][j].dest]){
					rutas[g[o.dest][j].dest] = temp;
					cola.push(temp);
				}
			}
		}
	}
	printf("%d %d\n",rutas[T].km,rutas[T].sol);
	return 0;
}


void iniciar(){
	for( int i = 0 ; i <= N ; ++i ){
		rutas[i] =crea(0,INF,INF);
		visita[i] = false;
	}
}
