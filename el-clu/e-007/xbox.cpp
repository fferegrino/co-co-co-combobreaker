#include<cstdio>
#define MAXN 1000010
using namespace std;
int points[MAXN], N, mx, end;
int main(){
	scanf("%d",&N);
	for(int i = 0; i < N; i++)
		scanf("%d",&points[i]);
	mx = end = points[0];
	for(int i = 1; i < N; i++){
		if(end < 0)
            end = points[i];
        else
            end += points[i];
        if( end >= mx ) mx  = end;
	}
   printf("%d\n", mx);
}