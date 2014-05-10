#include <cstdio>
#include <cstring>
int c[300];
char s1[102];
char s2[102];

int main(){
	int T;
	int l1, l2;
	int ans = 0;
	scanf("%d",&T);
	while(T--){
		ans = 0;
		for(int i = 0; i < 300; i++) c[i] = 0;
		scanf("%s%s",s1,s2);
		l1 = strlen(s1);
		l2 = strlen(s2);
		for(int i = 0; i < l2; i++) c[s2[i]]++;
		for(int i = 0; i < l1; i++){
			ans += c[s1[i]];
			c[s1[i]] = 0;
		}
		printf("%d\n", ans);
	}
}

