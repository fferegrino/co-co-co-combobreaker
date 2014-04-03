#include <iostream>
#include <vector>
#include <map>
using namespace std;
char n1[21], n2[21];
int p = 1;
map<string, int> mapa;
vector<int> namistades;
vector<int> padres;

int root(string n){
	int padre = 0;
	if(mapa[n] == 0){
		mapa[n] = p;
		padres.insert(padres.end(),p);
		namistades.insert(namistades.end(),1);
		padre = p;
		p++;
	}else{
		if(padres[mapa[n]] != mapa[n]){
			padres[mapa[n]] = root(n);
		}
		padre = padres[mapa[n]];
	}
	return padre;
}

int join(string n01, string n02){
	int p1 = root(n01);
	int p2 = root(n02);
	if(p1 != p2){
		padres[p1] = padres[p2];
		namistades[p2] += namistades[p1];
	}
	return namistades[padres[mapa[n02]]];
}

int main(){
	int t, F;
	cin >> t;
	
	while(t--){
		cin >> F;
		namistades.clear();
		padres.clear();
		mapa.clear();
		p = 1;
		namistades.insert(namistades.end(),0);
		padres.insert(padres.end(),0);
		while(	F--){
			cin >> n1 >> n2;
			cout << join(n1,n2) << endl;
		}
	}
	return 0;
}