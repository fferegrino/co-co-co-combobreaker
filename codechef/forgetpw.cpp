#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define NN 1000003
struct Rule{
	char c, p;
};

void strip(int l, char * s, int * i, int * j){
	*i = 0;
	*j = l;
	while(s[*i]) {
		if(s[*i] - '0' > 0) break;
		(*i)++;
	}
}
std::vector<Rule> rules;
char S[NN];
bool v[NN];
char ci[2];
char pi[2];
int main(){
	int T, N;
	scanf("%d", &T); T++;
	while(--T){
		rules.clear();
		for(int i = 0; i < NN; i++){ S[i] = '\0'; v[i] = false; }
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			Rule r;
			scanf("%s %s", ci, pi);
			r.c = ci[0]; r.p = pi[0];
			rules.push_back(r);
		}
		scanf("%s", S);
		int l = 0;
		for(int i = 0; i < rules.size(); i++){
			l = 0;
			while(S[l]){
				if(S[l] == rules[i].c && !v[l]){
					S[l] = rules[i].p;
					v[l] = true;
				}
				l++;
			}
		}
		l = strlen(S);
		int ix, j = l;
		ix = 0;
		while(S[ix]) {
			if(S[ix] != '0' || S[ix] == '.') break;
			ix++;
		}
		int f = ix;
		while(S[f]){
			if(S[f] == '.') break;
			f++;
		}
		f = f == l ? f : 0;
		while(j > f) {
			if(S[j-1] == '.'){
				j--;
				break;
			}
			if(S[j-1] != '0'){
				break;
			} 
			j--;
		}
		S[j] = '\0';
		if(ix < j)
			printf("%s\n", S+ix);
		else
			printf("0\n");
	}
}