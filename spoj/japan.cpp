#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
 
int * ac;
 
void update(int ix, int val, int n){
	int nv = val;
	for(; ix < n + 1; ix += (ix & -ix))
		ac[ix] += val;
}
 
int query(long long int ix){
	int r = 0;
	while(ix){
		r += ac[ix];
		ix -= (ix & -ix);
	}
	return r;
}
 
struct bridge{
	int E;
	int W;
};
 
inline bool operator<(const bridge& a, const bridge& b)
{
	return (a.E == b.E) ? a.W < b.W : a.E < b.E;
}
 
int main(){
	cin.sync_with_stdio(false);
	int T;
	int N, M, K, e, w;
	cin >> T;
	T++;
	for(int ix = 1; ix < T; ix++) { 
		cin >> N >> M >> K;
		int n = K;
		vector<bridge> bridges;
		int res = 0;
		ac = new int[n+1]; 
		memset(ac, 0, sizeof( int)*(n+1)); 
		while(K--){
			cin >> e >> w;
			bridge b;
			b.E = e;
			b.W = w;
			bridges.push_back(b);
		}
		std::sort (bridges.begin(), bridges.end()); 
		
		for(int i = 0; i < n; i++){
			update(bridges[i].W,1,n);
		}
		for(int i = 0; i < n; i++){
			res += query(bridges[i].W - 1);
			update(bridges[i].W,-1,n);
		}
		
		cout << "Test case " << ix << ": " << res << endl;
	}
	return 0;
}