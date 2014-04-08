#include <iostream>
using namespace std;
long long pot(int n){
	long long i = n, x = 10, r = 1;
	while (i > 0){
		if (i % 2 != 0)
			r = r * x ;
		x = x * x;
		i /= 2;
	}
	return r;
}
int main(){	
	long long int p;
	long long int pr;
	long long int necesita;
	long long int k;
	int magia [] = {1,2,3,4,5,6,7,8,9,0};
	//scanf("%l64d%l64d", &p, &k);	
	cin >> p >> k;
	pr = p;
	int i = 0;
	necesita = 0;
	while(p){
		int z = p % 10;
		p -= magia[z];
		p /= 10;
		long long int d = magia[z] * pot(i);
		if(necesita + d <= k)
			necesita += d;
		else break;
		i++;
	}
	cout << (pr-necesita) << endl;
}