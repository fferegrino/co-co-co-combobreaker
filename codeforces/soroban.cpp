#include <iostream>

using namespace std;

void printn(int i){
	int o = 4;
	if(i >= 5){
			i -= 5;
			cout << "-O|";
	}else
		cout << "O-|";
	while(i--){
		cout << "O";
		o--;
	}
	cout << "-";
	while(o--)
		cout << "O";
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	do{
		printn(n % 10);
		n /= 10;
	}while(n);
	return 0;
}
