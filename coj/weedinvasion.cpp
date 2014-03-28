#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 109
using namespace std;
char farm[MAX][MAX];
bool visita[MAX][MAX];
struct punto{
	int x;
	int y;
	int d;
};
queue<punto> puntos;

int mx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int my[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int X, Y, wx, wy;
int weed(){
	int w = 0;
	punto p;
	p.x = Y - wy;
	p.y = wx -1;
	p.d = 0;
	puntos.push(p);
	while(!puntos.empty()){
		punto pto = puntos.front();
		puntos.pop();
		visita[pto.x][pto.y] = true;
		for(int i = 0; i < 8; i++){
			punto pp;
			pp.x = pto.x + mx[i];
			pp.y = pto.y + my[i];
			if(!visita[pp.x][pp.y]){
				pp.d = pto.d + 1;
				if(pp.x < 0 || pp.y < 0 || pp.y >= X || pp.x >= Y){
					continue;
				}
				if(farm[pp.x][pp.y] != '.'){
					continue;
				}
				visita[pp.x][pp.y] = true;
				w = pp.d >= w ? pp.d : w;
				puntos.push(pp);
			}
		}
	}
	return w;
}

int main(){
	scanf("%d%d%d%d",&X,&Y,&wx,&wy);
	for(int i = 0; i < Y; i++){
		scanf("%s",farm[i]);
	}
	printf("%d",weed());
	return 0;
}