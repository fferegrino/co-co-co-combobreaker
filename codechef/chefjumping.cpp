#include <cstdio>
int main(){
	long long int a;
	scanf("%lld",&a);
	long long int mod = a % 6;
	(mod == 0 || mod == 1 || mod == 3) ? printf("yes\n") : printf("no\n");
}