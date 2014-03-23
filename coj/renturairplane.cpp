#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
using namespace std;
struct Order{
	int inicio;
	int fin;
	int precio;
};

long long int m[10001][10001];
int n;
int t;

bool lessFunction(Order a, Order b){
	return a.inicio < b.inicio;
}

int nextOrder(vector<Order>& orders, int i){
	int fin = orders[i].fin;
	while(orders[i].inicio < fin)
		i++;
	return i;
}

long long int resolver(vector<Order>& orders, int last){
	if(last >= n)
		return 0;
	int next = last +1; //= nextOrder(orders,last);
	printf("%d:%d %d:%d\n", last, orders[last].fin, next, orders[next].inicio);
	if(orders[last].fin <= orders[next].inicio){
			return max(	resolver(orders, next),
						resolver(orders, next) + orders[last].precio);
	}
	return resolver(orders, next);
}

int main(){
	int i;
	int fin;
	scanf("%d", &t);
	for(;t > 0; t--){
		
		scanf("%d", &n);
		vector<Order> orderVector;
		for(i = 0;i < n; i++){
			Order o;
			scanf("%d",&(o.inicio));
			scanf("%d",&fin);
			o.fin = fin + o.inicio;
			scanf("%d",&(o.precio));
			orderVector.push_back(o);
		}
		sort(orderVector.begin(), orderVector.end(), lessFunction);
		long long int price = resolver(orderVector, 0);
		printf("%lld\n",price);
	}
	return 0;
}





