#include <stdio.h>
#include <algorithm>
using namespace std;
int l[1002];
int m[1002][1002];
int N;
int main(){
		int T;
		scanf("%d",&T);
		while(T--){
					
					
			scanf("%d",&N);
		
			for(int i = 0; i <= N+1; i++)
				for(int j = 0; j <= N+1; j++)
					m[i][j] = 0;
			for(int i = 0; i < N; i++){
				scanf("%d",&l[i]);
			}
			for(int i = N; i >= 0; i--){
				for(int u = N; u >= 0; u--){
					if(l[u] < l[i]){
						m[u][i] =  max(m[i][i+1] + 1, m[u][i+1]);
					}
					else{
						m[u][i] = m[u][i+1];
					}
				}
			}
			printf("%d\n",m[0][0]);
		}
        return 0;
}
