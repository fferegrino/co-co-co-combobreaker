#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 109
using namespace std;
vector<int> diferencias;
int partidos, goles;
int main(){
	scanf("%d%d",&partidos,&goles);
	int m, n, puntos = 0;
	for(int i = 0; i < partidos; i++){
		scanf("%d%d",&m,&n);
		if(n - m >= 0)
			diferencias.push_back(n-m);
		else
			puntos+=3;
	}
	sort(diferencias.begin(), diferencias.end());
	for(int i= 0; i < diferencias.size() /*&& goles*/; i++){
		int ganar = diferencias[i] + 1;
		
		if(goles >= ganar){
			puntos += 3;
			goles-= ganar;
		}
		else if(diferencias[i] ==  goles){
			puntos+=1;
			goles-= diferencias[i];
		}
	}
	printf("%d\n",puntos);
	return 0;
}