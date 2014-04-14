#include <cstdio>
#include <cmath>
#define MAXS 100005 
using namespace std;
char s[MAXS];
int mem[MAXS];
int n = 0, m = 0, q = 0;
int calcb(int step){
	int b2 = 0, b1 = 0;
	int t = 0;
	for(int i = step-1; i >= 0; i--){
		t = (s[step] - '0') - (s[i] - '0');
		if(t == 0){
			b2 += mem[i];
			mem[step] = b2;
			break;
		}
		b2 += abs(t);
		mem[step] = b2;
	}
	return b2;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i = 0; i < n; i++){
		calcb(i);
	}
	while(m--){
		scanf("%d",&q);
		printf("%d\n",calcb(q-1));
	}
	return 0;
}