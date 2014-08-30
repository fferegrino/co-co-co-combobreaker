#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int v[100];
struct xD{
	int val;
	string id;	
};
 
bool func(xD x1, xD x2){
	return x1.val > x2.val;
}
int suma(string xxD){
	int res = 0;
	for(int  i = 0; i < 3; i++)
		res += v[(int)xxD[i]];
	return res;
}
xD vals[8];
int main() {
	int a,b,c,d,e,f, mejor, mejor2, mejor3;
	unsigned long long int N, res = 0;
	scanf("%lld", &N);
	scanf("%d%d%d%d%d%d", &v['a'], &v['b'], &v['c'], &v['d'], &v['e'], &v['f']);
	if(N == 1){
		printf("%d\n" , v['a'] + v['b'] + v['c'] + v['d'] + v['e'] + v['f'] - max(v['a'], max(v['b'], max(v['c'], max(v['d'], max(v['e'], v['f']))))));
	}else{
		vals[0].val = suma("dae");
		vals[0].id = "bcf";
		vals[1].val = suma("eac");
		vals[1].id = "bfd";
		vals[2].val = suma("cab");
		vals[2].id = "def";
		vals[3].val = suma("dab");
		vals[3].id = "cef";
		vals[4].val = suma("bfd");
		vals[4].id = "ace";
		vals[5].val = suma("dfe");
		vals[5].id = "abc";
		vals[6].val = suma("cfe");
		vals[6].id = "abd";
		vals[7].val = suma("bfc");
		vals[7].id = "dae";
		sort(vals, vals+8, func);
		mejor = min(v[vals[0].id[0]], min(v[vals[0].id[1]], v[vals[0].id[2]]));
		mejor3 = max(v[vals[0].id[0]], max(v[vals[0].id[1]], v[vals[0].id[2]]));
		mejor2 = v[vals[0].id[0]] + v[vals[0].id[1]] + v[vals[0].id[2]] - mejor - mejor3;
		res = ((unsigned long long int)mejor * N * N) + mejor * (N - 1ull) * (N - 1ull) * 4ull;
		res +=  (unsigned long long int)mejor3 * 4ull;
		res += (unsigned long long int)mejor2 * (2ull * N - 2ull) * 4ull;
		printf("%lld\n", res);
	}
	return 0;

