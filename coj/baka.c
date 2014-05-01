#include <stdio.h>
#include <string.h>
int main(){
	int res = 0, len, i;
	char n[17];
	scanf("%s",n);
	len = strlen(n);
	for(i = 0; i < len; i++){
		if('A' <= n[i] && n[i] <= 'C') res += 3;
		if('D' <= n[i] && n[i] <= 'F') res += 4;
		if('G' <= n[i] && n[i] <= 'I') res += 5;
		if('J' <= n[i] && n[i] <= 'L') res += 6;
		if('M' <= n[i] && n[i] <= 'O') res += 7;
		if('P' <= n[i] && n[i] <= 'S') res += 8;
		if('T' <= n[i] && n[i] <= 'V') res += 9;
		if('W' <= n[i] && n[i] <= 'Z') res += 10;
	}
	printf("%d\n", res);
	return 0;
}