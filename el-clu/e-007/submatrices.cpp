#include <cstdio>
#define MX 1010
using namespace std;
int N[MX][MX], M[MX][MX], R[MX][MX], ren, col, r, c, ii,jj;
int main() {
	bool matr;
	scanf("%d%d", &ren, &col);
	for(int i = 0; i < ren; i++)
		for(int j = 0; j < col; j++)
			scanf("%d", &N[i][j]);
	scanf("%d%d", &r, &c);
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			scanf("%d", &M[i][j]);
	for(int i = 0; i <= (ren - r); i++){
		for(int j = 0; j <= (col - c); j++){
			jj = ii = 0;
			if(N[i][j]== M[ii][jj]){
				matr = true;
				for(ii = 0; ii < r && matr; ii++){
					for(jj = 0; jj < c && matr; jj++){
						if(N[i+ii][j+jj] != M[ii][jj]){
							matr = false;
							break;
						}
					}
				}
				if(matr) {
					for(ii = 0; ii < r && matr; ii++){
						for(jj = 0; jj < c && matr; jj++){
							R[i+ii][j+jj] = 1;
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < ren; i++) {
		for(int j = 0; j < col; j++) {
			printf("%d ", R[i][j]);
		}
		printf("\n");
	}
	return 0;
}