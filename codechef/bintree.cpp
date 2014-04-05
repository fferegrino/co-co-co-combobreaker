#include <cstdio>
#define MAX 31
using namespace std;
long long pot(int n);
int r(long long int n);
struct Rango{
	long long int min, low;
	bool operator== (const long long int &n) const
	{
		return min <= n && n <= low;
	}
};
int T;
long long int i, j;
Rango rangos[MAX];
int main(){
	for(int ix = 0; ix < MAX; ix++){
		rangos[ix].min = pot(ix);
		rangos[ix].low = pot(ix+1)-1;
	}
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld", &i, &j);
		int lca = 0;
		long long int pi = 0, pj = 0;
		int ni = r(i), nj = r(j)
		int c = ni + nj;
		if(ni < nj){
			while(ni != nj){
				j /= 2;
				nj = r(j);
			}
		}
		if(ni > nj){
			while(ni != nj){
				i /= 2;
				ni = r(i);
			}
		}
		if(ni == nj){
			pi = i;
			pj =  j;
			while(pi != pj){
				pi /=2;
				pj /=2;
			}
			lca = r(pi);
		}
		printf("%d\n",c - lca * 2);
	}
	return 0;
}	

int r(long long int n){
	int i = -1;
	while(!(rangos[++i] == n));
	return i;
}

long long pot(int n){
	long long i = n, x = 2, r = 1;
	while (i > 0){
		if (i % 2 != 0)
			r = r * x ;
		x = x * x;
		i /= 2;
	}
	return r;
}