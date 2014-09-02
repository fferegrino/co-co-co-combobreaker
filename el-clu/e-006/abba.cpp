#include <cstdio>
#include <cstring>
#define M 1000
using namespace std;
char in[1000010];
char P[M];
int C[M];
char root(char c){
	if(c != P[c])
		P[c] = root(P[c]);
	return P[c];
}
void join(char a, char b){
	char pa = root(a);
	char pb = root(b);
	if(pa != pb){
		P[pa] = P[pb];
		C[pb] += C[pa];
		C[pa] = 0;
	}
}
int main() {
	for(int i = 'a'; i <= 'z'; i++){
		P[i] = i;
		C[i] = 1;
	}
	scanf("%s", in);
	int mid = strlen(in);
	int i = 0, j = mid -1;
	mid = mid / 2;
	while(i < mid){
		join(in[i++], in[j--]);
	}
	int res = 0;
	for(int i = 'a'; i <= 'z'; i++)
		if(C[i] > 1)
			res += C[i] - 1;
		}
	}
	printf("%d\n", res)	;
	return 0;
}
