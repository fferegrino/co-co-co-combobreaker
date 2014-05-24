#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define NN 2003
using namespace std;
int C[NN];
char K[NN];
char M[NN];

int main(){
	int T;
	scanf("%d", &T);
	while(T){
		for(int i = 0; i < T; i++){
			scanf("%x", &C[i]);
		}
		scanf("%s %s", M, K);
		for(int i = 0; i < T; i++){
			if(M[i] != '_'){
				C[i] = C[i] ^ M[i] ^ K[i];
			}
			printf("%02X ", C[i]);
		}
		printf("\n");
		scanf("%d", &T);
	}
	return 0;
}