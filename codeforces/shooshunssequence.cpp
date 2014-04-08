#include <cstdio>
#include <vector>
#define MAX 100001
using namespace std;
int cub[MAX];
vector<int> l;
int n, k, a;
int main(){ 
	bool posible = false;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		cub[a]++;
		l.push_back(a);
		if(cub[a] == n){
			posible = true;
			printf("0");
		}
	}
	for(int i = 0; i < MAX+1 && !posible; i++){
		cub[l[i]]--;
		l.push_back(l[k-1 +i]);
		cub[l[k-1 +i]]++;
		if(cub[a] == n){
			posible = true;
			printf("%d", i +1);
		}
		//l.erase(l.begin());  // <= O(N)
	}
	posible ? printf("\n") : printf("-1\n");
	return 0;
}