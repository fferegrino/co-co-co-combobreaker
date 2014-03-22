#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
int ac [100000];
 
void update(int ix, int val, int n){
	int nv = val;
	for(; ix < n + 1; ix += (ix & -ix))
		ac[ix] += val;
}
 
int query(int ix){
	int r = 0;
	while(ix){
		r += ac[ix];
		ix -= (ix & -ix);
	}
	return r;
}
 
struct par{
	int M;
	int F;
};
 
inline bool operator<(const par& a, const par& b)
{
	return a.M < b.M;
}
 
int main(){
	int N, n;
	int	m, f;
	cin >> N;
	n = N;
	vector<par> parejas;
	vector<int> fem;
	map<int, int> mapa;
	while(N--){
		cin >> m >> f;
		par p;
		p.M = m;
		p.F = f;
		parejas.insert(parejas.end(),p);
		fem.insert(fem.end(),f);
	}
	std::sort (fem.begin(), fem.end()); 
	std::sort (parejas.begin(), parejas.end());
	for(int i = 0; i < n; i++){
		mapa[fem[i]] = i+1;
	}
	for(int i = 1; i < n+1; i++){
		update(mapa[parejas[i-1].F],1,n);
	}
	long long int res = 0;
	for(int i = 0; i < n; i++){
		res += query(mapa[parejas[i].F]) - 1;
		update(mapa[parejas[i].F],-1,n);
	}
	cout << res << endl;
	return 0;
}