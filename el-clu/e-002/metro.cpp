#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 30003
using namespace std;
int N, M;
int p[MAX];
int root(int n){
	if(p[n] != n){
		p[n] = root(p[n]);
	}
	return p[n];
}

struct tramo {
	int a,b,c;
	
	bool operator < (const tramo &t1) const{
		return c < t1.c;
	}
	
};

vector<tramo> tramos;

bool join(int a, int b){
	int aa = root(a);
	int bb = root(b);
	if(aa != bb){
		p[aa] = p[bb];
		return true;
	}
	return false;
}

int main() {
	int a, b, c;
	int res = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i <= N; i++) p[i] = i;
	for(int i = 0; i < M; i++){
		tramo t;
		scanf("%d %d %d", &t.a, &t.b, &t.c);
		tramos.push_back(t);
	}
	
	sort(tramos.begin(), tramos.end());
	for(int i = 0; i < tramos.size(); i++){
		if(join(tramos[i].a, tramos[i].b)){
			res += tramos[i].c;
		}
	}
	printf("%d\n", res);
	return 0;
}