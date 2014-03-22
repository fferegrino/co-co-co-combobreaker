#include <stdio.h>
#include <string.h>
#include <stdio.h>
#define S 25
using namespace std;

unsigned long long int nChoosek(unsigned long long int n,unsigned long long int k )
{
    if (k > n) return 0;
    if (k == 0) return 1;
	if(n == k) return 1;
	if(n-k < k) k = n - k;
    unsigned long long int result = n;
    for( unsigned long long int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
		printf("NCHOOSEK %lld %lld\n",i, result);
    }
    return result;
}


int main(){
	char cad[1000001];
	char c;
	int cub[S];
	while(scanf("%s",cad) != EOF){
		int len = strlen(cad);
		unsigned long long int res = 1;
		for(int i = 0; i < len; i++){
			cub[cad[i] - 'a']++;
			
		}
		for(int i = 0; i < S; i++){
			if(cub[i] > 0){
				unsigned long long int rr = nChoosek(len, cub[i]);
				//int ct = 10;
				printf("\t%lld %lld %d\n",len,  cub[i], rr);
				while(rr % 10 == 0 ){
					//printf("%lld DIV\n",rr);
					rr /= 10;
				}
				res *= rr % 10;
				len -= cub[i];
			}
		}
		/*
		while(res % 10 == 0)
			res /= 10;
			*/
		printf("%lld\n", res % 10); // Ultimo digito de res
		memset(cub,0,S*sizeof(int));
	}	
	return 0;
}