#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, k, i;
	int *concursantes;
	int res;
	scanf("%d",&n);
	scanf("%d",&k);
	res = k - 1;
	concursantes = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++){
		scanf("%d",&concursantes[i]);
	}
	i = concursantes[res];
	if(concursantes[res] > 0){
		for(; concursantes[res] == i && res < n ; res++);
	}
	else{
		for(; concursantes[res] == i && res >= 0 ; res--);
		res++;
	}

	printf("%d",res);
	return 0;
}