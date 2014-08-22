// This code gives Partially Answered with 90% on OmegaUp
#include <cstdio>
#include <algorithm>
#define MAX 1010
using namespace std;
int sc[MAX];
int q[MAX][MAX];
int m[MAX][MAX];
int N;
int query(int i, int j){
	if(i == N || j == N) 
		return 0;
	else {
		return m[i][j];
	}
}
int main() {
	scanf("%d", &N);
	for(int i = 0;  i < N; i++){
		for(int j = 0;  j < N; j++){
			scanf("%d", &q[i][j]);
			m[i][j] = 0;
		}
	}
	for(int i = N -1; i >= 0; i--){
		for(int j = N - 1; j >= 0; j--){
			if(!q[i][j]){
				m[i][j] = min(query(i+1,j), min(query(i+1, j+1), query(i, j+1))) + 1;
				sc[m[i][j]]++;
			}
			else
			{
				m[i][j] = 0;
			}
		}
	}
	for(int i = N - 2; i > 0; i--){
		if(sc[i+1])
			sc[i] += sc[i+1];
	}
	for(int i = 1; i <= N; i++){
		printf("%d\n", sc[i]);
	}
	return 0;
}
