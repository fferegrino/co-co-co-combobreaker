#include <cstdio>
#define mg 50003
#define ll unsigned long long int
int roots[mg];
int nodes[mg];
bool tomado[mg];

ll gcd(ll a, ll b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

ll lcm(ll a, ll b)
{
    ll temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

ll root(ll n){
	if(roots[n] != n)
	roots[n] = root(roots[n]);
	return roots[n];
}
bool join(ll a, ll b){
	ll p1 = root(a);
	ll p2 = root(b);
	if(p1 != p2){
		roots[p1] = roots[p2];
		nodes[p2] += nodes[p1];
		nodes[p1] = 1;
		return true;
	}
	return false;
}

int main(){
	ll N,q;
	scanf("%lld", &N);
	for(ll i = 1; i <= N +1; i++){
		roots[i] = i;
		nodes[i] = 1;
		tomado[i] = false;
	}
	for(ll i = 1; i <= N; i++){
		scanf("%lld", &q);
		join(i, q);
	}
	ll res = 1;
	for(ll i = 1; i <= N; i++){
		if(!tomado[nodes[i]] && nodes[i] > 1){
			res = lcm(res, nodes[i]);
			tomado[nodes[i]] = true;
		}
	}
	printf("%lld\n", res);
}
