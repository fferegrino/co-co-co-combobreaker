#include <stdio.h>
#include <cstring>
#define MAX 10001
using namespace std;
char num[MAX];
int m[MAX][MAX];
int n;
bool isp2(int nn){
	return !(nn & (nn-1));
}
int p2(int i, int prev){
	if(i >= n)
		return 0;
	int nv = num[i] - '0';
	if(m[i][prev] != -1)
		return m[i][prev];
	if(isp2(prev * 10 + nv)){
		printf("%d\n",prev * 10 + nv);
		return m[i][prev] = 1 + p2(i+1, prev * 10 + nv) +  p2(i+1, prev);
	}
	else{
		return m[i][prev] =  p2(i+1, prev * 10+ nv) +  p2(i+1, prev);
	}
}
int main(){
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			m[i][j] = -1;
		}
	}
	scanf("%s",num);
	n = strlen(num);
	printf("%d\n", p2(0,0));
	return 0;
}