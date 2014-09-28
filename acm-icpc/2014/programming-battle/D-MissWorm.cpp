#include <cstdio>
#include <vector>
#include <stack>
#include <bitset>
#define MAXV 100000
#define vi vector<int>
using namespace std;
vector<vi> SCC;
bitset<MAXV> b;
int low[MAXV];
int num[MAXV];
bool inStack[MAXV];
vi g[MAXV];
vi gt[MAXV];
stack<int> Stack;
int T, S, A, B, C, Q;

void DFS(int s){
	if(b[s])
	{
		b[s] = 0;
		for(int i = 0; i < g[s].size(); i++){
			DFS(g[s][i]);
		}
		Stack.push(s);
	}
}

void DFSt(int s){
	if(b[s])
	{
		printf("%d ", s);
		b[s] = 0;
		for(int i = 0; i < g[s].size(); i++){
			DFSt(gt[s][i]);
		}
	}
}


int main () {
	while(scanf("%d %d", &T, &S) != EOF)
	{
		for(int i = 0; i < T; i++)
		{
			scanf("%d%d%d", &A, &B, &C);
			g[A -1].push_back(B - 1);
			gt[B - 1].push_back(A - 1);
		}
		b.set();
		DFS(0);
		if(!Stack.empty())
		{
			b.set();
			do{
				int source = Stack.top();
				printf("%d: ", source);
				DFSt(source);
				Stack.pop();
				printf("\n");
			}while(!Stack.empty());
		}
		scanf("%d", &Q);
		for(int q = 0; q < Q; q++)
		{
				scanf("%d%d", &A, &C);
		}
		printf("\n");
		break;
	}
	return 0;
}
