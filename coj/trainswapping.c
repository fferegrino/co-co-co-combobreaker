#include <stdio.h>

int main(){
	int t, l, i, n = 0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&l);
		int * trains = (int *)malloc(sizeof(int) * l);
		for(i = 0; i < l; i++){
			scanf("%d",&trains[i]);
		}
		
		free(trains);
	}
	return 0;
}