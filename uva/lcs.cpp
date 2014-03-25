#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAXW 1005
using namespace std;
int m[MAXW][MAXW];
char a[MAXW];
char b[MAXW];
int la;
int lb;
int lcs(int pa, int pb){
	if(pa >= la || pb >= lb)
		return 0;
	if(m[pa][pb] != -1)
		return m[pa][pb];
	if(a[pa] != b[pb])
		return m[pa][pb] = max(lcs(pa,pb+1) , lcs(pa+1,pb) );
	else
		return m[pa][pb] = /*max(*/ lcs(pa+1,pb+1) + 1;/*, max(lcs(pa,pb+1) , lcs(pa+1,pb) ));*/
}

int main(){
	while(scanf("%s", a) != EOF){
		scanf("%s",b);
		for(int i = 0; i < MAXW; ++i)
			for(int j = 0; j < MAXW; ++j)
				m[i][j] = -1;
		la = strlen(a);
		lb = strlen(b);
		printf("%d\n",lcs(0,0));
	}
	return 0;
}
