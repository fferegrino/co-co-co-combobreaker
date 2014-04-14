#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int T, a1, a2;
int r1[4][4];
int r2[4][4];

int main(){
	scanf("%d",&T);
	for(int ix = 1; ix <= T; ix++){
		vector<int> subset(4);
		vector<int>::iterator it;
		int x;
		scanf("%d",&a1);
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				scanf("%d",&x);
				r1[i][j] = x;
			}
		}
		scanf("%d",&a2);
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				scanf("%d",&x);
				r2[i][j] = x;
			}
		}
		sort(r1[a1-1], r1[a1-1]+4);
		sort(r2[a2-1], r2[a2-1]+4);
		it = set_intersection (r1[a1-1], r1[a1-1]+4, r2[a2-1], r2[a2-1]+4, subset.begin());
		subset.resize(it-subset.begin());
		printf("Case #%d: ",ix);
		if(subset.size() == 1)
			printf("%d",subset[0]);
		else if(subset.size() > 1 )
			printf("Bad magician!");
		else if(subset.size() == 0)
			printf("Volunteer cheated!");
		printf("\n");
		
	}
	return 0;
}