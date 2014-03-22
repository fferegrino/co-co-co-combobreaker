#include <stdio.h>

int main(){
	int a, b, t = 0,r = 0;	
	scanf("%d%d",&a,&b);
	while(a--){
		r++;
		t++;
		if(r == b){
			r = 0;
			a++;
		}
	}
	printf("%d\n",t);
	return 0;
}