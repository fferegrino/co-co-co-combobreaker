#include <cstdio>
#include <cmath>
#define MAXS 100005 
using namespace std;
char s[MAXS];
int A[MAXS];
int n = 0, m = 0, q = 0;
void precalc(){
	int t = 0;
	for(int step = 0; step < n; step++){
		int ans = 0;
		for(int i = step-1; i >= 0; i--){
			t = (s[step] - '0') - (s[i] - '0');
			if(t == 0){
				ans += A[i];
				A[step] = ans;
				break;
			}
			ans += abs(t);
			A[step] = ans;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	precalc();
	while(m--){
		scanf("%d",&q);
		printf("%d\n",A[q-1]);
	}
	return 0;
}
