#include <cstdio>
#include <cstring>
#define NN 501
#define MM 1000000009
int N;
int M[NN][NN];
int B[NN][NN];
char in[NN];
int dp(int i, int j){
	if(i >= N || j >= N)
		return 0;
	if(M[i][j] != -1)
		return M[i][j];
	if(i == N - 1 && j == N - 1)
		return 1;
	if(B[i][j] == 0)
		return 0;
	return M[i][j] = ((dp(i + B[i][j], j) % MM) + (dp(i, j + B[i][j]) % MM)) % MM;
}
int main(){
	while(fgets(in,NN,stdin) != NULL){ 
		sscanf(in, "%d", &N);
		
		for(int i = 0; i < N; i++){
			fgets(in,NN,stdin);
			for(int j = 0; j < N; j++){
				B[i][j] = in[j] - '0';
				M[i][j] = -1;
			}
		}
		printf("%d\n", dp(0,0));
	}
	return 0;
}