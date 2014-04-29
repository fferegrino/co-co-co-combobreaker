#include <cstdio>
#include <algorithm>
#include <utility>
typedef  std::pair<int, int> pint;
pint tiros[10001];
bool operator<(const pint& a, const pint& b){ 
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}
int a, b, x, y;
int main(){
	scanf("%d%d%d%d",&x,&y,&a,&b);
	a = std::max(b+1,a);
	int b1 = b;
	int t = 0;
	for(;b <= y; b++){
		for(int ax = std::max(b+1,a); ax <= x; ax++){
				tiros[t].first = ax;
				tiros[t].second = b;
				t++;
		}
	}
	std::sort(tiros, tiros+t);
	printf("%d\n", t);
	for(int i = 0; i < t;i++){
		printf("%d %d\n", tiros[i].first, tiros[i].second);
	}
	return 0;
}