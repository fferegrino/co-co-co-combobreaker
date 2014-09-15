#include <cstdio>
#define MP 510
using namespace std;
int P, F, C, x, y;
int f[MP];
int cc[MP][MP];
int main() {
	scanf("%d%d%d", &P, &F, &C);
	for(int i = 0; i < F; i++)
		scanf("%d", &f[i]);
	for(int i = 1; i <= P; i++)
		for(int j = 1; j <= P; j++)
			cc[i][j] = 1 << 15;
	for(int i = 1; i <= P; i++)
		cc[i][i] = 0;
	for(int i = 0; i < C; i++) {
		scanf("%d%d", &x, &y);
		scanf("%d", &cc[x][y]);
		cc[y][x] = cc[x][y];
	}
	for(int i = 1; i <= P; i++)
		for(int j = 1; j <= P; j++)
			for(int k = 1; k <= P; k++)
				if(cc[j][k] > cc[j][i] + cc[i][k])
					cc[j][k] = cc[j][i] + cc[i][k];
	
	int ix = 0, mx = 1 << 30, ax = 0;
	for(int i = 1; i <= P; i++){
		ax = 0;
		for(int j = 0; j < F; j++){
			ax += cc[i][f[j]];
		}
		if(mx > ax){
			ix = i;
			mx = ax;
		}
	}	
	printf("%d\n", ix);
	return 0;
}