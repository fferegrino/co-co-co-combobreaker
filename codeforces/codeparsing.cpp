#include <cstdio>
#include <algorithm>
#include <cstring>
int main(){
	char inn[1000010] ;
	scanf("%s", inn);
	int r = 0;
	int l = strlen(inn);
	for(int i = 0; i < l; i++){
		r += (inn[i] == 'x') ? 1 : -1;
	}
	char a = '\0';
	if(r > 0){
		a = 'x';
	}
	else {
		a = 'y';
	}
	r = abs(r);
	for(int i = 0; i < r; i++){
		printf("%c",a);
	}
	printf("\n");
	return 0;
}