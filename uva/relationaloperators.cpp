#include <cstdio>
using namespace std;

int main() {
	int N, a , b;
	scanf("%d", &N); N++;
	while(--N){
		scanf("%d %d", &a, &b);
		if(a == b)
			printf("=");
		else if(a < b)
			printf("<");
		else
			printf(">");
		printf("\n");
	}
	return 0;
}