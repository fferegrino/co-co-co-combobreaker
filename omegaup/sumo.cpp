#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int grupo [] = { 0, 2 , 1};

struct pelea{
	int destino;
	int ronda;
	bool operator==(const pelea& a) const
	{
		return destino == a.destino;
	}
};

vector<pelea> *g;
int * visita;
int rondaMaxima;

bool dfs(int nodo, int padre, int gpo){
	if(visita[nodo] > 0){
		if(visita[nodo] == gpo){
			return true;
		}
		return false;
	}
	visita[nodo] = gpo;
	bool posible = true;
	for(int i = 0; i < g[nodo].size() && posible; i++){
		if(g[nodo][i].destino != padre &&  g[nodo][i].ronda <= rondaMaxima)
			posible = posible && dfs(g[nodo][i].destino, nodo ,grupo[gpo]);
	}
	return posible;
}

int main(){
	int L, P, i, d, u, l;
	cin >> L >> P;	
	g = new vector<pelea>[L + 1];
	visita = new int[L + 1];
	memset(visita,0, sizeof(int) * (L + 1));
	int gpo = grupo[2];
	for(int ix = 1; ix <= P; ix++){
		cin >> i >> d;
		pelea p1;
		p1.ronda = ix;
		p1.destino = d;
		pelea p2;
		p2.ronda = ix;
		p2.destino = i;
		g[i].push_back(p1);
		g[d].push_back(p2);

	}
	
	u = 1; 
	l = P;
	while(u < l){
		rondaMaxima = (u + l) / 2;
		if(dfs(1,1,gpo))
			u = rondaMaxima + 1;
		else
			l = rondaMaxima;
		for(int v = 0; v < L+1; v++){
			visita[v] = 0;
		}
	}
	if(!dfs(1,1,gpo))
		cout << rondaMaxima;
	else
		cout << rondaMaxima + 1;
	return 0;
}