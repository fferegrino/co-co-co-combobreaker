#include <cstdio>
#include <bitset>
#define M 20020
int P, R, x;
int jumps[M];
std::bitset<M> v;
int jump(int ix, int jmp);

int main() {
	int nj = 0;
	scanf("%d %d", &P, &R);
	for(int ii = 0; ii < P; ii++){
		scanf("%d", &jumps[ii]);
	}
	for(int ii = 0; ii < P; ii++){
		v[nj] = 1;
		nj = jump(nj, jumps[ii]) - 1;
	}
	nj += 1;
	int ans = R -nj;
	if(ans < 1){
		ans = P + ans;
	}
	printf("%d\n", ans);
	return 0;
}

int jump(int ix, int jmp){
	int i = ix;
	for(;jmp; i++){
		if(i == P) i = 0;
		if(!v[i]) --jmp;
	}
	return i;
}
