#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1000002
#define I  (long long int)1<<31
using namespace std;
int T, P, Q;
struct Stop{
	int c;
	int id;
	int o;
	bool operator<(const Stop &c2) const
	{	    
            return c > c2.c;
	}
};
priority_queue<Stop> q;
vector<Stop> g[MAX];
long long int d[MAX];
bool visita[MAX];
void clear(){ for(int i = 0; i < P+1; i++) { d[i] = I; visita[i] = false; } }
void clearG(){ for(int i = 0;i <= P; i++){ g[i].clear(); } }
void dj(int s);
int main(){	
	scanf("%d",&T);
	int ix;
	long long int total = 0;
	while(T--){
		vector<Stop> path;
		scanf("%d%d",&P,&Q);
		for(int i = 0; i < Q; i++){
			Stop s;
			scanf("%d%d%d",&s.o,&s.id,&s.c);
			g[s.o].push_back(s);
			path.push_back(s);
		}
		clear();
		dj(1);
		for(int i = 1; i <= P;i++){
			total += d[i];
		}
		clearG();
		for(int i = 0; i < Q; i++){
			ix = path[i].o;
			path[i].o = path[i].id;
			path[i].id = ix;
			g[path[i].o].push_back(path[i]);
		}	
		clear();
		dj(1);
		for(int i = 1; i <= P;i++){
			total += d[i];
		}
		printf("%lld\n",total);
		clearG();
		total = 0;
	}
	return 0;
}
 
void dj(int s){
	d[s] = 0;
	Stop stop;
	stop.id = s;
	stop.c = 0;
	q.push(stop);
	while(!q.empty()){
		Stop st = q.top();
		q.pop();
		if(visita[st.id]) continue;
		visita[st.id] = true;
		for(int i = 0; i < g[st.id].size(); i++){
			if(!visita[g[st.id][i].id]){
				long long int nwdst = d[st.id] + g[st.id][i].c;
				if(nwdst < d[g[st.id][i].id]){
					d[g[st.id][i].id] = nwdst;
					Stop fake;
					fake.c = nwdst;
					fake.id =g[st.id][i].id;
					q.push(fake);
				}
			}
		}
	}
}