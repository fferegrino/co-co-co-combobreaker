#include <cstdio>
#include <stack>
#include <utility>
#include <algorithm>
#define lli unsigned long long int
#define MAX 1000010
#define altura first
#define ve second
using namespace std;
typedef pair<int, int> edificio;
lli E[MAX], N, izq[MAX], der[MAX];
stack<edificio> S;
int main() {
	scanf("%lld", &N);
	for(int i = 0; i < N; i++)
		scanf("%lld", &E[i]);
	for(int i = 0; i < N; i++)	{
		edificio e;
		e.ve = i;
		e.altura = E[i];
		if(!S.empty()){
			while(!S.empty()) {
				edificio cmp = S.top();
				if(cmp.altura >= e.altura){
					e.ve = cmp.ve;
					S.pop();
				} else break;
			}
		}
		izq[i] = e.ve;
		S.push(e);
	}
	while(!S.empty()) S.pop();
	for(int i = N-1; i >= 0; i--){
		edificio e;
		e.ve = i;
		e.altura = E[i];
		if(!S.empty()){
			while(!S.empty()) {
				edificio cmp = S.top();
				if(cmp.altura >= e.altura){
					e.ve = cmp.ve;
					S.pop();
				} else break;
			}
		}
		der[i] = e.ve;
		S.push(e);
	}
	lli mx = 0;
	for(int i = 0; i < N; i++)
		mx = max(mx, E[i] * (der[i] - izq[i] + 1ll));
	printf("%lld\n", mx);
	return 0;
}