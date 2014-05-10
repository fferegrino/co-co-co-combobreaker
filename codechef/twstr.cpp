#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define NOD 28
struct Trie{
	char val = '\0';
	Trie * nodes;
	char mvp;
	int value;
	void init(char ss){
		val = ss;
		mvp ='A';
		value = -1 * (1 << 30);
		nodes = new Trie[NOD];
	}
};
Trie * addChar(Trie *t, char c){
		if(c == '-') c = 'z' +1;
		if(!t->nodes[c - 'a'].val){
			t->nodes[c-'a'].init(c);
		}
		return &(t->nodes[c-'a']);
}
Trie * nextChar(Trie * t, char c){
	if(c == '-') c = 'z' +1;
	if(t->nodes[c - 'a'].val != '\0')
		return &(t->nodes[c - 'a']);
	return NULL;

}

int main(){
	int N, Q;
	char sq[1002];
	scanf("%d", &N);
	Trie t;
	Trie * ax;
	t.init('\0');
	int strl;
	int pp;
	for(int i = 0; i < N; i++){
		scanf("%s%d", sq, &pp);
		strl = strlen(sq);
		ax = &t;
		for(int j = 0; j < strl; j++){
			if(ax->value < pp){
				ax->mvp = sq[j];
				ax->value = pp;
			}
			ax = addChar(ax, sq[j]);
		}
	}
	bool existe = true;
	char ans[1002];
	int j;
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		existe = true;
		scanf("%s", sq);
		strl = strlen(sq);
		ax = &t;
		j = 0;
		for( ;j < strl; j++){
			ax = nextChar(ax, sq[j]);
			if(ax == NULL){
				existe = false;
				printf("NO\n");
				break;
			}
			ans[j] = sq[j];
		}
		if(existe){
			while(ax->mvp != 'A'){
				ans[j++] = ax->mvp;
				ax = nextChar(ax, ax->mvp);
			}
			ans[j] = '\0';
			printf("%s\n",ans);
		}
	}
}