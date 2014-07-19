#include <cstdio>
#include <algorithm>
#include <utility>
#define place second
#define distance first
#define NN 100002

typedef std::pair<int,int> frog;
frog frogs[NN];
int roots[NN];
int N, K, P;

int root(int n){
	if(roots[n] != n)
		roots[n] = root(roots[n]);
	return roots[n];
}

bool join(int a, int b){
	int p1 = root(a);
	int p2 = root(b);
	if(p1 != p2){
		roots[p1] = roots[p2];
		return true;
	}
	return false;
}

bool operator <(const frog& l,const frog& r){
	return l.distance < r.distance;
}

int main(){
	int a, b;
	scanf("%d%d%d", &N, &K, &P);
for(int i = 1; i <= N; i++){
	roots[i] = i;
	scanf("%d", &frogs[i].distance);
	frogs[i].place = i;
}
std::sort(frogs+1, frogs+N+1);
for(int i = 1; i < N; i++){
	if(frogs[i + 1].distance - frogs[i].distance <= K){
		join(frogs[i + 1].place, frogs[i].place);
	}
}
	for(int i = 0; i < P; i++){
			scanf("%d%d", &a, &b);
			root(a) == root(b) ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}

