#include <cstdio>
#define M 1001
int mat[M][M];
int col[M];
int row[M];
char cmd[2];
int m, n, k, x, y;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < M; i++){ col[i] = i; row[i] = i; }
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			scanf("%d",&mat[i][j]);
		}
	while(k--){
		scanf("%s%d%d", cmd, &x, &y);
		if(cmd[0] == 'g'){
			printf("%d\n",mat[row[x]][col[y]]);
		}
		else if(cmd[0] == 'r'){
			int a = row[y];
			row[y] = row[x];
			row[x] = a;
		}
		else if(cmd[0] == 'c'){
			int a = col[y];
			col[y] = col[x];
			col[x] = a;
		}
	}
}