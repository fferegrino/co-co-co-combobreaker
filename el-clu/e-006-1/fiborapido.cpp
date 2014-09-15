#include <cstdio>
#include <cstdlib>
#include <cstring>
#define mod 98765431
#define lli long long int
lli fibonacci(lli n)
{
    lli fib[2][2]= {{1,1},{1,0}},ret[2][2]= {{1,0},{0,1}},tmp[2][2]= {{0,0},{0,0}};
    int i,j,k;
    while(n)
    {
        if(n&1)
        {
            memset(tmp,0,sizeof tmp);
            for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                        tmp[i][j]=(tmp[i][j]+(ret[i][k]*fib[k][j]) % mod) % mod;
            for(i=0; i<2; i++) for(j=0; j<2; j++) ret[i][j]=tmp[i][j];
        }
        memset(tmp,0,sizeof tmp);
        for(i=0; i<2; i++) for(j=0; j<2; j++) for(k=0; k<2; k++)
                    tmp[i][j]=(tmp[i][j]+(fib[i][k]*fib[k][j]) % mod) % mod;
        for(i=0; i<2; i++) for(j=0; j<2; j++) fib[i][j]=tmp[i][j];
        n/=2;
    }
    return (ret[0][1] % mod);
}

int main() {
	lli N;
	scanf("%lld", &N);
	printf("%lld\n", fibonacci(N));
}
