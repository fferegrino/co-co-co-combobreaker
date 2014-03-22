#include <iostream>
using namespace std;
 
long long ac [1000001];
 
void update(int ix, int val, int n){
	int nv = val;
	for(; ix < n + 1; ix += (ix & -ix))
		ac[ix] += val;
}
 
long long query(int ix){
	long long r = 0;
	while(ix){
		r += ac[ix];
		ix -= (ix & -ix);
	}
	return r;
}
 
int main(){
	int N, Q, a, i, j;
	char opt;
	cin >> N;
	cin >> Q;
	for(int i = 1; i < N +1; i++){
		cin >> a;
		update(i, a, N);
	}
	while(Q--){
		cin >> opt;
		cin >> i;
		cin >> j;
		if(opt == 'S')
			cout << query(j+1) - query(i) << endl;
		else
			update(i+1,(opt == 'T' ? -j : j),N);
	}
	return 0;
}