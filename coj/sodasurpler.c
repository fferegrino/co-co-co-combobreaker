#include <stdio.h>

int main(){
	int casos;
	scanf("%d",&casos);
	while(casos--){
		int e, f, c, t = 0;
		scanf("%d%d%d", &e, &f, &c);
		if(c != 1){
			e += f;
			while(e / c){
				t += e / c;
				e = e / c + e % c;
			}
		}
		printf("%d\n",t);
		
	}
	return 0;
}