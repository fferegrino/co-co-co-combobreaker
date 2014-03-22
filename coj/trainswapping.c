#include <stdio.h>
int trains[51];
int main(){
	int t, l, i, n = 0,c = 1;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&l);
		for(i = 0; i < l; i++){
			scanf("%d",&trains[i]);
		}
		while(c){
			c = 0;
			for(i = 1; i < l; i++){
				if(trains[i-1] > trains[i]){
					int a =  trains[i-1];
					trains[i-1] = trains[i];
					trains[i] = a;
					n++;
					c = 1;
				}
			}
			l--;
		}
		printf("Optimal train swapping takes %d swaps.\n",n);
		n = 0;
		c = 1;
	}
	return 0;
}