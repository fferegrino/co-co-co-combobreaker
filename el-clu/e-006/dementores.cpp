#include <cstdio>
#include <algorithm>
#define M 1002
#define DER 0
#define IZQ 1
using namespace std;
int N, O, x, y;
bool o[M][M];
int d[M][M];
int dirs[] = {IZQ, DER};

void clean();
void bfs(int x, int y, int qty, int dir);
int exec(int dir);

int main(){
	int dir = 0, countI = 0, countD = 0;
	scanf("%d %d", &N, &O); O++;
	while(--O){
		scanf("%d %d", &x, &y);
		o[y][x] = true;
	}
	countI = exec(IZQ);
	countD = exec(DER);
	printf("%d\n", min(countI, countD));
	return 0;
}

void bfs(int x, int y, int qty, int dir){
	d[x][y] += qty;
	if(dir == DER){
		if(x+1 != N)
			if(o[x+1][y]) {
				bfs(x+1, y, 0,dir);
			} else {
				bfs(x+1, y, d[x][y],dir);
				d[x][y] = 0;
			}	
	}else{
		if(y+1 != N)
			if(o[x][y+1]) {
				bfs(x, y+1, 0,dir);
			} else {
				bfs(x, y+1, d[x][y],dir);
				d[x][y] = 0;
			}		
	}
}

int exec(int dir){
	int count = 0;
	clean();
	while(d[N-1][N-1] != 2 * N -1){
		for(int i = 0; i < N; i++){
			if(dir == IZQ)
				bfs(i,0,0,dir);
			else
				bfs(0,i,0,dir);
		}
		dir = dirs[dir];
		count++;
	}
	return count;
}

void clean(){
	for(int i = 0; i < N; i++){
		d[i][0] = 1;
		d[0][i] = 1;
	}	
	d[N-1][N-1] = 0;
}
