#include <cstdio>
#include <cstring>
#include <utility>
#define MAX 30
#define nodos first
#define padre second
using namespace std;
pair<int,int> rec[MAX];
bool pasada[MAX];
int root(int n){
		if(rec[n].padre != n) 
			rec[n].padre = root(rec[n].padre);
	return rec[n].padre;
}
int join(int i, int j){
	int pi = root(i);
	int pj = root(j);
	if(pi != pj){
		rec[pj].padre = rec[pi].padre;
		rec[pi].nodos += rec[pj].nodos;
	}	
	return 0;
}
int T, N;
char in[70];
int main(){
	fgets(in,70,stdin);
	sscanf(in,"%d", &T);
	while(T--){
		int P = 0, j = 0;
		int acorns = 0, trees = 0;
		for(int i = 0; i < MAX; i++){
			pasada[i] = true;
			rec[i].nodos = 1;
			rec[i].padre = i;
		}
		
		while(fgets(in,70,stdin) != NULL){ 
			if(in[0] == '*') continue;
			if(in[0] == '('){
				join(in[1] - 'A', in[3] - 'A');
			}
			else{
				N =  strlen(in);
				for(int ii = 0; ii < N; ii += 2){
					pasada[in[ii] - 'A'] = false;
				}
				break;
			}
		}
		while(j < 26){
			P = root(rec[j].padre);
			if(rec[P].nodos == 1){
				if(!pasada[P]){
					pasada[P] = true;
					acorns++;
				}
			}else if(rec[P].nodos > 1){
				if(!pasada[P]){
					pasada[P] = true;
					trees++;
				}
			}else{
				
			}
			while(root(rec[j].padre) == P && j < 26) j++;
		}
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
	}
	return 0;
}