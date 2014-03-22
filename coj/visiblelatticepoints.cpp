#include <iostream>
using namespace std;
int p[1001];

int mcd(int a, int b){ 
	int aux, r; 
	if(b > a){ 
		aux = a; 
		a = b; 
		b = aux; 
	} 
	while( (r = (a % b)) != 0){ 
		a = b; 
		b = r; 
	} 
	return b; 
} 

int main(){
	int t, n;
	p[0] = 0;
	p[1] = 3;
	for(int x = 2; x < 1001; x++){
		int sum = 0;
		for(int y = 1; y < x; y++){
			if(mcd(x,y) == 1) sum++;
		}
		p[x] = p[x-1] + 2 * sum;
	}
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		cout << i << " " << n << " "<< p[n] << endl;
	}
	return 0;
}

