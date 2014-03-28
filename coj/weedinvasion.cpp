#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 101
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
	p.x = wx -1;
	p.y = Y - wy;
	p.d = 0;
	printf("%d %d\n",p.x, p.y);
	puntos.push(p);
	while(!puntos.empty()){
		punto pto = puntos.front();
		puntos.pop();
		if(pto.x < 0 || pto.y < 0 || pto.x >= X || pto.y >= Y || farm[ pto.x][ pto.y] == '*')
			continue;
		visita[pto.x][pto.y] = true;
		for(int i = 0; i < 8; i++){
			punto pp;
			pp.x = pto.x + mx[i];
			pp.y = pto.y + my[i];
			if(!visita[pp.x][pp.y]){
				visita[pp.x][pp.y] = true;
				pp.d = pto.d + 1;
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
		printf("%s\n",farm[i]);
	}
	printf("%d",weed()-1);
	return 0;
}