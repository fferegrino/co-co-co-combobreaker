#include <cstdio>
#include <vector>
#define MAXN 2002
using namespace std;
int N,M,n;
bool v[MAXN];
vector<int> nodos[MAXN];
void dfs(int i){
	if(v[i])
		return;
	v[i] = true;
	n++;
	for(int j = 0; j < nodos[i].size(); j++)
		dfs(nodos[i][j]);
}
int main(){
	int a, b, c;
	bool ok = true;
	while(true){
		scanf("%d%d",&N,&M);
		if(N == 0) break;
		for(int i  = 0; i < M; i++){
			scanf("%d%d%d",&a,&b,&c);
			nodos[a].push_back(b);
			if(c == 2)
				nodos[b].push_back(a);
		}
		for(int i = 1; i <= N && ok; i++){
			dfs(i);
			ok = ok && n == N;
			for(int j = 1; j <= N; j++)
				v[j] = false;
			n = 0;
		}
		ok ? printf("1\n") : printf("0\n");
		for(int i = 0; i <= N; i++){
			v[i] = false;
			nodos[i].clear();
		}
		n = 0;
		ok =  true;
	}
}
