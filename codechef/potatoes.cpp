#include <cstdio>
#include <cmath>
#define MC 2500
using namespace std;
bool c[MC];
int main(){
	for(int i = 2; i < MC; i++) c[i] = true;
	for(int i = 2; i < ceil(sqrt(MC)); i++){
		if(c[i]){
			for(int j = i * 2; j < MC; j += i){
				c[j] = false;
			}
		}
	}
	int T,x,y,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		i = x + y;
		while(!c[++i]);
		printf("%d\n",i - x - y);
	}
}