#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
priority_queue<int> q;
int main()
{
	int R, G, B, M, T, O, x, mr, mg, mb;
	scanf("%d", &T);
	while(T--)
	{
		mr = mb = mg = -1;
		scanf("%d%d%d%d", &R, &G, &B, &M);
		while(R--)
		{
			scanf("%d", &x);
			mr = max(mr, x);
		}
		while(G--)
		{
			scanf("%d", &x);
			mg = max(mg, x);
		}
		while(B--)
		{
			scanf("%d", &x);
			mb = max(mb, x);
		}
		q.push(mb);
		q.push(mg);
		q.push(mr);
		while(M--)
		{
			int x = q.top(); q.pop();
			q.push(x / 2);
		}
		printf("%d\n", q.top());
		while(!q.empty())
		{
			q.pop();
		}
	}
	
}
