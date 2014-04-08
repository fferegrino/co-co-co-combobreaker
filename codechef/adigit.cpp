#include <cstdio>
#include <vector>
#define MAXS 10005 
using namespace std;
char s[MAXS];
int n = 0, m = 0, q = 0;
int calcb(int step){
	int b2 = 0, b1 = 0;
	int t = 0;
	for(int i = 0; i < step; i++){
		t = (s[step] - '0') - (s[i] - '0');
		if(t < 0)
			b2 += t;
		else
			b1 += t;
	}
	return b1 - b2;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	while(m--){
		scanf("%d",&q);
		printf("%d\n",calcb(q-1));
	}
	return 0;
}