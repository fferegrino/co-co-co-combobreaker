#include <cstdio>
#define TRI 44730
int num[TRI];
bool buscar(int i, int f, int val){
	while(i < f){
		int m  = (i + f) / 2;
		if(num[m] == val) return true;
		if(num[m] < val)
			i = m + 1;
		else 
			f = m;
	}
	return false;
}
int main(){
	int n = 0;
	for(int i = 1; i < TRI; i++)
		num[i] = i *(i + 1) / 2;
	scanf("%d",&n);
	bool posible = false;
	for(int i = 1; i < TRI && !posible; i++){
		int valb = n - num[i];
		posible = buscar(i, TRI, valb);
	}
	posible ? printf("YES\n") : printf("NO\n");
}