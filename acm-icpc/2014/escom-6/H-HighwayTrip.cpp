#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> hoteles;
long long int M[40];
int mx, mi, H;
long long int trip(int h){
	if(h == H)
		return 0;
	if(M[h] != -1)
		return M[h];
	if(hoteles[h] == 7000)
		return 1;
	long long int res = 0;
	for(int i = h + 1; i < H ; i++){
		if(hoteles[h] + mi <= hoteles[i] && hoteles[i] <= hoteles[h] + mx){
			res += trip(i);
		}
	}
	return M[h] = res;
}

int main(){
	bool z = false;
	bool zz = false;
	int ax;
	while(1){
		scanf("%d%d%d", &mi, &mx, &H);
		if(mi || mx || H){
			hoteles.clear();
			z = false;
			zz = false;
			for(int j = 0; j < 40; j++) M[j] = -1;
			for(int i = 0; i < H; i++){
				scanf("%d", &ax);
				z = ax == 0 || z;
				hoteles.push_back(ax);
			}
			if(!z){
				hoteles.push_back(0);
				H++;
			}
			sort(hoteles.begin(), hoteles.end());
			printf("%lld\n", trip(0));
		}
		else break;
	}
	return 0;
}