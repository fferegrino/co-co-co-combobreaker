#include <cstdio>
#include <cstring>
using namespace std;
int c[5];
int n, m, t, v, prev = -1, max = -1;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(c,0,sizeof(int)*n);
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				scanf("%d",&v);
				c[j] += v;
				if(prev < c[j]){
					max = j;
				}
				prev = c[j];
			}
			
		}
		printf("%d\n",max+1);
		max = -1;
		prev = -1;
	}
	return 0;
}