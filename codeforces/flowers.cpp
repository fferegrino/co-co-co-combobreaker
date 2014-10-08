#include <cstdio>
#define MOD 1000000007
using namespace std;
int k;
int m[100009];
int dp();
int main() 
{
	int t, a , b;
	scanf("%d%d",&t,&k);
	m[0]=1;
	dp();
	for(int i = 1; i < 100009; i++){
		m[i] = (m[i-1] + m[i]) % MOD ;
	}
		
	
	while(t--){
		scanf("%d%d", &a, &b);
		printf("%d\n",  (m[b] - m[a-1] + MOD) % MOD);
	}
	return 0;
}



int dp()
{
	for(int i = 1; i < 100009; i++){
		if(i - k >= 0)
			m[i] = (m[i-1] + m[i-k]) % MOD;
		else
			m[i] = m[i-1];
	}
	return 0;
}
