#include <cstdio>
#include <algorithm>
int main(){
	int n, a, mx = 0, tmp = 0; 
	scanf("%d", &n);
	n++;
	while(--n){ 
		scanf("%d", &a); 
		tmp += (a == 0) ? -tmp : 1; 
		mx = std::max(tmp, mx); 
	}
	printf("%d\n", mx);
	return 0;
}