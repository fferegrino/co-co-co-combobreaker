#include <algorithm>
#include <functional>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>

#define LINEAL

typedef struct _order{
	int s;
	int d;
	int p;
	

}Order;

int solucion[10001];
int n;
int t;

bool lessFunction(Order a, Order b){
	return a.s < b.s;
}

int nextOrder(std::vector<Order>& orders, int currentOrder){
	int nO = -1;
	int i, j;
	int fin = orders[currentOrder].s + orders[currentOrder].d;
	#ifdef LINEAL
	for(i = currentOrder + 1;i < orders.size() && nO < 0; i++){
		if(fin < orders[i].s){
			nO = i;
		}
	}
	#else
	i = currentOrder + 1;
	j = orders.size() ;
	while(i <= j){
		int middle = (i + j) / 2;
		if(orders[middle].s >= fin){
			j = middle-1;
			nO = middle;
		} else {
			i = middle+1;
		}
	}
	#endif
	return nO;
}

int resolver(std::vector<Order>& orders, int i){
	if(i >= n)
		return 0;
	if(solucion[i] > -1)
		return solucion[i];
	solucion[i] = resolver(orders, i + 1);
	solucion[i] = std::max(solucion[i], resolver(orders, nextOrder(orders, i)) + orders[i].p);
	return solucion[i];
}

int main(){
	int i;
	scanf("%d", &t);
	for(;t > 0; t--){
		scanf("%d", &n);
		Order *orders = (Order *)malloc(sizeof(Order) * n);
		for(i = 0;i < n; i++){
			scanf("%d",&(orders[i].s));
			scanf("%d",&(orders[i].d));
			scanf("%d",&(orders[i].p));
			
		}
		std::vector<Order> orderVector(orders, orders + n);
		std::sort(orderVector.begin(), orderVector.end(), lessFunction);
		memset(solucion,-1,10001);
		int price = resolver(orderVector, 0);
		printf("%d\n",price);
		free(orders);
	}
	return 0;
}
